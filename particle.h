#ifndef PARTICLE_H
#define PARTICLE_H

#include "reference.h"
#include "sprite.h"
#include "renderer.h"
#include "shader.h"

class Particle
{
    public:
        Particle(int x, int y, float lifetime, float sX, float sY, float sWidth, float sHeight, glm::vec3 dir);
        virtual ~Particle();

        void Update(Renderer& r, Shader& s);

        Sprite particle;
    protected:

    private:
        int x, y;
        float lifetime, sX, sY, sWidth, sHeight;
        glm::vec3 dir;

        float counter = 0;
};

#endif // PARTICLE_H
