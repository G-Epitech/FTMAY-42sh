/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include "defs.h"

/**
 * @brief Free a a struct utils.
 * @param utils Utils to free
 */
void utils_free(parsing_utils_t utils);

/**
 * @brief Create a new utils.
 * @return New utils struct
 */
parsing_utils_t *utils_new(char *input_user);

#endif /* !UTILS_H_ */
