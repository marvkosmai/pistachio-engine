#include <Pistachio.h>

class Sandbox : public Pistachio::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

int main()
{
	Sandbox* sandbox = new Sandbox();
	
	sandbox->Run();

	delete sandbox;

	return 1;
}