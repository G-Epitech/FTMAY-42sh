##
## EPITECH PROJECT, 2023
## 42sh
## File description:
## suite
##

import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("Builtin which")

test = Test("No args", "echo \"which\" | {shell}")
suite.addTest(test)

test = Test("One arg system", "echo \"which ls\" | {shell}")
suite.addTest(test)

test = Test("Multiple args system", "echo \"which wc ls pwd\" | {shell}")
suite.addTest(test)

test = Test("One arg builtin", "echo \"which echo\" | {shell}")
suite.addTest(test)

test = Test("Multiple args builtin", "echo \"which echo set unsetenv\" | {shell}")
suite.addTest(test)

test = Test("Invalid command", "echo \"which invalidcommandsystem\" | {shell}")
suite.addTest(test)

test = Test("Invalid command multiple", "echo \"which invalidcommandsystem secondinvalid otherinvalid\" | {shell}")
suite.addTest(test)

test = Test("Mix valid and invalid commands", "echo \"which ls invalidcommand setenv superinvalid pwd\" | {shell}")
suite.addTest(test)
