/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef INST_DEFS_H_
    #define INST_DEFS_H_

    #include <stdbool.h>
    #include "types/io/defs.h"
    #include "types/cmd/defs.h"
    #include "types/list/defs.h"

// Represent type of instruction
typedef enum e_isnt_type {
    INS_CMD,       // Instruction is a command
    INS_BLOCK      // Instruction is a block
} inst_type_t;

// Represent link with the next instruction
typedef enum e_separator {
    SP_BREAK,        // No link with next command or no next command
    SP_OR,           // Logical OR link
    SP_AND           // Logical AND link
} separator_t;

// Represent prototype of command
typedef struct s_inst_block {
    list_t *instructions;   // List of instructions (list of instructions_t)
} inst_block_t;

// Represent value of instruction
typedef union s_isnt_value {
    cmd_t *cmd;             // Command structure
    inst_block_t *block;    // Block of instructions
} inst_value_t;

// Represent value of instruction
typedef struct s_isnt {
    inst_value_t value;    // Value of instruction
    inst_type_t type;      // Type of instruction
    separator_t separator;  // Separator with next group (default SP_BREAK)
    char exit_code;         // Exited code of instruction
    ios_t ios;              // Input and output to use at runtime
} inst_t;

#endif /* !INST_DEFS_H_ */
