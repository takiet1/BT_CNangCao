#include <iostream>
#include <string>
#include <memory> // for std::unique_ptr

struct Resource
{
	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	
	std::string getData() { return "I'm data"; }
};

int main()
{
	std::unique_ptr<Resource> res(new Resource);

	if (res) // use implicit cast to bool to ensure res contains a Resource
		std::cout << (*res).getData() << std::endl;

	return 0;
}