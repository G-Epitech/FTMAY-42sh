/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#ifndef SHELL_H_
    #define SHELL_H_

    #include "defs.h"

/**
 * @brief Create a new shell integrating given environnement variables
 * @param env Environment array
 * @return New shell object
 */
shell_t *shell_new(char **env);

/**
 * @brief Free given shell and all its internal fields
 * @param shell Shell object
 */
void shell_free(shell_t *shell);
#endif /* !SHELL_H_ */
