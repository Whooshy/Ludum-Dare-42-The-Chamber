#ifndef TEXTURE_H
#define TEXTURE_H

#include "reference.h"

class Texture
{
    public:
        Texture(const char* filename);
        virtual ~Texture();

        void Bind() { glBindTexture(GL_TEXTURE_2D, texture); }
        void Unbind() { glBindTexture(GL_TEXTURE_2D, 0); }

    protected:

    private:
        unsigned int texture;
};

#endif // TEXTURE_H
