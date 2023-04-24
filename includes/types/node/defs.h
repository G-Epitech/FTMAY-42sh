/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Node definitions
*/

#ifndef NODE_DEFS_H_
    #define NODE_DEFS_H_

    #define NODE_DATA_FROM_PTR(ptr) ((node_data_t) (void *) ptr)
    #define NODE_DATA_TO_PTR(data, ptrtype) ((ptrtype) data.ptr)

// Represent a node of linked list
typedef struct s_node node_t;

// Represent data of node_t
typedef union u_node_data {
    void *ptr;          //Any pointer
} node_data_t;

// Represent a node of linked list
typedef struct s_node {
    node_t *prev;       //Previous node
    node_data_t data;   //Data of node
    node_t *next;       //Next node
} node_t;

// Node freer function prototype
typedef void (*node_freer_t)(node_data_t data);

#endif /* !NODE_DEFS_H_ */
