#include "engine.h"

void Engine::Start(){
    InitWindow(800,800, "ElementaEngine");
    SetTargetFPS(60);
    isRunning = true;
}

void Engine::Run(){
    while (isRunning && !WindowShouldClose())
    {
        float dt = GetFrameTime();
        for (auto const& map : maps) map->Update(dt);

        BeginDrawing();

        ClearBackground(currentMap->backgroundColor);

        for (auto const& map : maps) map->Draw();

        EndDrawing();
    }   
}

void Engine::Stop(){
    for (auto const& map : maps){
        if (map != nullptr)
        {
            delete map;
        }
        
    }
    CloseWindow();
}

void Engine::addMap(Map* map){
    maps.push_back(map);
}