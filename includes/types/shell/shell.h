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
 * @brief Check the format of var
 * @param input Input of user
 * @param shell Shell struct
 * @return true if no error else false
 */
bool shell_format_check(shell_t *shell, char *input);

/**
 * @brief Set the exit code of the shell.
 * @param shell Shell struct
 * @param code Code exit
 * @return Status of success
 */
bool shell_set_exit_code(shell_t *shell, int code);


#endif /* !SHELL_H_ */
