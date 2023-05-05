/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef EXECUTION_DEFS_H_
    #define EXECUTION_DEFS_H_

    #include "types/node/defs.h"

    #define EXECUTION_ERROR 1
    #define EXECUTION_NODE_TO_INST(n) (NODE_DATA_TO_PTR(n->data, inst_t *))
    #define EXECUTION_GET_INST(n) (n ? EXECUTION_NODE_TO_INST(n) : NULL)

#endif /* !EXECUTION_DEFS_H_ */
