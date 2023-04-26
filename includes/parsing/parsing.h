/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

typedef struct s_parsing_utils parsing_utils_t;
typedef struct s_inst inst_t;

/**
 * @brief Parse the redirection.
 * @param utils Utils struct 
 * @param instruction Instruction struct
 */
void parsing_redirection_handler(parsing_utils_t *utils, inst_t *instruction);

#endif /* !PARSING_H_ */
