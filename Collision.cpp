#include <iostream>
#include "Collision.h"

namespace MAGE {
    bool CollisionGroup::CheckCollisions() {
        for (Object obj : *second) {
            if (sqrtf(powf(obj.Position.x-first->Position.x, 2.0f)+powf(obj.Position.y-first->Position.y,2.0f)) < obj.CapsuleRadius + first->CapsuleRadius){ // TODO: Scaling
                return true;
            }
        }
        return false;
    }
}