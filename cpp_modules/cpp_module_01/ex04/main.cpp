#include <iostream>
#include <fstream>
#include <string>

void	ft_execute(std::string filename, std::string s1, std::string s2)
{
	std::ifstream	in_file;
	std::ofstream	out_file;
	size_t			s1_index = 0;
	std::string		temp;

	in_file.open(filename.c_str());
	if (!in_file.is_open())
	{
		std::cerr << "Error opening the file. Please check the file input and try again" << std::endl;
		exit (1);
	}
	out_file.open((filename + ".replace").c_str(), std::ios::trunc);
	if (!out_file.is_open())
	{
		std::cerr << "Critical error! Error creating the .replac file!" << std::endl;
		return ;
	}

	while (getline(in_file, temp))
	{
		s1_index = temp.find(s1);
		while ((s1_index = temp.find(s1, s1_index)) != std::string::npos)
		{
			temp.erase(s1_index, s1.size());
			temp.insert(s1_index, s2);
			s1_index += s2.length();
		}
		out_file << temp << std::endl;
	}
	in_file.close();
	out_file.close();
}

int	main(int argc, char **argv)
{
	std::string filename;

	if (argc != 4)
	{
		std::cerr << "Argument mismatch. Please enter the argument in the following format: <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	filename = argv[1];
	ft_execute(filename, argv[2], argv[3]);
}