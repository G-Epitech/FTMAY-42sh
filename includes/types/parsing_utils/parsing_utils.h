/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#ifndef TYPES_PARSING_UTILS_H_
    #define TYPES_PARSING_UTILS_H_

    #include "defs.h"

/**
 * @brief Free a a struct utils.
 * @param utils Utils to free
 */
void parsing_utils_free(parsing_utils_t *utils);

/**
 * @brief Create a new utils.
 * @return New utils struct
 */
parsing_utils_t *parsing_utils_new(char *input_user);

#endif /* !TYPES_PARSING_UTILS_H_ */
