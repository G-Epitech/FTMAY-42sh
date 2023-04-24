/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef CMD_DEFS_H_
    #define CMD_DEFS_H_ 

    #include <stdbool.h>

// =================================
// These functions must be destroyed once their prototyping is finished
// And obviousely add the correct include
typedef struct s_target {
    int temp;
} target_t;
typedef struct s_args {
    int temp;
} args_t;
// =================================

// Represent a prototype of command type enumeration
typedef enum e_cmd_type {
    CMD_NULL,       // Undefined command (by default)
    CMD_EMPTY,      // Empty command (nothing to do but not an error)
    CMD_SYSTEM,     // System command
    CMD_ABSOLUTE,   // Absolute command (explicit path given)
    CMD_BUILTIN     // Builtin command
} cmd_type_t;

// Represent a prototype of command type structure
typedef struct s_cmd {
    char *input;      // Original input given by user
    char *name;       // Name of command
    cmd_type_t type;  // Type of command
    target_t target;  // Target of command, depending of command type
    args_t args;      // Arguments of command
    bool forked;      // Specify if command is forked
} cmd_t;

#endif /* !CMD_DEFS_H_ */
