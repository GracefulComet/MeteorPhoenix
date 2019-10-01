
#include"Settings.hpp"

Settings::Settings(){
    Load();
}

Settings::~Settings(){}

// bool Settings::Load(){

    
//     std::ifstream loading("Settings.ini");
//     if(!loading.is_open()){
//         loading.close();
//         std::cout << "Unable to load/open Settings.ini. creating and saving default settings." << std::endl;
//         m_width = 800;
//         m_height = 600;
//         m_FullScreen = false;
//         m_scale = 2;
//         this->Save();
//         return false;
//     }
//     else{
//         loading >> m_width >> m_height >>  m_FullScreen >> m_scale;
//         loading.close(); 
//         std::cout << "Settings loaded Successfully" << std::endl;       
//         return true;

//     }


// }

bool Settings::Load(){

#ifdef __ANDROID__
    SDL_RWops * loading = SDL_RWFromFile("Settings.ini", "r");
#endif
#ifndef __ANDROID__
    SDL_RWops * loading = SDL_RWFromFile("assets/Settings.ini", "r");
#endif

    if(loading != nullptr){
        std::cout << "settings opened with RWops" << std::endl;
        char* settingsContents = nullptr;
        settingsContents = new char[256]; 
        SDL_RWread(loading,settingsContents,sizeof(char), 256);

        std::string settingsContentss;
        settingsContentss = settingsContents;
        std::stringstream ss;
        ss << settingsContentss;
        ss >> m_width >> m_height >> m_FullScreen >> m_scale ;
        std::cout << "settings loaded successfully" << std::endl;
        // m_width = 800;
        // m_height = 600;
        // m_scale = 1.0f;
        // m_FullScreen = false;

        SDL_FreeRW(loading);
        delete settingsContents;
        return true;
    }
    else{
        std::cout << "settings did not open" << std::endl;
        m_width = 800;
        m_height = 600;
        m_scale = 1.0f;
        m_FullScreen = false;

        return false;
    }


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

