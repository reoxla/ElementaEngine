#pragma once

#include "raylib.h"

#include <string>

class Entity;

class Component
{
public:

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;
    virtual ~Component() = default;
    Entity* ownedEntity;

};

class BaseComponent : public Component
{
public:
    Vector2 position;
    Vector2 scale;
    float rotation;

	BaseComponent();
	~BaseComponent();
    void Update(float deltaTime) {};
    void Draw() {};

private:

};

class SpriteComponent : public Component
{
private:
    Texture2D tex;
    Vector2 pos;
    Vector2 scale;
    float rotation;
    BaseComponent* base;
public:
    SpriteComponent(std::string texPathI, Entity* entityPass);
    ~SpriteComponent() override;
    void Draw() override;
    void Update(float deltaTime) override;
};

class CollisionComponent : public Component
{
public:
	CollisionComponent(Vector2 scale, Vector2 centerOffset);
	~CollisionComponent() = default;
	void Draw() override;
    void Update(float deltaTime) {};
	bool drawCollisionBox = false;

private:
	Rectangle collisionBox;

};