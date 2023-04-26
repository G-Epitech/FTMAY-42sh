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
    shell_t *shell = shell_new();

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
    shell_t *shell = shell_new();

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
    shell_t *shell = shell_new();

    cr_assert(!shell_set_var(shell, NULL, "fail"));
    shell_free(shell);
}

Test(types_shell_vars, shell_set_env_with_null_value)
{
    shell_t *shell = shell_new();

    cr_assert(!shell_set_var(shell, "try", NULL));
    shell_free(shell);
}

Test(types_shell_vars, shell_set_one_var_non_copy)
{
    shell_t *shell = shell_new();

    cr_assert(shell->vars->len == 0);
    cr_assert(shell_set_var(shell, "try", "working"));
    cr_assert(shell->vars->len == 1);
    cr_assert_str_eq(shell_get_var(shell, "try", false), "working");
    shell_free(shell);
}

Test(types_shell_vars, shell_set_one_var_copy)
{
    shell_t *shell = shell_new();
    char *copy = NULL;

    cr_assert(shell->vars->len == 0);
    cr_assert(shell_set_var(shell, "try", "working"));
    cr_assert(shell->vars->len == 1);
    copy = shell_get_var(shell, "try", true);
    cr_assert_not_null(copy);
    cr_assert_str_eq(copy, "working");
    free(copy);
    shell_free(shell);
}

Test(types_shell_vars, shell_get_copy_on_non_existant_var)
{
    shell_t *shell = shell_new();
    char *copy = NULL;

    copy = shell_get_var(shell, "try", true);
    cr_assert_null(copy);
    shell_free(shell);
}

Test(types_shell_vars, shell_get_non_existant_var)
{
    shell_t *shell = shell_new();

    cr_assert_null(shell_get_var(shell, "try", false));
    shell_free(shell);
}

Test(types_shell_vars, shell_set_several_vars)
{
    shell_t *shell = shell_new();

    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert(shell_set_var(shell, "V3", "world"));
    cr_assert_str_eq(shell_get_var(shell, "V1", false), "super");
    cr_assert_str_eq(shell_get_var(shell, "V2", false), "hello");
    cr_assert_str_eq(shell_get_var(shell, "V3", false), "world");
    shell_free(shell);
}

Test(types_shell_vars, shell_set_several_vars_and_reset_them)
{
    shell_t *shell = shell_new();

    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert_str_eq(shell_get_var(shell, "V1", false), "super");
    cr_assert_str_eq(shell_get_var(shell, "V2", false), "hello");
    cr_assert(shell_set_var(shell, "V2", "modification"));
    cr_assert_str_eq(shell_get_var(shell, "V2", false), "modification");
    shell_free(shell);
}

Test(types_shell_vars, shell_unset_var_on_invalid_shell)
{
    shell_unset_var(NULL, "V1");
}

Test(types_shell_vars, shell_get_var_on_null_shell)
{
    cr_assert_null(shell_get_var(NULL, "V1", "super"));
}
