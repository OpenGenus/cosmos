#include <iostream>
#include <memory>
using namespace std;

class IFlyBehavior
{
public :
	virtual ~IFlyBehavior(){}
	virtual void fly() = 0;
};

class FlyWithWings : public IFlyBehavior
{
public :
	void fly()
	{
		cout << "I fly with wings!" << endl;
	}	
};

class FlyNoWay : public IFlyBehavior
{
public :
	void fly() 
	{
		cout << "I don't fly, buddy." << endl;
	}
};

class IQuackBehavior 
{
public :
	virtual ~IQuackBehavior(){}
	virtual void quack() = 0;
};

class Quack : public IQuackBehavior
{
public :
	void quack()
	{
		cout << "Quack!" << endl;
	}
};

class Squeak : public IQuackBehavior
{
public :
	void quack() 
	{
		cout << "Squeak!" << endl;
	}
};

class MuteQuack : public IQuackBehavior
{
public :
	void quack()
	{
		cout << "I'm a mute duck." << endl;
	}
};

class Duck 
{
public :
	
	Duck()
	{
		flyBehavior = new FlyNoWay();
		quackBehavior = new Quack();
	}

	void setFlyBehavior(IFlyBehavior* fb)
	{
		flyBehavior = fb;
	}
	
	void setQuackBehavior(IQuackBehavior* qb)
	{
		quackBehavior = qb;
	}
	
	void performFly()
	{
		flyBehavior->fly();
	}
	
	void performQuack()
	{
		quackBehavior->quack();
	}
	
	virtual void display() 
	{
		cout << "I'm a generic duck!" << endl;
	}
    
    ~Duck() 
    {
        delete flyBehavior;
        delete quackBehavior;
    }
protected :
	IFlyBehavior* flyBehavior;
	IQuackBehavior* quackBehavior;
};

class FlyingQuackingDuck : public Duck
{
public :
		FlyingQuackingDuck() 
		{
			flyBehavior = new FlyWithWings();
			quackBehavior = new Quack();
		}
		void display()
		{
			cout << "I'm a flying quacking duck!" << endl;
		}
};

class MuteFlylessDuck : public Duck
{
public :
		MuteFlylessDuck() 
		{
			flyBehavior = new FlyNoWay();
			quackBehavior = new MuteQuack();
		}
		void display()
		{
			cout << "I'm a flyless mute duck." << endl;
		}
};

int main() {
	FlyingQuackingDuck coolDuck;
	MuteFlylessDuck nietzsche;

	coolDuck.display();
	coolDuck.performQuack();
	coolDuck.performFly();
	
	nietzsche.display();
	nietzsche.performQuack();
	nietzsche.performFly();
	return 0;
}
