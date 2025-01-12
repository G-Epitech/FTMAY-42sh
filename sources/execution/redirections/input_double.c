/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** double_left
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils/malloc2.h"

static char *get_user_input(void)
{
    char *reader = NULL;
    size_t size = 0;
    ssize_t readed = 0;

    write(1, "? ", 2);
    while (!reader)
        readed = getline(&reader, &size, stdin);
    if (readed == -1)
        return NULL;
    return reader;
}

static void exit_loop(char *new_word, char *input)
{
    free(new_word);
    free(input);
}

void execution_redirection_get_input_double(char *word, int fd)
{
    char *input = NULL;
    char *new_word = malloc2(sizeof(char) * (strlen(word) + 2));

    if (!new_word)
        return;
    memset(new_word, '\0', strlen(word) + 2);
    strcpy(new_word, word);
    strcat(new_word, "\n");
    while (true) {
        free(input);
        input = get_user_input();
        if (!input)
            return exit_loop(new_word, input);
        if (strcmp(input, new_word) == 0 || strcmp(input, word) == 0)
            return exit_loop(new_word, input);
        write(fd, input, strlen(input));
    }
}
