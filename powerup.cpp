#include "powerup.h"

Powerup::Powerup(glm::vec3 pos, int id) : id(id)
{
    float sX = 0.328125f;
    float sY;
    if(id == 0)
    {
        sY = 0.5f;
    }
    if(id == 1)
    {
        sY = 0.53125f;
    }
    powerup = Sprite(pos, glm::vec2(16, 16), sX, sY, 0.03125f, 0.03125f);
}

void Powerup::Draw(Renderer& r, Shader& s, float delta)
{
    if(!isCollected)
    {
        if(powerup.GetPos().y > 32)
        {
            powerup.Translate(glm::vec3(0, -1 * delta, 0));
        }
        powerup.Draw(r, s);
    }
}

Powerup::~Powerup()
{

}
