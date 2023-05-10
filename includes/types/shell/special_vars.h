/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef SHELL_SPECIAL_VARS_H_
    #define SHELL_SPECIAL_VARS_H_

    #include <unistd.h>
    #include <stdbool.h>
    #include "types/var/defs.h"

    #define SHELL_SPECIAL_VARS_LEN 12

/**
 * @brief Get special shell variable.
 * @param shell Shell object
 * @param name Name of special variable to get
 * @param copy Specify if value to get needs to be duplicated
 * @return Value of term variable or NULL if undefined
 */
char *shell_special_vars_std_get(shell_t *shell, char *name, bool copy);

/**
 * @brief Set special shell variable.
 * @param value Value to set to variable
 * @param name Name of special variable to get
 * @param dependency Name of dependency env variable
 * @param shell Shell object
 * @return Status of setting success
 */
bool shell_special_vars_std_set(char *name, char *value, char *dependency,
shell_t *shell);

/**
 * @brief Update special shell variable.
 * @param name Name of variable to update
 * @param value Value to set to variable
 * @param shell Shell object
 * @return Status of update success
 */
bool shell_special_vars_std_update(char *name, char *value, shell_t *shell);

/**
 * @brief Set special shell variable (std).
 * @param name Name of the variable that must be init
 * @param shell Shell object
 * @param dependency Name of dependency env variable
 * @return Status of init success
 */
bool shell_special_vars_std_init(char *name, shell_t *shell, char *dependency);

/**
 * @brief Get special shell variable (home).
 * @param shell Shell object
 * @param name Name of special variable to get
 * @param copy Specify if value to get needs to be duplicated
 * @return Value of term variable or NULL if undefined
 */
char *shell_special_vars_home_get(shell_t *shell, char *name, bool copy);

/**
 * @brief Set special shell variable (home).
 * @param value Value to set to variable
 * @param name Name of special variable to get
 * @param dependency Name of dependency env variable
 * @param shell Shell object
 * @return Status of setting success
 */
bool shell_special_vars_home_set(char *name, char *value, char *dependency,
shell_t *shell);

/**
 * @brief Update special shell variable (home).
 * @param name Name of variable to update (home)
 * @param value Value to set to variable (home)
 * @param shell Shell object
 * @return Status of update success
 */
bool shell_special_vars_home_update(char *name, char *value, shell_t *shell);

/**
 * @brief Set special shell variable (uid).
 * @param name Name of the variable that must be init
 * @param shell Shell object
 * @param dependency Name of dependency env variable
 * @return Status of init success
 */
bool shell_special_vars_pw_uid_init(char *name, shell_t *shell,
char *dependency);

/**
 * @brief Set special shell variable (gid).
 * @param name Name of the variable that must be init
 * @param shell Shell object
 * @param dependency Name of dependency env variable
 * @return Status of init success
 */
bool shell_special_vars_pw_gid_init(char *name, shell_t *shell,
char *dependency);

/**
 * @brief Set special shell variable (group).
 * @param name Name of the variable that must be init
 * @param shell Shell object
 * @param dependency Name of dependency env variable
 * @return Status of init success
 */
bool shell_special_vars_group_init(char *name, shell_t *shell,
char *dependency);

/**
 * @brief Set special shell variable (cwd).
 * @param name Name of the variable that must be init
 * @param shell Shell object
 * @param dependency Name of dependency env variable
 * @return Status of init success
 */
bool shell_special_vars_cwd_init(char *name, shell_t *shell,
char *dependency);

/**
 * @brief Set special shell variable (tty).
 * @param name Name of the variable that must be init
 * @param shell Shell object
 * @param dependency Name of dependency env variable
 * @return Status of init success
 */
bool shell_special_vars_tty_init(char *name, shell_t *shell, char *dependency);

/**
 * @brief Set special shell variable (shell).
 * @param name Name of the variable that must be init
 * @param shell Shell object
 * @param dependency Name of dependency env variable
 * @return Status of init success
 */
bool shell_special_vars_shell_init(char *name, shell_t *shell,
char *dependency);

// List of special shell variables
static const var_special_t shell_special_vars[SHELL_SPECIAL_VARS_LEN] = {
    {
        "term",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_std_init,
        "TERM"
    },
    {
        "home",
        &shell_special_vars_home_get,
        &shell_special_vars_home_set,
        &shell_special_vars_home_update,
        &shell_special_vars_std_init,
        "HOME"
    },
    {
        "uid",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_pw_uid_init,
        NULL
    },
    {
        "path",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_std_init,
        "PATH"
    },
    {
        "user",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_std_init,
        "USER"
    },
    {
        "group",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_group_init,
        "GROUP"
    },
    {
        "gid",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_pw_gid_init,
        NULL
    },
    {
        "cwd",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_cwd_init,
        NULL
    },
    {
        "owd",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_std_init,
        NULL
    },
    {
        "_",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_std_init,
        NULL
    },
    {
        "shell",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_shell_init,
        NULL
    },
    {
        "tty",
        &shell_special_vars_std_get,
        &shell_special_vars_std_set,
        &shell_special_vars_std_update,
        &shell_special_vars_tty_init,
        NULL
    }
};

#endif /* !SHELL_SPECIAL_VARS_H_ */
