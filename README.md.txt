# Image Encryption

## Description
Encodes and decodes an image using a Fibonacci LFSR. Takes a specified image and encodes it using a specified password, and decodes it if ran again with the same password and the output file that was produced from encoding.
### Installation
To run this program you need to have SFML installed. To install on linux run the command ```sudo apt-get install libsfml-dev``` <br>
To run the unit tests you also need the C++ Boost libraries. To install on linux run the command ```sudo apt-get install libboost-all-dev```
### Running the Code
Using the provided makefile, you can run the program with three command line inputs. ```./
### Features
To convert an alphanumeric password to 1s and 0s, I used the bitset class from the standard library to convert them. This is because a bitset stores the information through booleans. I converted the password to a seed by making a rang-based for loop to iterate over the given password then adding the characters to a bitset of size 16 then converting the bitset into a string to be used as the seed.
### Issues
When decrypting from the output file to get the original image, the SFML windows still say 'original' and 'encrypted'. When they should say 'original' and 'decrypted'. 

## Acknowledgements
<https://en.cppreference.com/w/cpp/utility/bitset>
