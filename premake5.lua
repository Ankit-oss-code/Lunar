workspace "Lunar"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Lunar"
    location "Lunar"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "$(SolutionDir)Lunar/vendor/spdlog/include"
    }


    filter "system:windows"
        buildoptions { "/utf-8" }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LU_PLATFORM_WINDOWS",
            "LU_BUILD_DLL"
        }


    filter "configurations:Debug"
        defines "LU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LU_RELEASE"    
        optimize "On"
    
    filter "configurations:Dist"
        defines "LU_DIST"
        optimize "On"  


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "$(SolutionDir)Lunar/vendor/spdlog/include/",
        "Lunar/src"
    }


    links
    {
        "Lunar"
    }
    filter "system:windows"
        buildoptions { "/utf-8" } 

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LU_PLATFORM_WINDOWS",
        }


    filter "configurations:Debug"
        defines "LU_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LU_RELEASE"    
        optimize "On"
    
    filter "configurations:Dist"
        defines "LU_DIST"
        optimize "On"  

    