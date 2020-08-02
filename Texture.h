#ifndef MAGE_TEXTURE_H
#define MAGE_TEXTURE_H

#include <string>

namespace MAGE {
    class Texture{
    public:
        unsigned int ID;
        Texture(const char *filePath);
        void Bind();
    };
}
#endif //MAGE_TEXTURE_H
