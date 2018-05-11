#include <SFML/Graphics.hpp>
#include "World.h"



int main()
{
    //initialize world
    World world;

    world.randomWorld();

    //initialize avatar

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
                //avatar.findPath(target);//************
            }
        }//event loop ends

        //logic
        //world.updateWorld(avatar.worldPos, 500);

        //view.setCenter(avatar.postion.x, avatar.postion.y);

        //output
        window.setView(view);
        window.clear();

        //world.displayWorld(avatar.worldPos, 500);

        window.display();
    }//main loop ends

    return EXIT_SUCCESS;
}
