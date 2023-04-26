/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#include <string.h>
#include "types/parsing_utils/parsing_utils.h"
#include "types/inst/inst.h"

char *concat_str(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    int i = 0;
    char *final = malloc(sizeof(char) * dest_len + src_len + 1);

    for (int y = 0; y < dest_len; y++) {
        final[y] = dest[y];
    }
    for (int y = 0; y < src_len; y++) {
        final[dest_len + y] = src[y];
    }
    final[dest_len + src_len] = '\0';
    return final;
}

static char *get_redirection(parsing_utils_t *utils, inst_t *instruction)
{
    bool in_redirection = false;
    char *user_redirection = malloc(sizeof(char) * 1);
    user_redirection[0] = "\0";

    while (in_redirection) {
        if (USER_INPUT(utils)[INDEX_PARSING(utils)] != ' ') {
            user_redirection = concat_str(user_redirection,
            USER_INPUT(utils)[INDEX_PARSING(utils)]);
        } else {
            in_redirection = true;
        }
        INDEX_PARSING(utils)++;
    }
    return user_redirection;
}

void parsing_redirection_handler(parsing_utils_t *utils, inst_t *instruction)
{
    char *redirection[4] = {"<", "<<", ">>", ">"};
    char *input_redirection = get_redirection(utils, instruction);

    printf("input redirection : [%s] | [%i] index of parsing\n", input_redirection, utils->index_parsing);
}
