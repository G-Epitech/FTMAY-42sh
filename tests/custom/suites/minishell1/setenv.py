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
unsetUseless="unsetenv "

simplesetenv = Test("Simple setenv command", "echo 'setenv TEST Hello_World ; echo $TEST' | env -i {shell}")
suite.addTest(simplesetenv)

argumentssetenv = Test("Too many arguments test", "echo 'setenv TEST Hello World' | env -i {shell}")
suite.addTest(argumentssetenv)

variablenamenumber = Test("Variable name number", "echo 'setenv TE4ST Hello_world ; echo $TE4ST' | env -i {shell}")
suite.addTest(variablenamenumber)

variablenamedot = Test("Variable name dot", "echo 'setenv .TEST Hello_world ; echo $_TEST' | env -i {shell}")
suite.addTest(variablenamedot)

variablenameminus = Test("Variable name minus", "echo 'setenv -TEST Hello_world ; echo $-TEST' | env -i {shell}")
suite.addTest(variablenameminus)

variablenameunderscore = Test("Variable name underscore", "echo 'setenv _TEST Hello_world ; echo $_TEST' | env -i {shell}")
suite.addTest(variablenameunderscore)

redifinevariable = Test("Redifine variable", "echo 'setenv PATH /bin ; echo $PATH' | env -i {shell}")
suite.addTest(redifinevariable)

emptyavariable = Test("Empty a variable", "echo 'setenv PATH ; echo $PATH' | env -i {shell}")
suite.addTest(emptyavariable)
