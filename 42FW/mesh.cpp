#include "mesh.h"

Mesh::Mesh()
{
    VAO = CreateVAO();
}

void Mesh::AddPos(float x, float y, float z)
{
    pos.push_back(x);
    pos.push_back(y);
    pos.push_back(z);
}

void Mesh::AddTex(float x, float y)
{
    tex.push_back(x);
    tex.push_back(y);
}

void Mesh::AddInd(unsigned int index)
{
    ind.push_back(index);
}

unsigned int Mesh::CreateVAO()
{
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    return VAO;
}

unsigned int Mesh::CreateVBO()
{
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    return VBO;
}

unsigned int Mesh::AddVBO(int attribute, float* data, unsigned int dataSize)
{
    unsigned int VBO = CreateVBO();
    BindVBO(VBO);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
    UnbindVBO();
    return VBO;
}

void Mesh::AppendVAO(int attribute, unsigned int VBO, int dimensions)
{
    Bind();
    BindVBO(VBO);
    glVertexAttribPointer(attribute, dimensions, GL_FLOAT, false, dimensions * sizeof(float), 0);
    glEnableVertexAttribArray(attribute);
    UnbindVBO();
    Unbind();
}

void Mesh::BuildPositions()
{
    int size = pos.size();
    float posData[size];
    posSize = size;
    for(int i = 0; i < size; i++)
    {
        posData[i] = pos.at(i);
    }
    size *= sizeof(float);
    unsigned int VBO = AddVBO(POS, posData, size);
    AppendVAO(POS, VBO, 3);
    std::vector<float>().swap(pos);
}

void Mesh::BuildTextures()
{
    int size = tex.size();
    float texData[size];
    texSize = size;
    for(int i = 0; i < size; i++)
        texData[i] = tex.at(i);
    size *= sizeof(float);
    unsigned int VBO = AddVBO(TEX, texData, size);
    AppendVAO(TEX, VBO, 2);
    std::vector<float>().swap(tex);
}

void Mesh::BuildIndices()
{
    int size = ind.size();
    unsigned int indData[size];
    indSize = size;
    for(int i = 0; i < size; i++)
        indData[i] = ind[i];
    size *= sizeof(unsigned int);
    Bind();
    unsigned int IBO = CreateVBO();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indData, GL_STATIC_DRAW);
    Unbind();
    std::vector<unsigned int>().swap(ind);
}

Mesh::~Mesh()
{
    //dtor
}
