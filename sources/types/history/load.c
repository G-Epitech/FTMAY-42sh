/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** load
*/

#include <stdio.h>
#include <string.h>
#include "types/history/history.h"

static int append(history_t *history, char *line, int date)
{
    history_entry_t *entry = NULL;

    history_append_entry(history, line);
    if (date != -1) {
        entry = NODE_DATA_TO_PTR(history->selected->data, history_entry_t *);
        entry->date = date;
    }
    return -1;
}

static void loop(history_t *history, FILE *stream)
{
    char *line = NULL;
    int read = 0;
    int date = -1;
    size_t len = 0;

    while (true) {
        read = getline(&line, &len, stream);
        if (read == -1)
            break;
        if (line[0] == '#') {
            date = atoi(++line);
            continue;
        }
        date = append(history, line, date);
    }
}

bool history_load(history_t *history, char *file)
{
    FILE *stream;

    if (!file || !history)
        return false;
    stream = fopen(file, "r");
    if (!stream)
        return false;
    loop(history, stream);
    fclose(stream);
    return true;
}
