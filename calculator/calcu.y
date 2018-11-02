%{
#include<stdio.h>
int flag=0,i;
%}

%token DIGIT
%left '+' '-'
%left '*' '/' '%' '^'
%left  '(' ')'

%%

expr: E{
	printf("\nResult=%d\n",$$); return 0;
        };

E:E'+'E {$$=$1+$3;}
|E'^'E {$$=1;
	for(i=$3;i>0;i--)
		$$*=$1;
	}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| DIGIT {$$=$1;}
;

%%



void main()

{

printf("\nEnter Any Arithmetic Expression\n");
yyparse();
if(flag==0)
printf("\nEntered arithmetic expression is Valid\n\n");
}

void yyerror()
{
printf("\nEntered arithmetic expression is Invalid\n\n");
flag=1;
}


