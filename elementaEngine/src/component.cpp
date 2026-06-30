#include "component.h"

SpriteComponent::SpriteComponent(std::string texPathI, Vector2 posI, float scaleI)
{
    tex = LoadTexture(texPathI.c_str());
    pos = posI;
    scale = scaleI;
}

SpriteComponent::~SpriteComponent()
{
    UnloadTexture(tex);
}

void SpriteComponent::Draw()
{
    DrawTextureEx(tex, pos, 0.0f, scale, WHITE);
}