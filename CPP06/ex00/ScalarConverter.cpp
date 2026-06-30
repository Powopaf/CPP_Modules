#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static bool stringToInt(const std::string& str, int& i) {
    std::stringstream ss(str);
    ss >> i;
    return ss && ss.eof();
}

static bool stringToDouble(const std::string& str, double& d) {
    std::stringstream ss(str);
    ss >> d;
    return ss && ss.eof();
}

static bool stringToFloat(const std::string& str, float& f) {
    std::string s = str;
    if (s[s.size() - 1] != 'f')
        return false;
    s.erase(s.size() - 1);
    std::stringstream ss(s);
    ss >> f;
    return ss && ss.eof();
}

static std::string formatFloat(float value) {
    std::ostringstream oss;
    float integerPart;

    if (std::modf(value, &integerPart) == 0.0f)
        oss << std::fixed << std::setprecision(1) << value;
    else
        oss << value;
    oss << 'f';
    return oss.str();
}

static std::string formatDouble(double value) {
    std::ostringstream oss;
    double integerPart;

    if (std::modf(value, &integerPart) == 0.0)
        oss << std::fixed << std::setprecision(1) << value;
    else
        oss << value;
    return oss.str();
}

static void display(float f, int i, double d, char c) {
    if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << formatFloat(f) << std::endl;
    std::cout << "double: " << formatDouble(d) << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
    float fval = 0.0f;
    int ival = 0;
    double dval = 0.0;
    char cval = 0;
    if (literal == "nan") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    else if (literal == "+inf" || literal == "-inf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    else if (literal.find("f") != std::string::npos) {
        if (!stringToFloat(literal, fval)) {
            std::cout << "Can't convert the literal to float" << std::endl;
            return;
        }
        ival = static_cast<int>(fval);
        dval = static_cast<double>(fval);
        cval = static_cast<char>(fval);
    }
    else if (literal.find(".") != std::string::npos) {
        if (!stringToDouble(literal, dval)) {
            std::cout << "Can't convert the literal to double" << std::endl;
            return;
        }
        ival = static_cast<int>(dval);
        fval = static_cast<float>(dval);
        cval = static_cast<char>(dval);
    }
    else {
        if (!stringToInt(literal, ival)) {
            std::cout << "Can't convert literal to int" << std::endl;
            return;
        }
        fval = static_cast<float>(ival);
        dval = static_cast<double>(ival);
        cval = static_cast<char>(ival);
    }
    display(fval, ival, dval, cval);
}