#pragma once
#include <cmath>
#include <array>

// add prototypes here

std::string solve(std::string encrypted_string);

std::string decryptCaesar(std::string ciphertext, int rshift);

char shiftChar(char c, int rshift);
