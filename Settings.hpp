#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

class Settings{
    public:
    Settings();
    ~Settings();
    bool Load();
    bool Save();


    

    int m_width;
    int m_height;
    bool m_FullScreen;
    int m_scale;

};