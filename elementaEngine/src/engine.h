#pragma once

#include <vector>

#include "entity.h"
#include "raylib.h"

class Engine
{
private:
    std::vector<Entity*> entities;
    bool isRunning = false;
public:
    Engine() : isRunning(false) {}

    void Start();
    void Run();
    void Stop();
    void addEntity(Entity* ent);

    ~Engine();
};