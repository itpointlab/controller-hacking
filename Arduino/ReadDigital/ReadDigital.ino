#include <Bounce2.h>

#define BUTTON_PIN 2
#define LED_PIN 8

Bounce debouncer = Bounce();
unsigned long buttonPressTimeStamp;
char *result = "value : ";

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  debouncer.attach( BUTTON_PIN );
  debouncer.interval(5);
}

// the loop routine runs over and over again forever:
void loop() {
  debouncer.update();
  if ( debouncer.fell() ) {
    Serial.println( millis()-buttonPressTimeStamp );
    buttonPressTimeStamp = millis();
  }
  int value = debouncer.read();
  Serial.print(result);
  Serial.println(value);
  if ( value == LOW ) {
    digitalWrite(LED_PIN, HIGH );
  } 
  else {
    digitalWrite(LED_PIN, LOW );
  }
}




