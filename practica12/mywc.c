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
    int numch = 0;
    int wds = 0;
    char espacio = 0;
    int fd = open(fileName,O_RDONLY);
    if(fd<0){
        perror("No se puede abrir");
        exit(1);
    }
    while(read(fd,&buffer,1)){
        numch+=1;
        if((char)buffer == '\n'){
            lin+=1;
        }
        if((buffer ==' ' || buffer =='\n' || buffer == EOF) && espacio == 0){
            espacio=1;
            wds+=1;
        }else if(buffer !=' ' && buffer !='\n' && buffer !=EOF){
            espacio=0; 
        }
    }
    printf("%d ",lin);
    printf("%d ",wds);
    printf("%d ",numch);
    printf("%s \n", fileName);
    close(fd);
    exit(0);
}