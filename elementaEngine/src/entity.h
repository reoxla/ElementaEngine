#pragma once

#include <vector>

class Component;

class Entity
{
public:
    std::vector<Component*> components;
    void addComponent(Component* comp);
    void Update(float deltaTime);
    void Draw();
    Entity();
    ~Entity();
};