/*
** EPITECH PROJECT, 2023
** G-42sh-1
** File description:
** errors
*/

#include <stdio.h>
#include "errors/defs.h"

char *errors_get_message_of_code(code_msg_t *messages, size_t messages_size,
int code)
{
    if (!messages)
        return NULL;
    for (size_t i = 0; i < messages_size; i++) {
        if (messages[i].code == code)
            return messages[i].msg;
    }
    return NULL;
}
