#ifndef PLAYER_H
#define PLAYER_H

#include "audiosource.h"
#include "audiodata.h"
#include "renderer.h"
#include "shader.h"
#include "sprite.h"
#include "window.h"
#include "bullet.h"

#include <GLFW/glfw3.h>
#include "AL/al.h"

class Player
{
    public:
        Player(glm::vec2 pos, int wWidth, int wHeight);
        virtual ~Player();

        void Update(Window& w, double delta);
        void Draw(Renderer& r, Shader& s);

        void Hit();

        glm::vec3 GetPos() const { return player->GetPos(); }

        void SetCollideLeft(bool value);
        void SetCollideRight(bool value);

        std::vector<Sprite> hp;
        std::vector<Sprite> ap;

        std::vector<Sprite> waveDigits;

        bool isCollidingLeft, isCollidingRight;
        bool isCollidingBottom, isCollidingTop;
        std::string WAVE = "0";
        int WAVE_NUM = 0;
        bool changingWave = false;

        AudioSource fireSource = AudioSource();
        AudioData fire = AudioData("./res/audio/hit.wav");

        int health = 5;
        int ammo = 50;
        int hitCooldown = 0;
    protected:

    private:
        Sprite* player;
        Sprite hpText, apText, wavText;
        glm::mat4 view;
        glm::vec2 pos;
        int wWidth, wHeight;
        bool canGetHit = true;
};

#endif // PLAYER_H
