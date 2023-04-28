/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** args criterion tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include "utils/malloc2.h"
#include "types/var/var.h"
#include "types/list/list.h"

Test(types_var, new_struct_var)
{
    var_t *var = var_new(strdup("test_name"), strdup("test_value"));

    cr_assert_str_eq(var->name, "test_name");
    cr_assert_str_eq(var->value, "test_value");
    var_free(var);
}

Test(types_var, new_struct_var_with_malloc_fail)
{
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert_null(var_new("hello", "world"));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
}

Test(types_var, set_new_value)
{
    var_t *test = var_new("test", "1");
    bool test_return = false;
    
    cr_assert_str_eq(test->value, "1");
    test_return = var_set(test, "2");
    cr_assert_str_eq(test->value, "2");
    cr_assert(test_return == true);
    var_free(test);
}

Test(types_var, set_bad_new_value)
{
    var_t *test = var_new("axel", "matheo");
    bool test_return = false;
    
    cr_assert_str_eq(test->value, "matheo");
    test_return = var_set(test, NULL);
    cr_assert(test_return == false);
    test_return = var_set(NULL, "flavien accepte la pr");
    cr_assert(test_return == false);
    var_free(test);
}

Test(types_var, free_null_pointer)
{
    var_free(NULL);
}

Test(types_var, var_list_set_in_null_list)
{
    cr_assert(!var_list_set(NULL, "hello", "super"));
}

Test(types_var, var_list_unset_in_null_list)
{
    var_list_unset(NULL, "hello");
}

Test(types_var, var_list_set_in_list)
{
    list_t *list = list_new();

    var_list_set(list, "hello", "super");
    cr_assert_str_eq(var_list_get_value(list, "hello", false), "super");
    list_free(list, &var_node_freer);
}

Test(types_var, var_list_set_in_list_with_malloc_fail)
{
    list_t *list = list_new();

    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_FAIL);
    cr_assert(!var_list_set(list, "hello", "super"));
    malloc2_mode(MALLOC2_SET_MODE, MALLOC2_MODE_NORMAL);
    list_free(list, &var_node_freer);
}

Test(types_var, var_node_freer_with_null_var)
{
    node_data_t data = {.ptr = NULL};

    var_node_freer(data);
}
