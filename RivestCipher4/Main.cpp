#include "KSA.h"
#include "Encryption.h"
#include "Decryption.h"

int main()
{
    string key; // Secret key
    string plaintext;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the secret key: ";
    getline(cin, key);

    KSA keyGen;
    keyGen.keystream(key);
    unsigned char* KeyStream = keyGen.generateKeystream(plaintext.length());

    cout << "-----------------------------\n";
    string ciphertext = Encryption::encrypt(plaintext, KeyStream);
    cout << "The Encrypted Text is: " << ciphertext << endl;

    string decryptedText = Decryption::decrypt(ciphertext, KeyStream);
    cout << "The Decrypted Text is: " << decryptedText << endl;
    cout << "-----------------------------\n";

    // Free memory
    delete[] KeyStream;

    return 0;
}