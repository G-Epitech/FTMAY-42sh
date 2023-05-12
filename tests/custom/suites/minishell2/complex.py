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
suite = TestSuite("Complex")

pipeRedirection = Test("One pipe to a file and multi command", "echo \"ls | grep l > axel; grep l < axel; rm -f axel\" | {shell}")
suite.addTest(pipeRedirection)

multiCmd = Test("Complex command", "echo \"echo begin; ls | grep l >> axel; rm -f axel;  echo end\" | {shell}")
suite.addTest(multiCmd)

multiWrongCmd = Test("Wrong complex command", "echo \"< | > ; ||\" | {shell}")
suite.addTest(multiWrongCmd)

multiLittleCmd = Test("Multiple simple command", "echo \"cd ..; pwd; cd; cd .; ls\" | {shell}")
suite.addTest(multiLittleCmd)
