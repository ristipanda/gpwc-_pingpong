#include "Bat.h"
#include "Ball.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
int main(){
    //create video mode object
    VideoMode vm(1366,768);

    //create window
    RenderWindow window(vm,"SFML",Style::Fullscreen);

    //create the bat
    Bat bat(1366/2.0,768-20);//position of bat 

    //create ball
    Ball ball(1366/2.0,0);

    Text hud;
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    hud.setFont(font);
    hud.setCharacterSize(75);
    hud.setFillColor(Color::White);
    hud.setPosition(20,20);
    hud.setString("Score: 0 Live: 3");

    //Initialise score and lives
    int score = 0;
    int lives = 3;

    //manage time
    Clock clock;
    while(window.isOpen()){
        //handle events
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        //Handle quiting game
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        //Handle the Right cursor
        if(Keyboard::isKeyPressed(Keyboard::Right)){
           if(bat.get_Position().left+bat.get_Position().width>1366){
            bat.stopRight();
           }else{
            bat.moveRight();
           }
        }else{
            bat.stopRight();
        }
        //Handle the Left cursor
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            if(bat.get_Position().left<0){
                bat.stopLeft();
            }else{
                bat.moveLeft();
            }
        }else{
            bat.stopLeft();
        }
        //update time
        Time dt=clock.restart();

        //update Bat
        bat.update(dt);

        //update ball
        ball.update(dt);

        //update score
        std::stringstream ss;
        ss << "Score: " << score << " Lives: " << lives;
        hud.setString(ss.str());

        //update the ball

        //ball hitting the bottom
        if(ball.getPosition().top > window.getSize().y){
            //reverse the ball direction
            ball.reboundBottom();
            //decrease lives
            lives--;
            if(lives < 1){
                //game over
                
                //reset score and lives
                score=0;
                lives=3;
            }
        }
        //ball hitting the top
        if(ball.getPosition().top < 0){
            //add score
            score++;
            //rebound
            ball.reboundBatOrTop();
        }
        //ball hitting the sides
        if(ball.getPosition().left < 0 || ball.getPosition().left+10 > window.getSize().x){
            //rebound
            ball.reboundSides();
        }
        //ball hitting the bat
        if(ball.getPosition().intersects(bat.get_Position())){
            //add score
            score++;
            //rebound
            ball.reboundBatOrTop();
        }


        //display
        window.clear();
        window.draw(hud);
        window.draw(bat.get_Shape());
        window.draw(ball.getShape());
        window.display();
    }
    return 0;
}