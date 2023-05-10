/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** status
*/

#include <stdio.h>
#include <sys/wait.h>
#include "errors/errors.h"
#include "execution/defs.h"
#include "types/inst/defs.h"
#include "types/node/defs.h"

static void handle_signaled_status(inst_t *inst, int status)
{
    inst->exit_code = EXECUTION_SIG_EXITCODE(status);
    fprintf(stderr, "%s", errors_strsignal(WTERMSIG(status)));
    if (WCOREDUMP(status))
        fprintf(stderr, " (core dumped)");
    fprintf(stderr, "\n");
}

static void handle_exited_status(inst_t *inst, int status)
{
    inst->exit_code = WEXITSTATUS(status);
}

bool execution_inst_handle_status(inst_t *inst, exec_utils_t *utils)
{
    if (!inst || !utils)
        return false;
    if (WIFSIGNALED(utils->status))
        handle_signaled_status(inst, utils->status);
    else
        handle_exited_status(inst, utils->status);
    return true;
}
