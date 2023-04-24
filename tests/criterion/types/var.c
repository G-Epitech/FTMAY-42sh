/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** args criterion tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include "types/var/var.h"

Test(types_io, new_struct_var)
{
    var_t *var = var_new(strdup("test_name"), strdup("test_value"));

    cr_assert_str_eq(var->name, "test_name");
    cr_assert_str_eq(var->value, "test_value");
    var_free(var);
}
