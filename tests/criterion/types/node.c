/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list
*/

#include <criterion/criterion.h>
#include "types/list/list.h"
#include "types/node/node.h"

static void free_ptr_from_node_data(node_data_t data)
{
    free(data.ptr);
}

Test(types_node, new_node)
{
    node_t *node = node_new(NODE_DATA_FROM_PTR(NULL));

    cr_assert(node != NULL);
}

Test(types_node, free_node_without_freeer)
{
    node_t *node = node_new(NODE_DATA_FROM_PTR(NULL));

    node_free(node, NULL);
}

Test(types_node, free_node_with_freeer)
{
    char *data = strdup("test");
    node_t *node = node_new(NODE_DATA_FROM_PTR(data));

    node_free(node, &free_ptr_from_node_data);
}

Test(types_node, free_node_null)
{
    node_free(NULL, NULL);
}
