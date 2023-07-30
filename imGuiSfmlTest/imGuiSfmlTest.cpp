#include "imgui/imgui.h"
#include "imgui/imgui-SFML.h"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    ImGui::SFML::Init(window);

    bool circleExists = true;
    float circleRadius = 200.f;
    int circleSegments = 100;
    sf::CircleShape shape(circleRadius, circleSegments);
    shape.setFillColor(sf::Color(204, 77, 5));
    shape.setOrigin(circleRadius, circleRadius);
    shape.setPosition(400, 400);

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Settings");
        ImGui::Checkbox("Circle", &circleExists);
        ImGui::SliderFloat("Radius", &circleRadius, 100.f, 300.f);
        ImGui::SliderInt("Sides", &circleSegments, 3, 150);
        ImGui::End();  

        shape.setRadius(circleRadius);
        shape.setOrigin(circleRadius, circleRadius);
        shape.setPointCount(circleSegments);

        window.clear(sf::Color(18, 33, 43));
        if (circleExists)
            window.draw(shape);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
    return 0;
}
