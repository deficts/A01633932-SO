#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFSIZE 512

int main(int argc, char **argv){
    char *originFileName = argv[1]; 
    char *dstFileName = argv[2];  
    char buf[BUFSIZE];  
    int from,to,nr,nw,n;
    if((from = open(originFileName, O_RDONLY))<0){
        perror("Error opening source file");
        exit(1);
    }
    if ((to=creat(dstFileName, 0666)) < 0) {
        perror("Error creating destination file");
        exit(2);
    }
    while((nr=read(from, buf, sizeof( buf))) != 0) {
        if (nr < 0) {
           perror("Error reading source file");
     exit(3);
        }
        nw=0;
        do {
          if ((n=write(to, &buf[nw], nr-nw)) < 0) {
            perror("Error writing destination file");
            exit(4);
          }
          nw += n;
        } while (nw < nr);
      }
      close(from); close(to); 
}