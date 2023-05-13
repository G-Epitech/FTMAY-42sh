##
## EPITECH PROJECT, 2023
## minishell2
## File description:
## suite
##

import pathlib
import os
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("Operators")

test = Test("Simple &&", "echo \"echo 12 && echo pounds\" | {shell}")
suite.addTest(test)

test = Test("Simple ||", "echo \"echo 12 || echo pounds\" | {shell}")
suite.addTest(test)

test = Test("Simple || and &&", "echo \"echo 12 || echo pounds && echo needs\" | {shell}")
suite.addTest(test)

test = Test("Fail || and &&", "echo \"false || echo pounds && echo needs\" | {shell}")
suite.addTest(test)

test = Test("Fail 2 || and &&", "echo \"false || false && echo needs\" | {shell}")
suite.addTest(test)

test = Test("3 consecutive ||", "echo \"false || false || echo needs\" | {shell}")
suite.addTest(test)

test = Test("Simple || and && with one parenthese", "echo \"(false || echo in) && false\" | {shell}")
suite.addTest(test)

test = Test("Several || with one parenthese", "echo \"(false || echo in) || ls\" | {shell}")
suite.addTest(test)
