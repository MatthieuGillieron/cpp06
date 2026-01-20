
#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>    // Pour atoi, atof
#include <cctype>     // Pour isdigit


// === CONSTRUCTOR ===

ScalarConverter::ScalarConverter()
{
	// non-instaciable class
};

ScalarConverter::ScalarConverter(const ScalarConverter& val)
{
	// non-instaciable class
	(void)val;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	// non-instaciable class
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	// non-instaciable class
};



// === PARSING === 

static bool isSpecial(const std::string& str)
{

	if (str == "nan" || str == "nanf")
		return true;
	if (str == "inf"|| str == "inff" || str == "+inf" || str == "+inff")
		return true;
	if (str == "-inf"|| str == "-inff")
		return true;
	
	return false;

}


static bool isValidInt(const std::string& str)
{
	if (str.empty())
		return false;

	size_t flag = 0;

	if (str[0] == '-' || str[0] == '+')
		flag = 1;
	
	if (flag >= str.length())
		return false;
			
	for (size_t i = flag;  i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;

	}	
	
	return true;
}


static bool isValidDouble(const std::string& str)
{

	if (str.empty())
		return false;

	size_t flag = 0;
	size_t count = 0;
	
	if (str[0] == '-' || str[0] == '+')
		flag = 1;
	
	if (flag >= str.length())
		return false;
	
	if (str[flag] == '.' || str[str.length() -1] == '.')
		return false;

	for (size_t i = flag; i < str.length(); i++)
	{
		if (str[i] == '.')
			count++;
		if (!isdigit(str[i]) && str[i] != '.')
			return false;
	}

	if (count != 1)
		return false;

	return true;
}



static bool isValidFloat(const std::string& str)
{


	if (str.empty())
		return false;

	size_t flag = 0;
	size_t count = 0;
	
	if (str[0] == '-' || str[0] == '+')
		flag = 1;
	
	if (str.length() < 4)
		return false;
	
	if (str[flag] == '.' || str[str.length() -2] == '.' || str[str.length() -1] != 'f') 
		return false;


	for (size_t i = flag; i < str.length() -1; i++)
	{
		if (str[i] == '.')
			count++;
		if (!isdigit(str[i]) && str[i] != '.')
			return false;
	}

	if (count != 1)
		return false;

	return true;
}



// === DISPLAY ===

static void displayChar(int value)
{
	std::cout << "char: ";

	if (value < 0 || value > 127)
		std::cout << "impossible";
	else if (value < 32 || value == 127)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";

	std::cout << std::endl;
}

static void displayInt(int intValue)
{
	std::cout << "int: " << intValue << std::endl;
}

static void displayFloat(float floatValue)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << floatValue  << "f" << std::endl;
}

static void displayDouble(double doubleValue)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << doubleValue << std::endl;
}



// === METHODE ===

void ScalarConverter::convert(const std::string& str)
{
	
	if (isSpecial(str) == true)
	{
		std::cout << "special car. " << std::endl;
		return;
	}
	
	if (str[0] == 39 && str[str.length() -1] == 39 && str.length() == 3)
	{
		int value = str[1];

		displayChar(value);
		displayInt(value);
		displayFloat(static_cast<float>(value));
		displayDouble(static_cast<double>(value));

		return;
	}
    
	if (isValidFloat(str))
	{
		float value = static_cast<float>(atof(str.c_str()));

		displayChar(static_cast<int>(value));
		displayInt(static_cast<int>(value));
		displayFloat(value);
		displayDouble(static_cast<double>(value));

		return;
	}

	if (isValidDouble(str))
	{
		double value = atof(str.c_str());

		displayChar(static_cast<int>(value));
		displayInt(static_cast<int>(value));
		displayFloat(static_cast<float>(value));
		displayDouble(value);

		return;
	}
	
	if (isValidInt(str))
	{
		int value = atoi(str.c_str());
		
		displayChar(value);
		displayInt(value);
		displayFloat(static_cast<float>(value));
		displayDouble(static_cast<double>(value));

		return;
	}

	else
		std::cout << "invalid input" << std::endl;
    
}

