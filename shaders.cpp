#include"opengl.h"


//This file has shader programs and contains the code that compiles the shaders and links them to the current program

    unsigned shader_t :: shader_program_id;

    shader_t::shader_t(){shader_program_id = 0;}

    void shader_t::set_shaders(){
    const char *vertexShaderSource ="#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "uniform mat4 projection;\n"
	"uniform mat4 scale;\n"
    "void main()\n"
    "{\n"
    "   gl_Position =projection* scale *vec4(aPos, 1.0f);\n"
    "   ourColor = aColor;\n"
    "}\0";

    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(ourColor,1.0);\n"
    "}\n\0";
    // build and compile our shader program
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        
    }
    // link shaders
    shader_program_id = glCreateProgram();
    glAttachShader(shader_program_id, vertexShader);
    glAttachShader(shader_program_id, fragmentShader);
    glLinkProgram(shader_program_id);
    // check for linking errors
    glGetProgramiv(shader_program_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader_program_id, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

    
   unsigned shader_t:: get_shader_program_id(){
        set_shaders();
        return shader_program_id;
    }
    





    
