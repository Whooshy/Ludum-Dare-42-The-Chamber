#ifndef RENDERER_H
#define RENDERER_H

#include "mesh.h"
#include "reference.h"

class Renderer
{
    public:
        Renderer();
        virtual ~Renderer();

        void Prepare();

        void DrawMeshVertices(Mesh& mesh);
        void DrawMesh(Mesh& mesh);

    protected:

    private:
};

#endif // RENDERER_H
