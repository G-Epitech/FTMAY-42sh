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
suite = TestSuite("Complexes")

test = Test("Complex parentheses, redirections and conditions",
            "echo \"(false || echo in) | (ls | cat -e) > file.tmp && cat file.tmp; rm -f file.tmp\" | {shell}")
suite.addTest(test)
