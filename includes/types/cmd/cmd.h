/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** cmd
*/

#ifndef CMD_H_
    #define CMD_H_

    #include "defs.h"

/**
 * @brief Create a new command.
 * @return New command
 */
cmd_t *cmd_new(void);

/**
 * @brief Free a command.
 * @param command Command to free
 */
void cmd_free(cmd_t *command);

/**
 * @brief Display given command details.
 * @param cmd Command of which display details
 */
void cmd_display(cmd_t *cmd);

/**
 * @brief Parse command input into string array.
 * @param command Command object
 * @return true if all went well, false else
 */
bool cmd_set_args(cmd_t *command);

/**
 * @brief Get len of simple input part.
 * @param input Input string
 * @param start Start index
 * @return The len of the simple input part
 */
int cmd_set_args_get_len_input(char *input, int start);

/**
 * @brief Get len of string input part.
 * @param input Input string
 * @param start Start index
 * @return The len of the string input part
 */
int cmd_set_args_get_len_input_string(char *input, int start);


/**
 * @brief Determine if target is builtin and set it if so.
 * @param cmd Command of which determine is target is builtin
 * @param shell Shell object
 * @return Status that indicates if command is builtin
 */
bool cmd_determine_target(cmd_t *cmd, shell_t *shell);

/**
 * @brief Determine if target is builtin and set it if so.
 * @param cmd Command of which determine is target is builtin
 * @param shell Shell object
 * @return Status that indicates if command is builtin
 */
bool cmd_determine_target_is_builtin(cmd_t *cmd, shell_t *shell);

/**
 * @brief Determine if target is builtin and set it if so.
 * @param cmd Command of which determine is target is builtin
 * @return Status that indicates if command is builtin
 */
bool cmd_determine_target_is_absolute(cmd_t *cmd);

/**
 * @brief Determine if target is empty and set it if so.
 * @param cmd Command of which determine is target is empty
 * @return Status that indicates if command is empty
 */
bool cmd_determine_target_is_empty(cmd_t *cmd);

/**
 * @brief Determine if target is system and set it if so.
 * @param cmd Command of which determine is target is system
 * @return Status that indicates if command is system
 */
bool cmd_determine_target_is_system(cmd_t *cmd);

#endif /* !CMD_H_ */
