#include "world.h"

int indexCount = 0;

float camX, camY;

World::World()
{
    for(int x = 0; x < 60; x++)
    for(int y = 0; y < 34; y++)
    {
        mesh.AddPos(x * 32, y * 32, 0);
        mesh.AddPos((x + 1) * 32, y * 32, 0);
        mesh.AddPos((x + 1) * 32, (y + 1) * 32, 0);
        mesh.AddPos(x * 32, (y + 1) * 32, 0);

        mesh.AddInd(0 + indexCount);
        mesh.AddInd(1 + indexCount);
        mesh.AddInd(2 + indexCount);
        mesh.AddInd(0 + indexCount);
        mesh.AddInd(3 + indexCount);
        mesh.AddInd(2 + indexCount);

        if((x == 0 && y == 0) || (x == 59 && y == 0) || (x == 59 && y == 33) || (x == 0 && y == 33))
        {
            mesh.AddTex(0.125f, 0.5625f + 0.0625f);
            mesh.AddTex(0.125f + 0.0625f, 0.5625f + 0.0625f);
            mesh.AddTex(0.125f + 0.0625f, 0.5625f);
            mesh.AddTex(0.125f, 0.5625f);
        }
        else if(x > 0 && x < 59 && y == 0)
        {
            mesh.AddTex(0.125f, 0.5f + 0.0625f);
            mesh.AddTex(0.125f + 0.0625f, 0.5f + 0.0625f);
            mesh.AddTex(0.125f + 0.0625f, 0.5f);
            mesh.AddTex(0.125f, 0.5f);
        }
        else if(x > 0 && x < 59 && y == 33)
        {
            mesh.AddTex(0.125f, 0.75f + 0.0625f);
            mesh.AddTex(0.125f + 0.0625f, 0.75f + 0.0625f);
            mesh.AddTex(0.125f + 0.0625f, 0.75f);
            mesh.AddTex(0.125f, 0.75f);
        }
        else if(y > 0 && y < 33 && x == 0)
        {
            mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
            mesh.AddTex(0.1875f, 0.5625f);
        }
        else if(y > 0 && y < 33 && x == 59)
        {
            mesh.AddTex(0, 0.5625f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.5625f);
            mesh.AddTex(0, 0.5625f);
        }
        else if(x == 34 && y == 13)
        {
            mesh.AddTex(0.1875f, 0.75f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.75f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.75f);
            mesh.AddTex(0.1875f, 0.75f);
        }
        else if(x == 26 && y == 13)
        {
            mesh.AddTex(0, 0.75f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.75f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.75f);
            mesh.AddTex(0, 0.75f);
        }
        else if(x == 34 && y == 21)
        {
            mesh.AddTex(0.1875f, 0.5f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.5f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.5f);
            mesh.AddTex(0.1875f, 0.5f);
        }
        else if(x == 26 && y == 21)
        {
            mesh.AddTex(0, 0.5f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.5f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.5f);
            mesh.AddTex(0, 0.5f);
        }
        else if(x > 26 && x < 34 && y == 21)
        {
            mesh.AddTex(0.0625f, 0.5f + 0.0625f);
            mesh.AddTex(0.0625f + 0.0625f, 0.5f + 0.0625f);
            mesh.AddTex(0.0625f + 0.0625f, 0.5f);
            mesh.AddTex(0.0625f, 0.5f);
        }
        else if(x > 26 && x < 34 && y == 13)
        {
            mesh.AddTex(0.0625f, 0.75f + 0.0625f);
            mesh.AddTex(0.0625f + 0.0625f, 0.75f + 0.0625f);
            mesh.AddTex(0.0625f + 0.0625f, 0.75f);
            mesh.AddTex(0.0625f, 0.75f);
        }
        else if(y > 13 && y < 21 && x == 26)
        {
            mesh.AddTex(0, 0.5625f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
            mesh.AddTex(0 + 0.0625f, 0.5625f);
            mesh.AddTex(0, 0.5625f);
        }
        else if(y > 13 && y < 21 && x == 34)
        {
            mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
            mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
            mesh.AddTex(0.1875f, 0.5625f);
        }
        else if(y > 13 && y < 21 && x < 34 && x > 26)
        {
            mesh.AddTex(0.0625f, 0.5625f + 0.0625f);
            mesh.AddTex(0.0625f + 0.0625f, 0.5625f + 0.0625f);
            mesh.AddTex(0.0625f + 0.0625f, 0.5625f);
            mesh.AddTex(0.0625f, 0.5625f);
        }
        else
        {
            mesh.AddTex(0.25f, 0.5f + 0.0625f);
            mesh.AddTex(0.25f + 0.0625f, 0.5f + 0.0625f);
            mesh.AddTex(0.25f + 0.0625f, 0.5f);
            mesh.AddTex(0.25f, 0.5f);
        }

        indexCount += 4;
    }

    mesh.BuildPositions();
    mesh.BuildIndices();
    mesh.BuildTextures();

    level = Entity(mesh, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));

    indexCount = 0;

    spawner = Sprite(glm::vec3(32 * 27.5f, 32 * 14.5f, 0), glm::vec2(192, 192), 0.25f, 0.625f, 0.1875f, 0.1875f);
}

void World::Shrink()
{
    size -= 1;
    if(size == 4)
    {
        mesh = Mesh();

        std::cout << "Shrinking level" << std::endl;

        for(int x = 5; x < 55; x++)
        for(int y = 0; y < 34; y++)
        {
            mesh.AddPos(x * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, (y + 1) * 32, 0);
            mesh.AddPos(x * 32, (y + 1) * 32, 0);

            mesh.AddInd(0 + indexCount);
            mesh.AddInd(1 + indexCount);
            mesh.AddInd(2 + indexCount);
            mesh.AddInd(0 + indexCount);
            mesh.AddInd(3 + indexCount);
            mesh.AddInd(2 + indexCount);

            if((x == 5 && y == 0) || (x == 54 && y == 0) || (x == 54 && y == 33) || (x == 5 && y == 33))
            {
                mesh.AddTex(0.125f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f);
                mesh.AddTex(0.125f, 0.5625f);
            }
            else if(x > 5 && x < 54 && y == 0)
            {
                mesh.AddTex(0.125f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f);
                mesh.AddTex(0.125f, 0.5f);
            }
            else if(x > 5 && x < 54 && y == 33)
            {
                mesh.AddTex(0.125f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f);
                mesh.AddTex(0.125f, 0.75f);
            }
            else if(y > 0 && y < 33 && x == 5)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 0 && y < 33 && x == 54)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(x == 34 && y == 13)
            {
                mesh.AddTex(0.1875f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f);
                mesh.AddTex(0.1875f, 0.75f);
            }
            else if(x == 26 && y == 13)
            {
                mesh.AddTex(0, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f);
                mesh.AddTex(0, 0.75f);
            }
            else if(x == 34 && y == 21)
            {
                mesh.AddTex(0.1875f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f);
                mesh.AddTex(0.1875f, 0.5f);
            }
            else if(x == 26 && y == 21)
            {
                mesh.AddTex(0, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f);
                mesh.AddTex(0, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 21)
            {
                mesh.AddTex(0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f);
                mesh.AddTex(0.0625f, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 13)
            {
                mesh.AddTex(0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f);
                mesh.AddTex(0.0625f, 0.75f);
            }
            else if(y > 13 && y < 21 && x == 26)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(y > 13 && y < 21 && x == 34)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 13 && y < 21 && x < 34 && x > 26)
            {
                mesh.AddTex(0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f);
                mesh.AddTex(0.0625f, 0.5625f);
            }
            else
            {
                mesh.AddTex(0.25f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f);
                mesh.AddTex(0.25f, 0.5f);
            }

            indexCount += 4;
        }
    }

    if(size == 3)
    {
        mesh = Mesh();

        std::cout << "Shrinking level" << std::endl;

        for(int x = 10; x < 50; x++)
        for(int y = 0; y < 34; y++)
        {
            mesh.AddPos(x * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, (y + 1) * 32, 0);
            mesh.AddPos(x * 32, (y + 1) * 32, 0);

            mesh.AddInd(0 + indexCount);
            mesh.AddInd(1 + indexCount);
            mesh.AddInd(2 + indexCount);
            mesh.AddInd(0 + indexCount);
            mesh.AddInd(3 + indexCount);
            mesh.AddInd(2 + indexCount);

            if((x == 10 && y == 0) || (x == 49 && y == 0) || (x == 49 && y == 33) || (x == 10 && y == 33))
            {
                mesh.AddTex(0.125f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f);
                mesh.AddTex(0.125f, 0.5625f);
            }
            else if(x > 10 && x < 49 && y == 0)
            {
                mesh.AddTex(0.125f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f);
                mesh.AddTex(0.125f, 0.5f);
            }
            else if(x > 10 && x < 49 && y == 33)
            {
                mesh.AddTex(0.125f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f);
                mesh.AddTex(0.125f, 0.75f);
            }
            else if(y > 0 && y < 33 && x == 10)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 0 && y < 33 && x == 49)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(x == 34 && y == 13)
            {
                mesh.AddTex(0.1875f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f);
                mesh.AddTex(0.1875f, 0.75f);
            }
            else if(x == 26 && y == 13)
            {
                mesh.AddTex(0, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f);
                mesh.AddTex(0, 0.75f);
            }
            else if(x == 34 && y == 21)
            {
                mesh.AddTex(0.1875f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f);
                mesh.AddTex(0.1875f, 0.5f);
            }
            else if(x == 26 && y == 21)
            {
                mesh.AddTex(0, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f);
                mesh.AddTex(0, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 21)
            {
                mesh.AddTex(0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f);
                mesh.AddTex(0.0625f, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 13)
            {
                mesh.AddTex(0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f);
                mesh.AddTex(0.0625f, 0.75f);
            }
            else if(y > 13 && y < 21 && x == 26)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(y > 13 && y < 21 && x == 34)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 13 && y < 21 && x < 34 && x > 26)
            {
                mesh.AddTex(0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f);
                mesh.AddTex(0.0625f, 0.5625f);
            }
            else
            {
                mesh.AddTex(0.25f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f);
                mesh.AddTex(0.25f, 0.5f);
            }

            indexCount += 4;
        }
    }

    if(size == 2)
    {
        mesh = Mesh();

        std::cout << "Shrinking level" << std::endl;

        for(int x = 15; x < 45; x++)
        for(int y = 0; y < 34; y++)
        {
            mesh.AddPos(x * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, (y + 1) * 32, 0);
            mesh.AddPos(x * 32, (y + 1) * 32, 0);

            mesh.AddInd(0 + indexCount);
            mesh.AddInd(1 + indexCount);
            mesh.AddInd(2 + indexCount);
            mesh.AddInd(0 + indexCount);
            mesh.AddInd(3 + indexCount);
            mesh.AddInd(2 + indexCount);

            if((x == 15 && y == 0) || (x == 44 && y == 0) || (x == 44 && y == 33) || (x == 15 && y == 33))
            {
                mesh.AddTex(0.125f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f);
                mesh.AddTex(0.125f, 0.5625f);
            }
            else if(x > 15 && x < 44 && y == 0)
            {
                mesh.AddTex(0.125f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f);
                mesh.AddTex(0.125f, 0.5f);
            }
            else if(x > 15 && x < 44 && y == 33)
            {
                mesh.AddTex(0.125f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f);
                mesh.AddTex(0.125f, 0.75f);
            }
            else if(y > 0 && y < 33 && x == 15)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 0 && y < 33 && x == 44)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(x == 34 && y == 13)
            {
                mesh.AddTex(0.1875f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f);
                mesh.AddTex(0.1875f, 0.75f);
            }
            else if(x == 26 && y == 13)
            {
                mesh.AddTex(0, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f);
                mesh.AddTex(0, 0.75f);
            }
            else if(x == 34 && y == 21)
            {
                mesh.AddTex(0.1875f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f);
                mesh.AddTex(0.1875f, 0.5f);
            }
            else if(x == 26 && y == 21)
            {
                mesh.AddTex(0, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f);
                mesh.AddTex(0, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 21)
            {
                mesh.AddTex(0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f);
                mesh.AddTex(0.0625f, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 13)
            {
                mesh.AddTex(0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f);
                mesh.AddTex(0.0625f, 0.75f);
            }
            else if(y > 13 && y < 21 && x == 26)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(y > 13 && y < 21 && x == 34)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 13 && y < 21 && x < 34 && x > 26)
            {
                mesh.AddTex(0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f);
                mesh.AddTex(0.0625f, 0.5625f);
            }
            else
            {
                mesh.AddTex(0.25f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f);
                mesh.AddTex(0.25f, 0.5f);
            }

            indexCount += 4;
        }
    }

    if(size == 1)
    {
        mesh = Mesh();

        std::cout << "Shrinking level" << std::endl;

        for(int x = 20; x < 40; x++)
        for(int y = 0; y < 34; y++)
        {
            mesh.AddPos(x * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, y * 32, 0);
            mesh.AddPos((x + 1) * 32, (y + 1) * 32, 0);
            mesh.AddPos(x * 32, (y + 1) * 32, 0);

            mesh.AddInd(0 + indexCount);
            mesh.AddInd(1 + indexCount);
            mesh.AddInd(2 + indexCount);
            mesh.AddInd(0 + indexCount);
            mesh.AddInd(3 + indexCount);
            mesh.AddInd(2 + indexCount);

            if((x == 20 && y == 0) || (x == 39 && y == 0) || (x == 39 && y == 33) || (x == 20 && y == 33))
            {
                mesh.AddTex(0.125f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5625f);
                mesh.AddTex(0.125f, 0.5625f);
            }
            else if(x > 20 && x < 39 && y == 0)
            {
                mesh.AddTex(0.125f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.5f);
                mesh.AddTex(0.125f, 0.5f);
            }
            else if(x > 20 && x < 39 && y == 33)
            {
                mesh.AddTex(0.125f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.125f + 0.0625f, 0.75f);
                mesh.AddTex(0.125f, 0.75f);
            }
            else if(y > 0 && y < 33 && x == 20)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 0 && y < 33 && x == 39)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(x == 34 && y == 13)
            {
                mesh.AddTex(0.1875f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.75f);
                mesh.AddTex(0.1875f, 0.75f);
            }
            else if(x == 26 && y == 13)
            {
                mesh.AddTex(0, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.75f);
                mesh.AddTex(0, 0.75f);
            }
            else if(x == 34 && y == 21)
            {
                mesh.AddTex(0.1875f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5f);
                mesh.AddTex(0.1875f, 0.5f);
            }
            else if(x == 26 && y == 21)
            {
                mesh.AddTex(0, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5f);
                mesh.AddTex(0, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 21)
            {
                mesh.AddTex(0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5f);
                mesh.AddTex(0.0625f, 0.5f);
            }
            else if(x > 26 && x < 34 && y == 13)
            {
                mesh.AddTex(0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.75f);
                mesh.AddTex(0.0625f, 0.75f);
            }
            else if(y > 13 && y < 21 && x == 26)
            {
                mesh.AddTex(0, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0 + 0.0625f, 0.5625f);
                mesh.AddTex(0, 0.5625f);
            }
            else if(y > 13 && y < 21 && x == 34)
            {
                mesh.AddTex(0.1875f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.1875f + 0.0625f, 0.5625f);
                mesh.AddTex(0.1875f, 0.5625f);
            }
            else if(y > 13 && y < 21 && x < 34 && x > 26)
            {
                mesh.AddTex(0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f + 0.0625f);
                mesh.AddTex(0.0625f + 0.0625f, 0.5625f);
                mesh.AddTex(0.0625f, 0.5625f);
            }
            else
            {
                mesh.AddTex(0.25f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f + 0.0625f);
                mesh.AddTex(0.25f + 0.0625f, 0.5f);
                mesh.AddTex(0.25f, 0.5f);
            }

            indexCount += 4;
        }
    }

    mesh.BuildPositions();
    mesh.BuildIndices();
    mesh.BuildTextures();

    indexCount = 0;

    level = Entity(mesh, glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
}

void World::Update(Player& p, Window& w, Renderer& r, Shader& s, float delta)
{
    if(bulletCooldown == 0 && w.lmb && p.ammo > 0)
    {
        p.ammo -= 1;
        bulletSound.Play(bulletData.GetABO());
        bullets.push_back(Bullet(p.GetPos(), glm::vec3((w.mouseX - (w.wWidth / 2) + 16) / 2500, (w.mouseY - (w.wHeight / 2) - 16) / -2500, 0)));
        bulletCooldown = 1;
    }

    int batCount = 0;

    for(int i = 0; i < bats.size(); i++)
    {
        if(!bats[i].dead)
            batCount++;
    }

    if(batCount == 0)
    {
        p.changingWave = true;
    }

    if(p.changingWave)
    {
        std::vector<Bullet>().swap(bullets);
        std::vector<Bat>().swap(bats);
        std::vector<Powerup>().swap(powerups);
        bats.resize((p.WAVE_NUM + 1) * 2);
        p.ammo = 50 + (10 * p.WAVE_NUM);
        for(int i = 0; i < bats.size(); i++)
        {
            int x = (rand() % 150) - 75;
            int y = (rand() % 150) - 75;

            bats[i] = Bat(glm::vec3(29.5f * 32 + x, 16.5f * 32 + y, 0), 8 + p.WAVE_NUM);
        }
    }

    if(bulletCooldown > 0)
    {
        bulletCooldown++;
        if(bulletCooldown > speed)
        {
            bulletCooldown = 0;
        }
    }

    level.Draw(r, s);
    spawner.Draw(r, s);

    for(int j = 0; j < bats.size(); j++)
    {
        if(!bats[j].dead) bats[j].Draw(r, s, p, delta);
        if(((p.GetPos().x >= bats[j].bat.GetPos().x && p.GetPos().x < bats[j].bat.GetPos().x + 32 && p.GetPos().y >= bats[j].bat.GetPos().y && p.GetPos().y < bats[j].bat.GetPos().y + 32)
           || (p.GetPos().x + 32 >= bats[j].bat.GetPos().x && p.GetPos().x + 32 < bats[j].bat.GetPos().x + 32 && p.GetPos().y + 32 >= bats[j].bat.GetPos().y && p.GetPos().y + 32 < bats[j].bat.GetPos().y + 32)) && p.hitCooldown == 0 && !bats[j].dead)
        {
            p.Hit();
            Shrink();
        }
    }

    for(int i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw(r, s, delta);
        for(int j = 0; j < bats.size(); j++)
        {
            if(bats[j].bat.GetPos().x > bullets[i].bullet.GetPos().x - 16 && bats[j].bat.GetPos().x < bullets[i].bullet.GetPos().x && bats[j].bat.GetPos().y > bullets[i].bullet.GetPos().y - 16 && bats[j].bat.GetPos().y < bullets[i].bullet.GetPos().y && !bats[j].dead)
            {
                bullets[i].bullet.Translate(glm::vec3(10000, 10000, 0));
                bats[j].Hit(damage);
                if(bats[j].hp <= 0 && (rand() % 3) == 0)
                {
                    powerups.push_back(Powerup(bats[j].bat.GetPos(), (rand() % 2)));
                }
            }
        }
    }

    for(int i = 0; i < powerups.size(); i++)
    {
        if(((p.GetPos().x >= powerups[i].powerup.GetPos().x && p.GetPos().x < powerups[i].powerup.GetPos().x + 16 && p.GetPos().y >= powerups[i].powerup.GetPos().y && p.GetPos().y < powerups[i].powerup.GetPos().y + 16)
           || (p.GetPos().x + 32 >= powerups[i].powerup.GetPos().x && p.GetPos().x + 32 < powerups[i].powerup.GetPos().x + 16 && p.GetPos().y + 32 >= powerups[i].powerup.GetPos().y && p.GetPos().y + 32 < powerups[i].powerup.GetPos().y + 16))
            && p.hitCooldown == 0 && !powerups[i].isCollected)
        {
            powerups[i].isCollected = true;
            if(powerups[i].id == 0)
                speed /= 1.5f;
            if(powerups[i].id == 1)
                damage += 1;
        }
        powerups[i].Draw(r, s, delta);
    }

    if(size == 5)
    {
        if(p.GetPos().x < 32)
        {
            p.SetCollideLeft(true);
        } else p.SetCollideLeft(false);

        if(p.GetPos().x > 58 * 32)
        {
            p.SetCollideRight(true);
        } else p.SetCollideRight(false);
    }
    if(size == 4)
    {
        if(p.GetPos().x < 32 * 6)
        {
            p.SetCollideLeft(true);
        } else p.SetCollideLeft(false);

        if(p.GetPos().x > 53 * 32)
        {
            p.SetCollideRight(true);
        } else p.SetCollideRight(false);
    }
    if(size == 3)
    {
        if(p.GetPos().x < 32 * 11)
        {
            p.SetCollideLeft(true);
        } else p.SetCollideLeft(false);

        if(p.GetPos().x > 48 * 32)
        {
            p.SetCollideRight(true);
        } else p.SetCollideRight(false);
    }
    if(size == 2)
    {
        if(p.GetPos().x < 32 * 16)
        {
            p.SetCollideLeft(true);
        } else p.SetCollideLeft(false);

        if(p.GetPos().x > 43 * 32)
        {
            p.SetCollideRight(true);
        } else p.SetCollideRight(false);
    }
    if(size == 1)
    {
        if(p.GetPos().x < 32 * 21)
        {
            p.SetCollideLeft(true);
        } else p.SetCollideLeft(false);

        if(p.GetPos().x > 38 * 32)
        {
            p.SetCollideRight(true);
        } else p.SetCollideRight(false);
    }
}

World::~World()
{

}
