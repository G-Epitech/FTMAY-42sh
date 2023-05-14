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
suite = TestSuite("Builtin set")

test = Test("Simple set blank", "echo \"set test\" | {shell}")
suite.addTest(test)

test = Test("Simple set with value", "echo 'set test=super && echo $test' | {shell}")
suite.addTest(test)

test = Test("Multiple blanks", "echo \"set test test2 test3 test4 && echo \"$test-$test2-$test3-$test4\"\" | {shell}")
suite.addTest(test)

test = Test("Multiple with values", "echo \"set test=super test2=super test3=super test4=super\" | {shell}")
suite.addTest(test)

test = Test("Mutliple mix", "echo \"set test test2=super test3 test4=super\" | {shell}")
suite.addTest(test)

test = Test("Set discarded", "echo \"set test = 1\" | {shell}")
suite.addTest(test)

test = Test("Multiple set discarded", "echo \"set test = 1 test2 = 2 test3 = 3\" | {shell}")
suite.addTest(test)

test = Test("Syntax error discarded", "echo \"set test= 1\" | {shell}")
suite.addTest(test)

test = Test("Multiple syntax error discarded", "echo 'set test = 1 test2=2 test3= 3 test4 test5; echo $test5' | {shell}")
suite.addTest(test)

test = Test("Set with string", "echo 'set test=\"big string for test\" && echo $test' | {shell}")
suite.addTest(test)

test = Test("Invalid variable name", "echo \"set 2test\" | {shell}")
suite.addTest(test)

test = Test("Invalid variable name content", "echo \"set te-st\" | {shell}")
suite.addTest(test)

test = Test("Valide extra name", "echo \"set _test\" | {shell}")
suite.addTest(test)

test = Test("Valide extra name content", "echo \"set te_st\" | {shell}")
suite.addTest(test)
