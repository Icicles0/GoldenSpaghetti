#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(533, 533), "GoldenSpaghetti Base");

    // read map data
    string stringmap;

    ifstream MapStream("main.gsp");

    getline(MapStream, stringmap);

    // load map data into vector
    vector<int> mapData;

    for (int i = 0; i < 100; i++) {
        mapData.push_back(stringmap[i] - '0'); // thank you kyle for the fix
    }

    for (int i = 0; i < 100; i++) {
        cout << mapData[i] << endl;
    }

    /*
    vector<int> mapData =
      { 1, 7, 7, 7, 7, 7, 7, 7, 7, 2,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        5, 9, 9, 9, 9, 9, 9, 9, 9, 6,
        3, 8, 8, 8, 8, 8, 8, 8, 8, 4 }; // 10x10 grid
    */

    vector<sf::Sprite> sprites;

    sf::View viewZoom(sf::FloatRect(0.f, 0.f, 16.f*10, 16.f*10));
    window.setView(viewZoom);

    // create and load textures from emberwild
    sf::Texture topLeftGrassTex;
    sf::Texture topRightGrassTex;
    sf::Texture bottomLeftGrassTex;
    sf::Texture bottomRightGrassTex;
    sf::Texture leftGrassTex;
    sf::Texture rightGrassTex;
    sf::Texture topGrassTex;
    sf::Texture bottomGrassTex;
    sf::Texture GrassTex;
    topLeftGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(0, 0, 16, 16));
    topRightGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(16*2, 0, 16, 16));
    bottomLeftGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(0, 16*2, 16, 16));
    bottomRightGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(16*2, 16*2, 16, 16));
    leftGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(0, 16, 16, 16));
    rightGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(16*2, 16, 16, 16));
    topGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(16, 0, 16, 16));
    bottomGrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(16, 16*2, 16, 16));
    GrassTex.loadFromFile("emberwildterrain.png", sf::IntRect(16, 16, 16, 16));

    // process map data and create sprites

    // create loading buffer
    sf::Sprite spritebuffer;

    for (int i = 0; i < mapData.size(); i++) {
        switch (mapData[i]) {
        case 1:
            spritebuffer.setTexture(topLeftGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10))/10)*16));
            /* MATH ONLY WORKS FOR 10x10 GRID (maybe idk)
            i worked out the math above painfully in idle to take in the spot it is in in the array
            and put out the pixel cords x and y
            you get the x cord by modulating it by 10 which basically just deletes everything but the
            ones place getting the blocks to the right essentially then we * by 16 getting the pixels
            the y is much more complicated
            so you round down the tenths place thats the floor(i / 10) * 10 then you would / by 10
            getting the amount of blocks downward then *ing by 16 again
            */
            sprites.push_back(spritebuffer);
            break;
        case 2:
            spritebuffer.setTexture(topRightGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;
        case 3:
            spritebuffer.setTexture(bottomLeftGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;
        case 4:
            spritebuffer.setTexture(bottomRightGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;
        case 5:
            spritebuffer.setTexture(leftGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;
        case 6:
            spritebuffer.setTexture(rightGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;
        case 7:
            spritebuffer.setTexture(topGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;
        case 8:
            spritebuffer.setTexture(bottomGrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;
        case 9:
            spritebuffer.setTexture(GrassTex);
            spritebuffer.setPosition(sf::Vector2f((i % 10) * 16, (((floor(i / 10) * 10)) / 10) * 16));
            sprites.push_back(spritebuffer);
            break;

        }
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < sprites.size(); i++) {
            window.draw(sprites[i]);
        }
        window.display();
    }

    return 0;
}