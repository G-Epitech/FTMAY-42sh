/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#ifndef HISTORY_H_
    #define HISTORY_H_

    #include <stdbool.h>
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

/**
 * @brief Append a new entry in history.
 * @param history History struct to complete
 * @param input User input to append in history
 * @return Status of Success about the operation
 */
bool history_append_entry(history_t *history, char *input);

/**
 * @brief Get current histroy entry.
 * @param history History to get entry
 * @return Histroy entry with coresponding data
 */
history_entry_t *history_current(history_t *history);

/**
 * @brief Clear the history.
 * @param history History to clear
 * @return Success of the operation
 */
bool history_clear(history_t *history);

/**
 * @brief Get the next command from history.
 * @param history History data
 * @return Next data if there was
 */
history_entry_t *history_next(history_t *history);

/**
 * @brief Get the prev command from history.
 * @param history History data
 * @return prev data if there was
 */
history_entry_t *history_prev(history_t *history);

#endif /* !HISTORY_H_ */
