/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef SHELL_DEFS_H_
    #define SHELL_DEFS_H_

    #define SHELL_EXIT_SUCCESS 0
    #define SHELL_EXIT_ERROR 1

    #include <unistd.h>
    #include <stdbool.h>
    #include "types/list/defs.h"

// Environnement variables
extern char **environ;

// Represent current shell status
typedef enum e_shell_status {
    SH_RUNNING,                 // Shell is running
    SH_EXITED                   // Shell is exited
} shell_status_t;

// Represent a shell
typedef struct s_shell {
    unsigned char exit_code;    // Last exit code of shell
    shell_status_t status;      // Shell current status
    bool is_tty;                // Specify if shell is in TTY mode
    list_t *vars;               // Shell variables (list of var_t)
    char *owd;                  // Old working directory
    char *pwd;                  // Path of current working directory
    char *home;                 // Path of user home directory
} shell_t;

#endif /* !SHELL_DEFS_H_ */
