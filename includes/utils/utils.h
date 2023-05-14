/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include <stdlib.h>
    #include <stdbool.h>
    #include <sys/stat.h>

    #define CHAR_IS_NUM(c) (c >= '0' && c <= '9')
    #define CHAR_IS_UPPER(c) (c >= 'A' && c <= 'Z')
    #define CHAR_IS_LOWER(c) (c >= 'a' && c <= 'z')
    #define CHAR_IS_ALPHA(c) (CHAR_IS_LOWER(c) || CHAR_IS_UPPER(c))
    #define CHAR_IS_ALPHANUM(c) (CHAR_IS_ALPHA(c) || CHAR_IS_NUM(c))
    #define CHAR_IS_ALPHA_EXT(c) (CHAR_IS_ALPHA (c) || c == '_' || \
c == '?')
    #define CHAR_IS_ALPHANUM_EXT(c) (CHAR_IS_ALPHANUM (c) || c == '_' || \
c == '?')
    #define STAT_MODE_XOK(s) ((s & S_IXUSR) || (s & S_IXGRP) || (s & S_IXOTH))
    #define KEY_CTRLS 0x1f
    #define KEY_DEL 0x7f
    #define KEY_TAB 0x09
    #define KEY_CTRL_ENTER 0x0d
    #define KEY_CTRL_A 0x01
    #define KEY_CTRL_D 0x04
    #define KEY_CTRL_C 0x03
    #define KEY_ARROWS 0x5b
    #define KEY_ARROW_UP 0x41
    #define KEY_ARROW_DOWN 0x42
    #define KEY_ARROW_RIGHT 0x43
    #define KEY_ARROW_LEFT 0x44

/**
 * @brief Check if a string is a valid number.
 * @param string String that must be a valid number
 * @return true if the string is a valid number, else false
 */
bool is_number(char *string);

/**
 * @brief Give the len number.
 * @param nb Number to have len
 * @return Number of number
 */
int len_number(int nb);

#endif /* !UTILS_H_ */
