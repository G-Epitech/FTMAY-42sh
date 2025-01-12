/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** mysh
*/

#ifndef MYSH_H_
    #define MYSH_H_

    #include "types/inst/defs.h"
    #include "types/shell/defs.h"

/**
 * @brief Run the main processus.
 * @return Exit code status of shell
 */
int mysh(void);

/**
 * @brief Get input given by user, then format it with shell
 * variables and then return it.
 * @param shell Shell object
 * @return Formated input
 */
char *mysh_get_input(shell_t *shell);

/**
 * @brief Parse input in order to convert it in executable
 * instructions.
 * @param shell Shell object
 * @param input Input to parse
 * @return Main block of instruction on success or NULL on failure
 */
inst_t *mysh_parse(shell_t *shell, char *input);

/**
 * @brief Launch execution of main block of instructions.
 * @param input Input given by user
 * @param block Main block of instructions
 * @param shell Shell object
 * @return Success status of execution
 */
bool mysh_execute(char *input, inst_t *block, shell_t *shell);

#endif /* !MYSH_H_ */
