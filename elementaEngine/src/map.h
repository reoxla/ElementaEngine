#include <vector>
#include "entity.h"

class Map
{
private:
    std::vector<Entity*> entities;
    
public:
    Color backgroundColor;

    Map(Color bgColor);
    ~Map();
    void Update(float deltaTime) {};
    void Draw();
    void addEntity(Entity* entity);
};
