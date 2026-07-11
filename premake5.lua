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

    -- 1. ImGui + rlImGui Static Library Project
    -- This compiles the docking branch dependency once, keeping your main compilation fast.
    project "ImGui"
        kind "StaticLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "Off"

        files {
            -- Core ImGui source files
            "dependencies/imgui/imgui.cpp",
            "dependencies/imgui/imgui_draw.cpp",
            "dependencies/imgui/imgui_tables.cpp",
            "dependencies/imgui/imgui_widgets.cpp",
            "dependencies/imgui/imgui_demo.cpp",
            
            -- The rlImGui backend bridge implementation file
            "dependencies/rlImGui/rlImGui.cpp"
        }

        includedirs {
            "dependencies/imgui",
            "dependencies/rlImGui"
        }

        filter "system:linux"
            -- Linux requires knowing where system raylib headers are if they aren't global
            -- Omit or change if your setup uses package managers like apt or pacman
            externalincludedirs { "/usr/include" } 

        filter "system:windows"
            -- Tell the ImGui static library where your local raylib headers live
            externalincludedirs { "dependencies/include" }

    -- 2. Your Main Engine Project
    project "ElementaEngine"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "Off"

        files {
            "elementaEngine/src/**.h",
            "elementaEngine/src/**.cpp"
        }

        -- Let your main codebase discover engine, imgui, and rlImGui headers
        includedirs {
            "elementaEngine/src",
            "dependencies/imgui",
            "dependencies/rlImGui"
        }

        -- Automatically link the static ImGui library we built above
        links { "ImGui" }

        filter "system:linux"
            links { "raylib", "GL", "m", "pthread", "dl", "rt", "X11" }

        filter "system:windows"
            includedirs { "dependencies/include" }
            libdirs { "dependencies/lib" }
            
            links { "raylib", "opengl32", "gdi32", "winmm" }