/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef HISTORY_DEFS_H_
    #define HISTORY_DEFS_H_

    #include <time.h>
    #include "types/list/defs.h"

// Represent a history
typedef struct s_history {
    list_t *entries;    // Entries of history
    node_t *selected;   // Current selected entry
    unsigned long count;   // Counter of entries added from start
} history_t;

// Represent a history entry
typedef struct s_history_entry {
    char *input;        // User input
    time_t date;        // Date of entry
    unsigned long id;   // Id of the entry
} history_entry_t;

#endif /* !HISTORY_DEFS_H_ */
