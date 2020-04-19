#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int shmId = shmget(200, 100, 0644 | IPC_CREAT);
    int hijos[5];
    for (int i = 0; i < 5; i++) {
        int pid = fork();
        hijos[i] = pid;
        if (pid != 0) {
            shmId = shmget(200, 100, 0644);
            int *var = (int*)shmat(shmId, NULL, 0);
            var = &var[i*10];
            for(int j = 0; j < 10; j++){
                var[j] = i;
            }
            return 0;
        }
    }
    for(int i = 0; i < 5; i++){
        waitpid(hijos[i],0,0);
    }
    printf("El contenido es: ");
    for (int i = 0; i < 5; i++) {
        shmId = shmget(200, 100, 0644);
        int *var = (int*)shmat(shmId, NULL, 0);
        var = &var[i*10];
        for(int j = 0; j < 10; j++){
            printf("%d",var[j]);
        }
    }
    printf("\n");
    return 0;
}