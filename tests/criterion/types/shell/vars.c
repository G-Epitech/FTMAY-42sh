/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell
*/

#include <unistd.h>
#include <string.h>
#include <criterion/criterion.h>
#include "types/var/var.h"
#include "utils/malloc2.h"
#include "builtins/defs.h"
#include "types/list/list.h"
#include "types/shell/shell.h"

Test(types_shell_vars, shell_set_severals_var)
{
    shell_t *shell = shell_new(builtins_cmds);
    size_t initial = shell->vars->len;

    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert(shell_set_var(shell, "V3", "world"));
    cr_assert(shell->vars->len - initial == 3);
    cr_assert(shell_set_var(shell, "V4", "nice"));
    cr_assert(shell->vars->len - initial == 4);
    shell_free(shell);
}

Test(types_shell_vars, shell_set_severals_var_and_unset)
{
    shell_t *shell = shell_new(builtins_cmds);
    size_t initial = shell->vars->len;

    cr_assert(shell->vars->len - initial == 0);
    cr_assert(shell_set_var(shell, "V1", "super"));
    cr_assert(shell_set_var(shell, "V2", "hello"));
    cr_assert(shell_set_var(shell, "V3", "world"));
    cr_assert(shell->vars->len - initial== 3);
    shell_unset_var(shell, "V1");
    cr_assert(shell->vars->len - initial== 2);
    shell_unset_var(shell, "V3");
    cr_assert(shell->vars->len - initial== 1);
    shell_unset_var(shell, "V2");
    cr_assert(shell->vars->len - initial == 0);
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
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(!shell_set_var(shell, NULL, "fail"));
    shell_free(shell);
}

Test(types_shell_vars, shell_set_env_with_null_value)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(shell_set_var(shell, "try", NULL));
    cr_assert_str_eq(shell_get_var(shell, "try", false), "");
    shell_free(shell);
}

Test(types_shell_vars, shell_set_one_var_non_copy)
{
    shell_t *shell = shell_new(builtins_cmds);
    size_t initial = shell->vars->len;

    cr_assert(shell->vars->len - initial == 0);
    cr_assert(shell_set_var(shell, "try", "working"));
    cr_assert(shell->vars->len - initial == 1);
    cr_assert_str_eq(shell_get_var(shell, "try", false), "working");
    shell_free(shell);
}

Test(types_shell_vars, shell_set_one_var_copy)
{
    shell_t *shell = shell_new(builtins_cmds);
    size_t initial = shell->vars->len;
    char *copy = NULL;

    cr_assert(shell->vars->len - initial == 0);
    cr_assert(shell_set_var(shell, "try", "working"));
    cr_assert(shell->vars->len - initial == 1);
    copy = shell_get_var(shell, "try", true);
    cr_assert_not_null(copy);
    cr_assert_str_eq(copy, "working");
    free(copy);
    shell_free(shell);
}

Test(types_shell_vars, shell_get_copy_on_non_existant_var)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *copy = NULL;

    copy = shell_get_var(shell, "try", true);
    cr_assert_null(copy);
    shell_free(shell);
}

Test(types_shell_vars, shell_get_non_existant_var)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert_null(shell_get_var(shell, "try", false));
    shell_free(shell);
}

Test(types_shell_vars, shell_set_several_vars)
{
    shell_t *shell = shell_new(builtins_cmds);

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
    shell_t *shell = shell_new(builtins_cmds);

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

Test(types_shell_vars, shell_special_var_init_with_null_shell)
{
    shell_special_vars_init(NULL);
}

Test(types_shell_vars, shell_special_var_set_std_with_null_shell)
{
    cr_assert_not(shell_special_vars_std_set("home", "super", "HOME", NULL));
}

Test(types_shell_vars, shell_special_var_set_std_with_null_name)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert_not(shell_special_vars_std_set(NULL, "super", "HOME", shell));
}

Test(types_shell_vars, shell_special_var_get_std_with_null_name)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert_null(shell_special_vars_std_get(shell, NULL, false));
}

Test(types_shell_vars, shell_special_var_get_std_with_null_shell)
{
    cr_assert_null(shell_special_vars_std_get(NULL, "home", false));
}

Test(types_shell_vars, shell_special_var_get_std_home)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *home = shell_special_vars_std_get(shell, "home", false);

    cr_assert_str_eq(home, getenv("HOME"));
}

Test(types_shell_vars, shell_special_var_get_std_home_unset_env_home)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *home = NULL;
    char *old = strdup(getenv("HOME"));

    unsetenv("HOME");
    home = shell_special_vars_std_get(shell, "home", false);
    cr_assert_str_eq(old, home);
}

Test(types_shell_vars, shell_special_var_unset_home)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell_unset_var(shell, "home");
    cr_assert_null(shell_get_var(shell, "home", false));
    cr_assert_not_null(getenv("HOME"));
}

Test(types_shell_vars, shell_special_var_set_home)
{
    shell_t *shell = shell_new(builtins_cmds);

    cr_assert(shell_set_var(shell, "home", "/"));
    cr_assert_str_eq(shell_get_var(shell, "home", false), "/");
    cr_assert_str_eq(getenv("HOME"), "/");
}

Test(types_shell_vars, shell_special_var_update_from_env)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell_special_vars_dispatch_env_update(shell, "HOME");
}

Test(types_shell_vars, shell_special_var_update_from_env_null_var_name)
{
    shell_t *shell = shell_new(builtins_cmds);

    shell_special_vars_dispatch_env_update(shell, NULL);
}

Test(types_shell_vars, shell_special_var_update_from_env_null_shell)
{
    shell_special_vars_dispatch_env_update(NULL, "HOME");
}

Test(types_shell_vars, shell_special_vars_home)
{
    shell_t *shell = shell_new(builtins_cmds);
    char *value = shell_special_vars_home_get(shell, "home", true);
    char *real_value = var_list_get_value(shell->vars, "home", true);

    cr_assert_str_eq(real_value, value);
}

Test(types_shell_vars, shell_special_vars_home_shell_null)
{
    char *value = shell_special_vars_home_get(NULL, "home", true);

    cr_assert_null(value);
}

Test(types_shell_vars, shell_special_vars_home_update_null)
{
    shell_t *shell = shell_new(builtins_cmds);
    bool status = false;

    status = shell_special_vars_home_update(NULL, "/test", shell);
    cr_assert(!status);
    status = shell_special_vars_home_update("name", NULL, shell);
    cr_assert(!status);
    status = shell_special_vars_home_update("name", "test", NULL);
    cr_assert(!status);
    status = shell_special_vars_home_update("", "", shell);
    cr_assert(!status);
}

Test(types_shell_vars, shell_special_vars_home_update_bad_malloc)
{
    shell_t *shell = shell_new(builtins_cmds);
    bool status = false;

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    status = shell_special_vars_home_update("super", "test", shell);
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    cr_assert(!status);
}

Test(types_shell_vars, shell_special_vars_home_update)
{
    shell_t *shell = shell_new(builtins_cmds);
    bool status = false;

    status = shell_special_vars_home_update("home", "42sh", shell);
    cr_assert(status);
}
