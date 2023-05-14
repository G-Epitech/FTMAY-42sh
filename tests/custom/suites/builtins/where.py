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

test = Test("Simple where", "where wc | {shell}")
suite.addTest(test)

test = Test("no argument where", "where | {shell}")
suite.addTest(test)

test = Test("ls where", "where ls | {shell}")
suite.addTest(test)

test = Test("Double where", "where wc ss | {shell}")
suite.addTest(test)

test = Test("Double where with builtin", "where wc cd ss | {shell}")
suite.addTest(test)

test = Test("no exist cmd", "where \"flavinou detend toi ca va bien se passer\" | {shell}")
suite.addTest(test)

test = Test("slash in cmd", "where l\s | {shell}")
suite.addTest(test)
