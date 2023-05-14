/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef HANDLERS_H_
    #define HANDLERS_H_

    #include <stdbool.h>
    #include "types/shell/defs.h"

typedef struct s_input_line input_line_t;

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

/**
 * @brief Delete character on the buffer->content.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_cursor_del(shell_t *shell, input_line_t *line);

/**
 * @brief Close the input_line and return of the main function the user input.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_keypressed_enter(shell_t *shell, input_line_t *line);

/**
 * @brief Close the input_line and exit the program.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_keypressed_d(shell_t *shell, input_line_t *line);

/**
 * @brief Open a new line.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_keypressed_c(shell_t *shell, input_line_t *line);

/**
 * @brief Select the prev instruction on the history.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_history_prev(shell_t *shell, input_line_t *line);

/**
 * @brief Select the next instruction on the history.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_history_next(shell_t *shell, input_line_t *line);

/**
 * @brief Display cursor position.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_keypressed_a(shell_t *shell, input_line_t *line);

/**
 * @brief Handle tabulation.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_keypressed_tab(shell_t *shell, input_line_t *line);

/**
 * @brief Delete a char in the user entry.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void delete_char(shell_t *shell, input_line_t *line);

#endif /* !HANDLERS_H_ */
