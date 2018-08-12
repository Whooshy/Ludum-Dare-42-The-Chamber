#ifndef BAT_H
#define BAT_H

#include <ctime>
#include <stdlib.h>

#include "reference.h"
#include "renderer.h"
#include "player.h"
#include "shader.h"
#include "sprite.h"

class Bat
{
    public:
        Bat() {}
        Bat(glm::vec3 pos, int hp);
        virtual ~Bat();

        void Hit(int amount);
        void Kill();
        void Draw(Renderer& r, Shader& s, Player& p, float delta);

        Sprite bat;
        bool dead = false;

        float speed = 0;
        int hp = 8;
    protected:

    private:
        int counter = 0;
        int frame = 0;

        glm::vec3 pos;
};

#endif // BAT_H
