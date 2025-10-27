/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27.10.2025
 * ИМЯ ФАЙЛА: myexec.c
 * НАЗНАЧЕНИЕ: Замена текущего процесса на /bin/ls -l (exec)
 * КЛЮЧЕВЫЕ ВЫЗОВЫ: execl(), getpid()
 * ПРИМЕР ЗАПУСКА:
 *   gcc -std=c99 -Wall -Wextra -O2 myexec.c -o myexec
 *   ./myexec
 * ФУНКЦИИ:
 *   main() — печатает PID, вызывает execl(); при ошибке — perror
 * ---------------------------------------------------- */
#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("I'm process %d and I'm about to exec an ls -l\n", (int)getpid());
    execl("/bin/ls", "ls", "-l", (char*)NULL);
    perror("execl"); /* сюда попадём только при ошибке */
    return 1;
}
