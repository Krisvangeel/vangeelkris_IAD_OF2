Uitleg Eindopdracht Open Frameworks - Alcoholmorpher.
Voor Open Frameworks ben ik aan de slag gegaan met de behandelde lesstof, en een eigen input.
Ik heb een alcohol sensor gekocht (+module) en wilde hiermee iets doen.
Ik heb uiteindelijk ervoor gekozen om te kijken of ik met de arduino en met de behandelde Haarfinder iets kon doen.
Dat kon. Mijn arduino, leest de waarde die hij door krijgt van sensor uit, en vertaald deze naar een grens (Net zoals bij de blaastest van de politie).
Alleen is deze visueel ondersteund. Als een persoon te veel heeft gedronken (100 of hoger) wordt er een groot kruis afgebeeld op het hoofd van de persoon die blaast. 
In principe is dit eigenlijk een visuele blaastest. 

Ik heb een klein stukje .ino code geupload op mijn arduino, om te zorgen dat alle data goed doorgevoerd werd naar OF.
Die ziet er als volgt uit:

byte val = 0;
const int analogPin = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  val = analogRead(A0) / 4;
  Serial.write(val);
  delay(25);

}

Dit is gedaan vanwegen de verschillende waardes die Arduino en OF doorkrijgen van hetzelfde (max 255 in of - max 1029 bij arduino zelf)
