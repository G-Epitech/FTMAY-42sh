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
    IOT_DEFAULT,        //Default redirection (often terminal directly)
    IOT_PIPED,          //Piped redirection to/from other command
    IOT_SIMPLE,         //Redirection to/from a file with simple chevron
    IOT_DOUBLE          //Redirection to/from a file with double chevron
} io_type_t;

// Represent a prototype of input / output type structure
typedef struct s_io {
    char *path;      //Path of target file or NULL if not set
    io_type_t type;  //Type of input/output
} io_t;

// Represent a prototype of inputs / outputs type structure
typedef struct s_ios {
    io_t input;       //Input target used by command
    io_t output;      //Output target used by command
} ios_t;

#endif /* !IO_DEFS_H_ */
