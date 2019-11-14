
#include"Settings.hpp"

Settings::Settings(){
    Load();
}

Settings::~Settings(){}


bool Settings::Load(){


std::string loading;

loading = getFileAsString("Settings.ini");

    if(!loading.empty() ){
        std::stringstream ss;
        ss << loading;
        ss >> m_width >> m_height >> m_FullScreen >> m_scale ;
        std::cout << "settings loaded successfully" << std::endl;
        return true;
    }
    else{
        std::cout << "settings did not open" << std::endl;
        SDL_DisplayMode display;
        if( SDL_GetCurrentDisplayMode(0,&display)  == 0  ){
            //trys to get devices display settings and creates a window 
            #ifndef __ANDROID__
            m_width = display.w; 
            m_height= display.h;
            #endif
            #ifdef __ANDROID__
            m_height =display.w; // defaults to widescreen when on android
            m_width =display.h;  // TODO : check if this works on all/more devices
            #endif
        }else{
            m_width = 800;
            m_height= 600;
        }
        m_scale = 1.0f;
        m_FullScreen = false;

        return false;
    }

    return false;
}


bool Settings::Save(){
    std::ofstream saving( "Settings.ini", std::ios::trunc);
    if(!saving.is_open()){
        std::cout << "Failed to Save Settings" << std::endl;
        saving.close();
        return false;
    }else{
        saving << m_width << std::endl << m_height << std::endl << m_FullScreen << std::endl << m_scale << std::endl;
        saving.close();
        std::cout << "Saved Settings Success" << std::endl;
        return true;
    }

}

