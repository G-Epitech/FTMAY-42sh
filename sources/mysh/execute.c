/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include "mysh/mysh.h"
#include "types/inst/inst.h"
#include "types/shell/defs.h"
#include "execution/execution.h"

bool mysh_execute(inst_t *block, shell_t *shell)
{
    if (!shell || !block)
        return false;
    return execution_main_block(block, shell);
}
