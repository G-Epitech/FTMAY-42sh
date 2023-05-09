/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef HANDLERS_H_
    #define HANDLERS_H_

    #include <stdbool.h>
    #include "defs.h"


/**
 * @brief Put the cursor in front position.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_cursor_forward(shell_t *shell, input_line_t *line);

/**
 * @brief Put the cursor in back position.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_cursor_backward(shell_t *shell, input_line_t *line);

#endif /* !HANDLERS_H_ */
