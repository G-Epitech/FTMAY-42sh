/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** io
*/

#ifndef IO_H_
    #define IO_H_

    #include "defs.h"

/**
 * @brief Free inner io content but no structure
 * @param io Prototype of input / output structure
 */
void io_free(io_t *io);

/**
 * @brief Free input and output io_t fields, but no structure
 * @param ios Prototype of inputs / outputs structure
 */
void ios_free(ios_t *ios);

#endif /* !IO_H_ */
