#include"opengl.h"


options_t* options_t::instance;
options_t* options_t::getOptionsInstance(){
	if(instance == NULL) instance = new options_t;
	return instance;
}

//For keyboard inputs
void key_callback(GLFWwindow *window, unsigned normal_key, int modifier_key){
	movement_t* movementInstance = movement_t::getInstance();
	options_t* options = options_t::getOptionsInstance();
	if(modifier_key == GLFW_MOD_SHIFT){
		//Add all the functions related to extra options like rotate left , undo etc..
		if(normal_key == 'L'){
			options->rotateLeft();
		}
		if(normal_key == 'D'){
			options->rotateDown();
		}
		if(normal_key == 'U'){
			movementInstance->undo_option();
		}
	}
	if(modifier_key == GLFW_MOD_ALT){
		//Add all the functions related to movement options 
		if(normal_key == 'l'){
			movementInstance->leftDown();
		}
		else if(normal_key == 'L'){
			movementInstance->direction = 1;
			movementInstance->leftDown();
			movementInstance->direction = 0;
		}
		else if(normal_key == 'r'){
			movementInstance->rightDown();
		}
		else if(normal_key == 'R'){
			movementInstance->direction = 1;
			movementInstance->rightDown();
			movementInstance->direction = 0;
		}
		else if(normal_key == 'u'){
			movementInstance->topLeft();
		}
		else if(normal_key == 'U'){
			movementInstance->direction = 1;
			movementInstance->topLeft();
			movementInstance->direction = 0;
		}
		else if(normal_key == 'd'){
			movementInstance->bottomLeft();
		}
		else if(normal_key == 'D'){
			movementInstance->direction = 1;
			movementInstance->bottomLeft();
			movementInstance->direction = 0;
		}
		else if(normal_key == 'v'){
			movementInstance->verticalMiddleDown();
		}
		else if(normal_key == 'V'){
			movementInstance->direction = 1;
			movementInstance->verticalMiddleDown();
			movementInstance->direction = 0;
		}
		else if(normal_key == 'h'){
			movementInstance->horizontalMiddleLeft();
		}
		else if(normal_key == 'H'){
			movementInstance->direction = 1;
			movementInstance->horizontalMiddleLeft();
			movementInstance->direction = 0;
		}
		else if(normal_key == 's'){
			movementInstance->shuffle();
		}
		else if(normal_key == 'f'){
			movementInstance->frontClockwise();
		}
		else if(normal_key == 'F'){
			movementInstance->direction = 1;
			movementInstance->frontClockwise();
			movementInstance->direction = 0;
		}
		else if(normal_key == 'b'){
			movementInstance->backClockwise();
		}
		else if(normal_key == 'B'){
			movementInstance->direction = 1;
			movementInstance->backClockwise();
			movementInstance->direction = 0;
		}
	}
}

//Rotating the whole cube is equivalent in rotating the three coloumns towards left
void options_t::rotateLeft(){
	moveInstance->topLeft();
	moveInstance->horizontalMiddleLeft();
	moveInstance->bottomLeft();
}

void options_t::rotateDown(){
	moveInstance->leftDown();
	moveInstance->verticalMiddleDown();
	moveInstance->rightDown();
}

//For zooming in and out
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
	static float scaleFactor=1;
	glm::mat4 zoom = glm::mat4(1.0f);
	if(yoffset>0) scaleFactor = scaleFactor*1.25; 
	else scaleFactor = scaleFactor*0.75;
	zoom = glm::scale(zoom,glm::vec3(scaleFactor,scaleFactor,scaleFactor));
	unsigned scaleLoc = glGetUniformLocation(shader_t::get_shader_program_id(),"scale");
    glUniformMatrix4fv(scaleLoc, 1, GL_FALSE, glm::value_ptr(zoom));
}

//For getting different views of the cube by clicking the mouse
void mouse_callback(GLFWwindow* window,int button, int action, int mods){
	if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
		options_t::getOptionsInstance()->differentAngleY();
	}
	if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
		options_t::getOptionsInstance()->differentAngleX();
	}
}

//shifts the view angle about Y axis
void options_t::differentAngleY(){
		if(cameraStatusY == 0){
			cameraPos = glm::vec3(-2.0f,0.0f,2.0f);
			cameraStatusY = 1;
		}
		else if(cameraStatusY == 1){
			cameraPos = glm::vec3(-2.0f,0.0f,-2.0f);
			cameraStatusY = 2;
		}
		else if(cameraStatusY == 2){
			cameraPos = glm::vec3(2.0f,0.0f,-2.0f);
			cameraStatusY = 3;
		}
		else if(cameraStatusY == 3){
			cameraPos = glm::vec3(2.0f,0.0f,2.0f);
			cameraStatusY = 4;
		}
		else if(cameraStatusY == 4){
			cameraPos = glm::vec3(0.0f,0.0f,2.0f);
			cameraStatusY = 0;
		}
	}

void options_t::differentAngleX(){
	switch(cameraStatusX){
		case 0: cameraPos = glm::vec3(0.0f,2.0f,2.0f);
				cameraUp = glm::vec3(0.0f,0.707f,-0.707f);
				cameraStatusX = 1;
				break;
		case 1: cameraPos = glm::vec3(0.0f,2.0f,-2.0f);
				cameraUp = glm::vec3(0.0f,0.707f,0.707f);
				cameraStatusX = 2;
				break;
		case 2: cameraPos = glm::vec3(0.0f,-2.0f,-2.0f);
				cameraUp = glm::vec3(0.0f,0.707,-0.707f);
				cameraStatusX = 3;
				break;
		case 3: cameraPos = glm::vec3(0.0f,-2.0f,2.0f);
				cameraUp  = glm::vec3(0.0f,0.707f,0.707f);
				cameraStatusX = 4;
				break;
		case 4: cameraPos = glm::vec3(0.0f,0.0f,2.0f);
				cameraUp = glm::vec3(0.0f,1.0f,0.0f);
				cameraStatusX = 0;
	}
}
