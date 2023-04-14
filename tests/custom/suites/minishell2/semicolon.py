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

simple_semi = Test("Simple semicolon", "echo \"ls; pwd\" | {shell}")
suite.addTest(simple_semi)

double_semi = Test("Double semicolon", "echo \"ls; echo salut; pwd\" | {shell}")
suite.addTest(double_semi)

triple_semi = Test("Triple semicolon", "echo \"ls; pwd; touch axxel; rm -rf axxel\" | {shell}")
suite.addTest(triple_semi)

wrong = Test("wrong", "echo \";\" | {shell}")
suite.addTest(wrong)

spaceWrong = Test("wrong with one space", "echo \" ;\" | {shell}")
suite.addTest(spaceWrong)

tabWrong = Test("wrong with one tab", "echo \"    ;\" | {shell}")
suite.addTest(tabWrong)

tabSpaceWrong = Test("wrong with one space and one tab", "echo \"        ;\" | {shell}")
suite.addTest(tabSpaceWrong)

simpleWrongTab = Test("wrong with one command and tab", "echo \"ls ;      \" | {shell}")
suite.addTest(simpleWrongTab)

simpleWrongTabSpace = Test("Complex wrong cmd", "echo \"ls         ;      \" | {shell}")
suite.addTest(simpleWrongTabSpace)

inversedWrong = Test("wrong inversed cmd semicolon", "echo \"; ls\" | {shell}")
suite.addTest(inversedWrong)
