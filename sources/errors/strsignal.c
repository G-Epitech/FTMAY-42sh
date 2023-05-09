/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** strerror2
*/

#include "errors/errors.h"

char *errors_strsignal(int sig)
{
    return errors_get_message_of_code(errors_sig_msg, sig);
}
