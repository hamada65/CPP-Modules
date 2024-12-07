#include <iostream>
#include <fstream>

void ft_replace(std::string &fileName, std::string &s1, std::string &s2) {
	std::ifstream input(fileName.c_str());
	if (!input.is_open())
	{
		std::cout << "Cannot Open File" << std::endl;
		return ;
	}
	std::string outName = fileName + ".replace";
	std::ofstream output(outName.c_str());
	if (!output.is_open())
	{
		std::cout << "Cannot Open output File" << std::endl;
		input.close();
		return ;
	}
	std::string line;
	if (!std::getline(input, line))
		return input.close(), output.close();
	input.seekg(0, std::ios::beg);
	while (std::getline(input, line))
	{
		size_t found = line.find(s1);
		while (s1 != s2 && !s1.empty() && found != std::string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
			found = line.find(s1);
		}
		output << line << "\n";
	}
	output.flush();
	input.close();
	output.close();
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