#pragma once

#include "Pistachio/Layer.h"

#include "Pistachio/Events/KeyEvent.h"
#include "Pistachio/Events/MouseEvent.h"
#include "Pistachio/Events/ApplicationEvent.h"

namespace Pistachio {

	class PISTACHIO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}