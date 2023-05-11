/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef INPUT_LINE_DEFS_H_
    #define INPUT_LINE_DEFS_H_

    #include <termios.h>
    #include "types/shell/defs.h"
    #include "handlers.h"

    #define CTRL_KEY_HANDLERS_NBR 8
    #define line_clear_after_cursor (printf ("\x1b[J"))
    #define PROMPT_LEN 7

// Represent value of arrow key
typedef enum e_ctrl_key {
    CTRL_KEY_REF = 1000,
    ARROW_KEY_UP,           // Code of key up
    ARROW_KEY_DOWN,         // Code of key down
    ARROW_KEY_RIGHT,        // Code of key right
    ARROW_KEY_LEFT,         // Code of key left
    CTRL_KEY_ENTER,
    CTRL_KEY_DEL,
    CTRL_KEY_A,
    CTRL_KEY_D
} ctrl_key_e;

// Represent the input of the user
typedef struct s_input_line_buffer {
    size_t len;                     // Len of the user input
    size_t cursor;                  // Pos in x of the cursor on the content
    int rows_start_cursor;          // Pos y of the curs at the start of command
    int pos_col_cursor;             // Number orws of the command
    int pos_rows_cursor;            // Number orws of the command
    int nb_rows;
    size_t history_cursor;          // Pos in x of the cursor on the history
    char *history_content;          // Buffer of the history
    char *content;                  // Buffer of the user input
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
    ctrl_key_e key;                 // Value of arrow key
    ctrl_handler_t handler;         // Function arrow key
} ctrl_key_handler_t;

// Array control key handlers
static const ctrl_key_handler_t ctrl_key_handlers[CTRL_KEY_HANDLERS_NBR] = {
    {ARROW_KEY_UP, &input_line_history_prev},
    {ARROW_KEY_DOWN, &input_line_history_next},
    {ARROW_KEY_RIGHT, &input_line_cursor_forward},
    {ARROW_KEY_LEFT, &input_line_cursor_backward},
    {CTRL_KEY_DEL, &delete_char},
    {CTRL_KEY_ENTER, &input_line_keypressed_enter},
    {CTRL_KEY_D, &input_line_keypressed_d},
    {CTRL_KEY_A, &input_line_keypressed_a}
};

#endif /* !INPUT_LINE_DEFS_H_ */
