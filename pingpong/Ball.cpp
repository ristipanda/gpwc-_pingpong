#include "Ball.h"

using namespace sf;

//Ball class constructor

Ball::Ball(float startX, float startY){
    //Set the initial position of the ball
    m_Position.x=startX;
    m_Position.y=startY;
    m_shape.setRadius(10.0);
    m_shape.setPosition(m_Position);
}
FloatRect Ball::getPosition(){
    return m_shape.getGlobalBounds();
}
CircleShape Ball::getShape(){
    return m_shape;
}
float Ball::getXvelocity(){
    return m_directionX;
}
void Ball::reboundSides(){
    m_directionX*=-1;
}
void Ball::reboundBatOrTop(){
    m_directionY*=-1;
}
void Ball::reboundBottom(){
    m_Position.x=500;
    m_Position.y=0;
    m_directionY*=-1;
}
void Ball::update(Time dt){
    //update ball position
    m_Position.x+=m_directionX*m_speed*dt.asSeconds();
    m_Position.y+=m_directionY*m_speed*dt.asSeconds();
    m_shape.setPosition(m_Position);
}



