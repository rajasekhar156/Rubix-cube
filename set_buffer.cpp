#include"opengl.h"

unsigned set_buffer::indices[NOPEICES][6]={   

    // squares on front face
    0, 1, 2, 2, 3, 0,/*{{{*/
    4, 5, 6, 6, 7, 4,
    8, 9, 10, 10, 11, 8,
    12, 13, 14, 14, 15, 12,
    16, 17, 18, 18, 19, 16,
    20, 21, 22, 22, 23, 20,
    24, 25, 26, 26, 27, 24,
    28, 29, 30, 30, 31, 28,
    32, 33, 34, 34, 35, 32,

    // squares on right side
    36, 37, 38, 38, 39, 36,
    40, 41, 42, 42, 43, 40,
    44, 45, 46, 46, 47, 44,
    48, 49, 50, 50, 51, 48,
    52, 53, 54, 54, 55, 52,
    56, 57, 58, 58, 59, 56,
    60, 61, 62, 62, 63, 60,
    64, 65, 66, 66, 67, 64,
    68, 69, 70, 70, 71, 68,

    // squares on back side
    72, 73, 74, 74, 75, 72,
    76, 77, 78, 78, 79, 76,
    80, 81, 82, 82, 83, 80,
    84, 85, 86, 86, 87, 84,
    88, 89, 90, 90, 91, 88,
    92, 93, 94, 94, 95, 92,
    96, 97, 98, 98, 99, 96,
    100, 101, 102, 102, 103, 100,
    104, 105, 106, 106, 107, 104,


    // squares on left side
    108, 109, 110, 110, 111, 108,
    112, 113, 114, 114, 115, 112,
    116, 117, 118, 118, 119, 116,
    120, 121, 122, 122, 123, 120,
    124, 125, 126, 126, 127, 124,
    128, 129, 130, 130, 131, 128,
    132, 133, 134, 134, 135, 132,
    136, 137, 138, 138, 139, 136,
    140, 141, 142, 142, 143, 140,
    
    // squares on top side
    144, 145, 146, 146, 147, 144,
    148, 149, 150, 150, 151, 148,
    152, 153, 154, 154, 155, 152,
    156, 157, 158, 158, 159, 156,
    160, 161, 162, 162, 163, 160,
    164, 165, 166, 166, 167, 164,
    168, 169, 170, 170, 171, 168,
    172, 173, 174, 174, 175, 172,
    176, 177, 178, 178, 179, 176,

    // squares on bottom side
    180, 181, 182, 182, 183, 180,
    184, 185, 186, 186, 187, 184,
    188, 189, 190, 190, 191, 188,
    192, 193, 194, 194, 195, 192,
    196, 197, 198, 198, 199, 196,
    200, 201, 202, 202, 203, 200,
    204, 205, 206, 206, 207, 204,
    208, 209, 210, 210, 211, 208,
    212, 213, 214, 214, 215, 212,
/*}}}*/

};

void set_buffer::init_buffer(){
    glBufferData(GL_ARRAY_BUFFER, sizeof(data::filledCube), data::filledCube, GL_DYNAMIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_DYNAMIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

GLsizei set_buffer::indices_size(){return sizeof(indices);}


