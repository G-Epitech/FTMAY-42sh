/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set_command_args
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include "utils/malloc2.h"
#include "types/cmd/defs.h"
#include "types/var/defs.h"
#include "parsing/parsing.h"
#include "types/shell/shell.h"

static void new_args(size_t *start, size_t *len, size_t *i, char *input)
{
    (*i)++;
    while (input[*i] == PARSING_SPACE || input[*i] == PARSING_TAB)
        (*i)++;
    if (input[*i] == PARSING_STRING) {
        (*i)++;
        (*len) = parsing_get_len_input_string(input, (*i));
    } else {
        (*len) = parsing_get_len_input(input, (*i));
    }
    (*start) = *i;
}

static bool fill_args(char **argv, char *input)
{
    size_t index_argv = 0;
    size_t len = 0;
    size_t start = 0;

    len = parsing_get_len_input(input, 0);
    start = 0;
    argv[index_argv] = malloc2(sizeof(char) * len + 1);
    for (size_t i = 0; input[i] != '\0'; i++) {
        if (start + len == i && input[i + 1] == '\0')
            break;
        if (start + len == i) {
            argv[index_argv][len] = '\0';
            new_args(&start, &len, &i, input);
            index_argv++;
            argv[index_argv] = malloc2(sizeof(char) * len + 1);
        }
        argv[index_argv][i - start] = input[i];
    }
    argv[index_argv][len] = '\0';
    return true;
}

static int get_input_parse_len(char *input)
{
    int len = 1;
    bool in_string = false;

    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] == PARSING_STRING)
            in_string = !in_string;
        if (in_string)
            continue;
        if (input[i] != PARSING_SPACE && input[i] != PARSING_TAB)
            continue;
        while (input[i] == PARSING_SPACE || input[i] == PARSING_TAB)
            i++;
        if (input[i] == '\0')
            break;
        i--;
        len++;
    }
    return len;
}

bool parsing_set_command_args(cmd_t *command, shell_t *shell)
{
    args_t *args = &command->args;

    (void) shell;
    if (!command->input)
        return false;
    args->argc = get_input_parse_len(command->input);
    args->argv = malloc2(sizeof(char *) * args->argc);
    if (!args->argv)
        return false;
    if (!fill_args(args->argv, command->input))
        return false;
    command->name = strdup(args->argv[0]);
    return true;
}
