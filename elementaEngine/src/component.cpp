#include "component.h"

SpriteComponent::SpriteComponent(std::string texPathI, Vector2 posI, Vector2 scaleI)
{
    tex = LoadTexture(texPathI.c_str());
    pos = posI;
    scaleRec = Rectangle{ pos.x, pos.y, scaleI.x, scaleI.y};
}

SpriteComponent::~SpriteComponent()
{
    UnloadTexture(tex);
}

void SpriteComponent::Draw()
{
    DrawTextureV(tex, pos, WHITE);
}