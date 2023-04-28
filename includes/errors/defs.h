/*
** EPITECH PROJECT, 2023
** G-42sh-1 [WSL: Ubuntu]
** File description:
** defs
*/

#ifndef ERRORS_DEFS_H_
    #define ERRORS_DEFS_H_

    #include <signal.h>

    #define ERRORS_SIG_MSG_LEN 31

// Prototype of node structure code_msg_t
typedef struct s_args {
    int code;          //Code of error
    char *msg;         //Message corresponding to this error
} code_msg_t;

static const code_msg_t errors_sig_msg[ERRORS_SIG_MSG_LEN] = {
    {SIGHUP, "Hangup"},
    {SIGINT, NULL},
    {SIGQUIT, "Quit"},
    {SIGILL, "Illegal instruction"},
    {SIGTRAP, "Trace/BPT trap"},
    {SIGABRT, "Abort"},
    {SIGBUS, "Bus error"},
    {SIGFPE, "Floating exception"},
    {SIGKILL, "Killed"},
    {SIGUSR1, "User signal 1"},
    {SIGSEGV, "Segmentation fault"},
    {SIGUSR2, "User signal 2"},
    {SIGPIPE, "Broken pipe"},
    {SIGALRM, "Alarm clock"},
    {SIGTERM, "Terminated"},
    {SIGSTKFLT, "Stack limit exceeded"},
    {SIGCHLD, NULL},
    {SIGCONT, NULL},
    {SIGSTOP, "\nSuspended (signal)"},
    {SIGTSTP, "\nSuspended"},
    {SIGTTIN, "\nSuspended (tty input)"},
    {SIGTTOU, "\nSuspended (tty output)"},
    {SIGURG, NULL},
    {SIGXCPU, "Cputime limit exceeded"},
    {SIGXFSZ, "Filesize limit exceeded"},
    {SIGVTALRM, "Virtual time alarm"},
    {SIGPROF, "Profiling time alarm"},
    {SIGWINCH, NULL},
    {SIGIO, "Pollable event occurred"},
    {SIGPWR, "Power failure"},
    {SIGSYS, "Bad system call"},
};

#endif /* !ERRORS_DEFS_H_ */
