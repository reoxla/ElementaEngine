#include "raylib.h"
#include "component.h"
#include "engine.h"

#include <iostream>
#include <vector>

int main() {

    {
        Engine engine = Engine();
        Map* scene1 = new Map(BLUE);
        engine.addMap(scene1);

        Entity* Mario = new Entity();

        SpriteComponent* marioSprite = new SpriteComponent("assets/textures/MarioIdle.png", Mario);
        CollisionComponent* marioCollision = new CollisionComponent(Vector2{ 100, 100 }, Vector2{ 0,0 });
        Mario->addComponent(marioSprite);
        Mario->addComponent(marioCollision);

        scene1->addEntity(Mario);
        
        engine.Run();
        engine.Stop();
    }
    return 0;
}