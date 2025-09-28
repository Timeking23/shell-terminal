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
  if (strcmp(input, "exit") == 0){
    exit(0);
  }
  if (strcmp(input, "ls") == 0){
    pid_t pid = fork();
    if (pid  == 0)
    {
      printf("child create\n");
      char path[] = "/bin/ls";
      char* argv[] = {"ls", NULL}; 
      execv(path, argv);
      perror("execv failed");
      _exit(1);
    }
    else if (pid > 0)
    {
    int status;
    waitpid(pid, &status, 0);
    }
    else
    {
    perror("fork failed");
    exit(1);
    }
  }
 }while(true);
}
