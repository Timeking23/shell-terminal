#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int  main(int argc, char* argv[])
{
char *input;
size_t len = 0; 

 do{
  printf("wish> ");
  ssize_t ninput =  getline(&input,&len,stdin);
  input[strcspn(input, "\n")] = 0;
  if (strcmp(input, "exit") == 0){
    exit(0);
  }
  if (strcmp(input, "ls") == 0){
    pid_t pid = fork();
    if (pid  == 0)
    {
      char path[] = "/bin/ls";
      char* argv[] = {"ls", NULL}; 
      execv(path, argv);
    }
  }
  if (strcmp(input, "cd") == 0){
    if (argc == 1)
    {
      chdir("~");
    }
    if (argc == 2)
    {
      chdir(argv[2]);
    }
    else
    {
      char error_message[30] = "An error has occurred\n";
      write(STDERR_FILENO, error_message, strlen(error_message)); 
    }
  }
 }while(true);
}
