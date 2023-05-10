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
    #define CHAR_IS_ALPHANUM_EXT(c) (CHAR_IS_ALPHANUM (c) || c == '_')
    #define STAT_MODE_XOK(s) ((s & S_IXUSR) || (s & S_IXGRP) || (s & S_IXOTH))

/**
 * @brief Check if a string is a valid number.
 * @param string String that must be a valid number
 * @return true if the string is a valid number, else false
 */
bool is_number(char *string);

#endif /* !UTILS_H_ */
