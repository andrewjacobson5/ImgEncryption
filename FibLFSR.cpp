// Copyright 2023 Andrew Jacobson

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "FibLFSR.hpp"

/// @brief Constructor for the FibLFSR class. Initializes a vector with the specified seed
/// @param seed , string seed given in the the constructor. Which is the put into the vector LFSR
FibLFSR::FibLFSR(std::string seed) {
    for (char p : seed) {
        LFSR.push_back(static_cast<int>(p - '0'));
    }
}

/// @brief Simulates a shift of the LFSR, with taps on the leftmost, 13th, 12th, and 10th bits.
/// @return the rightmost bit.
int FibLFSR::step() {
    int tapLeft = LFSR.front() ^ LFSR.at(2);
    // xor the front(leftmost) bit in the vector with the 13th bit
    int tap12 = tapLeft ^ LFSR.at(3);
    // xor the result above with the 12th bit in the vector
    int tap10 = tap12 ^ LFSR.at(5);
    // xor the result above with the 10th bit in the vector

    for (unsigned i = 0; i < LFSR.size() - 1; i++) {  // shift the bits over 1
        LFSR[i] = LFSR[i + 1];
    }

    LFSR[LFSR.size() - 1] = tap10;
    // add the completly xor'd bit to the end(rightmost) of the vector

    return LFSR.back();
    // return the righmost bit
}

/// @brief simulates k steps of the LFSR
/// @param k , number of steps to simulate
/// @return  , returns the value of the bit that has been extracted.
/// Which is the value of the last k bits in decimal
int FibLFSR::generate(int k) {
    int bit = 0;
    // initialize bit to 0
    for (int i = 0; i < k; i++) {
        // loops until simulates k bits
        bit *= 2;
        bit += step();
    }

    return bit;
}

/// @brief encodes an image by manipulating the pixels within an image
/// @param image SFML image object to encode
/// @param LFSR the LFSR object used to encode the image
void FibLFSR::transform(sf::Image &image, FibLFSR *LFSR) {
    sf::Color p;
    sf::Vector2u size = image.getSize();
    // int bitRed = LFSR->generate(8);
    // int bitGreen = LFSR->generate(8);
    // int bitBlue = LFSR->generate(8);
    for (unsigned x = 0; x < size.x; x++) {
        for (unsigned y = 0; y < size.y; y++) {
            p = image.getPixel(x, y);
            p.r = p.r ^ LFSR->generate(8);
            p.g = p.g ^ LFSR->generate(8);
            p.b = p.b ^ LFSR->generate(8);
            image.setPixel(x, y, p);
        }
    }
}

/// @brief overloads the << operator
/// @param outStream takes in the outStream by referance
/// @param lfsr takes in the lfsr object by reference to print out the contents of it's vector
/// @return returns the outStream
std::ostream &operator<<(std::ostream &outStream, const FibLFSR &lfsr) {
    for (unsigned i = 0; i < lfsr.LFSR.size(); i++) {
        // loops to print the vector
        outStream << lfsr.LFSR.at(i);
        // doesn't print new line because we want the bits on the same line
    }
    outStream << std::endl;
    // prints new line

    return outStream;
}
