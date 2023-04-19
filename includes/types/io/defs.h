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
    IOT_DEFAULT,        //Default input / output
    IOT_PIPED,          //Piped input / output
    IOT_SIMPLE,         //Simple input / output
    IOT_DOUBLE          //Double input / output
} io_type_t;

// Represent a prototype of input / output type structure
typedef struct s_io {
    char *path;      //Input / output path
    io_type_t type;  //Input / output type
} io_t;

// Represent a prototype of inputs / outputs type structure
typedef struct s_ios {
    io_t input;       //Prototype of input type
    io_t output;      //Prototype of ouput type
} ios_t;

#endif /* !IO_DEFS_H_ */
