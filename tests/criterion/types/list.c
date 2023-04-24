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

Test(types_list, new_list)
{
    list_t *list = list_new();

    cr_assert(list != NULL);
}

Test(types_list, append_one_item)
{
    list_t *list = list_new();
    char *str = "HELLO";
    node_t *node = node_new(NODE_DATA_FROM_PTR(str));

    list_append(list, node);
    cr_assert(list->len == 1);
    cr_assert(NODE_DATA_TO_PTR(list->first->data, char *) == str);
    list_free(list, NULL);
}

Test(types_list, append_null_item)
{
    list_t *list = list_new();

    list_append(list, NULL);
    cr_assert(list->len == 0);
    list_free(list, NULL);
}

Test(types_list, append_several_items)
{
    list_t *list = list_new();
    char *strings[5] = {"Super", "Super2", "Hello", "World", "Foo"};
    node_t *node = NULL;
    size_t j = 0;

    for (size_t i = 0; i < 5; i++) {
        node = node_new(NODE_DATA_FROM_PTR(strings[i]));
        list_append(list, node);
    }
    node = list->first;
    while (node) {
        cr_assert(NODE_DATA_TO_PTR(node->data, char *) == strings[j++]);
        node = node->next;
    }
    cr_assert(list->len == 5);
    list_free(list, NULL);
}

Test(types_list, delete_several_items)
{
    list_t *list = list_new();
    char *strings[5] = {"Super", "Super2", "Hello", "World", "Foo"};
    node_t *node = NULL;
    node_t *next = NULL;

    for (size_t i = 0; i < 5; i++) {
        node = node_new(NODE_DATA_FROM_PTR(strings[i]));
        list_append(list, node);
    }
    cr_assert(list->len == 5);
    node = list->first;
    while (node) {
        next = node->next;
        list_delete(list, node, NULL);
        node = next;
    }
    cr_assert(list->len == 0);
    list_free(list, NULL);
}

Test(types_list, remove_several_items)
{
    list_t *list = list_new();
    char *strings[5] = {"Super", "Super2", "Hello", "World", "Foo"};
    node_t *node = NULL;
    node_t *next = NULL;

    for (size_t i = 0; i < 5; i++) {
        node = node_new(NODE_DATA_FROM_PTR(strings[i]));
        list_append(list, node);
    }
    cr_assert(list->len == 5);
    node = list->first;
    while (node) {
        next = node->next;
        list_remove(list, node);
        node = next;
    }
    cr_assert(list->len == 0);
    list_free(list, NULL);
}

Test(types_list, delete_several_items_with_freer)
{
    list_t *list = list_new();
    char *tmp = NULL;
    node_t *node = NULL;
    node_t *next = NULL;

    for (size_t i = 0; i < 12; i++) {
        tmp = strdup("test");
        node = node_new(NODE_DATA_FROM_PTR(tmp));
        list_append(list, node);
    }
    cr_assert(list->len == 12);
    node = list->first;
    while (node) {
        next = node->next;
        list_delete(list, node, &free_ptr_from_node_data);
        node = next;
    }
    cr_assert(list->len == 0);
    list_free(list, NULL);
}
