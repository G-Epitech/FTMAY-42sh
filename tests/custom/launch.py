#!/usr/bin/env python3

from os import system, path
from subprocess import PIPE, Popen, run
from classes.tester import Tester
import suites.basics as basics
import suites.minishell1.cd as minishell1Cd
import suites.minishell1.env as minishell1Env
import suites.minishell1.unsetenv as minishell1Unsetenv
import suites.minishell1.setenv as minishell1Setenv
import suites.minishell1.error as minishell1Error
import suites.minishell2.semicolon as minishell2Semicolon
import suites.minishell2.pipe as minishell2Pipe
import suites.minishell2.redirection as minishellRedirection
import suites.minishell2.complex as minishell2Complex

if __name__ == '__main__':
    tester = Tester()
    # tester.addSuite(basics.suite)
    # tester.addSuite(minishell1Cd.suite)
    # tester.addSuite(minishell1Env.suite)
    # #tester.addSuite(minishell1Unsetenv.suite)
    # #tester.addSuite(minishell1Setenv.suite)
    # tester.addSuite(minishell1Error.suite)
    # tester.addSuite(minishell2Semicolon.suite)
    # tester.addSuite(minishell2Pipe.suite)
    # tester.addSuite(minishellRedirection.suite)
    # tester.addSuite(minishell2Complex.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

