/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** free
*/

#include <stdlib.h>
#include "types/shell/defs.h"
#include "types/list/list.h"

void shell_free(shell_t *shell)
{
    if (!shell)
        return;
    list_free(shell->env, NULL);
    list_free(shell->vars, NULL);
    free(shell->home);
    free(shell->owd);
    free(shell->pwd);
    free(shell);
}
