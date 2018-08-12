#include "sprite.h"

Sprite::Sprite(glm::vec3 pos, glm::vec2 size, float sX, float sY, float width, float height) : pos(pos), size(size), sX(sX), sY(sY), width(width), height(height)
{
    mesh.AddPos(0, 0, 0);
    mesh.AddPos(1, 0, 0);
    mesh.AddPos(1, 1, 0);
    mesh.AddPos(0, 1, 0);

    mesh.AddInd(0);
    mesh.AddInd(1);
    mesh.AddInd(2);
    mesh.AddInd(0);
    mesh.AddInd(3);
    mesh.AddInd(2);

    mesh.AddTex(sX, sY + height);
    mesh.AddTex(sX + width, sY + height);
    mesh.AddTex(sX + width, sY);
    mesh.AddTex(sX, sY);

    mesh.BuildPositions();
    mesh.BuildTextures();
    mesh.BuildIndices();

    entity = Entity(mesh, pos, glm::vec3(size.x, size.y, 1));
    entity.Scale(glm::vec3(size, 1));
}

void Sprite::UpdateSpriteCoords(float newSX, float newSY, float newSWidth, float newSHeight)
{
    if(newSX == sX && newSY == sY && newSWidth == width && newSHeight && height)
    {

    }
    else
    {
        mesh.AddTex(newSX, newSY + newSHeight);
        mesh.AddTex(newSX + newSWidth, newSY + newSHeight);
        mesh.AddTex(newSX + newSWidth, newSY);
        mesh.AddTex(newSX, newSY);

        mesh.BuildTextures();

        entity = Entity(mesh, GetPos(), glm::vec3(GetSize().x, GetSize().y, 1));
        entity.Scale(GetSize());
    }
}

void Sprite::Draw(Renderer& r, Shader& s)
{
    entity.Draw(r, s);
}

void Sprite::Translate(glm::vec3 dir)
{
    entity.Translate(dir);
}

void Sprite::Rotate(glm::vec3 dir)
{
    entity.Rotate(dir);
}

void Sprite::Scale(glm::vec2 dir)
{
    entity.Scale(glm::vec3(dir, 0));
}

void Sprite::Destroy()
{

}

Sprite::~Sprite()
{
    Destroy();
}
