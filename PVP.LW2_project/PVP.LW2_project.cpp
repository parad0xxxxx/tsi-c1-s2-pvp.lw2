#include <windows.h>

#include <iostream>
#include <iomanip>

const std::string INT_EXPECTED_ERROR = "Integer number expected ;)";

void setConsoleColor(int);
void checkNegative(int);
void logInfo(std::string, std::string);
void calcIntergers();
void calcSequence();
void countSequence();
void drawSnake();

int main()
{
	setConsoleColor(9);
	std::cout << "Variant ";
	setConsoleColor(15);
	std::cout << "8";
	setConsoleColor(9);
	std::cout << ".\n\n";

//	calcIntergers();
//	calcSequence();
//	countSequence();
	drawSnake();


	return 0;
}

void setConsoleColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void checkNegative(int c)
{
	if (c < 0) {
		setConsoleColor(9);
		std::cout << "(";
		setConsoleColor(15);
		std::cout << c;
		setConsoleColor(9);
		std::cout << ")";
	}
	else {
		setConsoleColor(15);
		std::cout << c;
	}
	setConsoleColor(9);
}

void logInfo(std::string loglevel, std::string log)
{
	if (loglevel == "warn") {
		setConsoleColor(4);
	}
	else {
		setConsoleColor(11);
	}

	std::cout << "\n" << log << "\n\n";
	setConsoleColor(7);
}

void calcIntergers()
{
	int a = 0, b = 0, c = 0, sum = 0,  mult = 0;
	float mean = 0;

	setConsoleColor(15);
	std::cout << "\nTask 1";
	std::cout << ".\n-----------------------------------------------\n\n";

	setConsoleColor(9);
	std::cout << "Enter first value (";
	setConsoleColor(15);
	std::cout << "a";
	setConsoleColor(9);
	std::cout << "): ";
	setConsoleColor(15);
	std::cin >> a;
	if (!std::cin) {
		logInfo("warn", INT_EXPECTED_ERROR);
	}
	std::cin.ignore(32767, '\n');

	setConsoleColor(9);
	std::cout << "Enter second value (";
	setConsoleColor(15);
	std::cout << "b";
	setConsoleColor(9);
	std::cout << "): ";
	setConsoleColor(15);
	std::cin >> b;
	if (!std::cin) {
		logInfo("warn", INT_EXPECTED_ERROR);
	}
	std::cin.ignore(32767, '\n');

	setConsoleColor(9);
	std::cout << "Enter third value (";
	setConsoleColor(15);
	std::cout << "c";
	setConsoleColor(9);
	std::cout << "): ";
	setConsoleColor(15);
	std::cin >> c;
	if (!std::cin) {
		logInfo("warn", INT_EXPECTED_ERROR);
	}
	std::cin.ignore(32767, '\n');

	std::cout << "\n";

	sum = a + b + c;

	checkNegative(a);
	std::cout << " + ";
	checkNegative(b);
	std::cout << " + ";
	checkNegative(c);
	std::cout << " = ";

	setConsoleColor(15);
	std::cout << sum << "\n";

	mult = a * b * c;

	checkNegative(a);
	std::cout << " * ";
	checkNegative(b);
	std::cout << " * ";
	checkNegative(c);
	std::cout << " = ";

	setConsoleColor(15);
	std::cout << mult << "\n";

	mean = (a + b + c) / 3.00;

	setConsoleColor(9);
	std::cout << "(";

	checkNegative(a);
	std::cout << " + ";
	checkNegative(b);
	std::cout << " + ";
	checkNegative(c);
	std::cout << ") / ";
	setConsoleColor(15);
	std::cout << "3";
	setConsoleColor(9);
	std::cout << " = ";

	std::cout.precision(3);
	setConsoleColor(15);
	std::cout << mean << "\n\n";

}

void calcSequence()
{
	int number = 0, sum = 0;

	setConsoleColor(15);
	std::cout << "\nTask 2";
	std::cout << ".\n-----------------------------------------------\n\n";

	setConsoleColor(9);
	std::cout << "Enter numbers in sequence (type ";
	setConsoleColor(15);
	std::cout << "999";
	setConsoleColor(9);
	std::cout << " to get result and quit).\n\n";

	while (number != 999)
	{
		sum = sum + number;
		setConsoleColor(9);
		std::cout << "Enter next number: ";
		setConsoleColor(15);
		std::cin >> number;
		if (!std::cin) {
			logInfo("warn", INT_EXPECTED_ERROR);
			break;
		}
		std::cin.ignore(32767, '\n');

	}
	
	setConsoleColor(9);
	std::cout << "\nSum of all numbers in sequence: ";
	setConsoleColor(15);
	std::cout << sum << "\n\n";



}

void countSequence()
{
	setConsoleColor(15);
	std::cout << "\nTask 3";
	std::cout << ".\n-----------------------------------------------\n\n";

	setConsoleColor(9);
	std::cout << "Enter numbers in sequence (type ";
	setConsoleColor(15);
	std::cout << "0";
	setConsoleColor(9);
	std::cout << " to get histogram and quit).\n\n";

	char choice = 'a';
	int counterThree = 0, counterSeven = 0, counterKey = 0;

	while (choice != '0')
	{
		setConsoleColor(9);
		std::cout << "Enter next symbol: ";
		setConsoleColor(15);
		std::cin >> choice;
		if (!std::cin) {
			logInfo("warn", INT_EXPECTED_ERROR);
			break;
		}
		std::cin.ignore(32767, '\n');

		switch (choice) {
			case '3': 
				counterThree++;
				break;
			case '7': 
				counterSeven++;
				break;
			case 'k': 
				counterKey++;
				break;
			case 'K':
				counterKey++;
				break;
			default:
				break;
		}
	}

	setConsoleColor(9);
	std::cout << "\nHistogram:\n";
	std::cout << "-----------------------------------------------\n";
	std::cout << std::left << std::setw(10)  << "Symbol" << std::setw(10) << "Count" << "Starline\n";
	std::cout << "-----------------------------------------------\n";
	setConsoleColor(15);
	
	std::cout << std::setw(10) << std::left << "3" << std::setw(10) << counterThree;
	for (int i = counterThree; i >= 1 ; i--) {
		std::cout << '*';
	}
	std::cout << "\n";

	std::cout << std::setw(10) << "7" << std::setw(10) << counterSeven;
	for (int i = counterSeven; i >= 1; i--) {
		std::cout << '*';
	}
	std::cout << "\n";

	std::cout << std::setw(10) << "K, k" << std::setw(10) << counterKey;
	for (int i = counterKey; i >= 1; i--) {
		std::cout << '*';
	}
	std::cout << "\n";

	setConsoleColor(9);
	std::cout << "-----------------------------------------------\n\n";
	setConsoleColor(7);
}

void drawSnake()
{
	setConsoleColor(15);
	std::cout << "\nTask 4";
	std::cout << ".\n-----------------------------------------------\n\n";
	
	setConsoleColor(3);
	std::cout << "The quality of programmers is a decreasing function of the density of ";
	setConsoleColor(15);
	std::cout << "go to";
	setConsoleColor(3);
	std::cout << " statements in the programs they produce. (c) Edsger W. Dijkstra.\n\n";

	int number = 0;

	setConsoleColor(9);
	std::cout << "Enter number for the sequence: ";
	setConsoleColor(15);
	std::cin >> number;
	if (!std::cin) {
		logInfo("warn", INT_EXPECTED_ERROR);
	}
	std::cin.ignore(32767, '\n');

	setConsoleColor(9);
	std::cout << "\n-----------------------------------------------\n";
	setConsoleColor(15);
	std::cout << "goto";
	setConsoleColor(9);
	std::cout << " snake:\n\n";
	setConsoleColor(15);

	int a = 0, b = 0, c = 0, d = 0;
	drawline:
		printf("*");
		b++;
	if (b < number) goto drawline;
	
	printf("\n");
	
	c = 0;
	if (a % 2) goto left;
	else goto right;


	left:
		printf("*");
		printf("\n");
		c++;
		if (c < number - 2)	goto left;
		else goto nexter;

	right:
		d = 0;
	rightouter:
		c = 0;
	rightinner:
		printf(" ");
		c++;
	
		if (c < number - 1)	goto rightinner;
		printf("*");
		printf("\n");
		d++;
		
		if (d < number - 2)	goto rightouter;
	
	nexter:
	a++;
	b = 0;

	if (a < number ) goto drawline;
	
	drawlastline:
		printf("*");
		b++;
		if (b < number)	goto drawlastline;
		printf("\n");


	setConsoleColor(9);
	std::cout << "\n-----------------------------------------------\n";
	setConsoleColor(15);
	std::cout << "normal";
	setConsoleColor(9);
	std::cout << " snake:\n\n";
	setConsoleColor(15);

	
	for (int i = 0; i < number; i++) {
		for (int i = 0; i < number; i++) {
			std::cout << "*";
		}
		std::cout << "\n";
		if (i % 2) {
			for (int i = 0; i < number - 2; i++) {
				std::cout << "*";
				std::cout << "\n";
			}
		}
		else {
			for (int i = 0; i < number - 2; i++) {
				for (int i = 0; i < number - 1; i++) {
					std::cout << " ";
				}
				std::cout << "*";
				std::cout << "\n";
			}
		} 
	}
	for (int i = 0; i < number; i++) {
		std::cout << "*";
	}
	std::cout << "\n";
	
	setConsoleColor(9);
	std::cout << "-----------------------------------------------\n\n";
	setConsoleColor(15);

}
