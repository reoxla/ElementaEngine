#pragma once

#include <vector>

#include "map.h"
#include "gui.h"
#include "raylib.h"
#include <imgui.h>
#include <rlImGui.h>

class Engine
{
private:
    std::vector<Map*> maps;
    bool isRunning = false;
	bool debugMode = false;
public:
    Map* currentMap;
    Engine();

    void Start();
    void Run();
    void Stop();
    void addMap(Map* map);

    ~Engine(){};
};