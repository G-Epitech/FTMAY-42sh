/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** execution
*/

#include <string.h>
#include "mysh/mysh.h"
#include "types/inst/inst.h"
#include "utils/asprintf2.h"
#include "types/shell/shell.h"
#include "execution/execution.h"

bool mysh_execute(char *input, inst_t *block, shell_t *shell)
{
    bool success = true;
    char *exit_code = NULL;

    if (input && strlen(input) == 0) {
        shell->exit_code = SHELL_EXIT_SUCCESS;
        return true;
    }
    if (!shell || !block) {
        shell->exit_code = SHELL_EXIT_ERROR;
        return false;
    }
    success = execution_main_block(block, shell);
    if (success) {
        if (asprintf2(&exit_code, "%i", shell->exit_code) == -1)
            return false;
        shell_set_var(shell, "?", exit_code);
        shell_set_var(shell, "status", exit_code);
    }
    return success;
}
