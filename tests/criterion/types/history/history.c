/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history
*/

#include <criterion/criterion.h>
#include "types/history/history.h"

Test(types_history, new_history)
{
    history_t *history = history_new();

    cr_assert(history->selected == NULL);
    cr_assert(history->count == 0);
    cr_assert(history->entries != NULL);
    history_free(history);
}

Test(types_history, free_history)
{
    history_t *history = history_new();

    history_free(history);
}

Test(types_history, free_null_history)
{
    history_t *history = NULL;

    history_free(history);
}
