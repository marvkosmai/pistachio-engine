#pragma once

#ifdef PACO_PLATFORM_WINDOWS
	#ifdef PACO_BUILD_DLL
		#define PISTACHIO_API __declspec(dllexport)
	#else
		#define PISTACHIO_API __declspec(dllimport)
	#endif
#else
	#error Pistachio only supports Windows!
#endif

#ifdef PACO_ENABLE_ASSERTS
	#define PACO_CORE_ASSERT(x, ...) { if(!(x)) { PACO_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define PACO_ASSERT(x, ...) { if(!(x)) { PACO_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define PACO_CORE_ASSERT(x, ...)
	#define PACO_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)