/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include "mysh/mysh.h"
#include "types/input_line/input_line.h"

int main(void)
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    input_line_t *user_input = input_line_new();
    user_input->buffer->cursor = 2;
    user_input->buffer->content = malloc(6);
    user_input->buffer->content[0] = 'c';
    user_input->buffer->content[1] = 'o';
    user_input->buffer->content[2] = 'u';
    user_input->buffer->content[3] = 'c';
    user_input->buffer->content[4] = 'o';
    user_input->buffer->content[5] = '\0';
    append_char(user_input, 66);
    return 0;
    //return mysh();
}
