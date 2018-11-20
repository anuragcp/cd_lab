%{
    #include <stdio.h>
    FILE *fptr;
    int vcount=0, ccount=0;
%}

%%
    [a|e|i|o|u|A|E|I|O|U]   {vcount++;}
    [a-zA-Z(^a|e|i|o|u|A|E|I|O|U)]   {vcount++;}
%%

int main(){
    fptr = fopen("file","r");
    yyin = fopen("file", "w");
    fscanf(fptr, "%s", str);
    yylex();
    printf("No. of vowels = %d\n", vcount);
    printf("No. of consonents = %d\n", ccount);
    return 0;
}

