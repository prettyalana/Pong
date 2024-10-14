#pragma once 
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat 
{
    private: 
    // Length of the pong bat
    int m_Length = 100;
    // Height of the pong bat 
    int m_Height = 10;
    // Location on x axis
    int m_XPosition;
    // Location on y axis
    int m_YPosition;

    public: 
    void moveRight();
    void moveLeft();
};