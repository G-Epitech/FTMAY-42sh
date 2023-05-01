/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <stdio.h>
#include <string.h>
#include "types/inst/inst.h"
#include "types/parsing_utils/parsing_utils.h"

char *add_char_to_str(char *dest, char charactere)
{
    int dest_len = strlen(dest);
    char *final = malloc(sizeof(char) * dest_len + 2 );

    for (int y = 0; y < dest_len; y++) {
        final[y] = dest[y];
    }
    final[dest_len] = charactere;
    final[dest_len + 1] = '\0';
    return final;
}

static bool is_redirection(char charactere)
{
    if (charactere == '<' || charactere == '>')
        return true;
    else
        return false;
}

static char *get_redirection(parsing_utils_t *utils)
{
    bool in_redirection = true;
    char *user_redirection = malloc(sizeof(char) * 1);
    user_redirection[0] = '\0';

    while (in_redirection) {
        if (is_redirection(USER_INPUT(utils)[INDEX_PARSING(utils)])) {
            user_redirection = add_char_to_str(user_redirection,
            USER_INPUT(utils)[INDEX_PARSING(utils)]);
        } else {
            in_redirection = false;
        }
        INDEX_PARSING(utils)++;
    }
    return user_redirection;
}

void parsing_redirection_handler(parsing_utils_t *utils, inst_t *instruction)
{
    char *redirection[4] = {"<", "<<", ">>", ">"};
    char *input_redirection = get_redirection(utils);

    (void) instruction;
    (void) redirection;
    printf("input: [%s] | i: [%i]\n", input_redirection, utils->index_parsing);
}
