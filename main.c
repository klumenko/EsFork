#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Creazione del processo figlio
    pid = fork();

    if (pid < 0) {
        // Errore durante fork()
        perror("Errore nella fork");
        return 1;
    }
    if (pid == 0) {
        // Processo figlio: stampa da 1 a 5
        for (int i = 1; i <= 5; i++) {
            printf("Figlio: %d\n", i);

        }
        exit(0);
    } else {
        // Processo padre: attende la terminazione del figlio
        wait(NULL);

        // Il padre stampa da 6 a 10
        for (int i = 6; i <= 10; i++) {
            printf("Padre: %d\n", i);

        }
    }

    return 0;
}