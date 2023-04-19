/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** simple test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(simple, simple_example) {
    cr_assert_eq(1, 1);
}
