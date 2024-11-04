 #include <stdio.h>
 #include <unistd.h>

 int main()
 {    
     printf("my process number : [%d] \n", getpid());
     printf("parents process number  : [%d] \n", getppid());
 }


