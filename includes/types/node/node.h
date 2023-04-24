/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** node
*/

#ifndef NODE_H_
    #define NODE_H_

    #include "defs.h"

/**
 * @brief Create a new with given data.
 * @param data Data to set to node
 * @return Created node
 */
node_t *node_new(node_data_t data);

/**
 * @brief Free given node and free data of it with freer if specified.
 * @param node Node to free
 * @param freer freer function for node data
 */
void node_free(node_t *node, node_freer_t freer);

/**
 * @brief Unlink given node from its neighbours.
 * @param node Node to unlink
 */
void node_unlink(node_t *node);

#endif /* !NODE_H_ */
