#pragma once

#include <vector>

#include "map.h"
#include "raylib.h"

class Engine
{
private:
    std::vector<Map*> maps;
    bool isRunning = false;
public:
    Map* currentMap;
    Engine() : isRunning(false) {}

    void Start();
    void Run();
    void Stop();
    void addMap(Map* map);

    ~Engine(){};
};