#!/usr/bin/env python3

from classes.tester import Tester
import suites.basics as basics
import suites.minishell1.cd as minishell1cd
import suites.minishell1.env as minishell1env
import suites.minishell1.unsetenv as minishell1unsetenv

if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(basics.suite)
    tester.addSuite(minishell1cd.suite)
    tester.addSuite(minishell1env.suite)
    tester.addSuite(minishell1unsetenv.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

