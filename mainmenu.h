#ifndef MAINMENU_H
#define MAINMENU_H

#include "reference.h"
#include "sprite.h"

class MainMenu
{
    public:
        MainMenu();
        virtual ~MainMenu();

        void Draw(Renderer& r, Shader& s);

        Sprite title;

        Sprite play;
        Sprite help;
        Sprite quit;
    protected:

    private:
};

#endif // MAINMENU_H
