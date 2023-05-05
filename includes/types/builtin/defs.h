/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin defs
*/

#ifndef BUILTIN_DEFS_H_
    #define BUILTIN_DEFS_H_

    #include "types/args/args.h"

typedef struct s_shell shell_t;

// Prototype of builtin command function
typedef unsigned char (*builtin_target_t)(args_t *args, shell_t *shell);

// Represent a builtin command
typedef struct s_builtin {
    char *name;                 // Name of builtin command
    builtin_target_t target;    // Function of builtin command
} builtin_t;

#endif /* !BUILTIN_DEFS_H_ */
