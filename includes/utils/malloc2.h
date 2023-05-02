/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** malloc2
*/

#ifndef MALLOC2_H_
    #define MALLOC2_H_

    #include <stdlib.h>
    #include <stdbool.h>

    #define MALLOC2_GET_MODE 0
    #define MALLOC2_SET_MODE 1
    #define MALLOC2_MODE_FAIL 0
    #define MALLOC2_MODE_NORMAL 1

/**
 * @brief Set failing mode of malloc2 function.
 * @param set Specify if required action is set or get mode
 * @param new_mode New mode to set to malloc2 function
 * @return Current mode of malloc2
 */
int malloc2_mode(int action, int new_mode);

/**
 * @brief Alias of malloc function with failure control.
 * @param size Size to allocate
 * @return Allocated memory zone
 */
void *malloc2(size_t size);

#endif /* !MALLOC2_H_ */
