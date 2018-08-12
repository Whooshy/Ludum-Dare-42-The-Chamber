#ifndef WORLD_H
#define WORLD_H

#include <ctime>
#include <stdlib.h>

#include "audiosource.h"
#include "audiodata.h"
#include "reference.h"
#include "bat.h"
#include "bullet.h"
#include "player.h"
#include "renderer.h"
#include "shader.h"
#include "mesh.h"
#include "entity.h"
#include "window.h"

#include "powerup.h"

class World
{
    public:
        World();
        virtual ~World();

        std::vector<std::vector< float > > xPos;
        std::vector<std::vector< float > > yPos;

        void Shrink();
        void CreateWorld();

        void Update(Player& p, Window& w, Renderer& r, Shader& s, float delta);

        std::vector<Bullet> bullets;
        std::vector<Bat> bats;
        std::vector<Powerup> powerups;

        Sprite spawner;
        int size = 5;

        int damage = 1;
        float speed = 600;

        AudioSource bulletSound = AudioSource();
        AudioData bulletData = AudioData("./res/audio/fire.wav");
    protected:

    private:
        Mesh mesh;
        Entity level;

        int bulletCooldown = 0;
        int hitCooldown = 0;
};

#endif // WORLD_H
