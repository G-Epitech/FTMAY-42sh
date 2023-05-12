##
## EPITECH PROJECT, 2023
## G-42sh-1
## File description:
## error
##

import pathlib
from classes.suite import TestSuite
from utils.os_type import OSType
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("Path")

test = Test("Simple path", "echo \"echo $PATH\" | {shell}")
suite.addTest(test)

test = Test("Without env heritage", "echo \"ls\" | env -i {shell}")
suite.addTest(test)

test = Test("With non env path", "unsetenv PATH; echo \"ls\" | {shell}")
suite.addTest(test)

commandTcsh="echo \"setenv PATH \"\"; ls\" | {shell}"
test = Test("With void env path", "echo \"ls\" | env PATH=\"\" {shell}", commandTcsh=commandTcsh)
suite.addTest(test)

commandTcsh="echo \"echo '$PATH'; echo '$PATH'\" | {shell}"
test = Test("Compare env PATH value", "echo 'echo $PATH; echo $path' | {shell}", commandTcsh=commandTcsh)
suite.addTest(test)

test = Test("Unset env PATH value", "echo 'unsetenv PATH; echo $PATH' | {shell}")
suite.addTest(test)

test = Test("Clear PATH variable", "echo 'unsetenv PATH; ls' | {shell}")
suite.addTest(test)

test = Test("Clear PATH variable and $path", "echo 'unsetenv PATH; unset path; ls' | {shell}")
suite.addTest(test)


