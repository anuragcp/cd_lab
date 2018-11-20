ARUN [a-zA-Z]
    char name[] = "ARUN";
%%
ARUN    printf("My name is %s", name);
%%
void main(){
    yylex();
}