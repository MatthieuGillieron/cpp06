
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>


Base* generate(void)
{
	int random = rand() % 3;
	
	if (random == 0)
	{
		std::cout << "Random choice: A" << std::endl;
		return new A();
	}

	else if (random == 1)
	{
		std::cout << "Random choice: B" << std::endl;
		return new B();
	}

	else
	{
		std::cout << "Random choice: C" << std::endl;
		return new C();
	}
}



void identify(Base* p)
{
	A* resultA = dynamic_cast<A*>(p);
	if (resultA != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}

	B* resultB = dynamic_cast<B*>(p);
	if (resultB != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	
	C* resultC = dynamic_cast<C*>(p);
	if (resultC != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p)
{

}

int main()
{
	
	srand(time(0));

	Base* obj = generate();
	Base* obj2 = generate();

	identify(obj);
	identify(obj2);

	delete obj;
	delete obj2;

	return 0;
}