/*****************************************************************//**
 * \file   main.cpp
 * \brief  Programme principal pour lire et afficher la température du capteur MCP9808.
 *
 * Ce programme initialise un capteur de température MCP9808 via I2C, lit la
 * température toutes les 5 secondes et affiche le résultat dans la console.
 * 
 * \author Alicia_B & Eden_C
 * \date   Septembre 2024
 *********************************************************************/

#include "sensor.h"
#include <iostream>
#include <unistd.h>  // Pour la fonction sleep()

using namespace std;

/**
 * \brief Fonction principale du programme.
 * 
 * Cette fonction initialise un capteur MCP9808, vérifie que l'initialisation
 * est réussie, et entre ensuite dans une boucle infinie pour lire et afficher
 * la température à intervalles de 5 secondes.
 * 
 * \return Retourne 0 si le programme s'exécute correctement.
 */
int main() {
    
    // Crée une instance du capteur MCP9808 avec l'adresse I2C 0x18
    MCP9808Sensor sensor(0x18);
    
    // Vérifie si l'initialisation du capteur échoue
    if (sensor.init() == false) {
        cout << "Erreur lors de l'initialisation du capteur\n"; // Message d'erreur
        return 0; // Sortie du programme si échec de l'initialisation
    }
    
    // Message confirmant que l'initialisation s'est bien déroulée
    cout << "Initialisation du capteur réussie !!!\n";
    
    // Boucle infinie pour lire et afficher la température toutes les 5 secondes
    while (true) {
        sensor.displayTemperature();  // Appelle la méthode pour afficher la température
        sleep(5);  // Attend 5 secondes avant la prochaine lecture
    }

    return 0;  // Retourne 0 si le programme s'est terminé correctement
}
