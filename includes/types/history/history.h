/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#ifndef HISTORY_H_
    #define HISTORY_H_

    #include "defs.h"

/**
 * @brief Create a new history structure.
 * @return New empty history
 */
history_t *history_new(void);

/**
 * @brief Free a entire history.
 * @param history History to free
 */
void history_free(history_t *history);

/**
 * @brief Create a new empty entry for the history.
 * @return New empty history entry
 */
history_entry_t *history_entry_new(void);

/**
 * @brief Free a single histroy entry.
 * @param history_entry Histroy entry to free
 */
void history_entry_free(history_entry_t *history_entry);

/**
 * @brief Can free a history entry from a list.
 * @param data Node data to free
 */
void history_entry_node_freer(node_data_t data);

#endif /* !HISTORY_H_ */
