/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef ARGS_DEFS_H_
    #define ARGS_DEFS_H_

// Represent argument of command
typedef struct s_args {
    char **argv;     //Values of command arguments
    int argc;        //Number of arguments in argc
} args_t;

#endif /* !ARGS_DEFS_H_ */
