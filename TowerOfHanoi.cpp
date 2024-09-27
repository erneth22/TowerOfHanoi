#include <iostream>

static void welcome() {
	std::cout << "|--------------------------------|\n";
	std::cout << "|Welcome to Tower of Hanoi solver|\n";
	std::cout << "|--------------------------------|\n";
}

static int askSizeValidation() {
	int towerSize{};
	int maxSize = 50;
	do {
		std::cout << "Please enter tower height: ";
		std::cin >> towerSize;
		if (towerSize > 0 && towerSize < maxSize) {
			std::cout << "Tower height: " << towerSize << "\n";
		}
		else if (towerSize == 0) {
			std::cout << "Where is your tower ?\n";
		}
		else if (towerSize > maxSize) {
			std::cout << "Nice tower my friend, can't compute that(too much work)\n";
		}
		else {
			std::cout << "Size cant be below 0 you dummy\n";
		}
	} while (towerSize <= 0 || towerSize > maxSize);
	return towerSize;
}

static void printSolution(int a,int c) {
	std::cout << "Move from " << a << " to " << c << "\n";
}

//A = beggining
//B = middleman
//C = destination
static void solveTOH(int n,int A,int B,int C) {
	if (n > 0) {
		solveTOH(n - 1,A,C,B);
		printSolution(A,C);
		solveTOH(n - 1,B,A,C);
	}
}

int main() {
	welcome();
	solveTOH(askSizeValidation(),1,2,3);
}