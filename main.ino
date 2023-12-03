// PROGRAMM: LED Würfel
 
 
// Pin des Tasters
int button = 2;


//LED for dice
int bottomLeft = 8;
int middleLeft = 7;
int upperLeft = 6;
int middle = 5;
int bottomRight = 4;
int middleRight = 3;
int upperRight = 12;


int state = 0;
long randNumber;

//Initial Setup
void setup() {
  pinMode(bottomLeft, OUTPUT);
  pinMode(middleLeft, OUTPUT);
  pinMode(upperLeft, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(bottomRight, OUTPUT);
  pinMode(middleRight, OUTPUT);
  pinMode(upperRight, OUTPUT);

  //Button
  pinMode(button,INPUT_PULLUP);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

bool initialAnimationDone = false;

void loop() {
  // Überprüfen, ob die Initialanimation bereits durchgeführt wurde
  if (!initialAnimationDone) {
    // Führe die Initialanimation aus
    simpleAnimation();
    initialAnimationDone = true;  // Setze die Variable auf true, um zu markieren, dass die Animation durchgeführt wurde
  }

  // Überprüfen, ob der Button gedrückt wurde
  if (digitalRead(button) == LOW && state == 0) {
    state = 1;
    randNumber = random(1, 7);
    delay(1000);
    Serial.println(randNumber);
    
    // Stopp der Animation
    clear();
    
    // Zeige die entsprechende Zahl an
    if (randNumber == 6) {
      six();
    } else if (randNumber == 5) {
      five();
    } else if (randNumber == 4) {
      four();
    } else if (randNumber == 3) {
      three();
    } else if (randNumber == 2) {
      two();
    } else if (randNumber == 1) {
      one();
    }
    
    delay(1000);
    clear();
    state = 0;
  }
}


void one()
{
  digitalWrite(middle, HIGH);
}

void two()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(upperRight, HIGH);
}

void three()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(upperRight, HIGH);
}

void four()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(upperLeft, HIGH); 
  digitalWrite(bottomRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void five()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(middle, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(upperRight, HIGH);
}

void six()
{
  digitalWrite(bottomLeft, HIGH);
  digitalWrite(middleLeft, HIGH);
  digitalWrite(upperLeft, HIGH);
  digitalWrite(bottomRight, HIGH);
  digitalWrite(middleRight, HIGH);
  digitalWrite(upperRight, HIGH);
}


void clear()
{
  digitalWrite(bottomLeft, LOW);
  digitalWrite(middleLeft, LOW);
  digitalWrite(upperLeft, LOW);
  digitalWrite(middle, LOW);
  digitalWrite(bottomRight, LOW);
  digitalWrite(middleRight, LOW);
  digitalWrite(upperRight, LOW);
}

// Funktion für eine einfache Animation
void simpleAnimation() {
  digitalWrite(bottomLeft, HIGH);
  delay(200);
  digitalWrite(bottomLeft, LOW);

  digitalWrite(middleLeft, HIGH);
  delay(200);
  digitalWrite(middleLeft, LOW);

  digitalWrite(upperLeft, HIGH);
  delay(200);
  digitalWrite(upperLeft, LOW);

  digitalWrite(middle, HIGH);
  delay(200);
  digitalWrite(middle, LOW);

  digitalWrite(bottomRight, HIGH);
  delay(200);
  digitalWrite(bottomRight, LOW);

  digitalWrite(middleRight, HIGH);
  delay(200);
  digitalWrite(middleRight, LOW);

  digitalWrite(upperRight, HIGH);
  delay(200);
  digitalWrite(upperRight, LOW);

  digitalWrite(middleRight, HIGH);
  delay(200);
  digitalWrite(middleRight, LOW);

  digitalWrite(bottomRight, HIGH);
  delay(200);
  digitalWrite(bottomRight, LOW);

  digitalWrite(middle, HIGH);
  delay(200);
  digitalWrite(middle, LOW);

  digitalWrite(upperLeft, HIGH);
  delay(200);
  digitalWrite(upperLeft, LOW);

  digitalWrite(middleLeft, HIGH);
  delay(200);
  digitalWrite(middleLeft, LOW);

  digitalWrite(bottomLeft, HIGH);
  delay(200);
  digitalWrite(bottomLeft, LOW);
  delay(200);
}

