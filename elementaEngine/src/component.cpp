#include "component.h"
#include "entity.h"

SpriteComponent::SpriteComponent(std::string texPathI, Entity* entityPass)
{
    ownedEntity = entityPass;
    tex = LoadTexture(texPathI.c_str());
    base = nullptr; // will resolve base component after components are added to the entity
}

BaseComponent::BaseComponent()
{
    position = Vector2{0.0f, 0.0f};
    rotation = Vector2{0.0f, 0.0f};
    scale = Vector2{100.0f, 100.0f};
}

BaseComponent::~BaseComponent() {}

SpriteComponent::~SpriteComponent()
{
    UnloadTexture(tex);
}

void SpriteComponent::Draw()
{
    Rectangle sourceRec = { 0.0f, 0.0f, (float)tex.width, (float)tex.height };
	DrawTexturePro(tex, sourceRec, Rectangle{ pos.x, pos.y, scale.x, scale.y }, Vector2{ 0.0f, 0.0f }, 0.0f, WHITE);
}

void SpriteComponent::Update(float deltaTime){
    if (base == nullptr && ownedEntity != nullptr) {
        // try to find a BaseComponent in the owner entity
        for (auto const& comp : ownedEntity->components) {
            BaseComponent* tryBase = dynamic_cast<BaseComponent*>(comp);
            if (tryBase != nullptr) {
                base = tryBase;
                break;
            }
        }
    }

    if ( base != nullptr) {
        pos = base->position;
        scale = base->scale;
        rotation = base->rotation;
    }
}

CollisionComponent::CollisionComponent(Vector2 scale, Vector2 centerOffset) {
    collisionBox = Rectangle{ centerOffset.x, centerOffset.y, scale.x, scale.y };
}

void CollisionComponent::Draw() {
    if (drawCollisionBox) {
        DrawRectangleLines(collisionBox.x, collisionBox.y, collisionBox.width, collisionBox.height, RED);
    }
}