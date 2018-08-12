#include "entity.h"

Entity::Entity(Mesh& mesh, glm::vec3 pos, glm::vec3 scale) : mesh(mesh), pos(pos)
{
    transform = glm::translate(transform, pos);

    xScale = scale.x;
    yScale = scale.y;
    zScale = scale.z;
}

void Entity::Draw(Renderer& r, Shader& s)
{
    s.Bind();
    s.TransferMatrix(transform, "transformation");
    r.DrawMesh(mesh);
    s.Unbind();
}

void Entity::Translate(glm::vec3 dir)
{
    transform = glm::translate(transform, dir);
    pos.x += dir.x * xScale;
    pos.y += dir.y * yScale;
    pos.z += dir.z;
}

void Entity::Rotate(glm::vec3 dir)
{
    transform = glm::rotate(transform, dir.x, glm::vec3(1, 0, 0));
    transform = glm::rotate(transform, dir.y, glm::vec3(0, 1, 0));
    transform = glm::rotate(transform, dir.z, glm::vec3(0, 0, 1));
}

void Entity::Scale(glm::vec3 dir)
{
    transform = glm::scale(transform, dir);
}

Entity::~Entity()
{

}
