#ifndef MAGE_SHADER_H
#define MAGE_SHADER_H

namespace MAGE {
    class Shader {
    public:
        unsigned int ID;

        Shader();

        bool AddComponent(unsigned int type, char *source);

        void Compile();
    };
}

#endif //MAGE_SHADER_H
