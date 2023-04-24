/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    #include "defs.h"

/**
 * @brief Create a new linked list.
 * @return Created list
 */
list_t *list_new(void);

/**
 * @brief Free given list and all its nodes with given freer if specified.
 * @param list List to free
 * @param freer freer to call on each node
 */
void list_free(list_t *list, node_freer_t freer);

/**
 * @brief Append given node in given list.
 * @param list List in which append node
 * @param node Node to append in list
 */
void list_append(list_t *list, node_t *node);

/**
 * @brief Remove given node of given list but not free node
 * @param list List in which remove node
 * @param node Node to remove of list
 */
void list_remove(list_t *list, node_t *node);

/**
 * @brief Remove given node of given list and free it.
 * @param list List in which remove node
 * @param node Node to remove of list
 * @param freer freer to call to free node data
 */
void list_delete(list_t *list, node_t *node, node_freer_t freer);

#endif /* !LIST_H_ */
