/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** get no var
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parsing/defs.h"
#include "parsing/parsing.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"

char *get_no_var(char *input, int start, int end)
{
    char *word = malloc(sizeof(char) * end - start + 1);
    int index = 0;

    memset(word, '\0', end - start + 1);
    while (start < end) {
        word[index] = input[start];
        index++;
        start++;
    }
    return word;
}
