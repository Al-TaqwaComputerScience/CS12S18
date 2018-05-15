#include <SFML/Graphics.hpp>
#include "World.h"
#include "Avatar.h"


int main()
{
    //initialize world
    World world;

    world.randomWorld();

    //initialize avatar
    Avatar avatar;
    //temporary fix
    avatar.worldPos = CoordsW(0,0);

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::View view;
    world.setWindow(&window);
	// Start the game loop
    while (window.isOpen())
    {

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            //mouse click
            if (event.type == sf::Event::MouseButtonPressed)
            {
                CoordsP mousePos(event.mouseButton.x, event.mouseButton.y);
                //CoordsW target = screenToWorldCoords(view,mousePos); //************
                CoordsW target(event.mouseButton.x - view.getCenter().x - view.getSize().x/2,
                               event.mouseButton.y - view.getCenter().y - view.getSize().y/2);
                avatar.findPath(target);//************
            }
        }//event loop ends

        //logic
        world.updateWorld(avatar.worldPos, 500);

        view.setCenter(avatar.position.x, avatar.position.y);

        //output
        window.setView(view);
        window.clear();

        world.displayWorld(avatar.worldPos, 500);

        window.display();
    }//main loop ends

    return EXIT_SUCCESS;
}
