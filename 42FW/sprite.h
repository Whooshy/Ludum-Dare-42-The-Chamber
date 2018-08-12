#ifndef SPRITE_H
#define SPRITE_H

#include "mesh.h"
#include "entity.h"
#include "renderer.h"
#include "shader.h"

#include <glm/glm.hpp>
#include "reference.h"

class Sprite
{
    public:
        Sprite() {}
        Sprite(glm::vec3 pos, glm::vec2 size, float sX, float sY, float width, float height);
        virtual ~Sprite();

        void Translate(glm::vec3 dir);
        void Rotate(glm::vec3 dir);
        void Scale(glm::vec2 dir);

        void UpdateSpriteCoords(float sX, float sY, float sWidth, float sHeight);

        void Draw(Renderer& r, Shader& s);
        void Destroy();

        glm::vec3 GetPos() { return entity.GetPos(); }
        glm::vec3 GetSize() { return entity.GetSize(); }

    protected:

    private:
        glm::vec3 pos;
        glm::vec2 size;

        Entity entity;
        Mesh mesh;

        float sX, sY, width, height;
};

#endif // SPRITE_H
