#include <vector>
#include "entity.h"
#include "raylib.h"

class Map
{
private:
    
public:
    std::vector<Entity*> entities;

    Color backgroundColor;

    Map(Color bgColor = WHITE);
    ~Map();
    void Update(float deltaTime);
    void Draw();
    void addEntity(Entity* entity);
};
