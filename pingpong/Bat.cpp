#include "Bat.h"

using namespace sf;

//Bat class constructor

Bat::Bat(float startX,float startY){
    m_Position.x=startX;
    m_Position.y=startY;
    m_shape.setSize(Vector2f(100.0,10.0));
    m_shape.setPosition(m_Position);
}

FloatRect Bat::get_Position(){
    return m_shape.getGlobalBounds();
}
RectangleShape Bat::get_Shape(){
    return m_shape;
}
void Bat::moveRight(){
    m_movingRight=true;
}
void Bat::moveLeft(){
    m_movingLeft=true;
}
void Bat::stopRight(){
    m_movingRight=false;
}
void Bat::stopLeft(){
    m_movingLeft=false;
}
void Bat::update(Time dt){
    if(m_movingRight){
        m_Position.x+=m_speed*dt.asSeconds();
        m_shape.setPosition(m_Position);
        if(m_Position.y > 1920){
            stopRight();
        }
    }
    if(m_movingLeft){
        m_Position.x-=m_speed*dt.asSeconds();
        m_shape.setPosition(m_Position);
        if(m_Position.x < 0){
            stopLeft();
        }
    }
}
