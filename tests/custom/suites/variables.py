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

test = Test("simple env var", "echo 'echo $PATH' | {shell}")
suite.addTest(test)

test = Test("var no exist", "echo 'echo $flavinouuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuu' | {shell}")
suite.addTest(test)

test = Test("Special cwd", "echo 'echo $cwd' | {shell}")
suite.addTest(test)

test = Test("Special ids", "echo 'echo \"$gid - $uid\"' | {shell}")
suite.addTest(test)

test = Test("Special owd", "echo 'cd ../ && echo $owd' | {shell}")
suite.addTest(test)

test = Test("Special owd", "echo 'cd ../ && echo $owd' | {shell}")
suite.addTest(test)

test = Test("Special user infos", "echo 'echo $user $group $home' | {shell}")
suite.addTest(test)

test = Test("Special shell infos", "echo 'echo $term' | {shell}")
suite.addTest(test)

test = Test("Special error code", "echo 'ls && echo $?' | {shell}")
suite.addTest(test)

test = Test("double var (env, spe) and one wrong", "echo \"echo $path; echo $PATH; echo $wrong\" | {shell}")
suite.addTest(test)
