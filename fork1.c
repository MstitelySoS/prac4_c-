/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27.10.2025
 * ИМЯ ФАЙЛА: fork1.c
 * НАЗНАЧЕНИЕ: Демонстрация порождения дочернего процесса (fork)
 * КЛЮЧЕВЫЕ ВЫЗОВЫ: fork(), getpid(), getppid()
 * ПРИМЕР ЗАПУСКА:
 *   gcc -std=c99 -Wall -Wextra -O2 fork1.c -o fork1
 *   ./fork1
 * ФУНКЦИИ:
 *   main() — вызывает fork(), различает ветки parent/child и печатает PID/PPID
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
        printf("I'm the child process with pid %d and ppid %d\n",
               (int)getpid(), (int)getppid());
    }

    printf("Pid %d terminates.\n", (int)getpid());
    return 0;
}
