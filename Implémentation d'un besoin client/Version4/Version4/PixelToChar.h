#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector>
#include <array>
#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

const int size_p = 8;
using pal = std::vector<std::string>;

std::string PixelToStr(int pixel, pal palette);