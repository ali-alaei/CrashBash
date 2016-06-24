#include <SFML-2.3.2/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 748), "SFML works!");
    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
