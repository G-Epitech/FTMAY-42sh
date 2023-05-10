/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** move
*/

#include "types/history/history.h"

history_entry_t *history_next(history_t *history)
{
    if (!history || !history->selected || !history->selected->next)
        return NULL;
    history->selected = history->selected->next;
    return history_current(history);
}

history_entry_t *history_prev(history_t *history)
{
    if (!history || !history->selected || !history->selected->prev)
        return NULL;
    history->selected = history->selected->prev;
    return history_current(history);
}
