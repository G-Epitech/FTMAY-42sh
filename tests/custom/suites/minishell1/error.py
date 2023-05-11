##
## EPITECH PROJECT, 2023
## G-42sh-1
## File description:
## error
##

import pathlib
from classes.suite import TestSuite
from classes.test import Test

pwd = pathlib.Path(__file__).parent.resolve()

global suite
suite = TestSuite("error")

segfault_core_dumped = Test("Segmentation with code dumped", "echo \"./tests/utils/my_sig.out 11\" | {shell}")
suite.addTest(segfault_core_dumped)

floating_core_dumped = Test("Floating point with code dumped", "echo \"./tests/custom/utils/my_floating_point\" | {shell}")
suite.addTest(floating_core_dumped)

bus_core_dumped = Test("Bus with code dumped", "echo \"./tests/custom/utils/my_bus\" | {shell}")
suite.addTest(bus_core_dumped)
