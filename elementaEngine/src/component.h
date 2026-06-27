#pragma once

#include "raylib.h"

class Component
{
public:
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    virtual ~Component() = default;
};

class ScriptComponent : public Component
{
private:
    Texture2D tex;
    const char* texPath;
    Vector2 pos;
    Vector2 scale;
public:
    ScriptComponent(Texture2D texI, Vector2 posI, Vector2 scaleI);
    ~ScriptComponent();
};


