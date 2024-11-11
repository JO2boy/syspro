#include <stdio.h> 
int main(int argc, char *argv[])
{ 
   int child, pid1, status;
   pid1 = fork( );
   if (pid1 == 0) { 
      execvp(argv[1], &argv[1]);
      fprintf(stderr, "%s:fail\n",argv[1]);
   } else { 
      child = wait(&status);
      printf("[%d] child process %d end \n", getpid(),pid1);
      printf("\tend code %d \n", status>>8);
   }
}


