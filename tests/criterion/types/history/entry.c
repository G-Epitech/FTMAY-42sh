/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** entry
*/

#include <criterion/criterion.h>
#include "types/history/history.h"

Test(types_history_entry, new_history_entry)
{
    history_entry_t *entry = history_entry_new();

    cr_assert(entry->date == 0);
    cr_assert(entry->input == NULL);
    cr_assert(entry->id == 0);
    history_entry_free(entry);
}

Test(types_history_entry, free_history_entry)
{
    history_entry_t *entry = history_entry_new();

    history_entry_free(entry);
}

Test(types_history_entry, free_null_history_entry)
{
    history_entry_t *entry = NULL;

    history_entry_free(entry);
}
