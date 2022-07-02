#ifndef _DATA_
#define _DATA_

#define NOPEICES 6*9
#define NODATAPOINTS 6*9*4*6


struct vectorCord{
	float xCord, yCord, zCord, rCol, gCol, bCol;
};

//It would be useful if you want to add some cube puzzles
enum class choice_t{shuffled , noCubes};

class data{
public:
    static float cubeSize;
	static float gap;
    static float filledCube[NODATAPOINTS];
	static struct vectorCord splitCube[static_cast<int>(choice_t::noCubes)][NOPEICES][4] ;
    static unsigned choice; //This will be useful if you have some cube puzzles
//	static choice_t choice;
	//copies the data from splitCube to filledCube which is passed to GPU
	static void buildCube();

};


#endif
