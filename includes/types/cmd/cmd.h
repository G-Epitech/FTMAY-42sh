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
 * @brief Create a new command
 * @return cmd_t* New command
 */
cmd_t *cmd_new(void);

/**
 * @brief Free a command
 * @param command Command to free
 */
void cmd_free(cmd_t *command);

#endif /* !CMD_H_ */
