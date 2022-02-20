#pragma once

#ifdef PACO_PLATFORM_WINDOWS

extern Pistachio::Application* Pistachio::CreateApplication();

int main(int argc, char** argv)
{
	Pistachio::Log::Init();
	PACO_CORE_INFO("Welcome to Pistachio Engine!");

	auto app = Pistachio::CreateApplication();
	app->Run();
	delete app;
}

#endif