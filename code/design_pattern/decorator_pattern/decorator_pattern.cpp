#include <iostream>
#include <string>

class IBeverage
{
public :
    IBeverage() 
    {
        description = "Unkown beverage";
    }
    virtual std::string getDescription()
    {
        return description;
    }
    virtual double cost() = 0;
protected :
    std::string description;
};

class HouseBlend : public IBeverage
{
public :
    HouseBlend()
    {
        description = "House Blend Coffee";
    }
    
    double cost()
    {
        return 0.89;
    }
};

class CondimentDecorator : public IBeverage
{
public :
    CondimentDecorator(IBeverage* bw)
    {
        this->beverageWrapper = bw;
    }
    
    std::string getDescription()
    {
        return this->beverageWrapper->getDescription();
    }

    double cost()
    {
        return this->beverageWrapper->cost();    
    }
    
    ~CondimentDecorator()
    {
        delete beverageWrapper;
    }
private :
    IBeverage* beverageWrapper;
};

class Mocha : public CondimentDecorator
{
public :
    Mocha(IBeverage* beverage) : CondimentDecorator(beverage) {}

    std::string getDescription()
    {
        return CondimentDecorator::getDescription() + ", Mocha ";
    }

    double cost()
    {
        return 0.20 + CondimentDecorator::cost();
    }
};

class Whip : public CondimentDecorator
{
public :
    Whip(IBeverage* beverage) : CondimentDecorator(beverage) {}

    std::string getDescription()
    {
        return CondimentDecorator::getDescription() + ", Whip ";
    }

    double cost()
    {
        return 0.10 + CondimentDecorator::cost();
    }
};

int main() 
{
    IBeverage* beverage = new HouseBlend();
    std::cout << beverage->getDescription() + " $" << beverage->cost() << std::endl;
    beverage = new Mocha(beverage);
    std::cout << beverage->getDescription() + " $" << beverage->cost() << std::endl;
    beverage = new Whip(beverage);
    std::cout << beverage->getDescription() + " $" << beverage->cost() << std::endl;
    return 0;
}
