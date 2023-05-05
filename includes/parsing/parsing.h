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
    #include "types/inst/defs.h"
    #include "types/shell/defs.h"
    #include "types/parsing_utils/defs.h"

    #define PARSING_STOP_CMD 1
    #define PARSING_ERROR_CMD 2
    #define PARSING_SIMPLE_LEFT 1
    #define PARSING_DOUBLE_LEFT 0
    #define PARSING_DOUBLE_RIGHT 2
    #define PARSING_SIMPLE_RIGHT 3
    #define PARSING_NO_ERROR_CMD 0
    #define PARSING_NO_OPEN_BLOCK 2
    #define PARSING_ERROR_SEPARATOR 2
    #define PARSING_ERROR_RECURSIVITY 0
    #define PARSING_NO_SPACE_SEMICOLON 0
    #define PARSING_NO_ERROR_SEPARATOR 1
    #define PARSING_ERROR_SEPARATOR 2
    #define VAR_NOT_FOUND 1
    #define VAR_FOUND 2
    #define ALPHA_NUMERIC(char) (('a' <= char && char <= 'z') || ('A' <= char \
&& char <= 'Z') || ('0' <= char && char <= '9') || char == '_')

/**
 * @brief Parse command input into string array.
 * @param command Command object
 * @param shell Shell main object
 * @return true if all went well, false else
 */
bool parsing_set_command_args(cmd_t *command, shell_t *shell);

/**
 * @brief Get len of simple input part.
 * @param input Input string
 * @param start Start index
 * @return The len of the simple input part
 */
int parsing_get_len_input(char *input, int start);

/**
 * @brief Get len of string input part.
 * @param input Input string
 * @param start Start index
 * @return The len of the string input part
 */
int parsing_get_len_input_string(char *input, int start);

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
void parsing_redirection_set_type(int index, inst_t *instruction);

/**
 * @brief Set path of redirection.
 * @param utils Utils struct
 * @param instruction Instruction struct
 * @param index Index of redirection
 */
void parsing_redirection_set_path(parsing_utils_t *utils,
inst_t *instruction, int index);

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

/**
 * @brief Parse separator in the user command.
 * @param utils Utils struct
 * @param instruction Instruction struct
 */
bool parsing_separator_handler(parsing_utils_t *utils, inst_t *instruction);

/**
 * @brief Parse break separator in the user command.
 * @param instruction Instruction struct
 */
bool parsing_break_separator(inst_t *instruction);

/**
 * @brief Analyse input of user.
 * @param utils Utils struct
 * @param block Instruction block
 * @param instruction Instruction struct
 * @return False if there is a problem when parsing, otherwise True
 */
bool parsing_analyse_data(parsing_utils_t *utils, inst_block_t *block,
                    inst_t *instruction);

/**
 * @brief Recursivity of parsing.
 * @param utils Utils struc
 * @return New instruction type block with all block/commands in it
 */
inst_t *parsing_recursivity(parsing_utils_t *utils);

/**
 * @brief Replace value of var.
 * @param input Input of user
 * @param shell Shell struct
 * @return Input with var remplaced
 */
char *parsing_var_replace(char *input, shell_t *shell);

/**
 * @brief Replace value of var.
 * @param input Input of user
 * @param shell Shell struct
 * @param parsing_index Index parsing on remplacing var
 * @return Value of var
 */
char *get_var(char *input, shell_t *shell, int *parsing_index);

/**
 * @brief Replace value of var.
 * @param input Input of user
 * @param start Start of nor var input
 * @param end End of nor var input
 * @return Input who is not var
 */
char *get_no_var(char *input, int start, int end);

#endif /* !PARSING_H_ */
