#pragma once //only one time
#include<SFML/Graphics.hpp>
using namespace sf;
class Bat
{
        Vector2f m_Position;
        RectangleShape m_shape;
        float m_speed=1000.0f;
        bool m_movingRight=false;
        bool m_movingLeft=false;

        public:
        Bat(float startX,float startY);
        FloatRect get_Position();//for vector2f
        RectangleShape get_Shape();
        void moveRight();
        void moveLeft();
        void stopRight();
        void stopLeft();
        void update(Time dt);
};
