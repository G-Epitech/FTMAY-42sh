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
 * @param new_line true if new line else false
 * @return Status of success
 */
bool input_line_disable_raw_mode(struct termios *default_tty, bool new_line);

/**
 * @brief Create struct for user input.
 * @return The struct initialised
 */
input_line_t *input_line_new(void);;

/**
 * @brief Free the structure line.
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

/**
 * @brief Refresh the screen after an action.
 * @param line Structure input entry
 */
void refresh_screen(input_line_t *line);

/**
 * @brief Display the cursor.
 * @param line Structure input entry
 */
void display_cursor(input_line_t *line);

#endif /* !INPUT_LINE_H_ */
