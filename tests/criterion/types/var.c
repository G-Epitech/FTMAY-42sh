/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** args criterion tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include "types/var/var.h"

Test(types_car, new_struct_var)
{
    var_t *var = var_new(strdup("test_name"), strdup("test_value"));

    cr_assert_str_eq(var->name, "test_name");
    cr_assert_str_eq(var->value, "test_value");
    var_free(var);
}

Test(types_var, set_new_value)
{
    var_t *test = var_new("test", "1");
    bool test_return = false;
    
    cr_assert_str_eq(test->value, "1");
    test_return = var_set_value(test, "2");
    cr_assert_str_eq(test->value, "2");
    cr_assert(test_return == true);
    var_free(test);
}

Test(types_var, set_bad_new_value)
{
    var_t *test = var_new("axel", "matheo");
    bool test_return = false;
    
    cr_assert_str_eq(test->value, "matheo");
    test_return = var_set_value(test, NULL);
    cr_assert(test_return == false);
    test_return = var_set_value(NULL, "flavien accepte la pr");
    cr_assert(test_return == false);
    var_free(test);
    var_free(NULL);
}
