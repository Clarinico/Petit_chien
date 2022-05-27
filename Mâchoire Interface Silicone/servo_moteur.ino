//https://arduino.developpez.com/tutoriels/arduino-a-l-ecole/?page=projet-12-utiliser-un-servomoteur
#include <Servo.h>  // on inclut la bibliothèque pour piloter un servomoteur

Servo monServo;  // on crée l'objet monServo

void setup()
{
  monServo.attach(9); // on définit le Pin utilisé par le servomoteur
}

//Pour le chien en ayant le moteur à plat dans le bouche, la bouche est fermée à 110 et ouverte à 70 
// ces valeurs sont à ajuster plus tard...
//Possibilité des créer des fonctions du genre, ouverture, fermeture, aboiement...
void loop()
{
  for (int position = 110; position >= 70; position --) { // on crée une variable position qui prend des valeurs entre 0 à 180 max
    monServo.write(position);  // le bras du servomoteur prend la position de la variable position
    delay(15);  // on attend 15 millisecondes
    //passage de la position 0° à 180° en 15*180 ms = 2.7 sec
  }

  delay(1000);
  
  for (int position = 70; position <= 110; position ++) { // cette fois la variable position passe de 180 à 0°
    monServo.write(position);  // le bras du servomoteur prend la position de la variable position
    delay(15);  // le bras du servomoteur prend la position de la variable position
  }

  delay(2000);
}
//La position ouverte et fermée sont à déterminer expérimentalment

/*
   /
  Code 24 - Edurobot.ch, destiné à l'Arduino
  Objectif : prouver que la bibliothèque Servo permet au servomoteur d'agir et de se maintenir
             en position même lorsque l'Arduino effectue une autre tâche.


  #include <Servo.h>  // on inclut la bibliothèque pour piloter un servomoteur

  Servo monServo;     // on crée l'objet monServo

  void setup()
  {
    monServo.attach(9);   // on définit le Pin utilisé par le servomoteur
    pinMode(13,OUTPUT);   // la Pin13 est mise en mode OUTPUT
  }

  void loop()
  {
    monServo.write(0);      // on dit à l'objet de mettre le servo à 0°
    diode13();              // appel de la fonction diode13 qui est définie plus bas
    monServo.write(180);    // on dit à l'objet de mettre le servo à 180°
    diode13();              // appel de la fonction diode13
  }

  void diode13()  //on va faire clignoter 15 fois la diode 13
  {
    for (int t=0;t<15;t++){
        digitalWrite(13,HIGH);
        delay(100);
        digitalWrite(13,LOW);
        delay(100);
    }
  }
*/
