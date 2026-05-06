#include <iostream>
#include <cctype>

int	main(int argc, char** argv)
{
	int	i;
	int	j;

	i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE NOICE *\n";
		return (0);
	}
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			std::cout << static_cast<char>(std::toupper(argv[i][j]));
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
