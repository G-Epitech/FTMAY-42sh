/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef VAR_DEFS_H_
    #define VAR_DEFS_H_

typedef struct s_shell shell_t;

// Prototype of special variable setter
typedef bool (*var_special_setter_t)(char *name, shell_t *shell);

// Prototype of special variable getter
typedef char *(*var_special_getter_t)(char *name, shell_t *shell);

// Represent a variable
typedef struct s_var {
    char *name;     //Name of variable
    char *value;    //Value of variable
} var_t;

#endif /* !VAR_DEFS_H_ */
