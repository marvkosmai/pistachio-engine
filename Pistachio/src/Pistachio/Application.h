#pragma once

#include "Pistachio/Core.h"
#include "Pistachio/Window.h"
#include "Pistachio/LayerStack.h"
#include "Pistachio/Events/Event.h"
#include "Pistachio/Events/ApplicationEvent.h"

namespace Pistachio {

	class PISTACHIO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}