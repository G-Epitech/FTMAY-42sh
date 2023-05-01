/*
** EPITECH PROJECT, 2023
** G-42sh-1
** File description:
** errors
*/

#include <stdio.h>
#include "errors/defs.h"

char *errors_get_message_of_code(code_msg_t *messages, int code)
{
    size_t i = 0;

    if (!messages)
        return NULL;
    while (messages[i].code != -1) {
        if (messages[i].code == code)
            return messages[i].msg;
        i += 1;
    }
    return messages[i].msg;
}
