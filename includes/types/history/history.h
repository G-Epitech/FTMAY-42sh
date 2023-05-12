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
    #include "types/shell/defs.h"

    #define BUILTIN_HISTORY_C(array) (array[0])
    #define BUILTIN_HISTORY_H(array) (array[1])
    #define BUILTIN_HISTORY_R(array) (array[2])
    #define BUILTIN_HISTORY_S(array) (array[3])
    #define BUILTIN_HISTORY_L(array) (array[4])
    #define BUILTIN_HISTORY_M(array) (array[5])
    #define BUILTIN_HISTORY_T(array) (array[6])
    #define BUILTIN_HISTORY_PATH ".42sh.history"

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

/**
 * @brief Save an history in a file.
 * @param history History to save
 * @param file Target file
 * @return False if there is an error, otherwise it's True
 */
bool history_save(history_t *history, char *file);

/**
 * @brief Load an history from a file.
 * @param history History to append new commands
 * @param file File to load
 * @param sort Sort entries
 * @return False if there is an error, otherwise, it's True
 */
bool history_load(history_t *history, char *file, bool sort);

/**
 * @brief Display the Shell history.
 * @param shell Shell object
 * @param occurrences Number of occurrences
 * @param array Bool array with option in it;
 */
void history_display(shell_t *shell, int occurrences, bool *array);

/**
 * @brief Append a new entry in history.
 * @param history SHell history
 * @param input User input
 * @param date Date
 * @return False if there is an error, otherwise, it's True
 */
bool history_append_entry_date(history_t *history, char *input, int date);

#endif /* !HISTORY_H_ */
