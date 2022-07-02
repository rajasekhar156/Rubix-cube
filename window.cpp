#include"opengl.h"



void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

GLFWwindow* init_window(){
        // glfw: initialize and configure
    glfwInit();
	//The below three function calls specify the minimum version of opengl required in the system inorder to render this graphic
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Rubik's Cube", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers--
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }
	//Display all instructions on console when the program starts
	printf("Instructions -- >\n");
	std::cout<<"- For all cube movements use ALT key as special key and for all rotations use SHIFT key as special key.\n";
	std::cout<<"And for the opposite directions we need to use capital letters instead of small letters\n";
    std::cout<<"- Key mappings :\n";
	std::cout<<"- ALT-l left down.\n- ALT-r right down.\n- ALT-u up right.\n- ALT-d down right.\n";
	std::cout<<"- ALT-v vertical down.\n- ALT-h horizontal right.\n- ALT-f front clockwise.\n";
	std::cout<<"- ALT-b back clockwise.\n";
	std::cout<<"- SHIFT-l rotate the whole cube towards left\n";
	std::cout<<"- SHIFT-d rotate the whole cube towards down\n";
    return window;
}

//call back functions

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
