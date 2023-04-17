#!/usr/bin/env python3

from classes.tester import Tester
import suites.basics as basics
import suites.minishell2.semicolon as minishell2Semicolon
import suites.minishell2.pipe as minishell2Pipe
import suites.minishell2.redirection as minishellRedirection
import suites.minishell2.complex as minishell2Complex

if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(basics.suite)
    tester.addSuite(minishell2Semicolon.suite)
    tester.addSuite(minishell2Pipe.suite)
    tester.addSuite(minishellRedirection.suite)
    tester.addSuite(minishell2Complex.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

