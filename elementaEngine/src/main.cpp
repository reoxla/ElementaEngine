#include "raylib.h"
#include "component.h"

#include <iostream>
#include <vector>










int main() {

    {
        Engine engine = Engine();
        engine.Start();
        engine.Run();
        engine.Stop();
    }
    return 0;
}