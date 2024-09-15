/*****************************************************************//**
 * \file   sensor.cpp
 * \brief  Implémentation de la classe MCP9808Sensor
 *
 * Ce fichier contient les définitions des méthodes de la classe
 * MCP9808Sensor. Il permet d'initialiser un capteur de température
 * MCP9808, de lire la température et de l'afficher via une 
 * communication I2C.
 *
 * \author Dioxigene
 * \date   Septembre 2024
 *********************************************************************/

#include "sensor.h"
#include <iostream>
#include <wiringPiI2C.h>
#include <unistd.h>

#define MCP9808_REG_CONFIG 0x01  ///< Registre de configuration du MCP9808
#define MCP9808_REG_AMBIENT_TEMP 0x05  ///< Registre de température ambiante du MCP9808

/**
 * \brief Constructeur de la classe MCP9808Sensor.
 * 
 * Initialise le capteur avec une adresse I2C spécifiée.
 * 
 * \param addr Adresse I2C du capteur.
 */
MCP9808Sensor::MCP9808Sensor(int addr) : address(addr), fd(-1), temperature(0.0) {}

/**
 * \brief Initialise la communication I2C avec le capteur.
 * 
 * Cette méthode configure le capteur MCP9808 en réinitialisant son
 * registre de configuration et en établissant la communication I2C.
 * 
 * \return true si l'initialisation est réussie, false sinon.
 */
bool MCP9808Sensor::init() {
    fd = wiringPiI2CSetup(address);
    if (fd == -1) {
        std::cerr << "Échec de l'initialisation de la communication I2C.\n";
        return false;
    }
    std::cout << "Communication I2C correctement configurée.\n";

    // Réinitialise le registre de configuration à 0x0000
    if (wiringPiI2CWriteReg16(fd, MCP9808_REG_CONFIG, 0x0000) == -1) {
        std::cerr << "Erreur lors de la configuration du capteur.\n";
        return false;
    }
    std::cout << "Registre de configuration du capteur réglé sur 0x0000.\n";

    return true;
}

/**
 * \brief Lit la température actuelle du capteur.
 * 
 * Cette méthode lit les données brutes de température à partir du registre
 * MCP9808, les traite pour obtenir la température en degrés Celsius.
 * 
 * \return La température en degrés Celsius, ou -1 en cas d'erreur.
 */
float MCP9808Sensor::getTemperature() {
    int rawTemp = wiringPiI2CReadReg16(fd, MCP9808_REG_AMBIENT_TEMP);
    if (rawTemp == -1) {
        std::cerr << "Erreur de lecture de la température.\n";
        return -1;
    }

    // Inversion des octets pour corriger l'endianness
    int temp = ((rawTemp & 0xff) << 8 | (rawTemp & 0xff00) >> 8);
    temp &= 0x0FFF;  // Masquage des bits de contrôle

    temperature = temp / 16.0;  // Conversion en degrés Celsius
    return temperature;
}

/**
 * \brief Affiche la température actuelle sur la console.
 * 
 * Appelle la méthode getTemperature() pour récupérer la température et
 * l'affiche sur la sortie standard.
 */
void MCP9808Sensor::displayTemperature() {
    float temp = getTemperature();
    if (temp != -1) {
        std::cout << "Température actuelle : " << temp << " °C\n";
    }
}

/**
 * \brief Destructeur de la classe MCP9808Sensor.
 * 
 * Permet de réaliser des opérations de nettoyage si nécessaire.
 */
MCP9808Sensor::~MCP9808Sensor() {
    // Pas de nettoyage nécessaire à ce stade
}
