#pragma once
#include "common.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

GLuint loadShader(const char* vertex_shader_file, const char* fragment_shader_file);

std::string readFile(const char *filePath);
