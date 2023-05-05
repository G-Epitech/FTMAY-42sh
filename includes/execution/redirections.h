/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirections
*/

#ifndef EXECUTION_REDIRECTIONS_H_
    #define EXECUTION_REDIRECTIONS_H_

/**
 * @brief Get content to use in double redirection left.
 * @param word End word delimiter
 * @param fd File descriptor in which write
 */
void execution_redirection_get_double_left(char *word, int fd);

#endif /* !EXECUTION_REDIRECTIONS_H_ */
