/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** var
*/

#ifndef VAR_H_
    #define VAR_H_

    #include <stdbool.h>
    #include "defs.h"
    #include "types/list/defs.h"

/**
 * @brief Create new variable
 * @param name Name of variable
 * @param value Value to set to value
 */
var_t *var_new(char *name, char *value);

/**
 * @brief Free var_t struct with its container
 * @param variable Variable to free
 */
void var_free(var_t *variable);

/**
 * @brief Set value of given variable
 * @param variable Variable of which set value
 * @param value Value to set in given variable
 * @return true if no error else false
 */
bool var_set_value(var_t *variable, char *value);

/**
 * @brief Get variable matching with given name
 * @param vars List variables in which search
 * @param name Name of variable to get
 * @return Variable reference or NULL if not found
 */
var_t *var_list_get(list_t *vars, char *name);

/**
 * @brief Get value of variable matchingererer
 * @param vars List variables in which search
 * @param name Name of variable of which get value
 * @param copy Specify if value to get needs to be duplicated
 * @return Value or NULL if not found
 */
char *var_list_get_value(list_t *vars, char *name, bool copy);

#endif /* !VAR_H_ */
