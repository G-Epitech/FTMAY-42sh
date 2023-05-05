/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** var
*/

#include <stdio.h>
#include <string.h>
#include "utils/utils.h"
#include "types/args/defs.h"
#include "types/list/list.h"
#include "types/node/node.h"
#include "types/shell/defs.h"
#include "types/var/var.h"

static node_t *list_get_lower(list_t *list)
{
    node_t *node = list->first;
    node_t *lower = node;

    while (node) {
        if (strcmp(NODE_DATA_TO_PTR(node->data, var_t *)->name,
        NODE_DATA_TO_PTR(lower->data, var_t *)->name) < 0) {
            lower = node;
        }
        node = node->next;
    }
    return lower;
}

static list_t *list_sort(list_t *list)
{
    list_t *sort_list = list_new();
    node_t *node = NULL;
    node_t *lower = NULL;

    if (!list || !sort_list)
        return NULL;
    node = list->first;
    while (node) {
        lower = list_get_lower(list);
        list_remove(list, lower);
        list_append(sort_list, lower);
        node = list->first;
    }
    return sort_list;
}

unsigned char builtin_var(args_t *args, shell_t *shell)
{
    node_t *node = NULL;

    if (!shell || !args)
        return SHELL_EXIT_ERROR;
    shell->vars = list_sort(shell->vars);
    if (!shell->vars)
        return SHELL_EXIT_ERROR;
    node = shell->vars->first;
    while (node) {
        printf("%s\t%s\n", NODE_DATA_TO_PTR(node->data, var_t *)->name,
        NODE_DATA_TO_PTR(node->data, var_t *)->value);
        node = node->next;
    }
    return SHELL_EXIT_SUCCESS;
}
