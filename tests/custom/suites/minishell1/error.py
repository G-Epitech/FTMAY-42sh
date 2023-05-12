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
suite = TestSuite("Error handling")

wrongBin = f"{pwd}/../../../utils/bin/bin-macos.bin"
sigBin = f"{pwd}/../../../utils/my_sig.out"
if (OSType.is_macos()):
    wrongBin = f"{pwd}/../../../utils/bin/bin-linux.bin"

test = Test("Icompatible binary", "echo \"" + wrongBin + "\" | {shell}")
suite.addTest(test)

test = Test("Division by zero", "echo \"" + sigBin + " 8\" | {shell}")
suite.addTest(test)

test = Test("Segmentation fault (without coredump)", "echo \"" + sigBin + " 11\" | {shell}")
suite.addTest(test)

test = Test("Segmentation fault (with coredump)", "echo \"" + sigBin + " 11 true\" | {shell}")
suite.addTest(test)

test = Test("Terminated", "echo \"" + sigBin + " 15\" | {shell}")
suite.addTest(test)

test = Test("Command not found", "echo \"supercommand\" | {shell}")
suite.addTest(test)

test = Test("Execute a directory", "echo \"./sources\" | {shell}")
suite.addTest(test)
