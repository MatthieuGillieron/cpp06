
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{

	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter& val);
		ScalarConverter &operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:

		static void convert(std::string& str);

};

#endif