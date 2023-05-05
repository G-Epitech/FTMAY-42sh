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
