
%{

#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int parser_id;
typedef struct ParserContext {
  Query * ssql;
  size_t condition_length;
  size_t value_length;
  Value values[MAX_NUM];
  size_t function_length;
  RelAttr functions[MAX_NUM];
  size_t parameter_length;
  Parameter parameters[MAX_NUM];
  size_t group_by_attr_length;
  RelAttr group_by_attrs[MAX_NUM];
  size_t having_condition_length;
  Condition having_conditions[MAX_NUM];
  size_t in_value_num;
  Value in_value[MAX_NUM];
  size_t insert_num;
  size_t insert_value_length[MAX_NUM];
  Value insert_values[MAX_NUM][MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
  size_t order_attr_size;
  RelAttr order_attrs[MAX_NUM];
  OrderFlag order_flag[MAX_NUM];
  size_t id_num;
  char id[MAX_NUM][MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

ParserContext *get_context(yyscan_t scanner)
{
  return &(((ParserContext *)yyget_extra(scanner))[parser_id]);
}

#define CONTEXT get_context(scanner)

void yyerror(yyscan_t scanner, const char *str)
{
  while(parser_id>=0){
	  ParserContext *context = CONTEXT;
      query_reset(context->ssql);
      context->ssql->flag = SCF_ERROR;
      context->condition_length = 0;
      context->value_length = 0;
      memset(context->insert_value_length,0,sizeof(context->insert_value_length));
      context->insert_num=0;
      context->id_num=0;
	  parser_id--;
  }
  parser_id=0;
  printf("parse sql failed. error=%s", str);
}


%}

%define api.pure full
%lex-param { yyscan_t scanner }
%parse-param { void *scanner }

//标识tokens
%token  SEMICOLON
        CREATE
        DROP
        TABLE
        TABLES
        INDEX
        SELECT
        DESC
        SHOW
        SYNC
        INSERT
        DELETE
        UPDATE
        LBRACE
        RBRACE
        COMMA
        TRX_BEGIN
        TRX_COMMIT
        TRX_ROLLBACK
        INT_T
        STRING_T
        FLOAT_T
		DATE_T
		TEXT_T
        HELP
        EXIT
        DOT //QUOTE
        INTO
        VALUES
        FROM
        WHERE
        GROUP
        HAVING
        AND
        SET
        ON
        LOAD
        DATA
        INFILE
        EQ
        LT
        GT
        LE
        GE
        NE
        NOT
        LIKE_T
        IS_T
        UNIQUE
        INNER
        JOIN
        AS
		ASC
		ORDER
		BY
		NULL_T
        NULLABLE
		EXISTS_T
		IN_T
		OR
%union {
  struct _Attr *attr;
  struct _Condition *condition1;
  struct _Value *value1;
  struct Function *function1;
  char *string;
  int number;
  float floats;
  char *position;
}

%token <number> NUMBER
%token <floats> FLOAT
%token <string> DATE
%token <string> ID
%token <string> PATH
%token <string> SSS
%token <string> STAR
%token <string> STRING_V
//非终结符

%type <number> type;
%type <condition1> condition;
%type <value1> value;
%type <number> number;
%type <function1> function;
%type <number> nullable

%%

commands: %empty 		//commands or sqls. parser starts here.
    /* empty */
    | commands command
    ;

command:
	  select  
	| insert
	| update
	| delete
	| create_table
	| drop_table
	| show_tables
	| desc_table
	| create_index	
	| drop_index
	| sync
	| begin
	| commit
	| rollback
	| load_data
	| help
	| exit
	| show_index
    ;

exit:			
    EXIT SEMICOLON {
        CONTEXT->ssql->flag=SCF_EXIT;//"exit";
    };

help:
    HELP SEMICOLON {
        CONTEXT->ssql->flag=SCF_HELP;//"help";
    };

sync:
    SYNC SEMICOLON {
      CONTEXT->ssql->flag = SCF_SYNC;
    }
    ;

begin:
    TRX_BEGIN SEMICOLON {
      CONTEXT->ssql->flag = SCF_BEGIN;
    }
    ;

commit:
    TRX_COMMIT SEMICOLON {
      CONTEXT->ssql->flag = SCF_COMMIT;
    }
    ;

rollback:
    TRX_ROLLBACK SEMICOLON {
      CONTEXT->ssql->flag = SCF_ROLLBACK;
    }
    ;

drop_table:		/*drop table 语句的语法解析树*/
    DROP TABLE ID SEMICOLON {
        CONTEXT->ssql->flag = SCF_DROP_TABLE;//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, $3);
    };

show_tables:
    SHOW TABLES SEMICOLON {
      CONTEXT->ssql->flag = SCF_SHOW_TABLES;
    }
    ;

desc_table:
    DESC ID SEMICOLON {
      CONTEXT->ssql->flag = SCF_DESC_TABLE;
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, $2);
    }
    ;

create_index:		/*create index 语句的语法解析树*/
    CREATE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, $3, $5, CONTEXT->id_num,CONTEXT->id,0);
		}
	| CREATE UNIQUE INDEX ID ON ID LBRACE ID_get id_list RBRACE SEMICOLON
	    {
			CONTEXT->ssql->flag = SCF_CREATE_INDEX;//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, $4, $6, CONTEXT->id_num,CONTEXT->id,1);
		}
    ;

drop_index:			/*drop index 语句的语法解析树*/
    DROP INDEX ID  SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_DROP_INDEX;//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, $3);
		}
    ;
create_table:		/*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_CREATE_TABLE;//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, $3);
			//临时变量清零
			CONTEXT->value_length = 0;
		}
    ;
attr_def_list: %empty 
    /* empty */
    | COMMA attr_def attr_def_list {    }
    ;

attr_def:
    ID type LBRACE number RBRACE nullable
		{
			AttrInfo attribute;
			attr_info_init(&attribute, $1, $2, $4,$6);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
    |ID type nullable
		{
			AttrInfo attribute;
			attr_info_init_no_length(&attribute,$1, $2,$3);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			CONTEXT->value_length++;
		}
    ;
nullable:%empty{
	    $$=0;
	 }
    |NULLABLE{
		$$=1;
	 }
	|NOT NULL_T{
		$$=0;
	};
number:
		NUMBER {$$ = $1;}
		;
type:
	INT_T { $$=INTS; }
       | STRING_T { $$=CHARS; }
       | FLOAT_T { $$=FLOATS; }
	   | DATE_T { $$=DATES;}
	   | TEXT_T { $$=TEXTS;}
       ;
id_list: %empty
   /*empty*/
   |COMMA ID_get id_list{
	 
   };
ID_get:
	ID 
	{
		size_t cur_size = CONTEXT->id_num;
		snprintf(CONTEXT->id[cur_size], sizeof(CONTEXT->id[cur_size]), "%s", $1);
		CONTEXT->id_num++;
	}
	;

	
insert:				/*insert   语句的语法解析树*/
     INSERT INTO ID VALUES value_def value_def_list SEMICOLON 
		{
			CONTEXT->ssql->flag=SCF_INSERT;//"insert";
			inserts_init(&CONTEXT->ssql->sstr.insertion, $3, CONTEXT->insert_values, CONTEXT->insert_value_length,CONTEXT->insert_num);
            //临时变量清零
			for(int i=0;i<CONTEXT->insert_num;i++){
				CONTEXT->insert_value_length[i]=0;
			}
			CONTEXT->value_length=0;
			CONTEXT->insert_num=0;
         }
value_def_list: %empty 
  /* empty */ 
  | COMMA value_def value_def_list{
  };

value_def:
  LBRACE insert_value value_list RBRACE{
	CONTEXT->insert_num++;
  };
value_list: %empty 
    /* empty */
    | COMMA insert_value value_list  {
	  }
    ;
insert_value:
   value{
	CONTEXT->insert_values[CONTEXT->insert_num][CONTEXT->insert_value_length[CONTEXT->insert_num]++]=*$1;
   };

get_select:
   SELECT{
	parser_id++;
	CONTEXT->ssql=query_create();
};
value:
    NUMBER{
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], $1);
		$$=&CONTEXT->values[CONTEXT->value_length-1];
		}
    |FLOAT{
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], $1);
		$$=&CONTEXT->values[CONTEXT->value_length-1];
		}
    |SSS {
		$1 = substr($1,1,strlen($1)-2);
  		value_init_string(&CONTEXT->values[CONTEXT->value_length++], $1);
		$$=&CONTEXT->values[CONTEXT->value_length-1];
		}
	|DATE{
		$1 = substr($1,1,strlen($1)-2);
		if(value_init_date(&CONTEXT->values[CONTEXT->value_length++], $1)<0){
		  CONTEXT->ssql->date_parse_err = -1;
		}
		$$=&CONTEXT->values[CONTEXT->value_length-1];
	}
	|NULL_T{
  		value_init_null(&CONTEXT->values[CONTEXT->value_length++]);
		$$=&CONTEXT->values[CONTEXT->value_length-1];
	}
	|LBRACE get_select select_attr FROM rel_id rel_list join_attr_list where group_by having order_by RBRACE{

		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		selects_append_group_by(&CONTEXT->ssql->sstr.selection, CONTEXT->group_by_attrs, CONTEXT->group_by_attr_length);
		selects_append_having(&CONTEXT->ssql->sstr.selection, CONTEXT->having_conditions, CONTEXT->having_condition_length);
		selects_append_order(&CONTEXT->ssql->sstr.selection, CONTEXT->order_attrs, CONTEXT->order_attr_size, CONTEXT->order_flag);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";
		Query * query = CONTEXT->ssql;
		//临时变量清零
		CONTEXT->condition_length=0;
		CONTEXT->value_length = 0;
		parser_id--;
		value_init_select(&CONTEXT->values[CONTEXT->value_length++],query);
		$$=&CONTEXT->values[CONTEXT->value_length-1];
	}
    ;
    
delete:		/*  delete 语句的语法解析树*/
    DELETE FROM ID where SEMICOLON 
		{
			CONTEXT->ssql->flag = SCF_DELETE;//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, $3);
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
    ;
update:			/*  update 语句的语法解析树*/
    UPDATE ID SET eq_define eq_define_list where SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_UPDATE;//"update";
			updates_init(&CONTEXT->ssql->sstr.update,$2,CONTEXT->id_num,CONTEXT->id,CONTEXT->values, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
    ;
eq_define:
   ID_get EQ value{

};
eq_define_list:%empty
   |COMMA eq_define eq_define_list{

   }

select:				/*  select 语句的语法解析树*/
    	SELECT select_attr FROM rel_id rel_list join_attr_list where group_by having order_by SEMICOLON {
		selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);
		selects_append_group_by(&CONTEXT->ssql->sstr.selection, CONTEXT->group_by_attrs, CONTEXT->group_by_attr_length);
		selects_append_having(&CONTEXT->ssql->sstr.selection, CONTEXT->having_conditions, CONTEXT->having_condition_length);
		selects_append_order(&CONTEXT->ssql->sstr.selection, CONTEXT->order_attrs, CONTEXT->order_attr_size, CONTEXT->order_flag);
		CONTEXT->ssql->flag=SCF_SELECT;//"select";

		//临时变量清零
		CONTEXT->condition_length=0;
		CONTEXT->value_length = 0;
	}
	;
join_attr:
      	INNER JOIN ID ON and_condition condition_list{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $3, NULL);
   	}
      	| INNER JOIN ID AS ID ON and_condition condition_list{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $3, $5);
   	}
	;

join_attr_list:%empty
    | join_attr join_attr_list{
   }
;
order_by:%empty
    | ORDER BY order_attr order_attr_lists order {
		
	}
	;
order:%empty {
	    CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
    }
    | DESC {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = DESC_T;
	}
	| ASC {
		CONTEXT->order_flag[CONTEXT->order_attr_size] = ASC_T;
	}
	;
order_attr:
    ID  order{ 
			RelAttr attr;
			relation_attr_init(&attr, NULL, $1);
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
    }
    | ID DOT ID order{
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			CONTEXT->order_attrs[CONTEXT->order_attr_size++]=attr;
		}
		;
order_attr_lists:%empty
    | COMMA order_attr order_attr_lists
	;
group_by: %empty
	| GROUP BY ID group_by_list {
		RelAttr attr;
		relation_attr_init(&attr, NULL, $3);
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
	| GROUP BY ID DOT ID group_by_list {
		RelAttr attr;
		relation_attr_init(&attr, $3, $5);
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
	;

group_by_list: %empty
	| COMMA ID {
		RelAttr attr;
		relation_attr_init(&attr, NULL, $2);
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
	| COMMA ID DOT ID {
		RelAttr attr;
		relation_attr_init(&attr, $2, $4);
		CONTEXT->group_by_attrs[CONTEXT->group_by_attr_length++] = attr;
	}
	;

having: %empty
	| HAVING having_condition having_condition_list {};

having_condition_list: %empty
	| AND having_condition having_condition_list {};

having_condition:
    function comOp value {
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, $1, NULL, 0, NULL, right_value);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
	| function comOp ID {
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, $3);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, $1, NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
	| function comOp ID DOT ID {
		RelAttr right_attr;
		relation_attr_init(&right_attr, $3, $5);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, $1, NULL, 1, &right_attr, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
    	| value comOp function {
		Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, $3, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
	| ID comOp function {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $3);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, $3, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
	| ID DOT ID comOp function {
		RelAttr left_attr;
		relation_attr_init(&left_attr, $1, $3);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, $5, NULL);
		CONTEXT->having_conditions[CONTEXT->having_condition_length++] = condition;
	}
	;

select_attr:
    STAR attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
    | ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
    | ID DOT ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
    | ID DOT STAR attr_list{
			RelAttr attr;
			relation_attr_init(&attr, $1, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
    }
    | function attr_list {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, $1, NULL);
    }
    | ID AS ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $1);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, $3);
    }
    | ID DOT ID AS ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $1, $3);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, $5);
    }
    | function AS ID attr_list {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, $1, $3);
    }
    ;

function:
	ID LBRACE function_attr RBRACE {
		function_init(&CONTEXT->functions[CONTEXT->function_length++], &CONTEXT->parameters,
			CONTEXT->parameter_length, $1);
		CONTEXT->parameter_length = 0;
		$$=&CONTEXT->functions[CONTEXT->function_length-1];
	}
	;

function_attr: %empty
	| ID function_attr_list {
		RelAttr attr;
		relation_attr_init(&attr, NULL, $1);
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
	| ID DOT ID function_attr_list {
		RelAttr attr;
		relation_attr_init(&attr, $1, $3);
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
	| STAR function_attr_list {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
	| value function_attr_list {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}

function_attr_list: %empty
	| COMMA ID function_attr_list {
		RelAttr attr;
		relation_attr_init(&attr, NULL, $2);
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
	| COMMA ID DOT ID function_attr_list {
		RelAttr attr;
		relation_attr_init(&attr, $2, $4);
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
	| COMMA STAR function_attr_list {
		RelAttr attr;
		relation_attr_init(&attr, NULL, "*");
		parameter_init_attr(&CONTEXT->parameters[CONTEXT->parameter_length++], &attr);
	}
	| COMMA value function_attr_list {
		Value *value = &CONTEXT->values[CONTEXT->value_length - 1];
		parameter_init_value(&CONTEXT->parameters[CONTEXT->parameter_length++], value);
	}

attr_list: %empty 
    /* empty */
    | COMMA ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, NULL, $2);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
      }
    | COMMA ID DOT ID attr_list {
			RelAttr attr;
			relation_attr_init(&attr, $2, $4);
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
  	  }
	| COMMA ID DOT STAR attr_list{
			RelAttr attr;
			relation_attr_init(&attr, $2, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr, NULL);
	}
    | COMMA function attr_list {
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, $2, NULL);
    }
    ;

rel_id:
    ID{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $1, NULL);
    }
    | ID AS ID{
		selects_append_relation(&CONTEXT->ssql->sstr.selection, $1, $3);
    }
;
rel_list: %empty 
    /* empty */
    | COMMA rel_id rel_list {	
		  }
    ;
in_value:%empty
   | value{
	CONTEXT->in_value[CONTEXT->in_value_num++] = *$1;
   };
in_value_list:%empty
   | COMMA in_value in_value_list{
   };
where: %empty 
    /* empty */ 
    | WHERE and_condition condition_list {	
			}
    ;
condition_list: %empty 
    /* empty */
    | AND and_condition condition_list {

	}
	| OR  or_condition condition_list {
	}
    ;
and_condition:
   condition{
	CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 0;
}
or_condition:
   condition{
     CONTEXT->conditions[CONTEXT->condition_length-1].is_or = 1;
};
condition:
	EXISTS_T value{
		CONTEXT->comp = EXISTS;

		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	| NOT EXISTS_T value{
		CONTEXT->comp = NOT_EXISTS;
		Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];
		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	| ID comOp LBRACE in_value in_value_list RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
	| ID DOT ID comOp LBRACE in_value in_value_list RBRACE{
		RelAttr left_attr;
		relation_attr_init(&left_attr,$1, $3);

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 1, &left_attr, NULL,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
	| value comOp LBRACE in_value in_value_list RBRACE {
		Value *left_value = $1;

		Condition condition;
		condition_in_init(&condition, CONTEXT->comp, 0, NULL, left_value,CONTEXT->in_value_num,CONTEXT->in_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		CONTEXT->in_value_num = 0;
	}
    | ID comOp value {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);

		Value *right_value = $3;

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;

	}
	|value comOp value 
	{
		Value *left_value = $1;
		Value *right_value = $3;

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
	|ID comOp ID {
		RelAttr left_attr;
		relation_attr_init(&left_attr, NULL, $1);
		RelAttr right_attr;
		relation_attr_init(&right_attr, NULL, $3);

		Condition condition;
		condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
		CONTEXT->conditions[CONTEXT->condition_length++] = condition;
	}
    |value comOp ID
		{
			Value *left_value = $1;
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, $3);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
		}
    |ID DOT ID comOp value
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3);
			Value *right_value = $5;

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
		
							
    }
    |value comOp ID DOT ID
		{
			Value *left_value = $1;

			RelAttr right_attr;
			relation_attr_init(&right_attr, $3, $5);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
									
    }
    |ID DOT ID comOp ID DOT ID
		{
			RelAttr left_attr;
			relation_attr_init(&left_attr, $1, $3);
			RelAttr right_attr;
			relation_attr_init(&right_attr, $5, $7);

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
    }
    ;

comOp:
  	  EQ { CONTEXT->comp = EQUAL_TO; }
    | LT { CONTEXT->comp = LESS_THAN; }
    | GT { CONTEXT->comp = GREAT_THAN; }
    | LE { CONTEXT->comp = LESS_EQUAL; }
    | GE { CONTEXT->comp = GREAT_EQUAL; }
    | NE { CONTEXT->comp = NOT_EQUAL; }
	| LIKE_T {CONTEXT->comp = LIKE;}
	| NOT LIKE_T {CONTEXT->comp = NOT_LIKE;}
	| IS_T {CONTEXT->comp = IS;}
	| IS_T NOT{CONTEXT->comp = IS_NOT;}
	| IN_T {CONTEXT->comp = IN;}
	| NOT IN_T {CONTEXT->comp = NOT_IN;}
    ;

load_data:
		LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON
		{
		  CONTEXT->ssql->flag = SCF_LOAD_DATA;
			load_data_init(&CONTEXT->ssql->sstr.load_data, $7, $4);
		}
		;

show_index:
        SHOW INDEX FROM ID SEMICOLON
		{
			CONTEXT->ssql->flag = SCF_SHOW_INDEX;
			show_index_init(&CONTEXT->ssql->sstr.show_index, $4);
		}
		;
%%
//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context[MAX_NUM];
	memset(&context, 0, sizeof(context));
	parser_id = 0;

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context[parser_id].ssql = sqls;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
