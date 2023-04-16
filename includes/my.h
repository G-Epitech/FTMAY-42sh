/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

    #include <stdbool.h>

typedef struct shell_t;

/**
 * @brief Check if given shell is in tty mode.
 * @param shell Shell object of which check tty mode
 * @return true if shell is in tty mode, false
 */
bool shell_in_tty_mode(shell_t *shell);


// Prototype of a shell builtin function
typedef int (*shell_builtin_t)(int argc, char **argv, char **env);

#endif /* !MY_H_ */
