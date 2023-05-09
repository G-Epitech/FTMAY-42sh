/*
** EPITECH PROJECT, 2023
** G-42sh-1 [WSL: Ubuntu]
** File description:
** errors
*/

#ifndef ERRORS_H_
    #define ERRORS_H_

    #include <stdio.h>
    #include "errors/defs.h"

/**
 * @brief Find the message corresponding to given code.
 * @param messages Array with messages and codes for signals
 * @param code Error codes
 * @return Message string or NULL if code is not found.
 */
char *errors_get_message_of_code(const code_msg_t *messages, int code);

/**
 * @brief Get error message corresponding to given errnum.
 * @param errnum Number of error
 * @return Message associated to given error number
 */
char *errors_strerror(int errnum);

/**
 * @brief Get error message corresponding to given signal.
 * @param sig Number of signal
 * @return Message associated to given signal
 */
char *errors_strsignal(int sig);

#endif /* !ERRORS_H_ */
