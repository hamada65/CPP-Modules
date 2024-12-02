#include <iostream>
#include <cctype>


int main (int ac, char **av)
{
    std::string s;
    if (ac > 1)
    {
        while (*(++av))
        {
            s = (*av);
            for (size_t i = 0; s[i]; i++)
                std::cout << (char) std::toupper(s[i]);
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}