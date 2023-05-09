/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mode
*/

#include <unistd.h>
#include "types/input_line/input_line.h"

bool intput_line_enable_raw_mode(input_line_t *custom_tty,
struct termios *default_tty)
{
    if (tcgetattr(STDIN_FILENO, default_tty) == -1)
        return false;
    custom_tty->settings = default_tty;
    custom_tty->settings->c_iflag &= ~(BRKINT | INPCK | ICRNL | ISTRIP );
    custom_tty->settings->c_oflag &= ~(OPOST);
    custom_tty->settings->c_cflag |= (CS8);
    custom_tty->settings->c_lflag &= ~(ECHO | ICANON);
    if (tcsetattr(STDIN_FILENO, TCSANOW, custom_tty->settings) == -1)
        return false;
    return true;
}

bool intput_line_disable_raw_mode(struct termios *default_tty)
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, default_tty) == -1)
        return false;
    return true;
}
