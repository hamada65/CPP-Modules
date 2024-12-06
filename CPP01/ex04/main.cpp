#include <iostream>
#include <fstream>

void ft_replace(std::string &fileName, std::string &s1, std::string &s2) {
	std::ifstream input(fileName.c_str());
	if (!input.is_open())
	{
		std::cout << "Cannot Open File" << std::endl;
		return ;
	}
	std::string line;
	if (!std::getline(input, line))
		return input.close();
	input.seekg(0, std::ios::beg);
	// std::cout << fileName + " Opened Succes" << std::endl;
	while (std::getline(input, line))
	{
		std::cout << line << std::endl;
	}
	input.close();
	(void)s1;
	(void)s2;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "ARGS ERROR ! \n";
		std::cout << "Usage : ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string fileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	ft_replace(fileName, s1, s2);
	return 0;
}