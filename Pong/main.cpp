//
//  main.cpp
//  Pong
//
//  Created by Alana Edwards on 10/14/24.
//

#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main()
{
    // Create video mode object
    VideoMode vm(VideoMode::getDesktopMode());
    // Create and open a window for the game
    RenderWindow window(vm, "Pong");
    int score = 0;
    int lives = 3;

    // Create a bat at the bottom center of the screen
    Bat bat(1440 / 2, 900 - 20);

    // Ball will be added later
    Ball ball(1440 / 2, 0);

    // Create a text object called hud
    Text hud;

    // Retro style font
    Font font;
    font.loadFromFile("/Users/alana/alana-fullstackdev/Pong/fonts/DS-DIGI.TTF");

    // Set the font to the Text object hud
    hud.setFont(font);

    // Make the font big
    hud.setCharacterSize(75);

    // Choose a color
    hud.setFillColor(Color::White);

    hud.setPosition(20, 20);

    // Here is the clock for timing everything
    Clock clock;
    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
                // Quit the game when the window is closed
                window.close();
        }

        // Handle the player quitting
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
        {
            window.close();
        }

        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
        {
            bat.moveLeft();
        }
        else
        {
            bat.stopLeft();
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
        {
            bat.moveRight();
        }
        else
        {
            bat.stopRight();
        }

        // Update the bat, the ball, and the HUD
        // Update the delta time
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        // Update the HUD text
        std::stringstream ss;
        ss << "Score:" << score << " Lives:" << lives;
        hud.setString(ss.str());

        // Draw the bat, the ball, and the HUD
        window.clear();
        window.draw(hud);
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.display();
    }

    return 0;
}
