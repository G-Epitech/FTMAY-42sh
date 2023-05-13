/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** save
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "utils/asprintf2.h"
#include "types/history/history.h"

static void save_date(history_entry_t *entry, int fd)
{
    char *date = NULL;
    ssize_t size = 0;

    size = asprintf2(&date,"#+%d\n", entry->date);
    write(fd, date, size - 1);
}

static void save_input(history_entry_t *entry, int fd)
{
    char *name = NULL;
    ssize_t size = 0;

    size = asprintf2(&name,"%s\n", entry->input);
    write(fd, name, size - 1);
}

bool history_save(history_t *history, char *file)
{
    int fd = 0;
    node_t *node = NULL;
    history_entry_t *entry = NULL;

    if (!file || !history || !history->entries->first)
        return false;
    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 00600);
    if (fd == -1)
        return false;
    node = history->entries->first;
    while (node) {
        entry = NODE_DATA_TO_PTR(node->data, history_entry_t *);
        save_date(entry, fd);
        save_input(entry, fd);
        node = node->next;
    }
    return true;
}
