/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include "types/list/list.h"
#include "types/shell/shell.h"

Test(types_shell_vars, shell_set_severals_var)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(shell->vars->len == 0);
    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert(shell_set_var(shell, "V3", "world"));
    cr_assert(shell->vars->len == 3);
    cr_assert(shell_set_var(shell, "V4", "nice"));
    cr_assert(shell->vars->len == 4);
    shell_free(shell);
}

Test(types_shell_vars, shell_set_severals_var_and_unset)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(shell->vars->len == 0);
    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert(shell_set_var(shell, "V3", "world"));
    cr_assert(shell->vars->len == 3);
    shell_unset_var(shell, "V1");
    cr_assert(shell->vars->len == 2);
    shell_unset_var(shell, "V3");
    cr_assert(shell->vars->len == 1);
    shell_unset_var(shell, "V2");
    cr_assert(shell->vars->len == 0);
    shell_free(shell);
}

Test(types_shell_vars, shell_set_env_from_all_null_params)
{
    cr_assert(!shell_set_var(NULL, NULL, NULL));
}

Test(types_shell_vars, shell_set_env_from_null_shell)
{
    cr_assert(!shell_set_var(NULL, "try", "fail"));
}

Test(types_shell_vars, shell_set_env_with_null_name)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(!shell_set_var(shell, NULL, "fail"));
    shell_free(shell);
}

Test(types_shell_vars, shell_set_env_with_null_value)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(!shell_set_var(shell, "try", NULL));
    shell_free(shell);
}

Test(types_shell_vars, shell_set_one_var)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(shell->vars->len == 0);
    cr_assert(shell_set_var(shell, "try", "working"));
    cr_assert(shell->vars->len == 1);
    cr_assert_str_eq(shell_get_var(shell, "try", false), "working");
    shell_free(shell);
}

Test(types_shell_vars, shell_set_several_vars)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert(shell_set_var(shell, "V3", "world"));
    cr_assert_str_eq(shell_get_var(shell, "V1", false), "super");
    cr_assert_str_eq(shell_get_var(shell, "V2", false), "hello");
    cr_assert_str_eq(shell_get_var(shell, "V3", false), "world");
    shell_free(shell);
}

Test(types_shell_vars, shell_set_several_vars_and_unset)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert(shell_set_var(shell, "V3", "world"));
    cr_assert(shell->vars->len == 3);
    shell_unset_var(shell, "V1");
    cr_assert(shell->vars->len == 2);
    shell_unset_var(shell, "V3");
    cr_assert(shell->vars->len == 1);
    cr_assert(shell_set_var(shell, "V411", "another"));
    cr_assert(shell->vars->len == 2);
    cr_assert(shell_set_var(shell, "V412", "another2"));
    cr_assert(shell_set_var(shell, "V413", "another3"));
    cr_assert(shell->vars->len == 4);
    shell_free(shell);
}

