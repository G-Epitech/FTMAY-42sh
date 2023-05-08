/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include <ctype.h>
#include <errno.h>

// #define ABUF_INIT {NULL, 0}

// typedef struct erow {
//   int size;
//   char *chars;
// } erow;

// struct editorConfig {
//   int cx, cy;
//   struct termios orig_termios;
//   int numrows;
//   erow row;
// };

// enum editorKey {
//   ARROW_LEFT = 1000,
//   ARROW_RIGHT,
//   ARROW_UP,
//   ARROW_DOWN
// };

// struct editorConfig E;

// struct abuf {
//   char *b;
//   int len;
// };

// void die(const char *s)
// {
//   write(STDOUT_FILENO, "\x1b[2J", 4);
//   write(STDOUT_FILENO, "\x1b[H", 3);

//   perror(s);
//   exit(1);
// }

// void disableRawMode(void)
// {
//   tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios);
// }

// void abAppend(struct abuf *ab, const char *s, int len) {
//   char *new = realloc(ab->b, ab->len + len);
//   if (new == NULL) return;
//   memcpy(&new[ab->len], s, len);
//   ab->b = new;
//   ab->len += len;
// }

// void abFree(struct abuf *ab) {
//   free(ab->b);
// }

// void enableRawMode(void)
// {
//   tcgetattr(STDIN_FILENO, &E.orig_termios);
//   atexit(disableRawMode);
//   struct termios raw = E.orig_termios;
//   raw.c_iflag &= ~(ICRNL | IXON);
//   raw.c_oflag &= ~(OPOST);
//   raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
//   raw.c_cc[VMIN] = 0;
//   raw.c_cc[VTIME] = 1;
//   tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
// }

// int editorReadKey() {
//   int nread;
//   char c;
//   while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
//     if (nread == -1 && errno != EAGAIN) die("read");
//   }
//   if (c == '\x1b') {
//     char seq[3];
//     if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
//     if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';
//     if (seq[0] == '[') {
//       switch (seq[1]) {
//         case 'A': return ARROW_UP;
//         case 'B': return ARROW_DOWN;
//         case 'C': return ARROW_RIGHT;
//         case 'D': return ARROW_LEFT;
//       }
//     }
//     return '\x1b';
//   } else {
//     return c;
//   }
// }

// /*** output ***/
// void editorRefreshScreen() {
//   struct abuf ab = ABUF_INIT;
//   abAppend(&ab, "\x1b[?25l", 6);
//   abAppend(&ab, "\x1b[H", 3);

//   char buf[32];
//   snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);
//   abAppend(&ab, buf, strlen(buf));
//   abAppend(&ab, "\x1b[?25h", 6);
//   write(STDOUT_FILENO, ab.b, ab.len);
//   abFree(&ab);
// }

// void editorMoveCursor(int key) {
//   switch (key) {
//     case ARROW_LEFT:
//       E.cx--;
//       break;
//     case ARROW_RIGHT:
//       E.cx++;
//       break;
//     case ARROW_UP:
//       E.cy--;
//       break;
//     case ARROW_DOWN:
//       E.cy++;
//       break;
//   }
// }


// /*** input ***/
// void editorProcessKeypress() {
//   int c = editorReadKey();

//   switch (c) {
//     case ('q'):
//       write(STDOUT_FILENO, "\x1b[2J", 4);
//       write(STDOUT_FILENO, "\x1b[H", 3);
//       exit(0);
//       break;
//     case ARROW_UP:
//     case ARROW_DOWN:
//     case ARROW_LEFT:
//     case ARROW_RIGHT:
//       enableRawMode();
//       editorMoveCursor(c);
//       break;

//     default:
//       disableRawMode();
//       break;
//   }
// }

// /*** init ***/
// int main() {
//   E.cx = 0;
//   E.cy = 0;
//   E.numrows = 0;


//   write(STDOUT_FILENO, "\x1b[2J", 4);
//   enableRawMode();
//   while (1) {
//     editorRefreshScreen();
//     editorProcessKeypress();
//   }
//   return 0;
// }

#include <string.h>

struct editorConfig {
  int cx, cy;
  struct termios orig_termios;
};

struct editorConfig E;

struct abuf {
  char *b;
  int len;
};

#define ABUF_INIT {NULL, 0}

enum editorKey {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};

void abAppend(struct abuf *ab, const char *s, int len) {
  char *new = realloc(ab->b, ab->len + len);
  if (new == NULL) return;
  memcpy(&new[ab->len], s, len);
  ab->b = new;
  ab->len += len;
}

void abFree(struct abuf *ab) {
  free(ab->b);
}

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &E.orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &E.orig_termios);

  struct termios raw = E.orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int editorReadKey() {
  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
  }
  if (c == '\x1b') {
    char seq[3];
    if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
    if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';
    if (seq[0] == '[') {
      switch (seq[1]) {
        case 'A': return ARROW_UP;
        case 'B': return ARROW_DOWN;
        case 'C': return ARROW_RIGHT;
        case 'D': return ARROW_LEFT;
      }
    }
    return '\x1b';
  } else {
    return c;
  }
}

void editorRefreshScreen() {
  struct abuf ab = ABUF_INIT;
  // abAppend(&ab, "\x1b[?25l", 6);
  // abAppend(&ab, "\x1b[H", 3);

  char buf[32];
  snprintf(buf, sizeof(buf), "\x1b[%d;%dH", E.cy + 1, E.cx + 1);
  abAppend(&ab, buf, strlen(buf));
  //abAppend(&ab, "\x1b[?25h", 6);
  write(STDOUT_FILENO, ab.b, ab.len);
  abFree(&ab);
}

void editorMoveCursor(int key) {
  switch (key) {
    case ARROW_LEFT:
      E.cx--;
      break;
    case ARROW_RIGHT:
      E.cx++;
      break;
    case ARROW_UP:
      E.cy--;
      break;
    case ARROW_DOWN:
      E.cy++;
      break;
  }
}

/*** input ***/
void editorProcessKeypress() {
  int c = editorReadKey();
  switch (c) {
    case ('q'):
      disableRawMode();
      exit(0);
      break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
      enableRawMode();
      editorMoveCursor(c);
      break;

    default:
      disableRawMode();
      break;
  }
}

int main() {
  E.cx = 0;
  E.cy = 10;
  enableRawMode();

  //write(STDOUT_FILENO, "\x1b[2J", 4); cllear l'écran de debut
  while (1) {
    editorRefreshScreen();
    editorProcessKeypress();
  }
}


