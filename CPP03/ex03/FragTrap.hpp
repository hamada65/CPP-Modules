#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string &name);
        FragTrap(const FragTrap &source);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &source);
        
        void highFivesGuys(void);
};

#endif