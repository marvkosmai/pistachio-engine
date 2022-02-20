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

#define BIT(x) (1 << x)