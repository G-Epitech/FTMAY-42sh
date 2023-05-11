/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include "utils/utils.h"
#include "types/input_line/handlers.h"
#include "types/input_line/input_line.h"

int input_line_read_key(void)
{
    int character = getchar();

    character = input_line_get_character(character);
    if (character >= CTRL_KEY_REF)
        return character;
    if (iscntrl(character)) {
        return input_line_get_cntrls(character);
    } else
        return character;
}

static void call_function(input_line_t *line,
shell_t *shell, int index)
{
    if (ctrl_key_handlers[index].handler)
        ctrl_key_handlers[index].handler(shell, line);
}

static void lunch_control_function(int character, input_line_t *line,
shell_t *shell)
{
    for (int index = 0; index < CTRL_KEY_HANDLERS_NBR; index++) {
        if ((int) ctrl_key_handlers[index].key == character)
            call_function(line, shell, index);
    }
}

static void get_position_curseur(int *row, int *col)
{
    printf("\033[6n");
    scanf("\033[%d;%dR", row, col);
}

static void get_terminal_size(int *rows, int *columns)
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    *rows = size.ws_row;
    *columns = size.ws_col;
}

void input_line_get_content(input_line_t *line, shell_t *shell)
{
    int character = 0;
    int x = 0;
    int size_term_rows = 0;
    int size_term_col = 0;

    get_terminal_size(&size_term_rows, &size_term_col);
    get_position_curseur(&line->buffer->rows_start_cursor, &x);
    line->buffer->pos_rows_cursor = line->buffer->rows_start_cursor;
    while (line->status == IL_RUNNING) {
        character = input_line_read_key();
        if (line->buffer->pos_col_cursor >= size_term_col) {
            line->buffer->pos_rows_cursor++;
            line->buffer->pos_col_cursor = 0;
        }
        if (character <= 127) {
            append_char(line, character);
            refresh_screen(line);
        } else {
            lunch_control_function(character, line, shell);
        }
    }
}
