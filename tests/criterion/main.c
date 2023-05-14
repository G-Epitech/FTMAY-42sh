/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include <criterion/criterion.h>

int main(int argc, char **argv)
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    struct criterion_test_set *tests = criterion_initialize();
    int result = 0;

    if (criterion_handle_args(argc, argv, true))
        result = !criterion_run_all_tests(tests);
    criterion_finalize(tests);
    return result;
}
