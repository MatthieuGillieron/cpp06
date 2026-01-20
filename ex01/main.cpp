
#include "Serializer.hpp"

int main()
{
	Data client;
	client.id = 12;

	std::cout << " === CLASSIC OBJET ==="<< std::endl;
	std::cout << "Adress: " << &client << std::endl;
	std::cout << "id: " << client.id << std::endl;

	std::cout << std::endl;

	std::cout << " === SERIALIZE ==="<< std::endl;
	uintptr_t raw = Serializer::serialize(&client);

	std::cout << "Reinterpret adress: " << raw << std::endl;
	std::cout << "id: " << client.id << std::endl;
	
	std::cout << std::endl;

	std::cout << " === DESERIALIZE ==="<< std::endl;
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Reinterpret back adress: " << ptr << std::endl;
	std::cout << "id: " << client.id << std::endl;


	std::cout << std::endl;

	std::cout << " === VERIFICATION ==="<< std::endl;
	if (&client == ptr)
	{
		
		
		std::cout << "Before: " << &client << "   after: " << ptr << std::endl;
		std::cout << "Correct!" << std::endl;
	}	
	else
		std::cout << "[ X ] Dosen't work .." << std::endl;
	

	return 0;
}