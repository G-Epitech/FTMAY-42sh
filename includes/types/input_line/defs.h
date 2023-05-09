/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef INPUT_LINE_DEFS_H_
    #define INPUT_LINE_DEFS_H_

    #include <termios.h>
    #include "shell/defs.h"

    #define CTRL_KEY_HANDLERS_NBR 4

// Represent value of arrow key
typedef enum e_ctrl_key {
    ARROW_KEY_UP = 1000,    // Code of key up
    ARROW_KEY_DOWN,         // Code of key down
    ARROW_KEY_RIGHT,        // Code of key right
    ARROW_KEY_LEFT,         // Code of key left
    CTRL_KEY_ENTER,
    CTRL_KEY_D
} ctrl_key_t;

// Represent the input of the user
typedef struct s_input_line_buffer {
    size_t len;             // Len of the user input
    size_t cursor;          // Position in x of the cursor on the content
    char *content;          // Buffer of the user input
} input_line_buffer_t;

// Represent current input_line status
typedef enum e_input_line_status {
    IL_RUNNING,                 // Input line is running
    IL_EXITED                   // Input line is exited
} input_line_status_t;

// Represent evoluted input entry
typedef struct s_input_line {
    struct termios *settings;        // Settings of the shell
    input_line_buffer_t *buffer;     // Information about user input
    input_line_status_t status;      // Input line current status
} input_line_t;

// Prototype function control handler
typedef void (*ctrl_handler_t)(shell_t *shell, input_line_t *line);

// Prototype control key handler
typedef struct s_ctrl_key_handler {
    ctrl_key_t key;                 // Value of arrow key
    ctrl_handler_t handler;         // Function arrow key
} ctrl_key_handler_t;

// Array control key handlers
static const ctrl_key_handler_t ctrl_key_handlers[CTRL_KEY_HANDLERS_NBR] = {
    {ARROW_KEY_UP, NULL},
    {ARROW_KEY_DOWN, NULL},
    {ARROW_KEY_RIGHT, NULL},
    {ARROW_KEY_LEFT, NULL}
};

#endif /* !INPUT_LINE_DEFS_H_ */
