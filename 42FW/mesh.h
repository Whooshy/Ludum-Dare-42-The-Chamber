#ifndef MESH_H
#define MESH_H

#include "reference.h"

class Mesh
{
    public:
        Mesh();
        virtual ~Mesh();

        void AddPos(float x, float y, float z);
        void AddTex(float x, float y);

        void AddInd(unsigned int index);

        unsigned int CreateVAO();
        unsigned int CreateVBO();

        unsigned int AddVBO(int attribute, float* data, unsigned int dataSize);
        void AppendVAO(int attribute, unsigned int VBO, int dimensions);

        unsigned int GetPosSize() { return posSize; }
        unsigned int GetIndSize() { return indSize; }

        void BuildPositions();
        void BuildTextures();

        void BuildIndices();

        void Bind() { glBindVertexArray(VAO); }
        void Unbind() { glBindVertexArray(0); }

        enum {
            POS,
            TEX,
            AMT_VBOs
        };

    protected:

    private:
        unsigned int VAO;

        std::vector<float> pos;
        std::vector<float> tex;

        std::vector<unsigned int> ind;

        unsigned int posSize;
        unsigned int texSize;
        unsigned int indSize;

        void BindVBO(int VBO) { glBindBuffer(GL_ARRAY_BUFFER, VBO); }
        void UnbindVBO() { glBindBuffer(GL_ARRAY_BUFFER, 0); }
};

#endif // MESH_H
