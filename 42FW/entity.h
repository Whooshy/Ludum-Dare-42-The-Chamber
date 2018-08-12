#ifndef ENTITY_H
#define ENTITY_H

#include "mesh.h"
#include "shader.h"
#include "renderer.h"

#include <glm/glm.hpp>
#include "reference.h"

class Entity
{
    public:
        Entity() {}
        Entity(Mesh& mesh, glm::vec3 pos, glm::vec3 scale);
        virtual ~Entity();

        void Draw(Renderer& r, Shader& s);

        void Translate(glm::vec3 dir);
        void Rotate(glm::vec3 dir);
        void Scale(glm::vec3 dir);

        glm::vec3 GetPos() { return pos; }
        glm::vec3 GetSize() { return glm::vec3(xScale, yScale, zScale); }

        glm::mat4 transform;
        glm::mat4 start;
    protected:

    private:
        glm::vec3 pos;
        glm::vec3 scale;

        Mesh mesh;

        float xScale, yScale, zScale;
};

#endif // ENTITY_H
