class Tester:
    def __init__(self) -> None:
        self.suites = []
        self.nbTests = 0
        self.nbPassed = 0
    
    def addSuite(self, suite):
        self.suites.append(suite)
        
    def stats(self):
        print(f"\033[1m=== SUMMARY (total {self.nbTests}) ===\033[0m")
        print(f"   \033[92m✓ {self.nbPassed} passed\033[0m")
        print(f"   \033[31m✕ {self.nbTests - self.nbPassed} failed\033[0m")

    def execute(self) -> bool:
        for suite in self.suites:
            passed, nbTests = suite.execute()
            self.nbPassed += passed
            self.nbTests += nbTests
            print("\n", end="")
        self.stats()
        return self.nbPassed == self.nbTests