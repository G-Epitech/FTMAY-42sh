/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef PARSING_DEFS_H_
    #define PARSING_DEFS_H_

    #define PARSING_TAB '\t'
    #define PARSING_SPACE ' '
    #define PARSING_STRING '"'
    #define PARSING_VAR_PREFIX '$'

// Struct of limit of a word.
typedef struct s_index_word {
    int start;      // Start index of the word
    int end;        // End index of the word
} index_word_t;

#endif /* !PARSING_DEFS_H_ */
