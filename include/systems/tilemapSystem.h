#include "systems/system.h"

class TilemapSystem : public System{
    public:
        TilemapSystem(){}

        void start() override;
        void update() override;
        void render() override;

        virtual ~TilemapSystem(){}
};
