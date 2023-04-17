##
## EPITECH PROJECT, 2023
## G-42sh-1
## File description:
## env
##

import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("env")

simpleenv = Test("Simple env command", "echo \"env\" | {shell}")
suite.addTest(simpleenv)
