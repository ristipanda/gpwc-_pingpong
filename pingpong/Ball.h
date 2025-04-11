#pragma once //only one time
#include<SFML/Graphics.hpp>
using namespace sf;

class Ball{
    private:
    Vector2f m_Position;
    CircleShape m_shape;
    float m_speed=1000.f;
    float m_directionX=.2f;
    float m_directionY=.2f;

    public:
    Ball(float x,float y);
    FloatRect getPosition();
    CircleShape getShape();
    float getXvelocity();
    void reboundSides();
    void reboundBatOrTop();
    void reboundBottom();
    void update(Time dt);

};