#pragma once
#include <iostream>
#include <fstream>
#include "common.h"

/*
* LOAD RAW DATA
*/


struct Data{
    char* filename;
    std::string dataType;
    GLenum GL_dataType;
    void* raw_data_ptr = NULL;
    int dimX;
    int dimY;
    int dimZ;
    int depth;
};

void loadRaw(Data &data);
