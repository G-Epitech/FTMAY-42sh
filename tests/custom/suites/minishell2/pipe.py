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
suite = TestSuite("Pipes")

simplePipe = Test("Simple pipe", "echo \"ls | grep l\" | {shell}")
suite.addTest(simplePipe)

doublePipe = Test("Double pipe", "echo \"ls | grep l | grep M\" | {shell}")
suite.addTest(doublePipe)

triplePipe = Test("Triple pipe", "echo \"ls | grep l | grep M | wc -c\" | {shell}")
suite.addTest(triplePipe)

wrongPipe = Test("Wrong pipe", "echo \"|\" | {shell}")
suite.addTest(wrongPipe)

spaceWrongPipe = Test("Wrong pipe with one space", "echo \" |\" | {shell}")
suite.addTest(spaceWrongPipe)

tabWrong_pipe = Test("Wrong pipe with one tab", "echo \"    |\" | {shell}")
suite.addTest(tabWrong_pipe)

tabSpaceWrongPipe = Test("Wrong with one space and one tab", "echo \"        |\" | {shell}")
suite.addTest(tabSpaceWrongPipe)

SimpleWrongTabPipe = Test("Wrong with one command and tab", "echo \"ls |      \" | {shell}")
suite.addTest(SimpleWrongTabPipe)

SimpleWrongTabSpacePipe = Test("Multiple wrong pipes", "echo \"ls         |      \" | {shell}")
suite.addTest(SimpleWrongTabSpacePipe)

InversedWrongPipe = Test("Wrong inversed command with pipe", "echo \"| ls\" | {shell}")
suite.addTest(InversedWrongPipe)
