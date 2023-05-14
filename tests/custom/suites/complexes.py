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

test = Test("Mix pipe & redirection", "echo \"(ls -R . | grep \".\" | sort) > errors.txt && rm -f errors.txt\" | {shell}")
suite.addTest(test)

test = Test("Mix multiple redirections and conditions",
            "echo \"((ls | cat -e) && ls) > output.txt && rm -f output.txt\" | {shell}")
suite.addTest(test)

test = Test("Big complexe command",
            "echo \"echo \"super example\" > input.loog; (((grep \"example\" < input.loog) >> output1.loog) > errors.loog) || ((ls | cat) > output2.loog) && (sort | uniq) | wc -l > final_output.loog\" | {shell}; rm -f *.loog")
suite.addTest(test)
