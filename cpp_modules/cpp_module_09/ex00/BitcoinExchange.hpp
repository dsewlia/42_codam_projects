#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>

class BitcoinExchange
{
private:
    std::unordered_map<std::string, double> _rates;
    std::vector<std::string> _dates;

public:
    BitcoinExchange();

    void loadDatabase(const std::string& filename);
    int processInput(const std::string& filename);

    bool validDate(const std::string& date);
    bool validValue(const std::string& value);

    std::string closestDate(const std::string& date);
};
