Report Outline
This project involves data structures, C and header files, and functions related to encryption and decryption using the RSA method.

Lists
The project uses two main lists: Liste (a list of characters containing phrases) and Liste1 (a structured list containing encrypted phrases). The Liste1 structure includes a direct storage array.

Files
ELTINT.C: Defines primitives with necessary modifications for displaying paired elements.
ELTINT1.C: Defines primitives with necessary modifications for displaying encrypted elements.
ELTCHAR.C: Defines primitives with necessary modifications for displaying character elements containing phrases.
Functions
Encryption & Decryption
void crypt_decrypt(LISTE L, LISTE L2, LISTE1 LL, LISTE1 LL1, Pile pilePublic, Pile pilePrivee, int N);
This function encrypts a phrase using the RSA method and stores it in Liste1. It also decrypts the encrypted phrase by converting it back to its original ASCII codes and stores the result in another Liste1. It utilizes the chiffrement_dechiffrement function to encrypt an integer array using the RSA method.

Stacks Management

void piles(int tableau[100], int N, Pile pilePublic, Pile pilePrivee);
This function fills private and public stacks after selecting prime numbers from the array and calculating the necessary variables (n, e, d, phi).
