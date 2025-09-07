#pragma once

#ifdef LU_PLATFORM_WINDOWS

extern Lunar::Application* Lunar::CreateApplication();
	
int main(int argc, char* argv[])
{
	Lunar::Log::Init();
	LU_CORE_WARN("Initialized Log!");
	LU_INFO("Welcome to Lunar Engine!");
	auto app = Lunar::CreateApplication();
	app->Run();
	delete app;
}

#endif