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
suite = TestSuite("Parenthesis")

test = Test("Simple parenthesis", "echo \"(echo salut)\" | {shell}")
suite.addTest(test)

test = Test("Simple parenthesis with redirection", "echo \"(echo salut) > file.tmp; cat -e file.tmp; rm -f file.tmp\" | {shell}")
suite.addTest(test)

test = Test("Simple parenthesis with pipes and redirection", "echo \"(cat Makefile | grep s) > file.tmp; cat -e file.tmp; rm -f file.tmp\" | {shell}")
suite.addTest(test)

test = Test("Several parentheses with pipes", "echo \"(cat Makefile | grep s) | (cat -e | wc -l)\" | {shell}")
suite.addTest(test)

test = Test("Several parentheses in parenthesis",
            "echo \"echo super_content > file.tmp; (cat Makefile | (grep > file.tmp) && echo salut) | (cat -e | wc -l) && echo end of command\" | {shell}")
suite.addTest(test)

test = Test("Several parentheses in parenthesis with error",
            "echo \"echo super_content > file.tmp; (cat Makefile | (grep < file.tmp) && echo salut)\" | {shell}")
suite.addTest(test)
