#pragma once

#include "component.h"

#include <vector>

class Entity
{
public:
    std::vector<Component*> components;
    void addComponent(Component* comp);
    void Update(float deltaTime);
    void Draw();
    ~Entity();
};