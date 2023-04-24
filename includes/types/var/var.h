/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** io
*/

#ifndef VAR_H_
    #define VAR_H_

    #include "defs.h"

/**
 * @brief Create new var struct
 * @param name Name of struct
 * @param value Value given in parameter
 */
var_t *var_new(char *name, char *value);

/**
 * @brief Free var_t struct with its container
 * @param variable Struct var_t to free
 */
void var_free(var_t *variable);

#endif /* !VAR_H_ */
