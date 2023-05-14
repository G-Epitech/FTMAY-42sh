##
## EPITECH PROJECT, 2023
## minishell2
## File description:
## suite
##

import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("Variables")

test = Test("Simple command", "echo \'ls; echo $?\' | {shell}")
suite.addTest(test)

test = Test("Fail : no command", "echo \'toto; echo $?\' | {shell}")
suite.addTest(test)

test = Test("Fail : grep", "echo \'grep t > file.txt; echo $?; rm -f file.txt; echo $?;\' | {shell}")
suite.addTest(test)

test = Test("Fail : ls | tree", "echo \'ls | tree; echo $?;\' | {shell}")
suite.addTest(test)

test = Test("Fail : ls | tree | grep sh | head -n 2", "echo \'ls | tree | grep sh | head -n 2; echo $?;\' | {shell}")
suite.addTest(test)

test = Test("Fail : (ls | tree) | (grep sh | cut -d 5)", "echo \'(ls | tree) | (grep sh | cut -d 5); echo $?;\' | {shell}")
suite.addTest(test)

test = Test("Complex parentheses, redirections and conditions",
            "echo \"(false || echo in) | (ls | cat -e) > file.tmp && cat file.tmp; rm -f file.tmp; echo $?\" | {shell}")
suite.addTest(test)