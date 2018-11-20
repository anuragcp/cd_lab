%{
    int lcount=0, ccount=0, wcount=0
%}
%%
[\n]    {lcount++;}
[a-zA-Z]    {ccount++;}
[" "]   {wcount++;}
%%

int main(){
    FILE *fptr;
    fptr = fopen("sample.txt", "r");
    yyin = fptr;
    yylex();
    printf("Line count %d.", lcount);
    printf("Char count %d.", ccount);
    printf("Word count %d.", wcount);
    return 0;
}
