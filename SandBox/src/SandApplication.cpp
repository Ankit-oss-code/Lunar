#include "Lunar.h"

class SandApplication : public Lunar::Application
{
	public:
	SandApplication()
	{
	}
	~SandApplication()
	{
	}
};

Lunar::Application* Lunar::CreateApplication()
{
	return new SandApplication();
}