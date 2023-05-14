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
suite = TestSuite("Builtin echo")

test = Test("Simple echo", "echo hello world | {shell}")
suite.addTest(test)

test = Test("With quotes", "echo \"hello world\" | {shell}")
suite.addTest(test)

test = Test("With quotes and special chars", "echo \"echo \"\\thello \\nworld\"\" | {shell}")
suite.addTest(test)

test = Test("Without quotes and special chars", "echo \"echo \\thello \\nworld\" | {shell}")
suite.addTest(test)

test = Test("Without new line", "echo \"echo -n thello world\" | {shell}")
suite.addTest(test)

test = Test("Without new line and empty content", "echo \"echo -n\" | {shell}")
suite.addTest(test)

test = Test("No arguments", "echo \"echo\" | {shell}")
suite.addTest(test)