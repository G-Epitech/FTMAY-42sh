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

simpleunsetenv = Test("Simple unsetenv command", "echo 'echo $USER ; unsetenv USER ; echo $USER' | {shell}")
suite.addTest(simpleunsetenv)

doubleunsetenv = Test("Double unsetenv execution", "echo 'echo $USER $MAIL ; unsetenv USER MAIL ; echo $USER $MAIL' | {shell}")
suite.addTest(doubleunsetenv)

multipleunsetenv = Test("Mutiple unsetenv execution", "echo 'echo $USER $MAIL $LANG $GROUP ; unsetenv USER MAIL LANG GROUP ; echo $USER $MAIL $LANG $GROUP' | {shell}")
suite.addTest(multipleunsetenv)
