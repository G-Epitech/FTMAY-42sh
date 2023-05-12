from classes.test import Test

class TestSuite:
    def __init__(self, label) -> None:
        self.label = label
        self.nbPassed = 0
        self.tests = []
    
    def addTest(self, test : Test):
        self.tests.append(test)

    def execute(self) -> tuple[int, int]:
        print(f"=== [{self.label}] ===")
        for test in self.tests:
            print(f"\033[94m\033[1m{test.label}\033[0m")
            if test.execute():
                print(f"    \033[92m✓ Passed\033[0m")
                self.nbPassed += 1
            else:
                print(f"    \033[31m✕ Failed\033[0m")
        return (self.nbPassed, len(self.tests))
