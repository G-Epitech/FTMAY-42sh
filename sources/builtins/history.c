/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history
*/

#include <stdio.h>
#include "utils/utils.h"
#include "types/shell/shell.h"
#include "types/history/history.h"

static bool check_char(args_t *args, int index, bool *array)
{
    char options[7] = {'c', 'h', 'r', 'S', 'L', 'M', 'T'};

    for (int i = 0; i < 7; i++) {
        if (options[i] == args->argv[1][index]) {
            array[i] = true;
            return true;
        }
    }
    return false;
}

static bool check_args(args_t *args, bool *array)
{
    int index = 1;

    while (args->argv[1][index] != '\0') {
        if (!check_char(args, index, array))
            return false;
        index++;
    }
    return true;
}

static int manage_options(shell_t *shell, bool *array)
{
    if (BUILTIN_HISTORY_C(array)) {
        history_clear(shell->history);
        return -2;
    }
    if (BUILTIN_HISTORY_S(array)) {
        history_save(shell->history, BUILTIN_HISTORY_SAVE_PATH);
        return -2;
    }
    if (BUILTIN_HISTORY_L(array)) {
        history_load(shell->history, BUILTIN_HISTORY_SAVE_PATH);
        return -2;
    }
    return -1;
}

static int handle_options(args_t *args, shell_t *shell, bool *array)
{
    char *error = NULL;

    if (args->argv[1][0] == '-') {
        if (!check_args(args, array)) {
            error = "Usage: history [-chrSLMT] [# number of events].\n";
            fprintf(stderr, error);
            return -3;
        }
        return manage_options(shell, array);
    } else {
        if (!is_number(args->argv[1])) {
            error = "history: Badly formed number.\n";
            fprintf(stderr, error);
            return -3;
        }
        return atoi(args->argv[1]);
    }
    return -1;
}

int builtin_history(args_t *args, shell_t *shell)
{
    int result = 100;
    bool array[7] = {false};

    if (!args || args->argc > 2)
        return SHELL_EXIT_ERROR;
    if (args->argc > 1)
        result = handle_options(args, shell, array);
    if (result == -3)
        return SHELL_EXIT_ERROR;
    if (result == -2)
        return 0;
    if (result == -1)
        result = 100;
    history_display(shell, result, array);
    return 0;
}
