#include "Bat.h"

// This is the constructor and it is called 
// when we create the object
Bat::Bat(float startX, float startY) : m_Position(startX, startY) 
{
    m_Shape.setSize(sf::Vector2f(50, 5));
    m_Shape.setPosition(m_Position);
}
FloatRect Bat::getPosition()
{
    return m_Shape.getGlobalBounds();
}
RectangleShape Bat::getShape()
{
    return m_Shape;
}
void Bat::moveLeft()
{
    m_MovingLeft = true;
}
void Bat::moveRight()
{
    m_MovingRight = true;
}
void Bat::stopLeft() 
{
    m_MovingLeft = false;
}
void Bat::stopRight()
{
    m_MovingRight = false;
}
void Bat::update(Time dt)
{
    if (m_MovingLeft) {
        m_Position.x -= m_Speed * dt.asSeconds();

        if (m_Position.x < 0) {
            m_Position.x = 0;
        }
    }
    if (m_MovingRight) {
        m_Position.x += m_Speed * dt.asSeconds();

        if (m_Position.x + m_Shape.getSize().x > 1440) {
            m_Position.x = 1440 - m_Shape.getSize().x;
        }
    }
    m_Shape.setPosition(m_Position);
}