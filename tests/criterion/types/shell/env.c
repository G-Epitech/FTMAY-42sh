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

static size_t get_string_array_size(char **array)
{
    size_t i = 0;

    while (array[i])
        i++;
    return i;
}

Test(types_shell_env, unserialize_serialize_env)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);
    size_t environ_len = get_string_array_size(environ);
    char **duplicated = shell_env_serialize(shell);

    cr_assert_eq(shell->env->len, environ_len);
    cr_assert_eq(shell->env->len, get_string_array_size(duplicated));
    for (size_t i = 0; i < environ_len; i++)
        cr_assert(strcmp(environ[i], duplicated[i]) == 0);
    shell_free(shell);
}

Test(types_shell_env, serialize_env_from_null_shell)
{
    cr_assert_null(shell_env_serialize(NULL));
}

Test(types_shell_env, shell_set_env_several_vars_and_unset)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);
    size_t len = shell->env->len;

    cr_assert(shell_set_env(shell, "V1", "super"));
    cr_assert(shell_set_env(shell, "V2", "hello"));
    cr_assert(shell_set_env(shell, "V3", "world"));
    cr_assert((len + 3) == shell->env->len);
    shell_unset_env(shell, "V1");
    cr_assert((len + 2) == shell->env->len);
    shell_unset_env(shell, "V3");
    cr_assert((len + 1) == shell->env->len);
    cr_assert(shell_set_env(shell, "V411", "another"));
    cr_assert((len + 2) == shell->env->len);
    cr_assert(shell_set_env(shell, "V412", "another2"));
    cr_assert(shell_set_env(shell, "V413", "another3"));
    cr_assert((len + 4) == shell->env->len);
    shell_free(shell);
}

Test(types_shell_env, shell_set_one_variable)
{
    extern char **environ;
    shell_t *shell = shell_new(environ);

    cr_assert(shell_set_env(shell, "V1", "super"));
    cr_assert_str_eq(shell_get_env(shell, "V1", false), "super");
    shell_free(shell);
}
