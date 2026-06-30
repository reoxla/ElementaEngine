#include "map.h"

Map::Map(Color bgColor){
    backgroundColor = bgColor;
}

Map::~Map() { for(auto const& entity : entities) delete entity; }

void Map::Draw() { for(auto const& entity : entities) entity->Draw(); }

void Map::addEntity(Entity* entity){
    entities.push_back(entity);
}