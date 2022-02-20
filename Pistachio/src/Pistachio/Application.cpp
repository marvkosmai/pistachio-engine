#include "pacopch.h"
#include "Application.h"

#include "Pistachio/Events/ApplicationEvent.h"
#include "Pistachio/Log.h"

namespace Pistachio {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		PACO_TRACE(e);

		while (true);
	}
}