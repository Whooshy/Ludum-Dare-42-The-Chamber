#ifndef BULLET_H
#define BULLET_H

#include "reference.h"
#include "renderer.h"
#include "shader.h"
#include "sprite.h"

class Bullet
{
    public:
        Bullet(glm::vec3 pos, glm::vec3 dir);
        virtual ~Bullet();

        void Draw(Renderer& r, Shader& s, float delta);

        Sprite bullet;
    protected:

    private:
        glm::vec3 dir;

        int counter = 0;
};

#endif // BULLET_H
