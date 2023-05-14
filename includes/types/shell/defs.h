/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef SHELL_DEFS_H_
    #define SHELL_DEFS_H_

    #include <unistd.h>
    #include <stdbool.h>
    #include "utils/utils.h"
    #include "special_vars.h"
    #include "types/var/defs.h"
    #include "types/list/defs.h"
    #include "types/builtin/defs.h"
    #include "types/history/defs.h"

    #define SHELL_EXIT_ERROR 1
    #define SHELL_EXIT_SUCCESS 0
    #define SHELL_DEFAULT_PATH "/usr/bin:/bin"
    #define SHELL_VAR_NOT_FOUND 1
    #define SHELL_VAR_FOUND 2
    #define SHELL_VAR_IGNOREEOF(value) (is_number(value) ? atoi(value) : 26)

// Environnement variables
extern char **environ;

// Represent current shell status
typedef enum e_shell_status {
    SH_RUNNING,                 // Shell is running
    SH_EXITED                   // Shell is exited
} shell_status_t;

// Represent a shell
typedef struct s_shell {
    int exit_code;              // Last exit code of shell
    int exit_in;                // Counter before exit if ignoreeof is set
    shell_status_t status;      // Shell current status
    bool is_tty;                // Specify if shell is in TTY mode
    list_t *vars;               // Shell variables (list of var_t)
    char *owd;                  // Old working directory
    char *pwd;                  // Path of current working directory
    const builtin_t *builtins;  // Builtins command available in shell
    history_t *history;         // Shell history of commands
} shell_t;

#endif /* !SHELL_DEFS_H_ */
