#include "components/component.h"

class RectColliderComponent : Component{
    public:
        enum CollidingDirection{
            UP=0,
            RIGHT,
            DOWN,
            LEFT,
        };

        RectColliderComponent();
        RectColliderComponent(float, float, float, float);

        void setColliding(bool);
        void setCollidingDirection(CollidingDirection);
        void setX(float);
        void setY(float);
        void setWidth(float);
        void setHeight(float);
        
        bool getColliding();
        CollidingDirection getCollidingDirection();
        float getX();
        float getY();
        float getWidth();
        float getHeight();
    private:

        bool m_isColliding;
        CollidingDirection m_direction;        

        float m_x;
        float m_y;
        float m_width;
        float m_height;
};
