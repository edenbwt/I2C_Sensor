
# I2C_Sensor

Projet scolaire utilisant un Raspberry Pi et la communication I2C pour récupérer les données d'un capteur de température **MCP9808**.

## Auteurs
- **Alicia B.**
- **Eden C.**

## Liste du matériel

### Logiciels utilisés
- **Geany** : Éditeur de texte pour le code.
- **G++** : Compilateur C++ pour compiler et exécuter le programme.

### Matériel
- **Raspberry Pi** : Mini-ordinateur pour l'exécution du programme.
- **Capteur de température MCP9808** : Capteur de température communiquant via I2C.

### Bibliothèque utilisée
- **WiringPi** : Bibliothèque permettant la communication I2C et GPIO avec le Raspberry Pi.

## Diagramme de séquence

Voici un diagramme de séquence illustrant la communication entre le Raspberry Pi et le capteur MCP9808 :

![Diagramme de séquence du projet I2C_Sensor](https://github.com/edenbwt/I2C_Sensor/blob/e9103c672ee1e36a379f9c8321e3ecb082b75029/Capture%20d%E2%80%99%C3%A9cran%202024-09-13%20121414.png)

## Explication du flux du programme

1. Le programme initialise la communication I2C avec le capteur **MCP9808**.
2. Si l'initialisation est réussie, le programme entre dans une boucle infinie.
3. Le Raspberry Pi interroge régulièrement le capteur pour lire la température.
4. La température lue est affichée sur la console toutes les 5 secondes.
5. En cas d'erreur, un message est affiché et le programme s'arrête.

## Prérequis

- Installer **WiringPi** sur votre Raspberry Pi. Vous pouvez utiliser la commande suivante :
  ```bash
  sudo apt-get install wiringpi
  ```

## Compilation et exécution

1. Pour compiler le programme, utilisez la commande suivante dans le terminal :
   ```bash
   g++ -o sensor main.cpp sensor.cpp -lwiringPi
   ```

2. Pour exécuter le programme :
   ```bash
   ./sensor
   ```

