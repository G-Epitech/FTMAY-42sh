##
## EPITECH PROJECT, 2023
## G-42sh-1
## File description:
## unsetenv
##

import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("unsetenv")

simpleunsetenv = Test("Simple unsetenv command", "echo \"env ; unsetenv USER ; env\" | {shell}")
suite.addTest(simpleunsetenv)

doubleunsetenv = Test("Double unsetenv execution", "echo \"env ; unsetenv USER MAIL ; env\" | {shell}")
suite.addTest(doubleunsetenv)

multipleunsetenv = Test("Mutiple unsetenv execution", "echo \"env ; unsetenv USER MAIL LANG GROUP ; env\" | {shell}")
suite.addTest(multipleunsetenv)
