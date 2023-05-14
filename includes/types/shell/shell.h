/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#ifndef SHELL_H_
    #define SHELL_H_

    #include <stdio.h>
    #include "defs.h"

/**
 * @brief Create a new shell integrating given environnement variables.
 * @param builtins Builtins command to set to shell
 * @return New shell object
 */
shell_t *shell_new(const builtin_t *builtins);

/**
 * @brief Free given shell and all its internal fields.
 * @param shell Shell object
 */
void shell_free(shell_t *shell);

/**
 * @brief Set value of variable matching with given name.
 * @param shell Shell object
 * @param name Name of variable to set
 * @param value Value to set to variable
 * @return true on success false otherwise
 */
bool shell_set_var(shell_t *shell, char *name, char *value);

/**
 * @brief Unset variable matching with given name.
 * @param shell Shell object
 * @param name Name of variable to unset
 */
void shell_unset_var(shell_t *shell, char *name);

/**
 * @brief Get value of variable matching with given name.
 * @param shell Shell object
 * @param name Name of variable of which get value
 * @param copy Specify if value to get needs to be duplicated
 * @return Value or NULL if not found
 */
char *shell_get_var(shell_t *shell, char *name, bool copy);

/**
 * @brief Wait for all user command entry.
 * @param shell Shell object
 * @param input Pointer to string in which export user input
 * @return Success status
 */
bool shell_get_input(shell_t *shell, char **input);

/**
 * @brief Display before the user input the shell prompt.
 * @param shell Shell object
 */
void shell_display_prompt(shell_t *shell);

/**
 * @brief Display prompt for exit and set status of shell to SH_EXITED.
 * @param shell Shell object
 */
void shell_exit(shell_t *shell);

/**
 * @brief Init specials variables of shell.
 * @param shell Shell object
 */
void shell_special_vars_init(shell_t *shell);

/**
 * @brief Update all specials vars depending on environnement.
 * variables.
 * @param shell Shell object
 * @param name Name of environnement variable
 */
void shell_special_vars_dispatch_env_update(shell_t *shell, char *name);

/**
 * @brief Init shell input / output.
 * @param shell Shell object
 * @return Success status of initialization
 */
bool shell_init_io(shell_t *shell);

/**
 * @brief Restore initial input / output of shell.
 * @param shell Shell object
 * @return Status of restoring success
 */
bool shell_restore_io(shell_t *shell);

/**
 * @brief Replace value of var in given string.
 * @param string String to format
 * @param shell Shell struct
 * @return String formated
 */
char *shell_format_string(char *string, shell_t *shell);

/**
 * @brief Replace value of variable.
 * @param string String to format
 * @param shell Shell struct
 * @param parsing_index Index parsing on remplacing var
 * @return Value of variable
 */
char *shell_format_string_get_var(char *string, shell_t *shell,
int *parsing_index);

/**
 * @brief Get string that containing no variables to replace.
 * @param string String to format
 * @param start Start of non var input
 * @param end End of non var input
 * @return Copied string
 */
char *shell_format_string_get_no_var(char *input, int start, int end);

/**
 * @brief Replace all pattern with symbol '!' with matching history entry.
 * @param original Original input given by user
 * @param shell Shell object
 * @param final Pointer to string in which store replaced input
 * @return Success status
 */
bool shell_input_replace_history(char *original, char **final, shell_t *shell);

/**
 * @brief During replacing step, get entry matching with pattern if exists.
 * @param pattern Pattern start point
 * @param len Length of pattern
 * @param shell Shell object
 * @return History entry if found, NULL otherwise
 */
history_entry_t *shell_input_replace_history_get_entry(char *pattern,
size_t len, shell_t *shell);

/**
 * @brief During replacing step, get entry matching with pattern if exists.
 * @param id Identifiant of command to execute
 * @param shell Shell object
 * @return History entry if found, NULL otherwise
 */
history_entry_t *shell_input_replace_history_get_entry_id(unsigned long id,
shell_t *shell);

/**
 * @brief Get pattern after reference symbol.
 * @param input Input given by user
 * @param i Index of current symbol
 * @param pattern_len Pointer to space in which store pattern length
 * @return Status of success
 */
void shell_input_replace_history_get_pattern(char *input, size_t i,
size_t *pattern_len);


/**
 * @brief Handle history replacement occurrence.
 * @param utils Utils replacement data
 * @param shell Shell object
 * @return Success of handling
 */
bool shell_input_replace_history_handle_occur(hist_replace_utils_t *utils,
shell_t *shell);

/**
 * @brief Replace history entry match by total entry at occurence position.
 * @param utils Utils replacement data
 * @param pattern_len Length of given pattern
 * @param entry Entry found in history or NULL if no match found
 * @return Success of replacement
 */
bool shell_input_replace_history_entry_occur(hist_replace_utils_t *utils,
size_t pattern_len, history_entry_t *entry);

/**
 * @brief Prevent error from non existant pattern and handle errors display.
 * @param utils Utils replacement data
 * @param pattern Pattern parsed
 * @param entry Entry found in history or NULL if no match found
 * @param shell Shell object
 */
void shell_input_replace_history_check_entry(hist_replace_utils_t *utils,
char *pattern, history_entry_t *entry, shell_t *shell);

/**
 * @brief Replace special entry in current input.
 * @param utils Utils replacement data
 * @param shell Shell object
 * @return tatus of success replacement
 */
bool shell_input_replace_history_entry_special(hist_replace_utils_t *utils,
shell_t *shell);

/**
 * @brief Replace from last entry match saved.
 * @param utils Utils replacement data
 * @param shell Shell object
 * @return Status of success replacement
 */
bool shell_input_replace_history_entry_last(hist_replace_utils_t *utils,
shell_t *shell);

#endif /* !SHELL_H_ */
