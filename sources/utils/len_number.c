/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** len_number
*/

int len_number(int nb)
{
    int size = 0;

    do {
        nb /= 10;
        size++;
    } while (nb != 0);
    return size;
}
