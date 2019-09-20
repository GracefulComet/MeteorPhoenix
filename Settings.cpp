
#include"Settings.hpp"

Settings::Settings(){
    Load();
}

Settings::~Settings(){}

bool Settings::Load(){

    
    std::ifstream loading("Settings.ini");
    if(!loading.is_open()){
        loading.close();
        std::cout << "Unable to load/open Settings.ini. creating and saving default settings." << std::endl;
        m_width = 800;
        m_height = 600;
        m_FullScreen = false;
        m_scale = 2;
        this->Save();
        return false;
    }
    else{
        loading >> m_width >> m_height >>  m_FullScreen >> m_scale;
        loading.close(); 
        std::cout << "Settings loaded Successfully" << std::endl;       
        return true;

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

