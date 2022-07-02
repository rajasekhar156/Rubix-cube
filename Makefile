LIB_FLAGS = -Wall -lglfw -lX11 -lXrandr -lpthread -ldl 
GTEST_FLAGS = -lgtest -lgtest_main 
SRC = main
SFML_FLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
SRC = main
.PHONY : clean 

$(SRC) : $(SRC).cpp menu.o set_buffer.o data.o shaders.o window.o options.o movement.o glad.o  opengl.h menu.h
	g++ -o $(SRC) $(SRC).cpp menu.o set_buffer.o data.o shaders.o window.o options.o movement.o glad.o $(LIB_FLAGS) $(SFML_FLAGS)

menu.o : menu.cpp menu.h
	g++ -c menu.cpp 

set_buffer.o : set_buffer.cpp opengl.h
	g++ -c set_buffer.cpp 

data.o : data.cpp opengl.h
	g++ -c data.cpp 

shaders.o : shaders.cpp opengl.h
	g++ -c shaders.cpp 

window.o : window.cpp opengl.h
	g++ -c window.cpp 

options.o : options.cpp opengl.h
	g++ -c options.cpp 

movement.o : movement.cpp opengl.h
	g++ -c movement.cpp 




clean : 
	rm  set_buffer.o data.o shaders.o window.o options.o movement.o menu.o
