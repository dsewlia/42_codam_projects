#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
    std::string str1 = str;

    /* **** If it is a char literal, store it's ascii value as a the string, else keep the string as is *****/
    if (str.length() == 1 && !std::isdigit(str[0])) {
        str1 = std::to_string(static_cast<int>(str[0]));
    }

	/* **** Sanity checks to see if conversion should be possible. eg: 42a, 42.0ff, etc should result in impossible conversion **** */
	int left = 0;
	while (str1[left] == ' ' || str1[left] == '\t' || str1[left] == '\n')
		left++;
	str1 = str1.substr(left);
	int right = str1.size() - 1;
	while ((str1[right] == ' ' || str1[right] == '\t' || str1[right] == '\n') && right >= 0)
		right--;
	if (right >= 0)
		str1 = str1.substr(0, right + 1);
	int dotCount = 0;
	int charCount = 0;
	int intCount = 0;
	bool possible = true;
	for (size_t i = 0; i < str1.size(); i++)
	{
		if (std::isdigit(str1[i]))
			intCount++;
		else if (str1[i] == '.')
			dotCount++;
		else if (i == 0 && (str1[i] == '+' || str1[i] == '-'))
			continue;
		else
			charCount++;
	}
	if (str1.size() > 0) {
		if (str1[str1.size() - 1] == 'f')
			charCount--;
	}
	if (dotCount > 1 || (charCount > 0 && intCount > 0) || (dotCount == 1 && charCount > 0))
	{
		if (!(str1 == "inf" || str1 == "+inf" || str1 == "nan" || str1 == "-nan" || str1 == "-inf" || str1 == "+nan" ||
				str1 == "inff" || str1 == "+inff" || str1 == "nanf" || str1 == "-nanf" || str1 == "-inff" || str1 == "+nanf"))
			possible = false;
	}

    /* **** CONVERSION TO CHAR **** */
    try {
		if (!possible) {
			std::cout << "char: impossible" << std::endl;
		}
		else {
			double value = std::stod(str1);

			/* **** Checks if it is +/-inf, nan, not a valid ascii char and if it is a float number **** */
			if (std::isinf(value) || std::isnan(value) || value < 0 || value > 127 || std::floor(value) != value) {
				std::cout << "char: impossible" << std::endl;
			} else {
				char c = static_cast<char>(value);

				/* **** Checks if it is displayable **** */
				if (std::isprint(static_cast<unsigned char>(c)) && !std::isspace(static_cast<unsigned char>(c))) {
					std::cout << "char: '" << c << "'" <<  std::endl;
				} else {
					std::cout << "char: Non Displayable" << std::endl;
				}
			}
		}
    } catch (std::exception &e) {
        (void) e;

        /* **** if conversion to double throws an exception **** */
        std::cout << "char: impossible" << std::endl;
    }

    /* **** CONVERSION TO INT **** */
    try {
		if (!possible) {
			std::cout << "int: impossible" << std::endl;
		} else {
			int i = std::stoi(str1);
			std::cout << "int: " << i << std::endl;
		}
    } catch(std::exception &e) {
        (void) e;

        /* **** if conversion to int throws an exception **** */
        std::cout << "int: impossible" << std::endl;
    }

    /* **** CONVERSION TO FLOAT **** */
    try {
		if (!possible) {
			std::cout << "float: impossible" << std::endl;
		} else {
			float f = std::stof(str1);

			/* **** checks if it is NaN **** */
			if (std::isnan(f)) {
				std::cout << "float: nanf" << std::endl;
			}
			/* **** checks if it is +/-inf **** */ 
			else if (std::isinf(f)) {
				if (f > 0) {
					std::cout << "float: inff" << std::endl;
				} else {
					std::cout << "float: -inff" << std::endl;
				}
			} else {
				std::cout << "float: " << f;

				/* **** checks if it is an integer, avoid using fixed/setprecision as if changes the flag for the stream and have to manually reset it **** */
				if (std::floor(f) == f) {
					std::cout << ".0f" << std::endl;
				} else {
					std::cout << "f" << std::endl;
				}
			}
		}
    } catch(std::exception &e) {
        (void) e;

        /* **** if conversion to float throws an exception **** */
        std::cout << "float: impossible" << std::endl;
    }

    /* **** CONVERSION TO DOUBLE **** */
    try {
		if (!possible) {
			std::cout << "double: impossible" << std::endl;
		} else {
			double d = std::stod(str1);

			/* **** checks if it is NaN **** */
			if (std::isnan(d)) {
				std::cout << "double: nan" << std::endl;
			} 
			/* **** checks if it is +/-inf **** */ 
			else if (std::isinf(d)) {
				if (d > 0) {
					std::cout << "double: inf" << std::endl;
				} else {
					std::cout << "double: -inf" << std::endl;
				}
			} else {
				std::cout << "double: " << d;

				/* **** checks if it is an integer, avoid using fixed/setprecision as if changes the flag for the stream and have to manually reset it **** */
				if (std::floor(d) == d) {
					std::cout << ".0" << std::endl;
				} else {
					std::cout << std::endl;
				}
			}
		}
    } catch (std::exception &e) {
        (void) e;

        /* **** if conversion to double throws an exception **** */
        std::cout << "double: impossible" << std::endl;
    }
}