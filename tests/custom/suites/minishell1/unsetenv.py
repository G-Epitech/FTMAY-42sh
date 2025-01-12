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

simpleunsetenv = Test("Simple unsetenv command", "echo \"echo \"env\" ; echo \"unsetenv USER\" ; echo \"env\"\" | {shell} | env -i tcsh")
suite.addTest(simpleunsetenv)

doubleunsetenv = Test("Double unsetenv execution", "echo \"echo \"env\" ; echo \"unsetenv USER\" ; echo \"env\"\" | {shell} | env -i tcsh")
suite.addTest(doubleunsetenv)

multipleunsetenv = Test("Mutiple unsetenv execution", "echo \"echo \"env\" ; echo \"unsetenv USER MAIL LANG GROUP\"; echo \"env\"\" | {shell} | env -i tcsh")
suite.addTest(multipleunsetenv)
