#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    btc.loadDatabase("data.csv");

	int result = btc.processInput(argv[1]);

    return result;
}