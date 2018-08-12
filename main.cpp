#include "audioplayer.h"
#include "player.h"
#include "mainmenu.h"
#include "reference.h"
#include "renderer.h"
#include "shader.h"
#include "sprite.h"
#include "texture.h"
#include "window.h"
#include "world.h"

#include "AL/al.h"

int main()
{
    Window window = Window(800, 600, "LD42", true);

    Renderer r = Renderer();
    Shader s = Shader("main");

    Texture atlas_1 = Texture("atlas_1");
    Texture menu = Texture("menu");
    Texture help = Texture("help");

    Sprite helpScreen = Sprite(glm::vec3(0, 0, 0), glm::vec2(800, 600), 0, 0, 1, 1);

    unsigned int STATE = 0;

    AudioPlayer ap = AudioPlayer();

    AudioData music = AudioData("./res/audio/music.wav");

    AudioSource plSource = AudioSource();

    Player player = Player(glm::vec2(29.5f * 32, 10 * 32), 800, 600);
    World world = World();

    MainMenu m = MainMenu();

    double timer = glfwGetTime();

    alSourcei(plSource.GetSource(), AL_LOOPING, AL_TRUE);
    alSourcef(plSource.GetSource(), AL_GAIN, 0.25f);
    plSource.Play(music.GetABO());

    float delta = 0;
    int fc = 0;

    while(window.IsOpen())
    {
        fc++;

        if(glfwGetTime() - timer >= 0.1)
        {
            delta =  0.1f / (float) fc;
            fc = 0;
            timer = glfwGetTime();
        }

        int mX = window.mouseX + player.GetPos().x - (window.wWidth / 2) + 32;
        int mY = -window.mouseY + (player.GetPos().y) + (window.wHeight / 2) + 64;

        s.Bind();
        s.CreateOrtho(player.GetPos().x - (window.wWidth / 2) + 32, player.GetPos().y - (window.wHeight / 2) + 96, player.GetPos().x + (window.wWidth / 2), player.GetPos().y + (window.wHeight / 2));
        s.UpdateProjection();
        r.Prepare();

        if(STATE == 0)
        {
            s.CreateOrtho(0, 0, 800, 600);
            s.UpdateProjection();
            menu.Bind();
            m.Draw(r, s);

            if((window.mouseX / (float) window.wWidth) < 0.25f && (window.mouseY / (float) window.wHeight) > 0.625f && (window.mouseY / (float) window.wHeight) < 0.75f)
            {
                if(window.lmb)
                {
                    player = Player(glm::vec2(29.5f * 32, 10 * 32), 800, 600);
                    world = World();
                    STATE = 1;
                }
            }
            if((window.mouseX / (float) window.wWidth) < 0.25f && (window.mouseY / (float) window.wHeight) > 0.75f && (window.mouseY / (float) window.wHeight) < 0.875f)
            {
                if(window.lmb)
                {
                    STATE = 2;
                }
            }
            if((window.mouseX / (float) window.wWidth) < 0.25f && (window.mouseY / (float) window.wHeight) > 0.875f)
            {
                if(window.lmb)
                {
                    window.Destroy();
                    return 0;
                }
            }
        }

        if(STATE == 1)
        {
            atlas_1.Bind();
            world.Update(player, window, r, s, delta);

            player.Update(window, delta);
            player.Draw(r, s);
        }

        if(STATE == 2)
        {
            s.CreateOrtho(0, 0, 800, 600);
            s.UpdateProjection();

            if(window.GetKey(GLFW_KEY_ESCAPE))
            {
                STATE = 0;
            }

            help.Bind();
            helpScreen.Draw(r, s);
        }

        if(player.health == 0)
        {
            STATE = 0;
        }

        window.Update();
    }

    return 0;
}
