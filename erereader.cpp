#include "erereader.h"

EREReader::EREReader()
{

}

void EREReader::LoadExport(World& world, const char* filename)
{
    std::ifstream reader;
    reader.open(filename);

    std::string line;
    int sheet, xPos, yPos;
    int x, y;
    while(reader >> sheet >> xPos >> yPos)
    {
        if(sheet != -1)
        {
            world.xPos[x][y] = xPos;
            world.yPos[x][y] = yPos;
        }

        x += 1;
        if(x >= 30)
        {
            x = 0;
            y += 1;
        }
    }
}

void EREReader::LoadNodes(World& world, Player& player, const char* filename)
{
    std::ifstream reader;
    reader.open(filename);

    std::string line;
    std::string name;
    int x, y;

    while(reader >> name >> x >> y)
    {
        if(name == "player") player = Player(glm::vec2(x, y));
    }
}

EREReader::~EREReader()
{

}
