workspace "Pistachio"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Pistachio/vendor/GLFW/include"
IncludeDir["GLAD"] = "Pistachio/vendor/GLAD/include"
IncludeDir["GLM"] = "Pistachio/vendor/GLM"
IncludeDir["ImGui"] = "Pistachio/vendor/imgui"
IncludeDir["FastNoise2"] = "Pistachio/vendor/FastNoise2/include"

group "Dependencies"
	include "Pistachio/vendor/GLFW"
	include "Pistachio/vendor/GLAD"
	include "Pistachio/vendor/imgui"
	include "Pistachio/vendor/FastNoise2"

group ""

project "Pistachio"
	location "Pistachio"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pacopch.h"
	pchsource "Pistachio/src/pacopch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.GLM}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.FastNoise2}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"FastNoise2",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"PACO_PLATFORM_WINDOWS",
			"PACO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "PACO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PACO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PACO_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Pistachio/vendor/spdlog/include",
		"Pistachio/src",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"Pistachio"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"PACO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PACO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PACO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PACO_DIST"
		runtime "Release"
		optimize "On"