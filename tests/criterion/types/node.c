/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** list
*/

#include <criterion/criterion.h>
#include "utils/malloc2.h"
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

Test(types_node, new_node_with_malloc_fail)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(node_new(NODE_DATA_FROM_PTR(NULL)));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(types_node, free_node_without_freer)
{
    node_t *node = node_new(NODE_DATA_FROM_PTR(NULL));

    node_free(node, NULL);
}

Test(types_node, free_node_with_freer)
{
    char *data = strdup("test");
    node_t *node = node_new(NODE_DATA_FROM_PTR(data));

    node_free(node, &free_ptr_from_node_data);
}

Test(types_node, free_node_null)
{
    node_free(NULL, NULL);
}

Test(types_node, unlink_single_node)
{
    list_t *list = list_new();
    char *tmp = NULL;
    node_t *node = NULL;
    node_t *node5 = NULL;
    node_t *node9 = NULL;

    for (size_t i = 0; i < 12; i++) {
        tmp = strdup("test");
        node = node_new(NODE_DATA_FROM_PTR(tmp));
        if (i == 5)
            node5 = node;
        if (i == 9)
            node9 = node;
        list_append(list, node);
    }
    node_unlink(node5);
    node_unlink(node9);
    list_free(list, NULL);
}
