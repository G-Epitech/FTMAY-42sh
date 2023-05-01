/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #include "types/inst/defs.h"
    #include "types/parsing_utils/defs.h"

/**
 * @brief Parse the entire user command.
 * @param input User command
 * @return Instruction with type block and all block and commands in it
 */
inst_t *parsing_get_main_block(char *input);

/**
 * @brief Parse the redirection.
 * @param utils Utils struct
 * @param instruction Instruction struct
 */
void parsing_redirection_handler(parsing_utils_t *utils, inst_t *instruction);

/**
 * @brief Get the word between to positions.
 * Index of start and index of end have to be in the range of the string.
 * @param utils Utils struct
 * @param start Index from start
 * @param end Index to end
 * @return New word malloc
 */
char *parsing_get_word(parsing_utils_t *utils, int start, int end);

/**
 * @brief Get command from user input.
 * @param utils Utils struct
 * @param cmd Cmd struct
 * @return New instruction type command
 */
inst_t *parsing_get_cmd(parsing_utils_t *utils);

#endif /* !PARSING_H_ */
