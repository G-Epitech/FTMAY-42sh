/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** io
*/

#ifndef VAR_H_
    #define VAR_H_

    #include "defs.h"

//Create new variable with given name and given data
var_t *var_new(char *name, char *value);

// Free given variable
void var_free(var_t *variable);

#endif /* !VAR_H_ */