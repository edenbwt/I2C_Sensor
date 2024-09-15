/*****************************************************************//**
 * \file   sensor.h
 * \brief  Déclaration de la classe MCP9808Sensor
 *
 * Ce fichier contient la déclaration de la classe MCP9808Sensor 
 * utilisée pour interagir avec un capteur de température MCP9808 via 
 * une interface I2C.
 *
 * \author Alicia_B & Eden_C
 * \date   Septembre 2024
 *********************************************************************/

#ifndef SENSOR_H
#define SENSOR_H

/**
 * \class MCP9808Sensor
 * \brief Classe permettant l'interaction avec le capteur MCP9808.
 * 
 * Cette classe permet d'initialiser le capteur, de lire la température
 * et d'afficher les résultats sur la sortie standard.
 */
class MCP9808Sensor {
public:
    /**
     * \brief Constructeur de la classe MCP9808Sensor.
     * 
     * \param addr Adresse I2C du capteur MCP9808.
     */
    MCP9808Sensor(int addr);

    /**
     * \brief Initialise la communication I2C avec le capteur.
     * 
     * \return true si l'initialisation est réussie, false sinon.
     */
    bool init();

    /**
     * \brief Récupère la température actuelle du capteur.
     * 
     * \return La température en degrés Celsius, ou -1 en cas d'erreur.
     */
    float getTemperature();

    /**
     * \brief Affiche la température actuelle sur la console.
     */
    void displayTemperature();

    /**
     * \brief Destructeur de la classe MCP9808Sensor.
     */
    ~MCP9808Sensor();

private:
    int address;      ///< Adresse I2C du capteur MCP9808
    int fd;           ///< Descripteur de fichier pour la communication I2C
    float temperature;///< Dernière température lue en degrés Celsius
};

#endif // SENSOR_H
