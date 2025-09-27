#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
int  main(int argc, char* argv[])
{
char input[30]; 
 do{
  printf("wish> ");
  scanf("%s", input);
  if (strcmp(input, "exit") == 0){
    exit(0);
  }
  if (strcmp(input, "ls") == 0){
    execv(input, argv[2]);
    exit(0);
  }
 }while(true);
}
