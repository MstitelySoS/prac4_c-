/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27.10.2025
 * ИМЯ ФАЙЛА: task.c
 * НАЗНАЧЕНИЕ: Создать два процесса (parent/child), выводящих счётчик в цикле
 * КЛЮЧЕВЫЕ ВЫЗОВЫ: fork(), getpid(), getppid(), sleep(), wait()
 * ПРИМЕР ЗАПУСКА:
 *   gcc -std=c99 -Wall -Wextra -O2 task.c -o task
 *   ./task
 * ФУНКЦИИ:
 *   ChildProcess()  — печатает счётчик с префиксом [child]
 *   ParentProcess() — печатает счётчик с префиксом [parent]
 *   main()          — fork(); child выполняет ChildProcess(); parent ждёт и запускает ParentProcess()
 * ---------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COUNT 5

static void ChildProcess(void) {
    for (int i = 1; i <= MAX_COUNT; ++i) {
        printf("   [child] iteration %d (pid=%d, ppid=%d)\n",
               i, (int)getpid(), (int)getppid());
        sleep(1);
    }
}

static void ParentProcess(void) {
    for (int i = 1; i <= MAX_COUNT; ++i) {
        printf("[parent] iteration %d (pid=%d, ppid=%d)\n",
               i, (int)getpid(), (int)getppid());
        sleep(1);
    }
}

int main(void) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        ChildProcess();
    } else {
        wait(NULL);       /* ждём завершения ребёнка для детерминированного порядка */
        ParentProcess();
    }
    return 0;
}
