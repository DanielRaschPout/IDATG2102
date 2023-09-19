/**
 * @file Oblig2Short.cpp
 * @author Daniel Fernando Petter Rasch-Pout (dfraschp@gmail.com)
 * @brief To funksjoner for Oblig 2.
 *        Oppgave A: Skriver ut ALLE noder med ID i intervallet 'min'-'max'.
 *       Oppgave B: Skriver alle VENSTRE BLADNODER i treet.
 * 
 * @date 20-09-2023
 * 
 * 
 */


#include <iostream>
using namespace std;

/**
 *  OPPGAVE A: Skriver ut ALLE noder med ID i intervallet 'min'-'max'.
 *
 *  @param   node   -  Noden som skal besøkes/undersøkes
 *  @param   min    -  minste verdi for en utskrevet node sin ID
 *  @param   max    -  største verdi for en utskrevet node sin ID
 */
void skrivIntervall(const Node* node, const int min, const int max) {

    if (!node) return;  //  Tomt tre.

    if (node->ID >= min && node->ID <= max)
        cout << node->ID << " ";

    // Sjekker om noden har barn, og om noden er i intervallet.
    skrivIntervall(node->left, min, max);
    skrivIntervall(node->right, min, max);
}


/**
 *  OPPGAVE B: Skriver alle VENSTRE BLADNODER i treet.
 *
 *   @param   node  -  Noden som skal besøkes.
 */
void skrivVenstreBladnode(const Node* node) {

    if (!node) return;  //  Tomt tre.

    // Sjekker om noden til venstre eksisterer, og om den har barn
    if (node->left != nullptr && !node->left->left && !node->left->right)
        cout << node->left->ID << " ";
    
    skrivVenstreBladnode(node->left);
    skrivVenstreBladnode(node->right);
}