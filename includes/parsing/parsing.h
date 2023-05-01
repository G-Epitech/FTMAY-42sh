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

    #define SIMPLE_LEFT_REDIRECTION 1
    #define DOUBLE_LEFT_REDIRECTION 0
    #define DOUBLE_RIGHT_REDIRECTION 2
    #define SIMPLE_RIGHT_REDIRECTION 3

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
 * @return true if no error else false
 */
bool parsing_redirection_handler(parsing_utils_t *utils, inst_t *instruction);

/**
 * @brief Set type of redirection.
 * @param index Index of redirection
 * @param instruction Instruction struct
 */
void set_type(int index, inst_t *instruction);

/**
 * @brief Set path of redirection
 * @param utils Utils struct
 * @param instruction Instruction struct
 * @param index Index of redirection
 */
void set_path(parsing_utils_t *utils, inst_t *instruction, int index);

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

/**
 * @brief Parse pipes in the user command.
 * @param utils Utils struct
 * @param block Instruction Block
 * @return True in success or False if failed
 */
bool parsing_pipes_handler(parsing_utils_t *utils, inst_block_t *block);

#endif /* !PARSING_H_ */
