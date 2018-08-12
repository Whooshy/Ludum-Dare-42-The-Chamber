#include "tree.h"

Tree::Tree(float x, float y)
{
    sprite = Sprite(glm::vec3(x, y, 0), glm::vec2(256, 256), 0, 0, 0.25f, 0.25f);
}

void Tree::Hit(int amount, double mX, double mY)
{
    for(int i = 0; i < 3; i++)
    {
        float dirX = rand() % 10;
        float dirY = rand() % 10;

        dirX -= 5;
        dirY -= 5;

        particles.push_back(Particle((int) mX, (int) mY, 5, 0.125f, 0.5f, 0.0078125f, 0.0078125f, glm::vec3(dirX / 100, dirY / 100, 0)));
    }

    hp -= amount;
    if(hp == 0) Break();
}

void Tree::Break()
{
    std::vector<Particle>().swap(particles);
    sprite.UpdateSpriteCoords(0.75f, 0, 0.25f, 0.25f);
    hp = 0;
}

void Tree::Draw(Renderer& r, Shader& s)
{
    sprite.Draw(r, s);
    for(int i = 0; i < particles.size(); i++)
    {
        particles[i].Update(r, s);
    }
}

Tree::~Tree()
{

}
