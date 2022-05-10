#include<iostream>

unsigned int CompileShader(unsigned int type, std::string& src);

unsigned int CreateShader(std::string& vertexSrc, std::string& fragmentSrc);

std::string ParseShader(const char* path);