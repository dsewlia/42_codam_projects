#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

bool BitcoinExchange::validDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    return true;
}

bool BitcoinExchange::validValue(const std::string& value)
{
    std::stringstream ss(value);
    double v;
    ss >> v;

    if (ss.fail())
        return false;

    if (v < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open database." << std::endl;
        exit(1);
    }

    std::string line;
    getline(file, line);

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string price;

        getline(ss, date, ',');
        getline(ss, price);

        double p = atof(price.c_str());

        _rates[date] = p;
        _dates.push_back(date);
    }

    std::sort(_dates.begin(), _dates.end());
}

std::string BitcoinExchange::closestDate(const std::string& date)
{
	int size = _dates.size() - 1;
    for (int i = size; i >= 0; i--)
    {
        if (_dates[i] <= date) {
            return _dates[i];
		}
    }

    return _dates.front();
}

int BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    getline(file, line);

	std::stringstream firstline(line);
	std::string isDate;
	std::string isValue;
	if (!getline(firstline, isDate, '|') || !getline(firstline, isValue))
	{
		std::cerr << "Error: Bad first line" << std::endl;
		return 1;
	}
	isDate.erase(isDate.find_last_not_of(" ") + 1);
    isValue.erase(0, isValue.find_first_not_of(" "));
	if (isDate != "date" || isValue != "value")
	{
		std::cerr << "Error: Bad first line" << std::endl;
		return 1;		
	}

    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;

        if (!getline(ss, date, '|') || !getline(ss, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date.erase(date.find_last_not_of(" ") + 1);
        value.erase(0, value.find_first_not_of(" "));

        if (!validDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!validValue(value))
            continue;

        double v = atof(value.c_str());
		if (v < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (date < _dates.front())
		{
			std::cerr << "Error: date before inception of data." << std::endl;
			continue;
		}

        std::string closest = closestDate(date);

        double total = _rates[closest] * v;
		if (total > std::numeric_limits<int>::max())
		{
			std::cerr << "Error: too large a number" << std::endl;
			continue;
		}

        std::cout << date << " => " << v << " = " << total << std::endl;
    }
	return 0;
}