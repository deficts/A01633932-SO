#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argn,char **argv){
    char *fileName= argv[1];
    char buffer;
    int lin = 0;
    int wds = 0;
    int fd = open(fileName,O_RDONLY);
    if(fd<0){
        perror("No se puede abrir");
        exit(1);
    }
    while(read(fd,&buffer,1)){
        printf("%c",buffer);
    }
    close(fd);
    exit(0);
}