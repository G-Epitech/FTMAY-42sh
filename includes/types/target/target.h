/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** target
*/

#ifndef TARGET_H_
    #define TARGET_H_

    #include "defs.h"
    #include "args/args.h"

typedef struct s_shell shell_t;
typedef char builtin_t(args_t *args, shell_t *shell);

typedef union s_target {
    char *path;             //Path to a binary file
    builtin_t *builtin; 	//Pointer to a builtin function
} target_t;

#endif /* !TARGET_H_ */
