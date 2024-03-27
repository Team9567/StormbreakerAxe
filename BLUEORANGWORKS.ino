#include <FastLED.h>

#define LED_PIN 2
#define TRIG_ORANGE_PIN 4
#define NUM_LEDS 60  // one led strip is 30 leds, we have 2 strips or 60 total, maybe adding a 3rd for 90 total.

CRGB leds[NUM_LEDS];
int fadeBrightness = 0;
int fadeBrightnessRed = 0;
int fadeBrightnessGreen = 255;
int fadeBrightnessBlue = 0;
int fadeBrightnessOrange = 0;
int Orange[3] = { 255, 45, 0 };
int count = 0;
int button = 0;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  //button = digitalInput(TRIG_ORANGE_PIN);gggggggggggygh
  pinMode(4, INPUT_PULLUP);
}

void loop() {
  //turnOffLEDs();  // uncomment and upload "->" to turn the axe off, BRIGHT!!!!!!!!!!!!!!!!!!!!!!!
  // turnOffLEDs();

  fadeBlue();
  //fadeRed();
  //digitalRead(4);
  //fadeRed();
  //solidOrange();
  /*
  //bool val = (digitalRead(4));
  if (digitalRead(4) == LOW){
    solidOrange();
  } else {
   fadeBlue();
  }
*/

  //fadeBlue();
  //fadeRed();
  //solidOrange();
  //fadeOrange();
  // EXAMPLE #1: DO ONE LED FADE OF DARK TO LIGHT, 0 TO 255
  /*
  for(int j = 0; j < 255; j++){
  orangeIfPressed();
  //fadeBrightness = fadeBrightness + 10;
  fadeBrightness = j;
  leds[0] = CRGB ( 0, 0, fadeBrightness); //flashing color
  FastLED.show();
  delay(5);
  }
  */

  /*
  // on random led
  for (int i = 0; i <= (NUM_LEDS - 1); i++) {
    orangeIfPressed();
    
    //i = random(0, NUM_LEDS);
    i = random8(0, NUM_LEDS);
    //delay(20);
    leds[i] = CRGB ( 0, 0, 30); //flashing color
    FastLED.show();
    delay(5);
   }

  //off random led
  for (int i = (NUM_LEDS - 1); i >= 0; i--) {

    orangeIfPressed();

    i = random8(0, NUM_LEDS);
        //delay(20);
    leds[i] = CRGB ( 0, 0, 255);
    FastLED.show();
    delay(5);
  }*/
}

void orangeIfPressed() {
  if (isTriggerPressed) turnAxeOrange();
}

void turnAxeOrange() {
  for (int i = (NUM_LEDS - 1); i >= 0; i--) {
    leds[i] = CRGB(fadeBrightnessRed, 0, fadeBrightnessBlue);  //solid color
  }
}

bool isTriggerPressed() {
  bool isPinTriggered = false;
  if (TRIG_ORANGE_PIN == 1) {
    isPinTriggered = true;
  } else {
    isPinTriggered = false;
  }
  return isPinTriggered;
}


///////////////////////////////////////////////////////////////
///////////////////////// FADE BLUE ///////////////////////////
///////////////////////////////////////////////////////////////
void fadeBlue() {
  // Step 2: fade to bright (count up 0 to 255)
  for (int j = 0; j < 255; j++) {
    if (digitalRead(4) == LOW) {  //if button pressed
      solidOrange();  //turn led orange snake
    }
    //orangeIfPressed();
    fadeBrightnessBlue = j;
    for (int k = 0; k < NUM_LEDS; k++) {
      leds[k] = CRGB(0, 0, fadeBrightnessBlue);  //flashing color
    }
    FastLED.show();
    delay(5);
  }

  // if boolean is false
  // Steo 3: fade to dark (count down 255 to 0)
  for (int j = 255; j > 0; j--) {
    if (digitalRead(4) == LOW) {
      solidOrange();
    }
    // orangeIfPressed();
    //fadeBrightness = fadeBrightness + 10;
    fadeBrightnessBlue = j;
    for (int k = 0; k < NUM_LEDS; k++) {
      leds[k] = CRGB(0, 0, fadeBrightnessBlue);  //flashing color
    }
    FastLED.show();
    delay(5);
  }
}



///////////////////////////////////////////////////////////////
///////////////////////// FADE RED ////////////////////////////
///////////////////////////////////////////////////////////////

void fadeRed() {
  // Step 1: switch a boolean every 255 counts

  // if boolean is true
  // Step 2: fade to bright (count up 0 to 255)
  for (int j = 0; j < 255; j++) {
    if (digitalRead(4) == LOW) {
      solidOrange();
    }
    //orangeIfPressed();
    //fadeBrightness = fadeBrightness + 10;
    fadeBrightnessRed = j;
    for (int k = 0; k < NUM_LEDS; k++) {
      leds[k] = CRGB(fadeBrightnessRed, 0, 0);  //flashing color
    }
    FastLED.show();
    delay(5);
  }

  // if boolean is false
  // Steo 3: fade to dark (count down 255 to 0)
  for (int j = 255; j > 0; j--) {
    if (digitalRead(4) == LOW) {
      solidOrange();
    }
    // orangeIfPressed();
    //fadeBrightness = fadeBrightness + 10;
    fadeBrightnessRed = j;
    for (int k = 0; k < NUM_LEDS; k++) {
      leds[k] = CRGB(fadeBrightnessRed, 0, 0);  //flashing color
    }
    FastLED.show();
    delay(5);
  }
}
//////////////////////////////////////////////////////////////
/////////////////////// SOLID ORANGE /////////////////////////
//////////////////////////////////////////////////////////////
void solidOrange() {
  for (int j = 0; j < NUM_LEDS; j++) {
    //orangeIfPressed();
    //fadeBrightness = fadeBrightness + 10;
    //solidBrightnessOrange = j;
    leds[j] = CRGB(Orange[0], Orange[1], Orange[2]);  //flashing color
    FastLED.show();
    delay(50);
  }
}

void turnOffLEDs() {
  for (int j = 0; j < NUM_LEDS; j++) {
    //orangeIfPressed();
    //fadeBrightness = fadeBrightness + 10;
    //solidBrightnessOrange = j;
    leds[j] = CRGB(0, 0, 0);  //flashing color
    FastLED.show();
    delay(50);
  }
}


void ButtonOrange() {
  int pinFourValue = (digitalRead(4));
  if (pinFourValue == LOW) {
    solidOrange();
    //for (int i = 0; i < NUM_LEDS; i++){
    //leds[i] = CRGB ( 0, fadeBrightnessGreen, 0); //flashing color
    //FastLED.show();
    //}
  }
}