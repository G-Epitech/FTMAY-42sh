/*
** EPITECH PROJECT, 2023
** G-42sh-1 [WSL: Ubuntu]
** File description:
** defs
*/

#ifndef ERRORS_DEFS_H_
    #define ERRORS_DEFS_H_

    #define ERRORS_SIG_MSG_LEN 31

// Prototype of node structure code_msg_t
typedef struct s_args {
    int code;          //Code of error
    char *msg;         //Message corresponding to this error
} code_msg_t;

#endif /* !ERRORS_DEFS_H_ */
