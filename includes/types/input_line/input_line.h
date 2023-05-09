/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** INPUT_LINE
*/

#ifndef INPUT_LINE_H_
    #define INPUT_LINE_H_

    #include <stdbool.h>
    #include "defs.h"

/**
 * @brief Enable on the tty raw mode.
 * @param line Structure input entry
 * @param default_tty Structure default tty
 * @return Status of success
 */
bool input_line_enable_raw_mode(input_line_t *line,
struct termios *default_tty);

/**
 * @brief Disable on the tty raw mode.
 * @param default_tty Structure default tty
 * @return Status of success
 */
bool input_line_disable_raw_mode(struct termios *default_tty);

/**
 * @brief Create struct for user input
 * @return The struct initialised
 */
input_line_t *input_line_new(void);;

/**
 * @brief Free the structure line
 * @param line Structure input entry
 */
void input_line_free(input_line_t *line);

/**
 * @brief Get user input with tty raw mode enable.
 * @param line Structure input entry
 * @param shell Structure of shell
 */
void input_line_get_content(input_line_t *line, shell_t *shell);

/**
 * @brief Get control character.
 * @param character First character pressed
 * @return Return character controle
 */
int input_line_get_cntrls(int character);

/**
 * @brief Get special key character.
 * @param character First character pressed
 * @return Return character controle
 */
int input_line_get_character(int character);

/**
 * @brief Append a char in buffer of user input.
 * @param line Structure input entry
 * @return Status of success
 */
bool append_char(input_line_t *line, int c);

#endif /* !INPUT_LINE_H_ */
