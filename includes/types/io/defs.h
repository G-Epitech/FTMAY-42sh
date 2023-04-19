/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** defs
*/

#ifndef IO_DEFS_H_
    #define IO_DEFS_H_

// Represent a prototype of input / output type enumeration
typedef enum e_io_type {
    IOT_DEFAULT,
    IOT_PIPED,
    IOT_SIMPLE,
    IOT_DOUBLE
} io_type_t;

// Represent a prototype of input / output type structure
typedef struct e_io {
    char *path;
    io_type_t type;
} io_t;

// Represent a prototype of inputs / outputs type structure
typedef struct e_ios {
    io_t input;
    io_t output;
} ios_t;

#endif /* !IO_DEFS_H_ */
