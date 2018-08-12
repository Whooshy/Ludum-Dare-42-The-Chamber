#ifndef POWERUP_H
#define POWERUP_H

#include "reference.h"
#include "sprite.h"
#include "renderer.h"
#include "shader.h"

class Powerup
{
    public:
        Powerup(glm::vec3 pos, int id);
        virtual ~Powerup();

        void Draw(Renderer& r, Shader& s, float delta);

        Sprite powerup;
        bool isCollected = false;
        int id;
    protected:

    private:
};

#endif // POWERUP_H
