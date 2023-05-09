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

Test(types_history, history_null_curent)
{
    history_t *history = NULL;

    cr_assert_null(history_current(history));
}

Test(types_history, history_current_null)
{
    history_t *history = history_new();

    cr_assert_null(history_current(history));
    history_free(history);
}

Test(types_history, history_current_basic)
{
    history_t *history = history_new();
    history_entry_t *entry = NULL;

    history_append_entry(history, "ls -la");
    entry = history_current(history);
    cr_assert(entry->id == 0);
    cr_assert(strcmp(entry->input, "ls -la") == 0);
    history_free(history);
}
