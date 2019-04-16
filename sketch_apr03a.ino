const int MGAV = 2, MGAR = 3, MDAV = 4, MDAR = 5;
const int trigAV = 6, echoAV = 7, trigAR = 8, echoAR = 9, trigG = 10, echoG = 11, trigD = 12, echoD = 13;
float distAV, distAR, distG, distD;

void setup() {
  pinMode(MGAV, OUTPUT);
  pinMode(MDAV, OUTPUT);
  pinMode(MGAR, OUTPUT);
  pinMode(MDAR, OUTPUT);

  digitalWrite(MGAV, LOW);
  digitalWrite(MDAV, LOW);
  digitalWrite(MGAR, LOW);
  digitalWrite(MDAR, LOW);
}

void loop() {
  arret(MGAV, MDAV, MGAR, MDAR);

  distAV = distance(trigAV, echoAV);

  if (distAV != 0)
    avancer( MGAV,  MDAV,  MGAR, MDAR);
  else if (distG != 0)
  {
    gauche(MGAV, MDAV, MGAR, MDAR);
    delay(1000);
    avancer( MGAV, MDAV, MGAR, MDAR);
  }
  else if (distD != 0)
  {
    droite(MGAV, MDAV, MGAR, MDAR);
    delay(1000);
    avancer( MGAV, MDAV, MGAR, MDAR);
  }
  else
    reculer(MGAV, MDAV, MGAR, MDAR);

}

void avancer(const int MGAV, const int MDAV, const int MGAR, const int MDAR)
{
  digitalWrite(MGAR, LOW);
  digitalWrite(MDAR, LOW);

  digitalWrite(MGAV, HIGH);
  digitalWrite(MDAV, HIGH);
}

void reculer(const int MGAV, const int MDAV, const int MGAR, const int MDAR)
{
  digitalWrite(MGAV, LOW);
  digitalWrite(MDAV, LOW);

  digitalWrite(MGAR, HIGH);
  digitalWrite(MDAR, HIGH);
}

void gauche(const int MGAV, const int MDAV, const int MGAR, const int MDAR)
{
  digitalWrite(MDAV, LOW);
  digitalWrite(MDAR, LOW);

  digitalWrite(MGAV, HIGH);
  digitalWrite(MGAR, HIGH);
}

void droite(const int MGAV, const int MDAV, const int MGAR, const int MDAR)
{
  digitalWrite(MGAV, LOW);
  digitalWrite(MGAR, LOW);

  digitalWrite(MDAV, HIGH);
  digitalWrite(MDAR, HIGH);
}

float distance(const int trig, const int echo)
{
  float duree, dist;
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duree = pulseIn(echo, HIGH);
  dist = (duree / 29) / 2;

  return dist;
}

void arret(const int MGAV, const int MDAV, const int MGAR, const int MDAR)
{
  digitalWrite(MGAV, LOW);
  digitalWrite(MGAR, LOW);

  digitalWrite(MDAV, LOW);
  digitalWrite(MDAR, LOW);
}
