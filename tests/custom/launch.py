#!/usr/bin/env python3

from classes.tester import Tester
import suites

if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(suites.basics.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

