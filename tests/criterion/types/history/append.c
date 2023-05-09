/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** append
*/

#include <string.h>
#include <criterion/criterion.h>
#include "types/history/history.h"
#include "utils/malloc2.h"

Test(types_history, history_append)
{
    history_t *history = history_new();
    char *input = "ls -la";

    history_append_entry(history, input);
    cr_assert(history->count == 1);
    cr_assert(history->entries->len == 1);
    cr_assert(history->selected == history->entries->first);
    history_entry_t *data = NODE_DATA_TO_PTR(history->entries->first->data, history_entry_t *);
    cr_assert(strcmp(data->input, input) == 0);
    history_free(history);
}

Test(types_history, history_null_append)
{
    history_t *history = NULL;
    char *input = "ls -la";

    cr_assert(history_append_entry(history, input) == false);
}

Test(types_history, history_input_null_append)
{
    history_t *history = history_new();
    char *input = NULL;

    cr_assert(history_append_entry(history, input) == false);
    history_free(history);
}

Test(types_history, history_append_malloc_failed)
{
    history_t *history = history_new();
    char *input = "ls -la";

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert(history_append_entry(history, input) == false);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    history_free(history);
}
