#pragma once

#include "raylib.h"

#include <string>

class Component
{
public:
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    virtual ~Component() = default;
};

class SpriteComponent : public Component
{
private:
    Texture2D tex;
    Vector2 pos;
    Rectangle scaleRec;
public:
    SpriteComponent(std::string texPathI, Vector2 posI, Vector2 scaleI);
    ~SpriteComponent() override;
    void Draw() override;
    void Update(float deltaTime) override {};
};