/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtins
*/

#ifndef BUILTINS_H_
    #define BUILTINS_H_

    #include "types/args/defs.h"
    #include "types/shell/defs.h"

typedef struct s_cmd cmd_t;

/**
 * @brief Handle exit builtin command.
 * @param args Arguments object of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_exit(args_t *args, shell_t *shell);

/**
 * @brief Handle cd builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_cd(args_t *args, shell_t *shell);

/**
 * @brief Handle env builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_env(args_t *args, shell_t *shell);

/**
 * @brief Handle unsetenv builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_unsetenv(args_t *args, shell_t *shell);

/**
 * @brief Handle setenv builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_setenv(args_t *args, shell_t *shell);

/**
 * @brief Handle set builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_set(args_t *args, shell_t *shell);

/**
 * @brief Handle unset builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_unset(args_t *args, shell_t *shell);

/**
 * @brief Handle var builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_var(args_t *args, shell_t *shell);

/**
 * @brief Handle which builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_which(args_t *args, shell_t *shell);

/**
 * @brief Handle where builtin command.
 * @param args Arguments of the command
 * @param shell Shell object
 * @return Exit code of the builtin
 */
int builtin_where(args_t *args, shell_t *shell);

/**
 * @brief Handle where command are storage.
 * @param cmd The command to find
 * @param shell Shell object
 * @return Exit code of the builtin
 */
bool builtin_where_determine_targets(cmd_t *cmd, shell_t *shell);

/**
 * @brief Get the path of the command.
 * @param dir The directory of command
 * @param name Name of command
 * @return The path of the command
 */
char *get_path(char *dir, char *name);

/**
 * @brief Determine if the path cmd is system
 * @param path Path of command
 * @return true if cmd is system else false
 */
bool is_system(char *path);

#endif /* !BUILTINS_H_ */
