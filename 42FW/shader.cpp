#include "shader.h"

Shader::Shader()
{
    std::string filepath = "./res/shaders/main";

    CreateProgram();
    AddShader(GL_VERTEX_SHADER, filepath);
    AddShader(GL_FRAGMENT_SHADER, filepath);
    Compile();
}

Shader::Shader(const char* title)
{
    std::string filepath = "./res/shaders/";
    filepath.append(title);

    CreateProgram();
    AddShader(GL_VERTEX_SHADER, filepath);
    AddShader(GL_FRAGMENT_SHADER, filepath);
    Compile();
}

void Shader::CreateProgram()
{
    program = glCreateProgram();
}

void Shader::AddShader(int type, std::string filepath)
{
    unsigned int shader = glCreateShader(type);
    std::string extension = (type == GL_VERTEX_SHADER) ? ".vsf" : ".fsf";
    const char* source = ReadFromFile((filepath + extension)).c_str();
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int success;
    char log[512];

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, log);
        std::cerr << log << std::endl;
    }

    glAttachShader(program, shader);
}

std::string Shader::ReadFromFile(std::string filepath)
{
    std::ifstream reader(filepath.c_str());
    std::string line;
    std::string output;
    while(std::getline(reader, line))
    {
        output.append(line + "\n");
    }
    return output;
}

void Shader::CreateOrtho(float x, float y, float width, float height)
{
    projection = glm::ortho(x, width, y, height, -1.f, 1.f);
}

void Shader::CreatePersp(float fov, float ratio, float nearPlane, float farPlane)
{
    projection = glm::perspective(fov, ratio, nearPlane, farPlane);
}

void Shader::UpdateProjection()
{
    TransferMatrix(projection, "projection");
}

void Shader::TransferVec3(glm::vec3 vec, const char* varName)
{
    glUniform3f(glGetUniformLocation(program, varName), vec.x, vec.y, vec.z);
}

void Shader::TransferMatrix(glm::mat4 matrix, const char* varName)
{
    glUniformMatrix4fv(glGetUniformLocation(program, varName), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::Compile()
{
    glLinkProgram(program);

    int success;
    char log[512];

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, log);
        std::cerr << log << std::endl;
    }

    glValidateProgram(program);

    glGetProgramiv(program, GL_VALIDATE_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(program, 512, NULL, log);
        std::cerr << log << std::endl;
    }
}

Shader::~Shader()
{
    glDeleteProgram(program);
}
