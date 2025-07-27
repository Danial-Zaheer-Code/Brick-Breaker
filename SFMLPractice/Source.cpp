#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
int main() {
    RenderWindow window(sf::VideoMode(1000, 600), "SFML Test");
    CircleShape ball(30.f);
	RectangleShape rect(Vector2f(30.f, 30.f));
	rect.setFillColor(Color::Green);
	rect.setPosition(200.f, 200.f);
    
    ball.setFillColor(Color::Red);
    ball.setPosition(300.f, 300.f);
    while (window.isOpen()) {
        Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

		Vector2f position = ball.getPosition();
		Vector2f position2 = ball.getPosition();
        window.clear(Color::Cyan);
        window.draw(ball);
		window.draw(rect);
        window.display();
    }

    return 0;
}