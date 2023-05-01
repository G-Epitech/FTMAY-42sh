/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** os
*/

#ifndef OS_H_
    #define OS_H_

    #if defined(__WIN16) || defined(__WIN32) || defined(__WIN64)
        #define OS_IS_WINDOWS
    #elif (defined(__APPLE__) && defined(__MACH__)) || defined(macintosh)
        #define OS_IS_MACOS
    #elif defined(__linux__) || defined(linux) || defined(__linux)
        #define OS_IS_LINUX
    #endif

#endif /* !OS_H_ */
