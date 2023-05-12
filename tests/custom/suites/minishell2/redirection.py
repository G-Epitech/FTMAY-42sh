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
suite = TestSuite("Redirections")

simpleWrongRedirection = Test("Simple redirection left", "echo \"ls > axel; grep l < axel; rm -f axel\" | {shell}")
suite.addTest(simpleWrongRedirection)

simpleRedirectionBegin = Test("Simple redirection left at begin", "echo \"cat -e < Makefile\" | {shell}")
suite.addTest(simpleRedirectionBegin)

simpleRedirectionMiddle = Test("Simple redirection left at middle", "echo \"cat < Makefile -e\" | {shell}")
suite.addTest(simpleRedirectionMiddle)

simpleRedirectionEnd = Test("Simple redirection left at end", "echo \"< Makefile cat -e\" | {shell}")
suite.addTest(simpleRedirectionEnd)

simpleWrongRedirection = Test("Simple redirection left", "echo \"ls < \" | {shell}")
suite.addTest(simpleWrongRedirection)

simpleRedirectionRight = Test("Simple redirection right", "echo \"ls > axel; rm -f axel\" | {shell}")
suite.addTest(simpleRedirectionRight)

simpleWrongRedirection = Test("Simple redirection right", "echo \"ls > \" | {shell}")
suite.addTest(simpleWrongRedirection)

doubleRedirectionRight = Test("Double redirection right", "echo \"ls >> axel; rm -f axel\" | {shell}")
suite.addTest(doubleRedirectionRight)

doubleWrongRedirection = Test("Double redirection right", "echo \"ls >> \" | {shell}")
suite.addTest(doubleWrongRedirection)

doubleWrongRedirection = Test("Double redirection left", "echo \"ls << \" | {shell}")
suite.addTest(doubleWrongRedirection)
