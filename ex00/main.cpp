
#include "ScalarConverter.hpp"

int main()
{

	// === VALID TEST ===
	std::cout << "test 1 -> single char" << std::endl;
	ScalarConverter::convert("'a'");   
	std::cout << std::endl;

	std::cout << "test 2 ->  all char" << std::endl;
	ScalarConverter::convert("'ad1212~~c'");   
	std::cout << std::endl;

	std::cout << "test 3 -> special" << std::endl;
	ScalarConverter::convert("inf");   
	std::cout << std::endl;


	std::cout << "test 4 -> special + sign" << std::endl;
	ScalarConverter::convert("-inf");   
	std::cout << std::endl;

	std::cout << "test 5 -> float" << std::endl;
	ScalarConverter::convert("25.07f");   
	std::cout << std::endl;


	std::cout << "test 6 -> double" << std::endl;
	ScalarConverter::convert("25.07");   
	std::cout << std::endl;

	std::cout << "test 7 -> int" << std::endl;
	ScalarConverter::convert("25");   
	std::cout << std::endl;


	std::cout << " === INVALID TEST [START] === " << std::endl;

	// INVALID TEST

	std::cout << "test 1 -> invalid input" << std::endl;
	ScalarConverter::convert("n8n");   
	std::cout << std::endl;

	std::cout << "test 2 -> invalid char" << std::endl;
	ScalarConverter::convert("'salut");   
	std::cout << std::endl;

	std::cout << "test 3 -> invalid double" << std::endl;
	ScalarConverter::convert(".25");   
	std::cout << std::endl;

	std::cout << "test 4 -> invalid double" << std::endl;
	ScalarConverter::convert("25.");   
	std::cout << std::endl;

	std::cout << "test 5 -> invalid float" << std::endl;
	ScalarConverter::convert("f2.5");   
	std::cout << std::endl;

	std::cout << "test 3 -> invalid float" << std::endl;
	ScalarConverter::convert("25.f");   
	std::cout << std::endl;

	return 0;
}