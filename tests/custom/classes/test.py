import os
from subprocess import PIPE, Popen

class Test:
    def __init__(self, label, command, custom = False, commandTcsh = False,
                customStdOut = False, customStdErr = False, allStdOut = False) -> None:
        self.label = label
        self.custom = custom
        self.command = command
        self.commandTcsh = command
        self.allStdOut = allStdOut
        self.execution = {
            'expected' : { 'out' : "", 'err' : "" },
            'found' : { 'out' : "", 'err' : "" }
        }
        if customStdErr:
            self.execution['expected']['err'] = customStdErr
        if customStdOut:
            self.execution['expected']['out'] = customStdOut
        if commandTcsh:
            self.commandTcsh = commandTcsh

    def executeTSCH(self):
        command = self.commandTcsh.format(shell="tcsh")
        proc = Popen(command, stderr=PIPE, stdout=PIPE, shell=True)
        proc.wait()
        if not self.execution['expected']['out']:
            self.execution['expected']['out'] = proc.stdout.read().decode(encoding="latin-1")
        if (self.allStdOut):
            self.execution['expected']['out'] += proc.stderr.read().decode(encoding="latin-1")
        else:
            self.execution['expected']['err'] = proc.stderr.read().decode(encoding="latin-1")

    def execute42Sh(self):
        command = self.command.format(shell="./42sh")
        proc = Popen(command, stderr=PIPE, stdout=PIPE, shell=True)
        proc.wait()
        self.execution['found']['out'] = proc.stdout.read().decode(encoding="latin-1")
        self.execution['found']['err'] = proc.stderr.read().decode(encoding="latin-1")

    def execute(self) -> bool:
        success = True
        command = self.command.format(shell="./42sh")
        print(command)
        if not self.custom:
            self.executeTSCH()
        self.execute42Sh()

        if (self.execution['expected']['out'] != self.execution['found']['out']
            and self.execution['expected']['out']):
            success = False
            print("STDOUT:")
            print("\033[31mFound    : \"" + self.execution['found']['out'] + "\"\033[0m")
            print("\033[31mExpected : \"" + self.execution['expected']['out'] + "\"\033[0m")
        if ((self.execution['expected']['err'] != self.execution['found']['err'])
            and not self.allStdOut):
            success = False
            print("STDERR:")
            print("\033[31mFound    : \"" + self.execution['found']['err'] + "\"\033[0m")
            print("\033[31mExpected : \"" + self.execution['expected']['err'] + "\"\033[0m")
        return success

        
