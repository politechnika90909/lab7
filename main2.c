#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) {
    pid_t pid_potomka;
    char *komunikat;
    int powtorzen;
    printf("Na razie działa jeden proces\n");
    pid_potomka = fork();
    switch (pid_potomka) {
        case -1:
            printf("rozwidlenie procesu nie powiodło się\n");
            exit(1);
        case 0:
            komunikat = "Jestem potomkiem";
            powtorzen = 3; // po prostu jeden trwa dluzej od drugiego
            break;
        default:
            komunikat = "Jestem rodzicem";
            powtorzen = 1;
            break;
}
    for (; powtorzen > 0; powtorzen--) {
        puts(komunikat);
        printf("rodzic: %d ja: %d potomek: %d \n", getppid(), getpid(), pid_potomka);

        sleep(1);
    }
}

/*
 * plik binarny fork1
 *
 * gcc -c main.c -o main.o; gcc -o fork1 main.o; ./fork1
 *
 */






