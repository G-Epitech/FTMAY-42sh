#!/usr/bin/env python3

from classes.tester import Tester
import suites.basics as basics
import suites.minishell2.semicolon as minishell2Semicolon


if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(basics.suite)
    tester.addSuite(minishell2Semicolon.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

