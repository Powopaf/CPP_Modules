#include "iter.hpp"
#include <iostream>
#include <string>

void printInt(int *value)
{
	std::cout << *value << ' ';
}

void incrementInt(int *value)
{
	(*value)++;
}

void printString(std::string *value)
{
	std::cout << *value << ' ';
}

void appendBang(std::string *value)
{
	*value += "!";
}

int main()
{
	int numbers[] = {1, 2, 3, 4, 5};
	int *numberPtr = numbers;

	std::cout << "ints: ";
	iter(numberPtr, 5, printInt);
	std::cout << std::endl;

	iter(numberPtr, 5, incrementInt);
	std::cout << "ints after increment: ";
	iter(numberPtr, 5, printInt);
	std::cout << std::endl;

	std::string words[] = {"hello", "iter", "test"};
	std::string *wordPtr = words;

	std::cout << "strings: ";
	iter(wordPtr, 3, printString);
	std::cout << std::endl;

	iter(wordPtr, 3, appendBang);
	std::cout << "strings after append: ";
	iter(wordPtr, 3, printString);
	std::cout << std::endl;

	return 0;
}