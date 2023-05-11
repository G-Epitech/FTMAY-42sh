/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include <string.h>
#include "mysh/mysh.h"
#include "types/inst/inst.h"
#include "types/shell/defs.h"
#include "execution/execution.h"

bool mysh_execute(char *input, inst_t *block, shell_t *shell)
{
    if (input && strlen(input) == 0) {
        shell->exit_code = SHELL_EXIT_SUCCESS;
        return true;
    }
    if (!shell || !block) {
        shell->exit_code = SHELL_EXIT_ERROR;
        return false;
    }
    return execution_main_block(block, shell);
}
