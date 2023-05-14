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

static bool new_args(int *start, int *len, int *i, char *input)
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
    return (input[*i - 1] == PARSING_STRING) ? true : false;
}

static void fill_string(index_word_t *world, char *string, int *i,
char *input)
{
    if (input[*i] == PARSING_BACKSLASH) {
        (*i)++;
        world->start++;
        if (world->is_string)
            string[*i - world->start] = cmd_get_new_value(input[*i]);
        else
            string[*i - world->start] = input[*i];
    } else {
        string[*i - world->start] = input[*i];
    }
    (*i)++;
}

static void fill_args(char **argv, char *input)
{
    int i = -1;
    int index_argv = 0;
    index_word_t world = {0, 0, false};

    world.is_string = new_args(&world.start, &world.end, &i, input);
    argv[index_argv] = malloc2(sizeof(char) * world.end + 1);
    while (input[i] != '\0') {
        if (world.start + world.end == i && input[i + 1] == '\0')
            break;
        if (world.start + world.end == i) {
            argv[index_argv][world.end] = '\0';
            world.is_string = new_args(&world.start, &world.end, &i, input);
            index_argv++;
            argv[index_argv] = malloc2(sizeof(char) * world.end + 1);
        }
        fill_string(&world, argv[index_argv], &i, input);
    }
    argv[index_argv][world.end] = '\0';
}

static int get_input_parse_len(char *input)
{
    int len = 1;
    bool in_string = false;

    for (int i = 0; input[i] != '\0'; i++) {
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
