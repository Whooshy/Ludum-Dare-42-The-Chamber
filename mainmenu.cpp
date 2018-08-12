#include "mainmenu.h"

MainMenu::MainMenu()
{
    title = Sprite(glm::vec3(10, 530, 0), glm::vec2(384, 64), 0, 0, 0.75f, 0.125f);

    play = Sprite(glm::vec3(10, 144, 0), glm::vec2(256, 64), 0, 0.125f, 0.5f, 0.125f);
    help = Sprite(glm::vec3(10, 74, 0), glm::vec2(256, 64), 0, 0.25f, 0.5f, 0.125f);
    quit = Sprite(glm::vec3(10, 4, 0), glm::vec2(256, 64), 0, 0.375f, 0.5f, 0.125f);
}

void MainMenu::Draw(Renderer& r, Shader& s)
{
    title.Draw(r, s);

    play.Draw(r, s);
    help.Draw(r, s);
    quit.Draw(r, s);
}

MainMenu::~MainMenu()
{

}
