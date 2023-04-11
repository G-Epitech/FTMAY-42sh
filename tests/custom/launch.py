#!/usr/bin/env python3

from classes.tester import Tester
import basics

if __name__ == '__main__':
    tester = Tester()
    tester.addSuite(basics.suite)

    if tester.execute():
        exit(0)
    else:
        exit(1)

