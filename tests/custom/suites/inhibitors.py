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
suite = TestSuite("Inhibitors")

simple = Test("Simple inhibitors", "echo \"echo \"\\tata\"\" | {shell}")
suite.addTest(simple)

simple_without = Test("Simple inhibitors without quote", "echo \"echo \\tata\" | {shell}")
suite.addTest(simple_without)

multiple = Test("Multiple inhibitors", "echo \"echo \"\\ta\\na\"\" | {shell}")
suite.addTest(multiple)

multiple_without = Test("Multiple inhibitors without quote", "echo \"echo \\ta\\na\" | {shell}")
suite.addTest(multiple_without)

# bonded_inibitors = Test("Bounded inibitors", "echo \"\\t\\t\\tahah\\t\\t\\t\"")
# suite.addTest(bonded_inibitors)

# bonded_inibitors_without = Test("Bounded inibitosr without quote", "echo \\t\\t\\tahah\\t\\t\\t")
# suite.addTest(bonded_inibitors_without)

bad_inibitors = Test("Bad inhibitors", "echo \"echo \"super test n n n ttt t\"\" | {shell}")
suite.addTest(bad_inibitors)

bad_inibitors_without = Test("Bad inhibitor without", "echo \"echo super test n n n ttt t\" | {shell}")
suite.addTest(bad_inibitors_without)
