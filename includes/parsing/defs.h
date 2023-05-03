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

typedef struct s_index_word {
    int start;
    int end;
} index_word_t;

#endif /* !PARSING_DEFS_H_ */
