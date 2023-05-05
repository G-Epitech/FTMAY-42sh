/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtins
*/

#ifndef BUILTINS_H_
    #define BUILTINS_H_

    #include "defs.h"
    #include "types/args/defs.h"
    #include "types/shell/defs.h"

/**
 * @brief Handle exit builtin command.
 * @param args Arguments object of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_exit(args_t *args, shell_t *shell);

/**
 * @brief Handle cd builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_cd(args_t *args, shell_t *shell);

/**
 * @brief Handle env builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_env(args_t *args, shell_t *shell);

/**
 * @brief Handle unsetenv builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_unsetenv(args_t *args, shell_t *shell);

/**
 * @brief Handle setenv builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_setenv(args_t *args, shell_t *shell);

/**
 * @brief Handle set builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_set(args_t *args, shell_t *shell);

/**
 * @brief Handle unset builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_unset(args_t *args, shell_t *shell);

/**
 * @brief Handle var builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
unsigned char builtin_var(args_t *args, shell_t *shell);

#endif /* !BUILTINS_H_ */
