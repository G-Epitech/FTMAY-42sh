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
suite = TestSuite("Semicolon")

simpleSemi = Test("Simple semicolon", "echo \"ls; pwd\" | {shell}")
suite.addTest(simpleSemi)

doubleSemi = Test("Double semicolon", "echo \"ls; echo salut; pwd\" | {shell}")
suite.addTest(doubleSemi)

tripleSemi = Test("Triple semicolon", "echo \"ls; pwd; touch axxel; rm -f axxel\" | {shell}")
suite.addTest(tripleSemi)

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
