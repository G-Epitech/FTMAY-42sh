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

pipeRedirection = Test("one pipe to a file and multi cmd", "echo \"ls | grep l > axel; grep l < axel; rm axel\" | {shell}")
suite.addTest(pipeRedirection)

multiCmd = Test("testing complex cmd", "echo \"echo begin; ls | grep l >> axel; rm axel;  echo end\" | {shell}")
suite.addTest(multiCmd)

multiWrongCmd = Test("testing wrong complex cmd", "echo \"< | > ; ||\" | {shell}")
suite.addTest(multiWrongCmd)

multiLittleCmd = Test("testing multiple of simple cmd", "echo \"cd ..; pwd; cd; cd .; ls\" | {shell}")
suite.addTest(multiLittleCmd)
