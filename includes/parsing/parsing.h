/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #include "defs.h"
    #include "types/cmd/defs.h"
    #include "types/shell/defs.h"

/**
 * @brief Parse command input into string array.
 * @param command Command object
 * @param shell Shell main object
 * @return true if all went well, false else
 */
bool parsing_set_command_args(cmd_t *command, shell_t *shell);

/**
 * @brief Get len of simple input part
 * @param input Input string
 * @param start Start index
 * @return The len of the simple input part
 */
int parsing_get_len_input(char *input, int start);

/**
 * @brief Get len of string input part
 * @param input Input string
 * @param start Start index
 * @return The len of the string input part
 */
int parsing_get_len_input_string(char *input, int start);

#endif /* !PARSING_H_ */
