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
suite = TestSuite("Builtin unset")

test = Test("Unset no args", "echo \"unset\" | {shell}")
suite.addTest(test)

test = Test("Invalid argument", "echo \"unset invalidarg\" | {shell}")
suite.addTest(test)

test = Test("Simple unset", "echo 'set cool && unset cool && echo $cool' | {shell}")
suite.addTest(test)

test = Test("Unset special variable", "echo 'unset path && echo $path' | {shell}")
suite.addTest(test)

test = Test("Unset multiple variables",
            "echo \"set test test2 test3 test4 && unset test test2 test3 test4\" | {shell}")
suite.addTest(test)
