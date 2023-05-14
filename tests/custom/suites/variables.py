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
suite = TestSuite("Variable")

test = Test("simple env var", "echo \"echo $PATH\" | {shell}")
suite.addTest(test)

test = Test("simple special var", "echo \"echo $path\" | {shell}")
suite.addTest(test)

test = Test("var no exist", "echo \"echo $flavinouuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu\" | {shell}")
suite.addTest(test)

test = Test("double var (env, spe)", "echo \"echo $path; echo $PATH\" | {shell}")
suite.addTest(test)

test = Test("double var (env, spe) and one wrong", "echo \"echo $path; echo $PATH; echo $wrong\" | {shell}")
suite.addTest(test)
