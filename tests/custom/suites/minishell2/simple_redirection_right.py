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

simpleRedirectionRight = Test("Simple redirection right", "echo \"ls > axel; rm axel\" | {shell}")
suite.addTest(simpleRedirectionRight)

simpleWrongRedirection = Test("Simple redirection right", "echo \"ls > \" | {shell}")
suite.addTest(simpleWrongRedirection)
