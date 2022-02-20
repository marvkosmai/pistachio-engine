#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pistachio {
	
	class PISTACHIO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define PACO_CORE_TRACE(...)    ::Pistachio::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PACO_CORE_INFO(...)     ::Pistachio::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PACO_CORE_WARN(...)     ::Pistachio::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PACO_CORE_ERROR(...)    ::Pistachio::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PACO_CORE_CRITICAL(...) ::Pistachio::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macro
#define PACO_TRACE(...)         ::Pistachio::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PACO_INFO(...)          ::Pistachio::Log::GetClientLogger()->info(__VA_ARGS__)
#define PACO_WARN(...)          ::Pistachio::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PACO_ERROR(...)         ::Pistachio::Log::GetClientLogger()->error(__VA_ARGS__)
#define PACO_CRITICAL(...)      ::Pistachio::Log::GetClientLogger()->critical(__VA_ARGS__)