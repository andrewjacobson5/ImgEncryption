// Copyright 2023 Andrew Jacobson
#include <iostream>
#include <string>
#include <bitset>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"

int main(int argc, char *argv[]) {
    sf::Image originalImage;  // init image object
    sf::Image encryptedImage;  // init image object
    argc = 3;  // how many arguments to expect from command line
    if (!originalImage.loadFromFile(argv[1]))  // load image from file
        return -1;  // return -1 on error

    if (!encryptedImage.loadFromFile(argv[2]))  // load encryted image from file
        return -1;                            // return -1 on error

    std::string password = argv[3];
    // initialize password to the third argument from the command line
    std::string seed;  // declare seed string to be made from bitset conversion
    for (char c : password) {  // for each char in the password string
        seed += std::bitset<16>(c).to_string();
        // convert the characters to 1s and 0s, then converting the bitset to a string.
    }
    FibLFSR photo(seed);  // initialize FibLFSR obj w/ seed
    photo.transform(encryptedImage, &photo);  // call transform on FibLFSR obj

    sf::Vector2u size = originalImage.getSize();
    // set size of the vector to the size of the image's size
    sf::RenderWindow window1(sf::VideoMode(size.x, size.y), "original");
    // init RenderWindow obj to size of the image
    sf::RenderWindow window2(sf::VideoMode(size.x, size.y), "encrypted");

    sf::Texture originalImage_texture;                  // init texture obj
    originalImage_texture.loadFromImage(originalImage);  // load texture from image

    sf::Texture encryptedImage_texture;
    encryptedImage_texture.loadFromImage(encryptedImage);

    sf::Sprite originalImage_sprite;  // inint sprite obj
    originalImage_sprite.setTexture(originalImage_texture);
    // set sprite texture to the texture obj

    sf::Sprite encryptedImage_sprite;
    encryptedImage_sprite.setTexture(encryptedImage_texture);

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }
        window1.clear();
        window1.draw(originalImage_sprite);
        window1.display();
        window2.clear();
        window2.draw(encryptedImage_sprite);
        window2.display();
    }

    if (!encryptedImage.saveToFile(argv[2]))  // if encrypted image is not saved to file
        return -1;                          // return -1 on error

    return 0;
}
