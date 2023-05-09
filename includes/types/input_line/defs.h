/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef INPUT_LINE_DEFS_H_
    #define INPUT_LINE_DEFS_H_

    #include <termios.h>

// Represent value of arrow key
typedef enum e_arrow_key {
    ARROW_KEY_UP = 1000,    // Code of key up
    ARROW_KEY_DOWN,         // Code of key down
    ARROW_KEY_RIGHT,        // Code of key right
    ARROW_KEY_LEFT          // Code of key left
} arrow_key_t;

// Represent the input of the user
typedef struct s_input_line_buffer {
    size_t len;             // Len of the user input
    size_t cursor;          // Position in x of the cursor on the content
    char *content;          // Buffer of the user input
} input_line_buffer_t;

// Represent evoluted input entry
typedef struct s_input_line {
    struct termios settings;        // Settings of the shell
    input_line_buffer_t *buffer;    // Information about user input
} input_line_t;

#endif /* !INPUT_LINE_DEFS_H_ */
