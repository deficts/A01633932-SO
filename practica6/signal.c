#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void processSignal(int x){
    printf("Recibi la senal %d\n",x);
    if(x==15){
        printf("No me puedes matar!!\n");
    }
}


int main(){
    signal(10,processSignal);
    signal(15,processSignal);
    while(1){
        sleep(3);
        printf("Trabajando!!\n");
    }
    return 1;
}