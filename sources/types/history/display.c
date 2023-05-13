/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** display
*/

#include <stdio.h>
#include "utils/utils.h"
#include "types/shell/defs.h"
#include "types/history/history.h"

static void print_line(history_entry_t *entry, bool *array)
{
    int space = 6;
    struct tm date;
    bool option_h = BUILTIN_HISTORY_H(array);

    if (!option_h) {
        space -= len_number(entry->id);
        for (int i = 0; i < space; i++)
            printf(" ");
        printf("%ld", entry->id);
        date = *localtime(&entry->date);
        printf("\t%d:%.2d\t", date.tm_hour, date.tm_min);
    }
    printf("%s\n", entry->input);
}

void history_display(shell_t *shell, int occurences, bool *array)
{
    int number = 0;
    node_t *node = NULL;

    node = shell->history->entries->last;
    while (node->prev && number < occurences) {
        node = node->prev;
        number++;
    }
    if (BUILTIN_HISTORY_R(array))
        node = shell->history->entries->last;
    number = 0;
    while (node && number < occurences) {
        print_line(NODE_DATA_TO_PTR(node->data, history_entry_t *), array);
        if (BUILTIN_HISTORY_R(array))
            node = node->prev;
        else
            node = node->next;
        number++;
    }
}
