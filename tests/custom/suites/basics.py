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
suite = TestSuite("Basics")

empty = Test("Empty command", "echo \"\" | {shell}")
suite.addTest(empty)

wrong = Test("Wrong simple command", "echo \"exitt\" | {shell}")
suite.addTest(wrong)

simple = Test("Simple execution", "echo \"ls -la\" | {shell}")
suite.addTest(simple)

pdf = Test("PDF command", "echo \"cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo OK\" | {shell}")
suite.addTest(pdf)

simple = Test("Simple execution", "echo \"ls -la\" | {shell}")
suite.addTest(simple)

simple = Test("Simple execution", "echo \"Hello, World!\" | {shell}")
suite.addTest(simple)

redirection = Test("Redirection", "echo \"echo Hello > output.txt; cat output.txt; rm -f output.txt\"  | {shell}")
suite.addTest(redirection)

variables = Test("Environment variables", "echo 'echo $PATH'  | {shell}")
suite.addTest(variables)

pipes = Test("Pipes", "echo \"ls | grep \"\.txt\" | wc -l\"  | {shell}")
suite.addTest(pipes)

options = Test("Command with options", "echo \"ls -l\"  | {shell}")
suite.addTest(options)

substitution = Test("Variable substitution", "echo 'set var = \"Hello\"; echo $var' | {shell}")
suite.addTest(substitution)

regex = Test("Regular expressions", "echo \"echo \"Hello, World!\" | sed -E s/World/Universe/\" | {shell}")
suite.addTest(regex)

interactive = Test("Interactive options", "echo \"rm -i file.txt\" | {shell}")
suite.addTest(interactive)

command_substitution = Test("Command substitution", "echo \"echo \"Today is $(date)\"\" | {shell}")
suite.addTest(command_substitution)

external_command = Test("External command", "echo \"/usr/bin/ls -l\"  | {shell}")
suite.addTest(external_command)

process_substitution = Test("Process substitution", "echo \"diff <(sort file1.txt) <(sort file2.txt)\"  | {shell}")
suite.addTest(process_substitution)

