/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** history_entry
*/

#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include "utils/utils.h"
#include "types/shell/defs.h"
#include "types/history/history.h"

history_entry_t *shell_input_replace_history_get_entry_pattern(char *pattern,
size_t len, shell_t *shell)
{
    history_t *history = shell ? shell->history : NULL;
    list_t *entries = history ? history->entries : NULL;
    node_t *node = entries ? entries->last : NULL;
    history_entry_t *entry = NULL;

    while (node) {
        entry = NODE_DATA_TO_PTR(node->data, history_entry_t *);
        if (strncmp(pattern, entry->input, len) == 0)
            return entry;
        node = node->prev;
    }
    return NULL;
}

history_entry_t *shell_input_replace_history_get_entry_id(unsigned long id,
shell_t *shell)
{
    history_t *history = shell ? shell->history : NULL;
    list_t *entries = history ? history->entries : NULL;
    node_t *node = entries ? entries->last : NULL;
    history_entry_t *entry = NULL;

    while (node) {
        entry = NODE_DATA_TO_PTR(node->data, history_entry_t *);
        if (entry->id == id)
            return entry;
        node = node->prev;
    }
    return NULL;
}

history_entry_t *shell_input_replace_history_get_entry(char *pattern,
size_t len, shell_t *shell)
{
    char *pattern_str = strndup(pattern, len);
    int id = -1;
    history_entry_t *entry = NULL;

    if (!pattern_str)
        return entry;
    if (is_number(pattern_str)) {
        id = strtoul(pattern_str, NULL, 10);
        entry = shell_input_replace_history_get_entry_id(id, shell);
    } else {
        entry = shell_input_replace_history_get_entry_pattern(pattern,
        len, shell);
    }
    return entry;
}
