##
## EPITECH PROJECT, 2023
## G-42sh-1
## File description:
## cd
##

import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("cd")

simplecd = Test("Simple cd command", "echo \"pwd ; cd sources ; pwd ; cd .. ; pwd\" | {shell}")
suite.addTest(simplecd)

backcd = Test("Back cd command", "echo \"cd sources ; pwd ; cd - ; pwd\" | {shell}")
suite.addTest(backcd)

emptycd = Test("Empty cd execution", "echo \"pwd ; cd ; pwd\" | {shell}")
suite.addTest(emptycd)
