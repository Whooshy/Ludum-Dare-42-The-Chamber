#include "bat.h"

Bat::Bat(glm::vec3 pos, int hp) : pos(pos), hp(hp)
{
    bat = Sprite(pos, glm::vec2(32, 32), 0.25f, 0.5625f, 0.0625f, 0.0625f);
    int r = rand() % 100000;
    speed = 100000 - (r - 50000);
}

void Bat::Draw(Renderer& r, Shader& s, Player& p, float delta)
{
    counter++;
    if(!dead && counter > 500 && frame == 0)
    {
        frame = 1;
        bat = Sprite(bat.GetPos(), glm::vec2(32, 32), 0.3125f, 0.5625f, 0.0625f, 0.0625f);
        counter = 0;
    }
    if(!dead && counter > 500 && frame == 1)
    {
        frame = 0;
        bat = Sprite(bat.GetPos(), glm::vec2(32, 32), 0.25f, 0.5625f, 0.0625f, 0.0625f);
        counter = 0;
    }

    if(!dead)
    {
        float dX = bat.GetPos().x - p.GetPos().x;
        float dY = bat.GetPos().y - p.GetPos().y;

        bat.Translate(glm::vec3(-dX * ((delta / speed) * 2500), -dY * ((delta / speed) * 2500), 0));
        bat.Draw(r, s);
    }
}

void Bat::Hit(int amount)
{
    hp -= amount;
    bat = Sprite(bat.GetPos(), glm::vec2(32, 32), 0.375f, 0.5625f, 0.0625f, 0.0625f);
    if(hp <= 0) Kill();
}

void Bat::Kill()
{
    dead = true;
}

Bat::~Bat()
{

}
