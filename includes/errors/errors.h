/*
** EPITECH PROJECT, 2023
** G-42sh-1 [WSL: Ubuntu]
** File description:
** errors
*/

#ifndef ERRORS_H_
    #define ERRORS_H_

    #include "errors/defs.h"

/**
 * @brief Find the message corresponding to given code
 * @param messages Array with messages and codes for signals
 * @param messages_size Size of messages and codes array
 * @param code Error codes
 * @return char* on the message string. If code is not found, return NULL.
 */
char *errors_get_message_of_code(code_msg_t *messages, size_t messages_size,
int code);

#endif /* !ERRORS_H_ */
