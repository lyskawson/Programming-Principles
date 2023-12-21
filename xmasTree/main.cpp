#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

struct snowFlake {
    float x, y, speed;
};

void drawTree(sf::RenderWindow& window, const std::vector<snowFlake>  &snowflakes, sf::Clock &blinkClock)
{
    //tree
    sf::CircleShape tree1(250, 3);
    sf::CircleShape tree2(200, 3);
    sf::CircleShape tree3(150, 3);
    tree1.setFillColor(sf::Color(102, 204, 0));
    tree2.setFillColor(sf::Color(102, 204, 0));
    tree3.setFillColor(sf::Color(102, 204, 0));
    //bombs
    sf::CircleShape bomb1(30);
    bomb1.setFillColor(sf::Color::Red);
    sf::CircleShape bomb2(30);
    bomb2.setFillColor(sf::Color::Red);
    sf::CircleShape bomb3(30);
    bomb3.setFillColor(sf::Color::Red);
    sf::CircleShape bomb4(30);
    bomb4.setFillColor(sf::Color::Red);
    sf::CircleShape bomb5(30);
    bomb5.setFillColor(sf::Color::Red);
    //trunk
    sf::RectangleShape trunk(sf::Vector2f(120, 120));
    trunk.setFillColor(sf::Color(102, 51, 0));
    //star
    sf::RectangleShape star(sf::Vector2f(80, 80));
    star.setFillColor(sf::Color(255, 223, 0));
    star.setRotation(45);
    sf::RectangleShape star2(sf::Vector2f(80, 80));
    star2.setFillColor(sf::Color(255, 223, 0));
    //presents
    sf::RectangleShape pres1(sf::Vector2f(250, 100));
    pres1.setFillColor(sf::Color(255, 0, 255));
    sf::RectangleShape pres2(sf::Vector2f(110, 260));
    pres2.setFillColor(sf::Color(255, 128, 0));
    sf::RectangleShape pres3(sf::Vector2f(200, 200));
    pres3.setFillColor(sf::Color(0, 102, 204));
    //positions
    star.setPosition(490, 150);
    star2.setPosition(450, 170);
    trunk.setPosition(440, 765);
    tree1.setPosition(250, 390);
    tree2.setPosition(295, 300);
    tree3.setPosition(340, 210);
    pres1.setPosition(500, 800);
    pres2.setPosition(280, 650);
    pres3.setPosition(600, 700);
    bomb1.setPosition(500, 350);
    bomb2.setPosition(420, 450);
    bomb3.setPosition(530, 550);
    bomb4.setPosition(430, 620);
    bomb5.setPosition(550, 680);
    //draw
    window.draw(tree1);
    window.draw(tree2);
    window.draw(tree3);
    window.draw(trunk);
    window.draw(bomb5);
    window.draw(pres3);
    window.draw(pres1);
    window.draw(pres2);
    window.draw(bomb1);
    window.draw(bomb2);
    window.draw(bomb3);
    window.draw(bomb4);
    //draw star
    if (blinkClock.getElapsedTime().asSeconds() < 0.4) {
        window.draw(star);
        window.draw(star2);
    }
    //draw snowflakes
    sf::CircleShape snowflake(7);
    snowflake.setFillColor(sf::Color::White);
    for (const auto &flake : snowflakes)
    {
        snowflake.setPosition(flake.x, flake.y);
        window.draw(snowflake);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Christmas Tree");
    window.setFramerateLimit(60);

    std::srand(std::time(0));
    sf::Clock blinkClock;

    std::vector<snowFlake> snowflakes(100);
    for (int i = 0; i < 100; i++)
    {
        snowflakes[i].x = std::rand() % 1000;
        snowflakes[i].y = std::rand() % 1000;
        snowflakes[i].speed = std::rand() % 6 + 1;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto &flake : snowflakes)
        {
            flake.y = flake.y + flake.speed;
            if (flake.y > 900) {
                flake.y = 0;
                flake.x = std::rand() % 1000;
            }
        }

        window.clear();
        drawTree(window, snowflakes, blinkClock);
        if (blinkClock.getElapsedTime().asSeconds() > 0.8)
        {
            blinkClock.restart();
        }
        window.display();
    }

    return 0;
}
