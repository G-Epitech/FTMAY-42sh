/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef TARGET_DEFS_H_
    #define TARGET_DEFS_H_

    #include "args/args.h"

typedef struct s_shell shell_t;

// Represent a prototype of builtin command
typedef char builtin_t(args_t *args, shell_t *shell);

// Represent a target of command
typedef union s_target {
    char *path;             //Path to a binary file
    builtin_t *builtin; 	//Pointer to a builtin function
} target_t;

#endif /* !TARGET_DEFS_H_ */
