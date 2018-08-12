#include "player.h"

float frameCount = 0;
int frame = 0;

float velY = 0;

Player::Player(glm::vec2 pos, int wWidth, int wHeight) : pos(pos), wWidth(wWidth), wHeight(wHeight)
{
    player = new Sprite(glm::vec3(pos, 0), glm::vec2(32, 32), 0, 0.625f, 0.0625f, 0.0625f);

    hpText = Sprite(glm::vec3(pos.x - 50, pos.y - 45, 0), glm::vec2(32, 16), 0, 0.8125f, 0.0625f, 0.03125f);
    apText = Sprite(glm::vec3(pos.x - 50, pos.y - 65, 0), glm::vec2(32, 16), 0, 0.8125f + 0.03125f, 0.0625f, 0.03125f);
    wavText = Sprite(glm::vec3(pos.x - 50, pos.y - 85, 0), glm::vec2(64, 16), 0, 0.875f, 0.125f, 0.03125f);

    hp.resize(5);
    for(int i = 0; i < 5; i++)
        hp[i] = Sprite(glm::vec3(pos.x - 50 + 24 + (i * 20), pos.y - 45, 0), glm::vec2(16, 16), 0.0625f, 0.8125f, 0.03125f, 0.03125f);

    ap.resize(5);
    for(int i = 0; i < 5; i++)
        ap[i] = Sprite(glm::vec3(pos.x - 50 + 24 + (i * 20), pos.y - 45 - 20, 0), glm::vec2(16, 16), 0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);

    waveDigits.resize(3);
    for(int i = 0; i < 3; i++)
        waveDigits[i] = Sprite(glm::vec3(pos.x - 50 + 45 + (i * 15), pos.y - 85, 0), glm::vec2(16, 16), 0, 0.90625f, 0.03125f, 0.03125f);

    alSourcef(fireSource.GetSource(), AL_GAIN, 1);
}

void Player::Hit()
{
    if(hitCooldown == 0)
    {
        health -= 1;
        for(int i = health; i < 5; i++)
            hp[i].UpdateSpriteCoords(0.0625f + 0.03125f, 0.8125f, 0.03125f, 0.03125f);
        hitCooldown = 1;
        player->UpdateSpriteCoords(0.375f, 0.5f, 0.0625f, 0.0625f);
        fireSource.Play(fire.GetABO());
    }
}

void Player::Update(Window& w, double delta)
{
    pos = glm::vec2(GetPos().x, GetPos().y);

    if(w.GetKey(GLFW_KEY_D) && !isCollidingRight)
    {
        frameCount += 0.001f;
        if(frameCount > 0.5f && frame == 0)
        {
            frame = 1;
            frameCount = 0;
            player->UpdateSpriteCoords(0, 0.625f, 0.0625f, 0.0625f);
        }
        if(frameCount > 0.5f && frame == 1)
        {
            frame = 0;
            frameCount = 0;
            player->UpdateSpriteCoords(0.125f, 0.625f, 0.0625f, 0.0625f);
        }
        player->Translate(glm::vec3(1 * (delta * 10), 0, 0));
        hpText.Translate(glm::vec3(1 * (delta * 10), 0, 0));
        apText.Translate(glm::vec3(1 * (delta * 10), 0, 0));
        wavText.Translate(glm::vec3(0.5f * (delta * 10), 0, 0));
        for(int i = 0; i < 5; i++) hp[i].Translate(glm::vec3(2 * (delta * 10), 0, 0));
        for(int i = 0; i < 5; i++) ap[i].Translate(glm::vec3(2 * (delta * 10), 0, 0));
        for(int i = 0; i < 3; i++) waveDigits[i].Translate(glm::vec3(2 * (delta * 10), 0, 0));
    }
    if(w.GetKey(GLFW_KEY_A) && !isCollidingLeft)
    {
        frameCount += 0.001f;
        if(frameCount > 0.5f && frame == 0)
        {
            frame = 1;
            frameCount = 0;
            player->UpdateSpriteCoords(0.0625f, 0.625f, 0.0625f, 0.0625f);
        }
        if(frameCount > 0.5f && frame == 1)
        {
            frame = 0;
            frameCount = 0;
            player->UpdateSpriteCoords(0.1875f, 0.625f, 0.0625f, 0.0625f);
        }
        player->Translate(glm::vec3(-1 * (delta * 10), 0, 0));
        hpText.Translate(glm::vec3(-1 * (delta * 10), 0, 0));
        apText.Translate(glm::vec3(-1 * (delta * 10), 0, 0));
        wavText.Translate(glm::vec3(-0.5f * (delta * 10), 0, 0));
        for(int i = 0; i < 5; i++) hp[i].Translate(glm::vec3(-2 * (delta * 10), 0, 0));
        for(int i = 0; i < 5; i++) ap[i].Translate(glm::vec3(-2 * (delta * 10), 0, 0));
        for(int i = 0; i < 3; i++) waveDigits[i].Translate(glm::vec3(-2 * (delta * 10), 0, 0));
    }

    if(ammo == 50)
    {
        for(int i = 0; i < 5; i++) ap[i].UpdateSpriteCoords(0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
    }
    if(ammo >= 40 && ammo < 50)
    {
        for(int i = 0; i < 5; i++) ap[i].UpdateSpriteCoords(0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
    }
    if(ammo >= 30 && ammo < 40)
    {
        for(int i = 0; i < 4; i++) ap[i].UpdateSpriteCoords(0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
        ap[4].UpdateSpriteCoords(0.09375f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
    }
    if(ammo >= 20 && ammo < 30)
    {
        for(int i = 0; i < 3; i++) ap[i].UpdateSpriteCoords(0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
        ap[3].UpdateSpriteCoords(0.09375f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
    }
    if(ammo >= 10 && ammo < 20)
    {
        for(int i = 0; i < 2; i++) ap[i].UpdateSpriteCoords(0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
        ap[2].UpdateSpriteCoords(0.09375f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
    }
    if(ammo >= 0 && ammo < 10)
    {
        for(int i = 0; i < 1; i++) ap[i].UpdateSpriteCoords(0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
        ap[1].UpdateSpriteCoords(0.09375f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
    }
    if(ammo == 0)
    {
        ap[0].UpdateSpriteCoords(0.09375f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);
    }

    if(changingWave)
    {
        for(int i = 0; i < 5; i++)
        ap[i] = Sprite(glm::vec3(pos.x - 50 + 24 + (i * 20), pos.y - 45 - 20, 0), glm::vec2(16, 16), 0.0625f, 0.8125f + 0.03125f, 0.03125f, 0.03125f);

        WAVE_NUM += 1;
        int dig0 = WAVE_NUM / 100;
        int dig1 = (WAVE_NUM / 10) - (dig0 * 10);
        int dig2 = WAVE_NUM - (dig1 * 10) - (dig0 * 100);

        waveDigits[0] = Sprite(glm::vec3(pos.x - 50 + 45 + (0 * 15), pos.y - 85, 0), glm::vec2(16, 16), dig0 * 0.03125f, 0.90625f, 0.03125f, 0.03125f);
        waveDigits[1] = Sprite(glm::vec3(pos.x - 50 + 45 + (1 * 15), pos.y - 85, 0), glm::vec2(16, 16), dig1 * 0.03125f, 0.90625f, 0.03125f, 0.03125f);
        waveDigits[2] = Sprite(glm::vec3(pos.x - 50 + 45 + (2 * 15), pos.y - 85, 0), glm::vec2(16, 16), dig2 * 0.03125f, 0.90625f, 0.03125f, 0.03125f);
        changingWave = false;
    }

    if(hitCooldown > 0)
    {
        hitCooldown++;
        if(hitCooldown == 1000)
            hitCooldown = 0;
    }

    if(GetPos().y > 32)
    {
        isCollidingBottom = false;
    } else isCollidingBottom = true;

    if(isCollidingBottom)
    {
        velY = 0;
        if(w.GetKey(GLFW_KEY_SPACE))
            velY = 2.5f * (0.0003f * 10);
    }
    if(!isCollidingBottom)
    {
        velY -= 0.001f * (0.0003f * 10);
        if(velY < -5)
        {
            velY = -5;
        }
    }

    player->Translate(glm::vec3(0, velY, 0));
    hpText.Translate(glm::vec3(0, velY * 2, 0));
    apText.Translate(glm::vec3(0, velY * 2, 0));
    wavText.Translate(glm::vec3(0, velY * 2, 0));
    for(int i = 0; i < 5; i++) hp[i].Translate(glm::vec3(0, velY * 2, 0));
    for(int i = 0; i < 5; i++) ap[i].Translate(glm::vec3(0, velY * 2, 0));
    for(int i = 0; i < 3; i++) waveDigits[i].Translate(glm::vec3(0, velY * 2, 0));
}

void Player::SetCollideLeft(bool value)
{
    bool* ptr = &isCollidingLeft;
    *ptr = value;
}

void Player::SetCollideRight(bool value)
{
     bool* ptr = &isCollidingRight;
    *ptr = value;
}

void Player::Draw(Renderer& r, Shader& s)
{
    player->Draw(r, s);
    hpText.Draw(r, s);
    apText.Draw(r, s);
    wavText.Draw(r, s);
    for(int i = 0; i < 5; i++) hp[i].Draw(r, s);
    for(int i = 0; i < 5; i++) ap[i].Draw(r, s);
    for(int i = 0; i < 3; i++) waveDigits[i].Draw(r, s);
}

Player::~Player()
{

}
