workspace "ElementaEngineProjesi"
    architecture "x64"
    configurations { "Debug", "Release" }

    targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")
    objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}")

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    project "ElementaEngine"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "Off"

        -- Burayı doğrudan senin klasör adın olan küçük harfli elementaEngine yaptık
        files {
            "elementaEngine/src/**.h",
            "elementaEngine/src/**.cpp"
        }

        includedirs {
            "elementaEngine/src"
        }

        filter "system:linux"
            links { "raylib", "GL", "m", "pthread", "dl", "rt", "X11" }

        filter "system:windows"
            links { "raylib", "opengl32", "gdi32", "winmm" }