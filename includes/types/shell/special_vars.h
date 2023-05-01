/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef SHELL_SPECIAL_VARS_H_
    #define SHELL_SPECIAL_VARS_H_

    #include <unistd.h>
    #include "types/var/defs.h"

    #define SHELL_SPECIAL_VARS_LEN 2

/**
 * @brief Get special shell variable
 * @param shell Shell object
 * @param name Name of special variable to get
 * @param copy Specify if value to get needs to be duplicated
 * @return Value of term variable or NULL if undefined
 */
char *shell_special_vars_std_get(shell_t *shell, char *name, bool copy);

/**
 * @brief Set special shell variable
 * @param value Value to set to variable
 * @param name Name of special variable to get
 * @param dependency Name of dependency env variable
 * @param shell Shell object
 * @return Status of setting success
 */
bool shell_special_vars_std_set(char *name, char *value, char *dependency,
shell_t *shell);

/**
 * @brief Update special shell variable
 * @param name Name of variable to update
 * @param value Value to set to variable
 * @param shell Shell object
 * @return Status of update success
 */
bool shell_special_vars_std_update(char *name, char *value, shell_t *shell);

// List of special shell variables
static const var_special_t shell_special_vars[SHELL_SPECIAL_VARS_LEN] = {
    {
        "term",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        "TERM"
    },
    {
        "home",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        "HOME"
    }
};

#endif /* !SHELL_SPECIAL_VARS_H_ */
