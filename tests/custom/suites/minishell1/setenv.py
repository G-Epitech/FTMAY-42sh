##
## EPITECH PROJECT, 2023
## G-42sh-1
## File description:
## setenv
##


import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("setenv")

simplesetenv = Test("Simple setenv command", "echo \"env ; setenv TEST Hello_World ; env\" | {shell}")
suite.addTest(simplesetenv)

argumentssetenv = Test("Too many arguments test", "echo \"env ; setenv TEST Hello World\" | {shell}")
suite.addTest(argumentssetenv)

variablenamenumber = Test("Variable Name number", "echo \"env ; setenv 4TEST Hello_world ; env\" | {shell}")
suite.addTest(variablenamenumber)

variablenamedot = Test("Variable Name dot", "echo \"env ; setenv .TEST Hello_world ; env\" | {shell}")
suite.addTest(variablenamenumber)

variablenameminus = Test("Variable Name minus", "echo \"env ; setenv -TEST Hello_world ; env\" | {shell}")
suite.addTest(variablenamenumber)

variablenameunderscore = Test("Variable Name underscore", "echo \"env ; setenv _TEST Hello_world ; env\" | {shell}")
suite.addTest(variablenamenumber)

redifinevariable = Test("Redifine variable", "echo \"env ; setenv PATH /bin ; env\" | {shell}")
suite.addTest(redifinevariable)

emptyavariable = Test("Empty a variable", "echo \"env ; setenv PATH ; env\" | {shell}")
suite.addTest(emptyavariable)
