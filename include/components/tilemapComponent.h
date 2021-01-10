#include "components/component.h"

class TilemapComponent : public Component{
    public:
        TilemapComponent();
        TilemapComponent(std::string);
        
        void setTilemapSource(std::string);
        std::string getTilemapSource();
    private:
        std::string m_tilemapSource = "";



};
