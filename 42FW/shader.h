#ifndef SHADER_H
#define SHADER_H

#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "reference.h"

class Shader
{
    public:
        Shader();
        Shader(const char* title);
        virtual ~Shader();

        void CreateProgram();

        void Bind() { glUseProgram(program); }
        void Unbind() { glUseProgram(0); }

        void CreateOrtho(float x, float y, float width, float height);
        void CreatePersp(float fov, float ratio, float nearPlane, float farPlane);

        void UpdateProjection();

        void AddShader(int shader, std::string filepath);

        std::string ReadFromFile(std::string filepath);

        void TransferMatrix(glm::mat4 matrix, const char* varName);
        void TransferVec3(glm::vec3 vec, const char* varName);

        void Compile();

    protected:

    private:
        unsigned int program;

        glm::mat4 projection;
};

#endif // SHADER_H
