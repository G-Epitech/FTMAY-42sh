/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mode
*/

#include <stdio.h>
#include <unistd.h>
#include "types/input_line/input_line.h"

bool input_line_enable_raw_mode(input_line_t *line,
struct termios *default_tty)
{
    struct termios settings;

    if (tcgetattr(STDIN_FILENO, default_tty) == -1)
        return false;
    if (tcgetattr(STDIN_FILENO, &settings) == -1)
        return false;
    line->settings = &settings;
    line->settings->c_iflag &= ~(BRKINT | INPCK | ICRNL | ISTRIP | IXON);
    line->settings->c_oflag &= ~(OPOST);
    line->settings->c_cflag |= (CS8);
    line->settings->c_lflag &= ~(ECHO | ICANON);
    line->settings->c_cc[VTIME] = 0;
    line->settings->c_cc[VMIN] = 1;
    if (tcsetattr(STDIN_FILENO, TCSANOW, line->settings) == -1)
        return false;
    return true;
}

bool input_line_disable_raw_mode(struct termios *default_tty)
{
    if (tcsetattr(STDIN_FILENO, TCSANOW, default_tty) == -1)
        return false;
    printf("\n");
    return true;
}
