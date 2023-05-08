/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef EXECUTION_DEFS_H_
    #define EXECUTION_DEFS_H_

    #include "types/node/defs.h"
    #include "types/inst/defs.h"

    #define EXECUTION_ERROR 1
    #define EXECUTION_NODE_TO_INST(n) (NODE_DATA_TO_PTR(n->data, inst_t *))
    #define EXECUTION_GET_INST(n) (n ? EXECUTION_NODE_TO_INST(n) : NULL)

typedef enum e_exec_caller {
    EXEC_SUPERIOR,
    EXEC_SIBLING,
    EXEC_MAIN
} exec_caller_t;

// Reprensent execution data
typedef struct s_exec_utils {
    int fd_herited[2];  // File descriptors of parent command
    int fd_my[2];       // File descriptors created by current command
    int level;          // Recursivity proof
    int status;         // Status code of current execution
    int pipe[2];        // Pipe for input
} exec_utils_t;

#endif /* !EXECUTION_DEFS_H_ */
