#include "renderer.h"

Renderer::Renderer()
{}

void Renderer::Prepare()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
}

void Renderer::DrawMeshVertices(Mesh& mesh)
{
    mesh.Bind();
    glDrawArrays(GL_TRIANGLES, 0, mesh.GetPosSize());
}

void Renderer::DrawMesh(Mesh& mesh)
{
    mesh.Bind();
    glDrawElements(GL_TRIANGLES, mesh.GetIndSize(), GL_UNSIGNED_INT, 0);
}

Renderer::~Renderer()
{}
