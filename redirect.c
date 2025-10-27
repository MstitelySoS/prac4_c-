/* ----------------------------------------------------
 * ИМЯ: Абрамов А.С., ID: 23К0607
 * ДАТА: 27.10.2025
 * ИМЯ ФАЙЛА: redirect.c
 * НАЗНАЧЕНИЕ: Перенаправить stdout в файл и выполнить команду (execvp)
 * КЛЮЧЕВЫЕ ВЫЗОВЫ: open(), dup2(), execvp(), close()
 * ПРИМЕР ЗАПУСКА:
 *   gcc -std=c99 -Wall -Wextra -O2 redirect.c -o redirect
 *   ./redirect out.txt ls -l
 * ФУНКЦИИ:
 *   main(argc,argv) — проверяет аргументы, перенаправляет stdout и запускает команду
 * ---------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <output_file> <command> [args...]\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }
    close(fd);

    execvp(argv[2], &argv[2]);
    perror("execvp"); /* сюда попадём только при ошибке */
    return 1;
}
