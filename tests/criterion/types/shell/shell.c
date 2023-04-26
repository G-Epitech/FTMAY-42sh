/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#include <unistd.h>
#include <criterion/criterion.h>
#include "types/list/list.h"
#include "types/shell/shell.h"

static size_t get_string_array_size(char **array)
{
    size_t i = 0;

    while (array[i])
        i++;
    return i;
}

Test(types_shell, new_valid_shell)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert_not_null(shell);
    cr_assert_not_null(shell->owd);
    cr_assert_not_null(shell->pwd);
    cr_assert_not_null(shell->env);
    cr_assert_not_null(shell->vars);
    cr_assert_eq(shell->exit_code, SHELL_EXIT_SUCCESS);
    cr_assert_eq(shell->is_tty, isatty(STDIN_FILENO));
    cr_assert_eq(shell->status, SH_RUNNING);
}

Test(types_shell, new_shell_unvalid_env)
{
    char **env = NULL;
    shell_t *shell = shell_new(env);

    cr_assert_null(shell);
}

Test(types_shell, new_shell_valid_env_list)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert_eq(shell->env->len, get_string_array_size(environ));
}

Test(types_shell, free_valid_shell)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    shell_free(shell);
}

Test(types_shell, free_bad_shell)
{
    shell_t *shell = NULL;

    shell_free(shell);
}
