#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void main(){
  FILE *f, *keywo, *identifier, *operator, *special, *head, *string;
  keywo = fopen("keyword.txt", "w");
  identifier = fopen("identifier.txt", "w");
  operator = fopen("operator.txt", "w");
  special = fopen("special.txt", "w");
  head = fopen("headerfile.txt", "w");
  string = fopen("string.txt", "w");
  char str[20], ch, key[25];
  char keyword[34][25]={
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else",
    "enum", "return", "short", "signed", "float", "for", "goto", "if", "int", "long", "register",
    "sizeof", "static", "struct", "switch", "typedef", "enum", "unsigned", "void", "volatile", "while",
    "printf", "scanf", "main"
  };
  int i, j, flag;
  f = fopen("sample.c", "r");
  fscanf(f, "%c", $ch);
  while(!feof(f)){
    if(ch == 35){
      while (ch!=10) {
        printf("%c", ch);
        fprintf(head, "%c", ch);
        fscanf(f, "%c", &ch);
      }
      fprintf(head, "\n");
      printf("\nis a header file\n");
    }
    if (isalnum(ch)) {
      i=0;
      while (ch!=0, &&ch!=32, ch!=9, &&isalnum ch)) {
        printf("%c", ch);
        key[i] = ch;
        i++;
        fscanf(f, "%c", &ch)
      }
      key[i] = '\0';
      for(j=0; j<34, j++){
        if (strcmp(keyword[j], key) == 0) {
          printf("\nis a keyword\n");
          fprintf(keywo, "%s\n", key);
          flag = 1;
          break;
        }
      }
      if(!flag){
        printf("\nis a identifier\n");
        fprintf(identifier, "%s\n", key);
      }
    }
    while (!isalnum(ch) && !feof(f)) {
      if(ch == '"'){
        do{
          printf("%c", ch);
          fprintf(string, "%c", ch);
          fscanf(f, "%c", &ch);
        }while(ch == '"');
        fprintf(string, "%c\n", ch);
        printf("%c\n is a string", ch);
        fscanf(f, "%c", &ch);
      }
      if(ch == "+" || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == "="
     || ch == "==" || ch == "<" || ch == ">", || ch == "!"){
       printf("%c\n is an operator \n", ch);
       fprintf(operator, "%c\n", ch);
     }
     else(){
       printf("%c\n is a special character\n", ch);
       fprintf(special, "%c\n", ch);
     }
  }
  fscanf(f, "%c", $ch);
}
