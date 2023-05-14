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
suite = TestSuite("Builtin where")

test = Test("Simple where", "echo \"where wc\" | {shell}")
suite.addTest(test)

test = Test("no argument where", "echo \"where\" | {shell}")
suite.addTest(test)

test = Test("simple built'in", "echo \"where cd\" | {shell}")
suite.addTest(test)

test = Test("Double where", "echo \"where wc ss\" | {shell}")
suite.addTest(test)

test = Test("Double where with builtin", "echo \"where wc cd ss\" | {shell}")
suite.addTest(test)

test = Test("no exist cmd", "echo \"where \"flavinou detend toi ca va bien se passer\"\" | {shell}")
suite.addTest(test)

test = Test("slash in cmd", "echo \"where l\s\" | {shell}")
suite.addTest(test)
