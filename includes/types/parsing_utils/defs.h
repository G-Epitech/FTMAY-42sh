/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef UTILS_DEFS_H_
    #define UTILS_DEFS_H_

    #define INDEX_PARSING(utils) utils->index_parsing
    #define USER_INPUT(utils) utils->input

// Represent the advancement of parsing
typedef struct s_parsing_utils {
    char *input;        // Original input given by user
    int index_parsing;  // Index of input parsed
} parsing_utils_t;

#endif /* !UTILS_DEFS_H_ */
