/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/var/var.h"
#include "types/list/list.h"
#include "types/shell/defs.h"

void shell_free(shell_t *shell)
{
    if (!shell)
        return;
    list_free(shell->vars, &var_node_freer);
    free(shell->home);
    free(shell->owd);
    free(shell->pwd);
    free(shell);
}
