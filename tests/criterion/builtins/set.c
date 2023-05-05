/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "types/args/args.h"
#include "builtins/builtins.h"
#include "types/shell/shell.h"
#include "types/node/defs.h"
#include "types/var/defs.h"

Test(builtins_set, set_display) {
    int commands_size = 1;
    char **commands = malloc(sizeof(char) * commands_size);
    commands[0] = "set";
    args_t args = {
        .argc = commands_size,
        .argv = commands
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
}

Test(builtins_set, one_set_void) {
    int commands_size = 2;
    char *argv[] = {"set", "super"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "");
}

Test(builtins_set, one_set_void_equal) {
    int commands_size = 2;
    char *argv[] = {"set", "super="};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "");
}

Test(builtins_set, one_set_arg_block_number) {
    int commands_size = 2;
    char *argv[] = {"set", "super=2"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "2");
}

Test(builtins_set, one_set_arg_block_string) {
    int commands_size = 2;
    char *argv[] = {"set", "super=\"Je test le truc de fou\""};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "Je test le truc de fou");
}

Test(builtins_set, one_set_arg_multi_block_number) {
    int commands_size = 4;
    char *argv[] = {"set", "super", "=", "2"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "2");
}

Test(builtins_set, one_set_arg_multi_block_string) {
    int commands_size = 4;
    char *argv[] = {"set", "super", "=", "\"Allez, le petit TT\""};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "Allez, le petit TT");
}

Test(builtins_set, multi_set_arg_block_number) {
    int commands_size = 4;
    char *argv[] = {"set", "super=1", "super2=2", "super3=3"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->name, "super2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->value, "2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->value, "1");
}

Test(builtins_set, multi_set_arg_block_string) {
    int commands_size = 4;
    char *argv[] = {"set", "super=\"Test super 1\"", "super2=\"Test super 2\"", "super3=\"Test super 3\""};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "Test super 3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->name, "super2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->value, "Test super 2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->value, "Test super 1");
}

Test(builtins_set, multi_set_arg_multi_block_number) {
    int commands_size = 10;
    char *argv[] = {"set", "super", "=", "1", "super2", "=", "2", "super3", "=", "3"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->name, "super2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->value, "2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->value, "1");
}

Test(builtins_set, multi_set_arg_multi_block_string) {
    int commands_size = 10;
    char *argv[] = {"set", "super", "=", "\"Test super 1\"", "super2", "=", "\"Test super 2\"", "super3", "=", "\"Test super 3\""};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "Test super 3");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->name, "super2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->data, var_t *)->value, "Test super 2");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->prev->prev->data, var_t *)->value, "Test super 1");
}

Test(builtins_set, first_letter_not_alpha, .init=cr_redirect_stderr) {
    int commands_size = 2;
    char *argv[] = {"set", "1beille"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("set: Variable name must begin with a letter.\n");
}

Test(builtins_set, unmatched_quote, .init=cr_redirect_stderr) {
    int commands_size = 2;
    char *argv[] = {"set", "super=\"ahah"};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
    cr_assert_stderr_eq_str("Unmatched '\"'.\n");
}

Test(builtins_set, multi_block_arg_void) {
    int commands_size = 3;
    char *argv[] = {"set", "super", "="};
    args_t args = {
        .argc = commands_size,
        .argv = argv
    };
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(&args, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_SUCCESS);
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->name, "super");
    cr_assert_str_eq(NODE_DATA_TO_PTR(shell->vars->last->data, var_t *)->value, "");
}

Test(builtins_set, no_args) {
    shell_t *shell = shell_new();
    unsigned char exit_status = SHELL_EXIT_SUCCESS;

    exit_status = builtin_set(NULL, shell);
    cr_assert_eq(exit_status, SHELL_EXIT_ERROR);
}
