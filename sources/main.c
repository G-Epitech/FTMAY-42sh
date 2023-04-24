/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** Main file of project
*/

#include "types/var/var.h"
#include <stdio.h>

int main(void)
{
    var_t *test = var_new("test", "1");
    printf("name : [%s] | [%s] : value\n", test->name, test->value);
    var_free(test);
}
