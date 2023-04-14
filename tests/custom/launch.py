#!/usr/bin/env python3

from classes.tester import Tester
import suites.basics as basics
import suites.minishell1.cd as minishell1cd

if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(basics.suite)
    tester.addSuite(minishell1cd.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

