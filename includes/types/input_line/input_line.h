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

#endif /* !INPUT_LINE_H_ */
