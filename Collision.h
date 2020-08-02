#ifndef MAGE_COLLISION_H
#define MAGE_COLLISION_H

#include "Object.h"

namespace MAGE {
    class CollisionGroup {
    public:
        CollisionGroup(Object *_first, std::vector<Object> *_second) : first(_first), second(_second) {}
        Object * first;
        std::vector<Object> * second;
        bool CheckCollisions();
    };
}

#endif //MAGE_COLLISION_H
