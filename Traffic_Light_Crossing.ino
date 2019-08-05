int btnPin = 9;
int redRelayPin = 2;
int grnRelayPin = 3;
int spkPin = 8;
int tones[] = {
  3465, 2850, 2333, 1956, 1638, 1380, 1161, 992, 814, 704, 500
}; 

void redLightOn() {
  digitalWrite(redRelayPin, LOW);  // turn relay ON
}
void redLightOff() {
  digitalWrite(redRelayPin, HIGH);  // turn relay OFF
}
void greenLightOn() {
  digitalWrite(grnRelayPin, LOW);  // turn relay ON
}
void greenLightOff() {
  digitalWrite(grnRelayPin, HIGH);  // turn relay OFF
}
bool hasButtonBeenPushed() {
  if (digitalRead(btnPin) == LOW) {
    // debounce
    delay(50);
    if (digitalRead(btnPin) == LOW) {
      return true;
    }
  }
  return false;
}

void playIdle() {
  tone(spkPin, 973, 25);
  delay(25);
  noTone(spkPin);
}
void playChirp() {
  // Iterate through all tones
  for (int i = 0; i < 11; i++) {
    // Play the next tone
    tone(spkPin, tones[i], 11);
    delay(11);
  }
}
void playWoodpecker() {
  // 17x = 2secs; 85x = 10 seconds
  for (int i = 0; i <= 85; i++) {
    tone(spkPin, 500, 30);
    delay(30);
    noTone(spkPin);
    delay(117); // wait
  }
}

// Start Flashing Red Light w/ Idle sound for 5 cycles
void doEndFlashing() {

  // Lights off
  greenLightOff();
  redLightOff();

  // Cycle Red w/ Idle sound x 5
  for (int i = 0; i < 5; i++) {
    redLightOn();
    playIdle();
    delay(600);
    redLightOff();
    delay(600);
  }
}

void doTrafficLightCrossing() {

  // Red Light On
  greenLightOff();
  redLightOn();

  // Idle Tone x 4
  playIdle();
  delay(1800);
  playIdle();
  delay(1800);
  playIdle();
  delay(1800);
  playIdle();
  delay(1800);

  // GO!
  redLightOff();
  greenLightOn();
  playChirp();

  // Woodpecker for 10 seconds
  playWoodpecker();

  doEndFlashing();

  // Red light goes back on
  redLightOn();

  // Idle sound x 3
  playIdle();
  delay(1800);
  playIdle();
  delay(1800);
  playIdle();
}

void setup() {
  // Setup pins
  pinMode(redRelayPin, OUTPUT);
  pinMode(grnRelayPin, OUTPUT);
  pinMode(spkPin, OUTPUT);
  pinMode(btnPin, INPUT);
}

void loop() {

  // Wait for button...
  if (hasButtonBeenPushed() == true) {

    // Run main program
    doTrafficLightCrossing();
  }

  // Pause for 5ms
  delay(5); 
}
