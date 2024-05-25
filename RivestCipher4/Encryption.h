#pragma once
#include <iostream>
using namespace std;

class Encryption
{
public:
    static string encrypt(const string& plaintext, const unsigned char* keystream)
    {
        string ciphertext = "";
        for (int i = 0; i < plaintext.length(); i++)
        {
            ciphertext += plaintext[i] ^ keystream[i];
        }
        return ciphertext;
    }
};