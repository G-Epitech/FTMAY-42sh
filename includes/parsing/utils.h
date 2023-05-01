/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** utils
*/

#ifndef PARSING_UTILS_H_
    #define PARSING_UTILS_H_

    #include <stdbool.h>
    #include "parsing.h"

/**
 * @brief Check if there is a redirection at the utils index.
 * @param utils Parsing utils structure
 * @return True if there is a redirection otherwise, it return False
 */
bool parsing_maybe_redirection(parsing_utils_t *utils);

/**
 * @brief Recursive fonction in parsing.
 * @param utils Parsing utils structure
 * @return new block with block or command in it
 */
inst_t *recursivity(parsing_utils_t *utils);

/**
 * @brief Display Block in order to know what we got
 * @param instruction Instruction to display
 */
void parsing_display(inst_t *instruction);

#endif /* !PARSING_UTILS_H_ */
