#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
    public:
        static void convert(const std::string& literal);
    private:
        // Prevent instantiation: declare canonical form special members as private
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter&);
};

#endif