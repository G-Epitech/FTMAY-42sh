#!/usr/bin/env python3

from classes.tester import Tester
import suites.basics as basics
import suites.minishell1.cd as minishell1Cd
import suites.minishell1.env as minishell1Env
import suites.minishell1.unsetenv as minishell1Unsetenv
import suites.minishell1.setenv as minishell1Setenv

if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(basics.suite)
    tester.addSuite(minishell1Cd.suite)
    tester.addSuite(minishell1Env.suite)
    tester.addSuite(minishell1Unsetenv.suite)
    tester.addSuite(minishell1Setenv.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

