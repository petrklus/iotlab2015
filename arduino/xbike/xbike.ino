int FIRST_PIN = 2;
int NUMBER_OF_PINS = 10;

char leds_color[10] = {'R', 'G', 'R', 'G', 'R', 'Y', 'R', 'Y', 'R', 'Y'};

void setup() {
  // put your setup code here, to run once:
  for (int x = NUMBER_OF_PINS; x >= 0 ; x--) {
    pinMode(x, OUTPUT);
  }
  
   Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

// 1. Change color
// 2. Change color fainthing leds

/*
void changeColour(char colour, int turnOffOtherColors) {
  int highLevel = 255;
  int lowLevel = 0;

  while (highLevel > 0 && lowLevel < 255) {
    for (int x = 0; x < NUMBER_OF_PINS; x++) {
      int currentPin = FIRST_PIN + x;
      if (leds_color[x] != colour) {
        if(turnOffOtherColors != 0) {
          analogWrite(currentPin, lowLevel);
        }
      } else {
        analogWrite(currentPin, highLevel);
      }
    }

    highLevel -= 10;
    lowLevel += 10;
    delay(10);
  }
}
*/

void changeColour(char colour, int turnOffOtherColors) {
    for (int x = NUMBER_OF_PINS; x >= 0 ; x--) {
      int currentPin = FIRST_PIN + x;
      if (leds_color[x] != colour) {
        if(turnOffOtherColors != 0) {
          digitalWrite(currentPin, LOW);
        }
      } else {
        digitalWrite(currentPin, HIGH);
      }
    }
}

void loop() {
  if (Serial.available() > 0) {
          // read the incoming byte:
          int c  = Serial.read();

          // say what you got:
          if(c == 82) { // R
            changeColour('R',0);
          }
          if(c == 71) { // G
            changeColour('G',0);
          }
          
          if(c == 89) { // Y
            changeColour('Y',0);
          }
          
          if(c == 79)  {// O
            changeColour('J',1);
          }
          Serial.print("I received: ");
          Serial.println(c, DEC);
  }
}
