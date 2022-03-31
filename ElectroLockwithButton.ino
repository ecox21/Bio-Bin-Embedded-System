 #include <ezButton.h>

// constants won't change
const int BUTTON_PIN1 = 7;
const int BUTTON_PIN2 = 6;
// Arduino pin connected to button's pin
const int RELAY_PIN1  = 3;
const int RELAY_PIN2  = 2;
// Arduino pin connected to relay's pin

ezButton button1(BUTTON_PIN1);
ezButton button2(BUTTON_PIN2);
 // create ezButton object that attach to pin 7;

void setup() {
  Serial.begin(9600);         // initialize serial
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);// set arduino pin to output mode
  button1.setDebounceTime(50);
  button2.setDebounceTime(50);// set debounce time to 50 milliseconds

  digitalWrite(RELAY_PIN1, HIGH);
  digitalWrite(RELAY_PIN2, HIGH);// lock the door
}

void loop() {
  button1.loop();
  button2.loop();// MUST call the loop() function first

  if(button1.isPressed()) {
    Serial.println("The button is pressed");
    digitalWrite(RELAY_PIN1, LOW);
    digitalWrite(RELAY_PIN2, LOW);// unlock the door in 10 seconds
    
  }
 
  if(button2.isPressed()) {
    Serial.println("The button is pressed");
    digitalWrite(RELAY_PIN1, HIGH);
    digitalWrite(RELAY_PIN2, HIGH);
  }
}
