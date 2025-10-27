/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27.10.2025
 * ИМЯ ФАЙЛА: fork2.c
 * НАЗНАЧЕНИЕ: Показать осиротевший процесс (sleep в child)
 * КЛЮЧЕВЫЕ ВЫЗОВЫ: fork(), sleep(), getpid(), getppid()
 * ПРИМЕР ЗАПУСКА:
 *   gcc -std=c99 -Wall -Wextra -O2 fork2.c -o fork2
 *   ./fork2
 * ФУНКЦИИ:
 *   main() — parent печатает info и завершается раньше; child спит и печатает новый PPID
 * ---------------------------------------------------- */
#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid;

    printf("I'm the original process with pid %d and ppid %d\n",
           (int)getpid(), (int)getppid());

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid != 0) {
        printf("I'm the parent process with pid %d and ppid %d\n",
               (int)getpid(), (int)getppid());
        printf("My child's pid is %d\n", (int)pid);
    } else {
        sleep(5);
        printf("I'm the child process with pid %d and ppid %d\n",
               (int)getpid(), (int)getppid());
        printf("Child became orphaned (ppid likely 1/systemd).\n");
    }

    printf("Pid %d terminates.\n", (int)getpid());
    return 0;
}
