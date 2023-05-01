/*
** EPITECH PROJECT, 2023
** G-42sh-1
** File description:
** defs
*/

#ifndef ERRORS_DEFS_H_
    #define ERRORS_DEFS_H_

    #include <errno.h>
    #include <signal.h>

    #define ERRORS_SIG_MSG_LEN 31
    #define ERRORS_ERRNO_MSG_LEN 126

// Prototype of node structure code_msg_t
typedef struct s_code_msg {
    int code;          // Code of error
    char *msg;         // Message corresponding to this error
} code_msg_t;

// Array with messages and codes for signals
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

// Array with messages and codes for errno errors
static const code_msg_t errors_errno_msg[ERRORS_ERRNO_MSG_LEN] = {
    {E2BIG, "Argument list too long."},
    {EACCES, "Permission denied."},
    {EADDRINUSE, "Address already in use."},
    {EADDRNOTAVAIL, "Address not available."},
    {EAFNOSUPPORT, "Address family not supported."},
    {EAGAIN, "Resource temporarily unavailable."},
    {EALREADY, "Connection already in progress."},
    {EBADE, "Invalid exchange."},
    {EBADF, "Bad file descriptor."},
    {EBADFD, "File descriptor in bad state."},
    {EBADMSG, "Bad message."},
    {EBADR, "Invalid request descriptor."},
    {EBADRQC, "Invalid request code."},
    {EBADSLT, "Invalid slot."},
    {EBUSY, "Device or resource busy."},
    {ECANCELED, "Operation canceled."},
    {ECHILD, "No child processes."},
    {ECHRNG, "Channel number out of range."},
    {ECOMM, "Communication error on send."},
    {ECONNABORTED, "Connection aborted."},
    {ECONNREFUSED, "Connection refused."},
    {ECONNRESET, "Connection reset."},
    {EDEADLK, "Resource deadlock avoided."},
    {EDEADLOCK, NULL},
    {EDESTADDRREQ, "Destination address required"},
    {EDOM, "Mathematics argument out of domain of function."},
    {EDQUOT, "Disk quota exceeded."},
    {EEXIST, "File exists."},
    {EFAULT, "Bad address."},
    {EFBIG, "File too large."},
    {EHOSTDOWN, "Host is down."},
    {EHOSTUNREACH, "Host is unreachable."},
    {EHWPOISON, "Memory page has hardware error."},
    {EIDRM, "Identifier removed."},
    {EILSEQ, NULL},
    {EINPROGRESS, "Operation in progress."},
    {EINTR, "Interrupted function call."},
    {EINVAL, "Invalid argument."},
    {EIO, "Input/output error."},
    {EISCONN, "Socket is connected"},
    {EISDIR, "Is a directory."},
    {EISNAM, "Is a named type file."},
    {EKEYEXPIRED, "Key has expired."},
    {EKEYREJECTED, "Key was rejected by service."},
    {EKEYREVOKED, "Key has been revoked."},
    {EL2HLT, "Level 2 halted."},
    {EL2NSYNC, "Level 2 not synchronized."},
    {EL3HLT, "Level 3 halted."},
    {EL3RST, "Level 3 reset."},
    {ELIBACC, "Cannot access a needed shared library."},
    {ELIBBAD, "Accessing a corrupted shared library."},
    {ELIBMAX, "Attempting to link in too many shared libraries."},
    {ELIBSCN, ".lib section in a.out corrupted."},
    {ELIBEXEC, "Cannot exec a shared library directly."},
    {ELOOP, "Too many levels of symbolic links."},
    {EMEDIUMTYPE, "Wrong medium type."},
    {EMFILE, "Too many open files."},
    {EMLINK, "Too many links."},
    {EMSGSIZE, "Message too long."},
    {EMULTIHOP, "Multihop attempted."},
    {ENAMETOOLONG, "Filename too long."},
    {ENETDOWN, "Network is down."},
    {ENETRESET, "Connection aborted by network."},
    {ENETUNREACH, "Network unreachable."},
    {ENFILE, "Too many open files in system."},
    {ENOANO, "No anode."},
    {ENOBUFS, "No buffer space available."},
    {ENODATA, NULL},
    {ENODEV, "No such device."},
    {ENOENT, "No such file or directory."},
    {ENOEXEC, "Exec format error."},
    {ENOKEY, "Required key not available."},
    {ENOLCK, "No locks available."},
    {ENOLINK, "Link has been severed."},
    {ENOMEDIUM, "No medium found."},
    {ENOMEM, "Not enough space/cannot allocate memory."},
    {ENOMSG, "No message of the desired type."},
    {ENONET, "Machine is not on the network."},
    {ENOPKG, "Package not installed."},
    {ENOPROTOOPT, "Protocol not available."},
    {ENOSPC, "No space left on device."},
    {ENOSR, "No STREAM resources."},
    {ENOSTR, "Not a STREAM."},
    {ENOSYS, "Function not implemented."},
    {ENOTBLK, "Block device required."},
    {ENOTCONN, "The socket is not connected."},
    {ENOTDIR, "Not a directory."},
    {ENOTEMPTY, "Directory not empty."},
    {ENOTRECOVERABLE, "State not recoverable."},
    {ENOTSOCK, "Not a socket."},
    {ENOTSUP, "Operation not supported."},
    {ENOTTY, "Inappropriate I/O control operation."},
    {ENOTUNIQ, "Name not unique on network."},
    {ENXIO, "No such device or address."},
    {EOPNOTSUPP, "Operation not supported on socket."},
    {EOVERFLOW, "Value too large to be stored in data type."},
    {EOWNERDEAD, "Owner died."},
    {EPERM, "Operation not permitted."},
    {EPFNOSUPPORT, "Protocol family not supported."},
    {EPIPE, "Broken pipe."},
    {EPROTO, "Protocol error."},
    {EPROTONOSUPPORT, "Protocol not supported."},
    {EPROTOTYPE, "Protocol wrong type for socket."},
    {ERANGE, "Result too large."},
    {EREMCHG, "Remote address changed."},
    {EREMOTE, "Object is remote."},
    {EREMOTEIO, "Remote I/O error."},
    {ERESTART, "Interrupted system call should be restarted."},
    {ERFKILL, "Operation not possible due to RF-kill."},
    {EROFS, "Read-only filesystem."},
    {ESHUTDOWN, "Cannot send after transport endpoint shutdown."},
    {ESPIPE, "Invalid seek."},
    {ESOCKTNOSUPPORT, "Socket type not supported."},
    {ESRCH, "No such process."},
    {ESTALE, "Stale file handle."},
    {ESTRPIPE, "Streams pipe error."},
    {ETIME, "Timer expired."},
    {ETIMEDOUT, "Connection timed out."},
    {ETOOMANYREFS, "Too many references: cannot splice."},
    {ETXTBSY, "Text file busy."},
    {EUCLEAN, "Structure needs cleaning."},
    {EUNATCH, "Protocol driver not attached."},
    {EUSERS, "Too many users."},
    {EWOULDBLOCK, "Operation would block."},
    {EXDEV, "Improper link."},
    {EXFULL, "Exchange full."}
};

#endif /* !ERRORS_DEFS_H_ */
