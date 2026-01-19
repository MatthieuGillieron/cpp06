
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& val);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter(); // a voir si warning ou non
	
	public:
	static void convert(const std::string& str);
};

#endif