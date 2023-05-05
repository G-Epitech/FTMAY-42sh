/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** executions
*/

#ifndef EXECUTIONS_H_
    #define EXECUTIONS_H_

    #include "types/node/defs.h"
    #include "types/shell/defs.h"

/**
 * @brief Execute given node instruction of type command
 * @param node_inst Node instruction
 * @return Exit code of command
 */
int execution_cmd(node_t *node_inst, shell_t *shell);

#endif /* !EXECUTIONS_H_ */
