#ifndef SHADER_UTILS_CLASS_H
#define SHADER_UTILS_CLASS_H

#include<iostream>
#include<fstream>
#include<sstream>
#include"GLEW/glew.h"

unsigned int CompileShader(unsigned int type, std::string& src);

unsigned int CreateShader(std::string& vertexSrc, std::string& fragmentSrc);

std::string ParseShader(const char* path);
#endif