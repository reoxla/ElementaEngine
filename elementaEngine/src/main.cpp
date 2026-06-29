#include "raylib.h"
#include "component.h"
#include "engine.h"

#include <iostream>
#include <vector>

int main() {

    {
        Engine engine = Engine();
        engine.Start();

        Entity* Mario = new Entity();
        SpriteComponent* marioSprite = new SpriteComponent("assets/textures/MarioIdle.png", Vector2 {200, 300}, Vector2{300, 500});
        Mario->addComponent(marioSprite);

        engine.addEntity(Mario);
        
        engine.Run();
        engine.Stop();
    }
    return 0;
}