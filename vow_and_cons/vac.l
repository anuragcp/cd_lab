%{
    #include<stdio.h>
    int vcount=0, ccount=0;
%}


%%
[a|e|i|o|u|A|E|I|O|U]   {vcount++;}
[a-zA-Z (^a|e|i|o|u|A|E|I|O|U)] {ccount++;}
%%

int main(){
    yylex();
    printf("Vowels = %d", vcount);
    printf("Consonents = %d", ccount);
    return 0;
}
