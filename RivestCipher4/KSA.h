#pragma once
#include <iostream>
#include <string>
using namespace std;

class KSA
{
private:
    unsigned char S[26], T[26];
    int j;

public:
    // Default Constructor
    KSA()
    {
        for (int i = 0; i < 26; i++)
        {
            S[i] = 0;
            T[i] = 0;
        }
        j = 0;
    }

    // Parameterized Constructor
    KSA(const string& key)
    {
        for (int i = 0; i < 26; i++)
        {
            S[i] = i;
            T[i] = key[i % key.length()];
        }
        j = 0;
    }

    // Copy Constructor
    KSA(KSA& obj)
    {
        for (int i = 0; i < 26; i++)
        {
            S[i] = obj.S[i];
            T[i] = obj.T[i];
        }
        j = obj.j;
    }

    // Keystream Generation 
    void keystream(string& key)
    {
        for (int i = 0; i < 26; i++)
        {
            S[i] = i;
            T[i] = key[i % key.length()];
        }

        j = 0;
        for (int i = 0; i < 26; i++)
        {
            j = (j + S[i] + T[i]) % 26;
            swap(S[i], S[j]);
        }
        j = 0;
    }

    // Pseudo-Random Generation Algorithm
    unsigned char* generateKeystream(int length)
    {
        unsigned char* keystream = new unsigned char[length];
        int i = 0;
        j = 0;

        for (int k = 0; k < length; k++)
        {
            i = (i + 1) % 26;
            j = (j + S[i]) % 26;
            swap(S[i], S[j]);
            keystream[k] = S[(S[i] + S[j]) % 26];
        }
        return keystream;
    }

    // Destructor
    ~KSA() {}
};