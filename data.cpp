#include"opengl.h"

//choice_t data::choice;
unsigned data::choice=1;
float data::filledCube[NODATAPOINTS];
float data::cubeSize = 1.50f;
float data::gap = 0.03f;

/*
 * we need a single array to render the cube so we copy all the splits into an array and send that into buffer
 * */

void data::buildCube(){
    for (unsigned j = 0; j < NOPEICES; j++) {
      for (unsigned i = 0; i < 4; i++) {
        filledCube[6* i + 24 * j] 	   = splitCube[choice-1][j][i].xCord;
        filledCube[6 * i + 24 * j + 1] = splitCube[choice-1][j][i].yCord;
        filledCube[6 * i + 24 * j + 2] = splitCube[choice-1][j][i].zCord;
        filledCube[6 * i + 24 * j + 3] = splitCube[choice-1][j][i].rCol;
        filledCube[6 * i + 24 * j + 4] = splitCube[choice-1][j][i].gCol;
        filledCube[6 * i + 24 * j + 5] = splitCube[choice-1][j][i].bCol;
      }
    }
}


//Position and Color coordinates of all the cube squares
struct vectorCord data::splitCube[static_cast<int>(choice_t::noCubes)][NOPEICES][4] = {
//front face green color {{{

	      - cubeSize/2,       cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
    - cubeSize/6-2*gap/3,       cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
    - cubeSize/6-2*gap/3,   cubeSize/6+2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
        - cubeSize/2,   cubeSize/6+2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
 
     - cubeSize/6+gap/3,      cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6-gap/3,      cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6-gap/3,  cubeSize/6+2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
     - cubeSize/6+gap/3,  cubeSize/6+2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,

       cubeSize/6+2*gap/3,      cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
           cubeSize/2,      cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
           cubeSize/2,  cubeSize/6+2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6+2*gap/3,  cubeSize/6+2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,

         - cubeSize/2,  cubeSize/6-gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
     - cubeSize/6-2*gap/3,  cubeSize/6-gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
     - cubeSize/6-2*gap/3,- cubeSize/6+gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
         - cubeSize/2,- cubeSize/6+gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,

     - cubeSize/6+gap/3,  cubeSize/6-gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6-gap/3,  cubeSize/6-gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6-gap/3,- cubeSize/6+gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
     - cubeSize/6+gap/3,- cubeSize/6+gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,

       cubeSize/6+2*gap/3,  cubeSize/6-gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
           cubeSize/2,  cubeSize/6-gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
           cubeSize/2,- cubeSize/6+gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6+2*gap/3,- cubeSize/6+gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,

         - cubeSize/2,- cubeSize/6-2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
     - cubeSize/6-2*gap/3,- cubeSize/6-2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
     - cubeSize/6-2*gap/3,    - cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
         - cubeSize/2,    - cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,

     - cubeSize/6+gap/3,- cubeSize/6-2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6-gap/3,- cubeSize/6-2*gap/3,       cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6-gap/3,    - cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,
     - cubeSize/6+gap/3,    - cubeSize/2,       cubeSize/2,  0.0f, 1.0f, 0.0f,

       cubeSize/6+2*gap/3, - cubeSize/6-2*gap/3,      cubeSize/2,  0.0f, 1.0f, 0.0f,
           cubeSize/2, - cubeSize/6-2*gap/3,      cubeSize/2,  0.0f, 1.0f, 0.0f,
           cubeSize/2,     - cubeSize/2,      cubeSize/2,  0.0f, 1.0f, 0.0f,
       cubeSize/6+2*gap/3,     - cubeSize/2,      cubeSize/2,  0.0f, 1.0f, 0.0f,

        //right face yellow color

           cubeSize/2,       cubeSize/2,      cubeSize/2,  1.0f, 1.0f, 0.0f,
           cubeSize/2,       cubeSize/2,  cubeSize/6+2*gap/3,  1.0f, 1.0f, 0.0f,
           cubeSize/2,   cubeSize/6+2*gap/3,  cubeSize/6+2*gap/3,  1.0f, 1.0f, 0.0f,
           cubeSize/2,   cubeSize/6+2*gap/3,      cubeSize/2,  1.0f, 1.0f, 0.0f,

           cubeSize/2,       cubeSize/2,  cubeSize/6-gap/3,  1.0f, 1.0f, 0.0f,
           cubeSize/2,       cubeSize/2,- cubeSize/6+gap/3,  1.0f, 1.0f, 0.0f,
           cubeSize/2,   cubeSize/6+2*gap/3,- cubeSize/6+gap/3,  1.0f, 1.0f, 0.0f,
           cubeSize/2,   cubeSize/6+2*gap/3,  cubeSize/6-gap/3,  1.0f, 1.0f, 0.0f,

           cubeSize/2,       cubeSize/2,- cubeSize/6-2*gap/3,  1.0f, 1.0f, 0.0f,
           cubeSize/2,       cubeSize/2,    - cubeSize/2,  1.0f, 1.0f, 0.0f,
           cubeSize/2,   cubeSize/6+2*gap/3,    - cubeSize/2,  1.0f, 1.0f, 0.0f,
           cubeSize/2,   cubeSize/6+2*gap/3,- cubeSize/6-2*gap/3,  1.0f, 1.0f, 0.0f,

          cubeSize/2,   cubeSize/6-gap/3,       cubeSize/2,  1.0f, 1.0f, 0.0f,
          cubeSize/2,   cubeSize/6-gap/3,   cubeSize/6+2*gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6+gap/3,   cubeSize/6+2*gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6+gap/3,       cubeSize/2,  1.0f, 1.0f, 0.0f,

          cubeSize/2,   cubeSize/6-gap/3,   cubeSize/6-gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2,   cubeSize/6-gap/3, - cubeSize/6+gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6+gap/3, - cubeSize/6+gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6+gap/3,   cubeSize/6-gap/3,  1.0f, 1.0f, 0.0f,

          cubeSize/2,   cubeSize/6-gap/3, - cubeSize/6-2*gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2,   cubeSize/6-gap/3,     - cubeSize/2,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6+gap/3,     - cubeSize/2,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6+gap/3, - cubeSize/6-2*gap/3,  1.0f, 1.0f, 0.0f,

          cubeSize/2, - cubeSize/6-2*gap/3,       cubeSize/2,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6-2*gap/3,   cubeSize/6+2*gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2,     - cubeSize/2,   cubeSize/6+2*gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2,     - cubeSize/2,       cubeSize/2,  1.0f, 1.0f, 0.0f,

          cubeSize/2, - cubeSize/6-2*gap/3,   cubeSize/6-gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6-2*gap/3, - cubeSize/6+gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2,     - cubeSize/2, - cubeSize/6+gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2,     - cubeSize/2,   cubeSize/6-gap/3,  1.0f, 1.0f, 0.0f,

          cubeSize/2, - cubeSize/6-2*gap/3, - cubeSize/6-2*gap/3,  1.0f, 1.0f, 0.0f,
          cubeSize/2, - cubeSize/6-2*gap/3,     - cubeSize/2,  1.0f, 1.0f, 0.0f,
          cubeSize/2,     - cubeSize/2,     - cubeSize/2,  1.0f, 1.0f, 0.0f,
          cubeSize/2,     - cubeSize/2, - cubeSize/6-2*gap/3,  1.0f, 1.0f, 0.0f,

        //back face blue color

          cubeSize/2,       cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6+2*gap/3,       cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6+2*gap/3,   cubeSize/6+2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
          cubeSize/2,   cubeSize/6+2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

      cubeSize/6-gap/3,       cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6+gap/3,       cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6+gap/3,   cubeSize/6+2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6-gap/3,   cubeSize/6+2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

    - cubeSize/6-2*gap/3,       cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
        - cubeSize/2,       cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
        - cubeSize/2,   cubeSize/6+2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6-2*gap/3,   cubeSize/6+2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

          cubeSize/2,   cubeSize/6-gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6+2*gap/3,   cubeSize/6-gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6+2*gap/3, - cubeSize/6+gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
          cubeSize/2, - cubeSize/6+gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

      cubeSize/6-gap/3,   cubeSize/6-gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6+gap/3,   cubeSize/6-gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6+gap/3, - cubeSize/6+gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6-gap/3, - cubeSize/6+gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

    - cubeSize/6-2*gap/3,   cubeSize/6-gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
        - cubeSize/2,   cubeSize/6-gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
        - cubeSize/2, - cubeSize/6+gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6-2*gap/3, - cubeSize/6+gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

          cubeSize/2, - cubeSize/6-2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6+2*gap/3, - cubeSize/6-2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6+2*gap/3,     - cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
          cubeSize/2,     - cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

      cubeSize/6-gap/3, - cubeSize/6-2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6+gap/3, - cubeSize/6-2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6+gap/3,     - cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
      cubeSize/6-gap/3,     - cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

    - cubeSize/6-2*gap/3, - cubeSize/6-2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
        - cubeSize/2, - cubeSize/6-2*gap/3,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
        - cubeSize/2,     - cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,
    - cubeSize/6-2*gap/3,     - cubeSize/2,     - cubeSize/2,  0.0f, 0.0f, 1.0f,

      //left face white colour

        - cubeSize/2,       cubeSize/2,     - cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,       cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,   cubeSize/6+2*gap/3, - cubeSize/6-2*gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,   cubeSize/6+2*gap/3,     - cubeSize/2,   1.0f, 1.0f, 1.0f,

        - cubeSize/2,       cubeSize/2, - cubeSize/6+gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,       cubeSize/2,   cubeSize/6-gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,   cubeSize/6+2*gap/3,   cubeSize/6-gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,   cubeSize/6+2*gap/3, - cubeSize/6+gap/3,   1.0f, 1.0f, 1.0f,

        - cubeSize/2,       cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,       cubeSize/2,       cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,       cubeSize/6+2*gap/3,       cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,       cubeSize/6+2*gap/3,   cubeSize/6+2*gap/3,   1.0f, 1.0f, 1.0f,

        - cubeSize/2,   cubeSize/6-gap/3,     - cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,   cubeSize/6-gap/3, - cubeSize/6-2*gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6+gap/3, - cubeSize/6-2*gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6+gap/3,     - cubeSize/2,   1.0f, 1.0f, 1.0f,

        - cubeSize/2,   cubeSize/6-gap/3, - cubeSize/6+gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,   cubeSize/6-gap/3,   cubeSize/6-gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6+gap/3,   cubeSize/6-gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6+gap/3, - cubeSize/6+gap/3,   1.0f, 1.0f, 1.0f,

        - cubeSize/2,   cubeSize/6-gap/3,   cubeSize/6+2*gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,   cubeSize/6-gap/3,       cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6+gap/3,       cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6+gap/3,   cubeSize/6+2*gap/3,   1.0f, 1.0f, 1.0f,

        - cubeSize/2, - cubeSize/6-2*gap/3,     - cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6-2*gap/3, - cubeSize/6-2*gap/6,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,     - cubeSize/2, - cubeSize/6-2*gap/6,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,     - cubeSize/2,     - cubeSize/2,   1.0f, 1.0f, 1.0f,

        - cubeSize/2, - cubeSize/6-2*gap/3, - cubeSize/6+gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6-2*gap/3,   cubeSize/6-gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,     - cubeSize/2,   cubeSize/6-gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,     - cubeSize/2, - cubeSize/6+gap/3,   1.0f, 1.0f, 1.0f,

        - cubeSize/2, - cubeSize/6-2*gap/3,   cubeSize/6+2*gap/3,   1.0f, 1.0f, 1.0f,
        - cubeSize/2, - cubeSize/6-2*gap/3,       cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,     - cubeSize/2,       cubeSize/2,   1.0f, 1.0f, 1.0f,
        - cubeSize/2,     - cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 1.0f, 1.0f,

        //top face red color

        - cubeSize/2,       cubeSize/2,     - cubeSize/2,   1.0f, 0.0f, 0.0f,
    - cubeSize/6-2*gap/3,       cubeSize/2,     - cubeSize/2,   1.0f, 0.0f, 0.0f,
    - cubeSize/6-2*gap/3,       cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.0f, 0.0f,
        - cubeSize/2,       cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.0f, 0.0f,

    - cubeSize/6+gap/3,       cubeSize/2,     - cubeSize/2,   1.0f, 0.0f, 0.0f,
      cubeSize/6-gap/3,       cubeSize/2,     - cubeSize/2,   1.0f, 0.0f, 0.0f,      
      cubeSize/6-gap/3,       cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.0f, 0.0f,
    - cubeSize/6+gap/3,       cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.0f, 0.0f,

      cubeSize/6+2*gap/3,       cubeSize/2,     - cubeSize/2,   1.0f, 0.0f, 0.0f,
          cubeSize/2,       cubeSize/2,     - cubeSize/2,   1.0f, 0.0f, 0.0f,
          cubeSize/2,       cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.0f, 0.0f,
      cubeSize/6+2*gap/3,       cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.0f, 0.0f,

        - cubeSize/2,       cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.0f, 0.0f,
    - cubeSize/6-2*gap/3,       cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.0f, 0.0f,
    - cubeSize/6-2*gap/3,       cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.0f, 0.0f,
        - cubeSize/2,       cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.0f, 0.0f,

    - cubeSize/6+gap/3,       cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.0f, 0.0f,
      cubeSize/6-gap/3,       cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.0f, 0.0f,
      cubeSize/6-gap/3,       cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.0f, 0.0f,
    - cubeSize/6+gap/3,       cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.0f, 0.0f,

      cubeSize/6+2*gap/3,       cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.0f, 0.0f,
          cubeSize/2,       cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.0f, 0.0f,
          cubeSize/2,       cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.0f, 0.0f,
      cubeSize/6+2*gap/3,       cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.0f, 0.0f,

        - cubeSize/2,       cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.0f, 0.0f,
    - cubeSize/6-2*gap/3,       cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.0f, 0.0f,
    - cubeSize/6-2*gap/3,       cubeSize/2,       cubeSize/2,   1.0f, 0.0f, 0.0f,
        - cubeSize/2,       cubeSize/2,       cubeSize/2,   1.0f, 0.0f, 0.0f,

    - cubeSize/6+gap/3,       cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.0f, 0.0f,
      cubeSize/6-gap/3,       cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.0f, 0.0f,
      cubeSize/6-gap/3,       cubeSize/2,       cubeSize/2,   1.0f, 0.0f, 0.0f,
    - cubeSize/6+gap/3,       cubeSize/2,       cubeSize/2,   1.0f, 0.0f, 0.0f,

      cubeSize/6+2*gap/3,       cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.0f, 0.0f,
          cubeSize/2,       cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.0f, 0.0f,
          cubeSize/2,       cubeSize/2,       cubeSize/2,   1.0f, 0.0f, 0.0f,
      cubeSize/6+2*gap/3,       cubeSize/2,       cubeSize/2,   1.0f, 0.0f, 0.0f,



        //bottom face
        - cubeSize/2,     - cubeSize/2,       cubeSize/2,   1.0f, 0.647f, 0.0f,
    - cubeSize/6-2*gap/3,     - cubeSize/2,       cubeSize/2,   1.0f, 0.647f, 0.0f,
    - cubeSize/6-2*gap/3,     - cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.647f, 0.0f,
        - cubeSize/2,     - cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.647f, 0.0f,

    - cubeSize/6+gap/3,     - cubeSize/2,       cubeSize/2,   1.0f, 0.647f, 0.0f,
      cubeSize/6-gap/3,     - cubeSize/2,       cubeSize/2,   1.0f, 0.647f, 0.0f,
      cubeSize/6-gap/3,     - cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.647f, 0.0f,
    - cubeSize/6+gap/3,     - cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.647f, 0.0f,

      cubeSize/6+2*gap/3,     - cubeSize/2,       cubeSize/2,   1.0f, 0.647f, 0.0f,
          cubeSize/2,     - cubeSize/2,       cubeSize/2,   1.0f, 0.647f, 0.0f,
          cubeSize/2,     - cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.647f, 0.0f,
      cubeSize/6+2*gap/3,     - cubeSize/2,   cubeSize/6+2*gap/3,   1.0f, 0.647f, 0.0f,

        - cubeSize/2,     - cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.647f, 0.0f,
    - cubeSize/6-2*gap/3,     - cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.647f, 0.0f,
    - cubeSize/6-2*gap/3,     - cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.647f, 0.0f,
        - cubeSize/2,     - cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.647f, 0.0f,

    - cubeSize/6+gap/3,     - cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.647f, 0.0f,
      cubeSize/6-gap/3,     - cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.647f, 0.0f,
      cubeSize/6-gap/3,     - cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.647f, 0.0f,
    - cubeSize/6+gap/3,     - cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.647f, 0.0f,

      cubeSize/6+2*gap/3,     - cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.647f, 0.0f,
          cubeSize/2,     - cubeSize/2,   cubeSize/6-gap/3,   1.0f, 0.647f, 0.0f,
          cubeSize/2,     - cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.647f, 0.0f,
      cubeSize/6+2*gap/3,     - cubeSize/2, - cubeSize/6+gap/3,   1.0f, 0.647f, 0.0f,

        - cubeSize/2,     - cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.647f, 0.0f,
    - cubeSize/6-2*gap/3,     - cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.647f, 0.0f,
    - cubeSize/6-2*gap/3,     - cubeSize/2,     - cubeSize/2,   1.0f, 0.647f, 0.0f,
        - cubeSize/2,     - cubeSize/2,     - cubeSize/2,   1.0f, 0.647f, 0.0f,

    - cubeSize/6+gap/3,     - cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.647f, 0.0f,
      cubeSize/6-gap/3,     - cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.647f, 0.0f,
      cubeSize/6-gap/3,     - cubeSize/2,     - cubeSize/2,   1.0f, 0.647f, 0.0f,
    - cubeSize/6+gap/3,     - cubeSize/2,     - cubeSize/2,   1.0f, 0.647f, 0.0f,

      cubeSize/6+2*gap/3,     - cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.647f, 0.0f,
          cubeSize/2,     - cubeSize/2, - cubeSize/6-2*gap/3,   1.0f, 0.647f, 0.0f,
          cubeSize/2,     - cubeSize/2,     - cubeSize/2,   1.0f, 0.647f, 0.0f,
      cubeSize/6+2*gap/3,     - cubeSize/2,     - cubeSize/2,   1.0f, 0.647f, 0.0f/*}}}*/
	};
