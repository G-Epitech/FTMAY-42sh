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
typedef bool (*var_special_setter_t)(char *name, char *value,
char *dependency, shell_t *shell);

// Prototype of special variable updater
typedef bool (*var_special_updater_t)(char *name, char *value,
shell_t *shell);

// Prototype of special variable getter
typedef char *(*var_special_getter_t)(shell_t *shell, char *name, bool copy);

// Represent a variable
typedef struct s_var {
    char *name;     //Name of variable
    char *value;    //Value of variable
} var_t;

// Represent a special variable
typedef struct s_var_special {
    char *name;                     //Name of variable
    var_special_getter_t getter;    //Getter of variable value
    var_special_setter_t setter;    //Setter of variable value
    var_special_updater_t updater;  //Value updater from dependency
    char *dependency;               //Environnement variable dependency of
                                    //special shell variable
} var_special_t;

#endif /* !VAR_DEFS_H_ */
