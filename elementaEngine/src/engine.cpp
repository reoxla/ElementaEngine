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
        for (auto const& entity : entities) entity->Update(dt);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("ElementaEngine Calisiyor!", 190, 200, 20, LIGHTGRAY);
        for (auto const& entity : entities) entity->Draw();
        EndDrawing();
    }   
}

void Engine::Stop(){
    for (auto const& entity : entities) delete entity;
    CloseWindow();
}

void Engine::addEntity(Entity* ent){
    entities.push_back(ent);
}

Engine::~Engine(){
    Stop();
}