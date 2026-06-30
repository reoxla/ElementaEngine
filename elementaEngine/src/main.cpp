#include "raylib.h"
#include "component.h"
#include "engine.h"

#include <iostream>
#include <vector>

int main() {

    {
        Engine engine = Engine();
        engine.Start();

        SpriteComponent* marioSprite = new SpriteComponent("assets/textures/MarioIdle.png", Vector2 {200, 300}, 0.2f);

        Entity* Mario = new Entity();        
        Mario->addComponent(marioSprite);

        Map* scene1 = new Map(BLACK);
        scene1->addEntity(Mario);

        engine.addMap(scene1);
        
        engine.Run();
        engine.Stop();
    }
    return 0;
}