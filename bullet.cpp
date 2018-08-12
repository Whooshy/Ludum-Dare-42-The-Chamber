#include "bullet.h"

Bullet::Bullet(glm::vec3 pos, glm::vec3 dir) : dir(dir)
{
    bullet = Sprite(pos, glm::vec2(8, 8), 0.3125f, 0.5f, 0.015625f, 0.015625f);
}

void Bullet::Draw(Renderer& r, Shader& s, float delta)
{
    counter++;
    if(counter <= 5000)
    {
        bullet.Translate(dir * (delta * 1000));
        bullet.Draw(r, s);
    }
}

Bullet::~Bullet()
{

}
