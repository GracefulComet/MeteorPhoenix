#pragma once
#include <string>
#include "iostream"


std::string getFileAsString(std::string FileName);
//returns a string containing the whole file, unless the file doesnt exist or couldnt be opened properly
//then it returns NULL. this is completed by reading the code useing a cross platform C-code and then converted 
//from a c-style string to a std::string. you are meant to parce  the file using std::stringstream.