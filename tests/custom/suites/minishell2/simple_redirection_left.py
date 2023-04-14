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

simpleWrongRedirection = Test("simple redirection left", "echo \"ls > axel; grep l < axel; rm axel\" | {shell}")
suite.addTest(simpleWrongRedirection)

simpleRedirectionBegin = Test("simple redirection left at begin", "echo \"cat -e < Makefile\" | {shell}")
suite.addTest(simpleRedirectionBegin)

simpleRedirectionMiddle = Test("simple redirection left at middle", "echo \"cat < Makefile -e\" | {shell}")
suite.addTest(simpleRedirectionMiddle)

simpleRedirectionEnd = Test("simple redirection left at end", "echo \"< Makefile cat -e\" | {shell}")
suite.addTest(simpleRedirectionEnd)

simpleWrongRedirection = Test("simple redirection left", "echo \"ls < \" | {shell}")
suite.addTest(simpleWrongRedirection)