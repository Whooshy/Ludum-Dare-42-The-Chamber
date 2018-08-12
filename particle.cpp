#include "particle.h"

Particle::Particle(int x, int y, float lifetime, float sX, float sY, float sWidth, float sHeight, glm::vec3 dir) : x(x), y(y), lifetime(lifetime), sX(sX), sY(sY), sWidth(sWidth), sHeight(sHeight), dir(dir)
{
    particle = Sprite(glm::vec3(x, y, 0), glm::vec2(7.5f, 7.5f), sX, sY, sWidth, sHeight);
}

void Particle::Update(Renderer& r, Shader& s)
{
    dir = glm::vec3(0, 0, 0);
    if(counter < lifetime)
    {
        particle.Translate(dir);
        particle.Draw(r, s);
    }
}

Particle::~Particle()
{

}
