#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
void forkexample() 
{ 
    pid_t pid,pid2;
    pid = fork();
    if(pid == 0){
        printf("Soy el hijo\n");
    }else{
        printf("Soy el padre\n");
    }
} 
int main() 
{ 
    forkexample(); 
    return 0; 
} 