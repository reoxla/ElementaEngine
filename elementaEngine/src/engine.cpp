#include "engine.h"
#include "component.h"

Engine::Engine() : isRunning(false), currentMap(nullptr){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 800, "ElementaEngine");
    SetTargetFPS(60);
    rlImGuiSetup(true);
    isRunning = true;
}

void Engine::Run(){
    while (isRunning && !WindowShouldClose())
    {
		if (currentMap == nullptr && !maps.empty())
		{
			currentMap = maps[0];
		}

        float dt = GetFrameTime();
        for (auto const& map : maps) map->Update(dt);

		if (GetKeyPressed() == KEY_F1) debugMode = !debugMode;
		if (debugMode == true) {
			DrawFPS(10, 10);
            for each(Entity* en in currentMap->entities)
            {
                for each(Component* com in en->components) {
                    if (CollisionComponent* collisionCom = dynamic_cast<CollisionComponent*>(com)) {
                        collisionCom->drawCollisionBox = true;
                    }
                }
            }
		}

        else
        {
            for each(Entity * en in currentMap->entities)
            {
                for each(Component * com in en->components) {
                    if (CollisionComponent* collisionCom = dynamic_cast<CollisionComponent*>(com)) {
                        collisionCom->drawCollisionBox = false;
                    }
                }
            }
        }

        BeginDrawing();

        rlImGuiBegin();



        rlImGuiEnd();

        if (currentMap != nullptr)
        {
            ClearBackground(currentMap->backgroundColor);

            for (auto const& map : maps) map->Draw();
        }
        else
        {
            printf("No current map set. Please set a current map before running the engine.\n");
            ClearBackground(BLACK);
        }

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
    rlImGuiShutdown();
    CloseWindow();
}

void Engine::addMap(Map* map){
    maps.push_back(map);
}