#!/usr/bin/env python3

from classes.tester import Tester
import suites.basics as basics
import suites.minishell2.semicolon as minishell2Semicolon
import suites.minishell2.pipe as minishell2Pipe
import suites.minishell2.simple_redirection_right as minishell2SRR
import suites.minishell2.double_redirection_right as minishell2DRR


if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(basics.suite)
    tester.addSuite(minishell2Semicolon.suite)
    tester.addSuite(minishell2Pipe.suite)
    tester.addSuite(minishell2SRR.suite)
    tester.addSuite(minishell2DRR.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

