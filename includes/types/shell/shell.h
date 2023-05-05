/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#ifndef SHELL_H_
    #define SHELL_H_

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
 * @return Command user input in format char *
 */
char *shell_get_input(shell_t *shell);

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

#endif /* !SHELL_H_ */
