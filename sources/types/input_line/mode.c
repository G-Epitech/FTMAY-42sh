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
    if (tcgetattr(STDIN_FILENO, default_tty) == -1)
        return false;
    line->settings = default_tty;
    line->settings->c_iflag &= ~(BRKINT | INPCK | ICRNL | ISTRIP | IXON);
    line->settings->c_oflag &= ~(OPOST);
    line->settings->c_cflag |= (CS8);
    line->settings->c_lflag &= ~(ECHO | ICANON);
    if (tcsetattr(STDIN_FILENO, TCSANOW, line->settings) == -1)
        return false;
    return true;
}

bool input_line_disable_raw_mode(struct termios *default_tty)
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, default_tty) == -1)
        return false;
    printf("\r\n");
    return true;
}
