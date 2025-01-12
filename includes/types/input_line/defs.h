/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef INPUT_LINE_DEFS_H_
    #define INPUT_LINE_DEFS_H_

    #include <termios.h>
    #include "handlers.h"
    #include "types/shell/defs.h"

    #define PROMPT_LEN 7
    #define CTRL_KEY_HANDLERS_NBR 10

// Represent value of arrow key
typedef enum e_ctrl_key {
    CTRL_KEY_REF = 1000,    // Code of key ref
    ARROW_KEY_UP,           // Code of key up
    ARROW_KEY_DOWN,         // Code of key down
    ARROW_KEY_RIGHT,        // Code of key right
    ARROW_KEY_LEFT,         // Code of key left
    CTRL_KEY_ENTER,         // Code of key controle enter
    CTRL_KEY_DEL,           // Code of key controle delete
    CTRL_KEY_A,             // Code of key controle a
    CTRL_KEY_D,             // Code of key controle d
    CTRL_KEY_C,             // Code of key controle c
    TAB,                    // Code of key tabulation
} ctrl_key_e;

// Represent the terminale size.
typedef struct s_terminale_size {
    int nb_rows;    // Number of rows of the terminal
    int nb_cols;    // Number of colonne of the terminal
} termine_size_t;

// Represent the input of the user.
typedef struct s_input_line_buffer {
    size_t len;                     // Len of the user input
    size_t cursor;                  // Pos in x of the cursor on the content
    int index_start_cmd;            // Pos where line edition begin
    int rows_start_cursor;          // Pos y of the curs at the start of command
    termine_size_t *term_size;      // Sizes of terminal
    size_t history_cursor;          // Pos in x of the cursor on the history
    char *history_content;          // Buffer of the history
    char *content;                  // Buffer of the user input
} input_line_buffer_t;

// Represent current input_line status.
typedef enum e_input_line_status {
    IL_RUNNING,                 // Input line is running
    IL_EXITED                   // Input line is exited
} input_line_status_t;

// Represent evoluted input entry.
typedef struct s_input_line {
    struct termios *settings;        // Settings of the shell
    input_line_buffer_t *buffer;     // Information about user input
    input_line_status_t status;      // Input line current status
} input_line_t;

// Prototype function control handler.
typedef void (*ctrl_handler_t)(shell_t *shell, input_line_t *line);

// Prototype control key handler.
typedef struct s_ctrl_key_handler {
    ctrl_key_e key;                 // Value of arrow key
    ctrl_handler_t handler;         // Function arrow key
} ctrl_key_handler_t;

// Array control key handlers.
static const ctrl_key_handler_t ctrl_key_handlers[CTRL_KEY_HANDLERS_NBR] = {
    {ARROW_KEY_UP, &input_line_history_prev},
    {ARROW_KEY_DOWN, &input_line_history_next},
    {ARROW_KEY_RIGHT, &input_line_cursor_forward},
    {ARROW_KEY_LEFT, &input_line_cursor_backward},
    {CTRL_KEY_DEL, &delete_char},
    {CTRL_KEY_ENTER, &input_line_keypressed_enter},
    {CTRL_KEY_D, &input_line_keypressed_d},
    {CTRL_KEY_A, &input_line_keypressed_a},
    {TAB, &input_line_keypressed_tab},
    {CTRL_KEY_C, &input_line_keypressed_c}
};

#endif /* !INPUT_LINE_DEFS_H_ */
