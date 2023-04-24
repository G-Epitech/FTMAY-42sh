/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef LIST_DEFS_H_
    #define LIST_DEFS_H_

    #include <stdlib.h>
    #include "types/node/defs.h"

// Represent linked list
typedef struct s_list {
    node_t *first;  //First node of list
    node_t *last;   //Last node of list
    size_t len;     //Length of list
} list_t;

#endif /* !LIST_DEFS_H_ */
