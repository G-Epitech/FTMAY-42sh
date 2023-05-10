/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef EXECUTION_DEFS_H_
    #define EXECUTION_DEFS_H_

    #include <sys/wait.h>
    #include "types/node/defs.h"
    #include "types/inst/defs.h"

    #define EXECUTION_ERROR 1
    #define EXECUTION_NODE_TO_INST(n) (NODE_DATA_TO_PTR(n->data, inst_t *))
    #define EXECUTION_GET_INST(n) (n ? EXECUTION_NODE_TO_INST(n) : NULL)
    #define EXECUTION_SIG_EXITCODE(c) (WTERMSIG(c) + 128)

// Represent type of execution caller
typedef enum e_exec_caller {
    EXEC_SUPERIOR,  // The execution is requested by a superior block
    EXEC_SIBLING,   // The execution is requested by a sibling instruction
    EXEC_MAIN       // The execution is requested by the main block
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
