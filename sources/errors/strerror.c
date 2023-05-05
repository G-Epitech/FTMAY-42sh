/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** strerror2
*/

#include "errors/errors.h"

char *errors_strerror(int errnum)
{
    return errors_get_message_of_code(errors_errno_msg, errnum);
}
