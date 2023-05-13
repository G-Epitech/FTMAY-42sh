/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef PARSING_DEFS_H_
    #define PARSING_DEFS_H_

    #include <stdbool.h>

    #define PARSING_TAB '\t'
    #define PARSING_SPACE ' '
    #define PARSING_STRING '"'
    #define PARSING_BACKSLASH '\\'
    #define PARSING_VAR_PREFIX '$'
    #define PARSING_STOP_CMD 1
    #define PARSING_ERROR_CMD 2
    #define PARSING_SIMPLE_LEFT 1
    #define PARSING_DOUBLE_LEFT 0
    #define PARSING_DOUBLE_RIGHT 2
    #define PARSING_SIMPLE_RIGHT 3
    #define PARSING_NO_ERROR_CMD 0
    #define PARSING_NO_OPEN_BLOCK 2
    #define PARSING_ERROR_SEPARATOR 2
    #define PARSING_ERROR_RECURSIVITY 0
    #define PARSING_NO_SPACE_SEMICOLON 0
    #define PARSING_NO_ERROR_SEPARATOR 1
    #define PARSING_NO_ERROR_RECURSIVITY 1
    #define PARSING_ERROR_SEPARATOR 2
    #define PARSING_SPECIAL_CHAR "abefnrtv"
    #define PARSING_SPECIAL_REPLACE "\a\b\e\f\n\r\t\v"

// Struct of limit of a word.
typedef struct s_index_word {
    int start;          // Start index of the word
    int end;            // End index of the word
    bool is_string;     // Global index
} index_word_t;

#endif /* !PARSING_DEFS_H_ */
