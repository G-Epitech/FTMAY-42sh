/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history
*/

#include <criterion/criterion.h>
#include "types/history/history.h"
#include "utils/malloc2.h"

Test(types_history, new_history)
{
    history_t *history = history_new();

    cr_assert(history->selected == NULL);
    cr_assert(history->count == 0);
    cr_assert(history->entries != NULL);
    history_free(history);
}

Test(types_history, new_history_malloc_failed)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    history_t *history = history_new();
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);

    cr_assert_null(history);
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
    cr_assert(entry->id == 1);
    cr_assert(strcmp(entry->input, "ls -la") == 0);
    history_free(history);
}

Test(types_history, history_clear_null)
{
    history_t *history = NULL;

    cr_assert(history_clear(history) == false);
}

Test(types_history, history_clear_basic)
{
    history_t *history = history_new();

    history_append_entry(history, "ls -la");
    cr_assert(history_clear(history) == true);
    cr_assert(history->selected == NULL);
    cr_assert(history->entries == NULL);
    history_free(history);
}

Test(types_history, history_prev_basic)
{
    history_t *history = history_new();
    history_entry_t *data = NULL;

    history_append_entry(history, "ls -la");
    history_append_entry(history, "cat Makefile -e");
    history_append_entry(history, "echo hey");
    data = history_prev(history);
    cr_assert(strcmp(data->input, "cat Makefile -e") == 0);
    history_free(history);
}

Test(types_history, history_prev_null)
{
    history_t *history = NULL;
    history_entry_t *data = NULL;

    data = history_prev(history);
    cr_assert_null(data);
    history_free(history);
}

Test(types_history, history_prev_empty)
{
    history_t *history = history_new();
    history_entry_t *data = NULL;

    data = history_prev(history);
    cr_assert_null(data);
    history_free(history);
}

Test(types_history, history_prev_prev)
{
    history_t *history = history_new();
    history_entry_t *data = NULL;

    history_append_entry(history, "ls -la");
    data = history_prev(history);
    cr_assert_null(data);
    history_free(history);
}

Test(types_history, history_next_basic)
{
    history_t *history = history_new();
    history_entry_t *data = NULL;

    history_append_entry(history, "ls -la");
    history_append_entry(history, "cat Makefile -e");
    history_append_entry(history, "echo hey");
    history_prev(history);
    data = history_next(history);
    cr_assert(strcmp(data->input, "echo hey") == 0);
    history_free(history);
}

Test(types_history, history_next_null)
{
    history_t *history = NULL;
    history_entry_t *data = NULL;

    data = history_next(history);
    cr_assert_null(data);
    history_free(history);
}

Test(types_history, history_next_empty)
{
    history_t *history = history_new();
    history_entry_t *data = NULL;

    data = history_next(history);
    cr_assert_null(data);
    history_free(history);
}

Test(types_history, history_next_next)
{
    history_t *history = history_new();
    history_entry_t *data = NULL;

    history_append_entry(history, "ls -la");
    data = history_next(history);
    cr_assert_null(data);
    history_free(history);
}

Test(types_history, history_load_basic)
{
    history_t *history = history_new();

    cr_assert(history_load(history, "history.tmp") == true);
    history_free(history);
}

Test(types_history, history_load_null)
{
    history_t *history = history_new();

    cr_assert(history_load(history, NULL) == false);
    history_free(history);
}

Test(types_history, history_load_history_null)
{
    history_t *history = NULL;

    cr_assert(history_load(history, "history.tmp") == false);
    history_free(history);
}

Test(types_history, history_save_basic)
{
    history_t *history = history_new();

    history_append_entry(history, "ls -la");
    history_append_entry(history, "echo 1");
    history_append_entry(history, "echo 2");
    history_append_entry(history, "pwd");
    cr_assert(history_save(history, "history.tmp") == true);
    history_free(history);
}

Test(types_history, history_save_null_path)
{
    history_t *history = history_new();

    cr_assert(history_save(history, NULL) == false);
    history_free(history);
}

Test(types_history, history_save_null_history)
{
    history_t *history = NULL;

    cr_assert(history_save(NULL, "history.tmp") == false);
    history_free(history);
}

Test(types_history, history_save_no_cmd)
{
    history_t *history = history_new();

    cr_assert(history_save(history, "history.tmp") == false);
    history_free(history);
}
