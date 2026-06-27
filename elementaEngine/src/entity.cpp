#include "entity.h"

void Entity::addComponent(Component* comp){
    components.push_back(comp);
}

void Entity::Update(float deltaTime){
    for(auto const& comp : components) comp->Update(deltaTime);
}

void Entity::Draw(){
    for(auto const& comp : components) comp->Draw();
}

Entity::~Entity(){
    for (auto const& comp : components) delete comp;
    components.clear();
}