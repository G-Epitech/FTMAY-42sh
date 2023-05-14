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
suite = TestSuite("Basics")

empty = Test("Empty command", "echo \"\" | {shell}")
suite.addTest(empty)

wrong = Test("Wrong simple command", "echo \"exitt\" | {shell}")
suite.addTest(wrong)

simple = Test("Simple execution", "echo \"ls -la\" | {shell}")
suite.addTest(simple)

pdf = Test("PDF command", "echo \"cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo OK\" | {shell}")
suite.addTest(pdf)