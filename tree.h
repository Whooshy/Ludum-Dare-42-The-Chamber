#ifndef TREE_H
#define TREE_H

#include <stdlib.h>

#include "sprite.h"
#include "particle.h"

class Tree
{
    public:
        Tree() {}
        Tree(float x, float y);
        virtual ~Tree();

        void Draw(Renderer& r, Shader& s);
        void Break();
        void Hit(int amount, double mX, double mY);

        std::vector<Particle> particles;
        Sprite sprite;
    protected:

    private:
        int hp = 5;
};

#endif // TREE_H
