#include "component.h"
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

Entity::Entity() {
    BaseComponent* base = new BaseComponent();
    addComponent(base);
}

Entity::~Entity(){
    for (auto const& comp : components){
        if(comp != nullptr){
            delete comp;
        }
    }
    components.clear();
}