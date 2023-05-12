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

wrong = Test("Empty command", "echo \";\" | {shell}")
suite.addTest(wrong)

spaceWrong = Test("Semicolon with space and empty command", "echo \" ;\" | {shell}")
suite.addTest(spaceWrong)

tabWrong = Test("Semicolon with tab and empty command", "echo \"    ;\" | {shell}")
suite.addTest(tabWrong)

tabSpaceWrong = Test("Semicolon with space, tab and empty command", "echo \"        ;\" | {shell}")
suite.addTest(tabSpaceWrong)

simpleWrongTab = Test("Semicolon with space, tab and valid command", "echo \"ls ;      \" | {shell}")
suite.addTest(simpleWrongTab)

simpleWrongTabSpace = Test("Simple command with spaces and semicolon", "echo \"ls         ;      \" | {shell}")
suite.addTest(simpleWrongTabSpace)

inversedWrong = Test("Empty command with semicolon followed by valid command", "echo \"; ls\" | {shell}")
suite.addTest(inversedWrong)

manySemicolons = Test("Many semicolons", "echo \";;;;;;;;;;\" | {shell}")
suite.addTest(manySemicolons)
