/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** io
*/

#ifndef VAR_H_
    #define VAR_H_

    #include <stdbool.h>
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

/**
 * @brief Set a value in structure var_t
 * @param value Value to set in struct varuable
 * @param variable Struct var_t where set the value
 * @return True if no error else False
 */
bool var_set_value(var_t *variable, char *value);

#endif /* !VAR_H_ */
