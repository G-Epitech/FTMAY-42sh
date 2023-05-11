/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set_command_args
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils/malloc2.h"
#include "types/cmd/cmd.h"
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
        (*len) = cmd_set_args_get_len_input_string(input, (*i));
    } else {
        (*len) = cmd_set_args_get_len_input(input, (*i));
    }
    (*start) = *i;
}

static void fill_args(char **argv, char *input)
{
    size_t i = -1;
    size_t index_argv = 0;
    size_t len = 0;
    size_t start = 0;

    new_args(&start, &len, &i, input);
    argv[index_argv] = malloc2(sizeof(char) * len + 1);
    while (input[i] != '\0') {
        if (start + len == i && input[i + 1] == '\0')
            break;
        if (start + len == i) {
            argv[index_argv][len] = '\0';
            new_args(&start, &len, &i, input);
            index_argv++;
            argv[index_argv] = malloc2(sizeof(char) * len + 1);
        }
        argv[index_argv][i - start] = input[i];
        i++;
    }
    argv[index_argv][len] = '\0';
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

bool cmd_set_args(cmd_t *command, shell_t *shell)
{
    args_t *args = &command->args;
    char *formated = NULL;

    if (!command->input)
        return false;
    formated = shell_format_string(command->input, shell);
    if (!formated)
        return false;
    free(command->input);
    command->input = formated;
    args->argc = get_input_parse_len(command->input);
    args->argv = malloc2(sizeof(char *) * (args->argc + 1));
    if (!args->argv)
        return false;
    fill_args(args->argv, command->input);
    args->argv[args->argc] = NULL;
    command->name = strdup(args->argv[0]);
    return true;
}
