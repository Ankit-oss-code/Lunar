#pragma once

#ifdef LU_PLATFORM_WINDOWS

extern Lunar::Application* Lunar::CreateApplication();
	
int main(int argc, char* argv[])
{

	auto app = Lunar::CreateApplication();
	app->Run();
	delete app;
}

#endif