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
 * @return New shell object
 */
shell_t *shell_new(void);

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

#endif /* !SHELL_H_ */
