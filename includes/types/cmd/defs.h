/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef CMD_DEFS_H_
    #define CMD_DEFS_H_

    #include <stdbool.h>
    #include "types/args/defs.h"
    #include "types/builtin/defs.h"

// Represent a target of command
typedef union s_target {
    char *path;             //Path to a binary file
    builtin_target_t builtin; 	//Pointer to a builtin function
} target_t;

// Represent type of command
typedef enum e_cmd_type {
    CMD_NULL,       // Undefined command (by default)
    CMD_EMPTY,      // Empty command (nothing to do but not an error)
    CMD_SYSTEM,     // System command
    CMD_ABSOLUTE,   // Absolute command (explicit path given)
    CMD_BUILTIN     // Builtin command
} cmd_type_t;

// Represent a command
typedef struct s_cmd {
    char *input;      // Original input given by user
    char *name;       // Name of command
    cmd_type_t type;  // Type of command
    target_t target;  // Target of command, depending of command type
    args_t args;      // Arguments of command
    bool forked;      // Specify if command is forked
} cmd_t;

#endif /* !CMD_DEFS_H_ */
