// Copyright 2023 Andrew Jacobson
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <SFML/Graphics.hpp>

class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed);
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);

    // Transforms image using FibLFSR
    void transform(sf::Image &, FibLFSR *);
    // Display an encrypted copy of the picture, using the LFSR to do the encryption

    friend std::ostream &operator<<(std::ostream &, const FibLFSR &lfsr);

 private:
    std::vector<int> LFSR;
};
std::ostream &operator<<(std::ostream &, const FibLFSR &lfsr);
