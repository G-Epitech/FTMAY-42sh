#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    initscr();
    newterm(getenv("TERM"), stdout, stdin);
    printw("Hello World !!!\n");
    refresh();
    getch();
    def_prog_mode();
    endwin();
    intrflush(stdscr, false);
    system("/bin/ls");
    reset_prog_mode();
    refresh();
    getch();
    printw("Another String\n");
    refresh();
    getch();
    endwin();
    return 0;

}
