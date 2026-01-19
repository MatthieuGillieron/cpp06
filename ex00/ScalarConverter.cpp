
#include "ScalarConverter.hpp"


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



// === UTILS === 

static bool isSpecial(const std::string& str)
{

	if (str == "nan" || str == "nanf")
		return true;
	if (str == "inf"|| str == "inff" || str == "+inf" || str == "+inff")
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



// === METHODE ===

void ScalarConverter::convert(const std::string& str)
{
	
	if (isSpecial(str) == true)
	{
		std::cout << "special car. " << std::endl;
		return;
	}
	
	if (str[0] == 39 && str[str.length() -1] == 39)
	{
		std::cout << "its a char" << std::endl;
		return;
	}
    
	if (isValidFloat(str))
	{
		std::cout << "it's a float" << std::endl;
		return;
	}

	if (isValidDouble(str))
	{
		std::cout << "it's a double" << std::endl;
		return;
	}
	
	if (isValidInt(str))
	{
		std::cout << "it's an int" << std::endl;
		return;
	}

	else
		std::cout << "invalid input" << std::endl;
    
}
