#include "component.h"

ScriptComponent::ScriptComponent(Texture2D texI, Vector2 posI, Vector2 scaleI)
{
    tex = texI;
    pos = posI;
    scale = scaleI;
}

ScriptComponent::~ScriptComponent()
{
    UnloadTexture(tex);
}
