#pragma once
#include <iostream>
using namespace std;

class Decryption
{
public:
    static string decrypt(const string& ciphertext, const unsigned char* keystream)
    {
        string plaintext = "";
        for (int i = 0; i < ciphertext.length(); i++)
        {
            plaintext += ciphertext[i] ^ keystream[i];
        }
        return plaintext;
    }
};