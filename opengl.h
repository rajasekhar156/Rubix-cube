#ifndef _OPENGL_
#define _OPENGL_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stack>
#include <functional>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "data.h"
#include <time.h>
#include <algorithm>
#include <gtest/gtest.h>
#define NOMOVEMENTS 8 //This will be changed if new movements are added




GLFWwindow* init_window();

//CallBackfunctions
void key_callback(GLFWwindow *window, unsigned normal_key, int modifier_key);//Defined in options.cpp file
void scroll_callback(GLFWwindow *window, double xoffset, double yoffset);
void processInput(GLFWwindow *window); //Defined in window.cpp file
void framebuffer_size_callback(GLFWwindow* window, int width, int height);//Defined in window.cpp file
void mouse_callback(GLFWwindow *window, int button, int action, int mods);

//a singleton class because we should have only one shader
//This class creates the shaders and atlast what we want is the id of shader program created

class shader_t{
    private:
    static unsigned shader_program_id;
    shader_t();
    static void set_shaders();
    public:
    static unsigned get_shader_program_id();
};


// In this atlast we want the size of indices to render the cube
class set_buffer{
    public:
    set_buffer()=default;
    static unsigned indices[NOPEICES][6];
	static GLsizei indices_size();

/**
 * It loads (saves) the data in to the buffer that is binded to GPU
*/
	static void init_buffer();
};




//we should have only one history maintainer and one set ofmovement matrix
//hence it is better to use singleton here
class movement_t{
private:
	static movement_t* Instance;
	data tempMoveObj;
	std::stack<std::pair<unsigned,bool>> history;
	movement_t()=default;
	bool undoStatus = 0;
public:
	bool direction=0 ;// 0 if it is in the standard direction and 1 if it is in opposite direction
	std::vector<unsigned>peiceNumbers;
	std::vector<unsigned>peiceNumbersSide;
	static movement_t* getInstance();
	//reverse if direction=1
	void reverseDirection();
	//Changes the colors of the indices provided in peiceNumbers and peiceNumbersSide so that it appears as if the peices are rotated
	void swapColors(const unsigned x, const unsigned y);
	void move();
	void moveSide();
	void undo_option();
	void shuffle();
	//Movements
	void leftDown();
	void rightDown();
	void topLeft();
	void bottomLeft();
	void verticalMiddleDown();
	void horizontalMiddleLeft();
	void frontClockwise();
	void backClockwise();
};

//This class takes care of additional options 
class options_t{
private:
	static options_t* instance;
	options_t()=default;
	glm::mat4 scale= glm::mat4(1.0f);
	movement_t* moveInstance = movement_t::getInstance();
public:
	//camera quantities are used for getting differnt views of the cube
	glm::vec3 cameraPos = glm::vec3(0.0f,0.0f,2.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f,1.0f,0.0f);
	//cameraStatus keeps track of the placement of the camera
	unsigned cameraStatusY=0;
	unsigned cameraStatusX=0;
	static options_t* getOptionsInstance();
	//To completely rotate the cube along Y axis and X axis
	void rotateLeft();
	void rotateDown();
	void differentAngleY(); //This function will change the values of cameraPos and camerUp 
	void differentAngleX();

};

#endif
