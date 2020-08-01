#ifndef MAGE_SHADERS_H
#define MAGE_SHADERS_H

namespace MAGE {
    class Shader {
    public:
        unsigned int ID;
        Shader();
        bool AddComponent(unsigned int type, char *source);
        void Compile();
    };
}

#endif //MAGE_SHADERS_H
