// CREDITS:
// - https://docs.arduino.cc/learn/microcontrollers/analog-output
// - https://forum.arduino.cc/t/2-button-to-1-pwm-output/910708/14
// - https://cdn.sparkfun.com/assets/resources/4/4/PWM_output_Arduino.pdf

const int BUTTON1 = 4;      // Button 1 connected to pin 4
const int BUTTON2 = 5;      // Button 2 connected to pin 5
const int LED = 6;          // LED connected to pin 6

int buttonState1 = 0;
int buttonState2 = 0;
int intensity = 255;        // Default LED intensity

void setup() {
    // Setup pins as INPUT or OUTPUT
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    // Read the state of the buttons
    buttonState1 = digitalRead(BUTTON1);
    buttonState2 = digitalRead(BUTTON2);

    // Determine LED intensity based on button states
    if (buttonState1 == HIGH && buttonState2 == HIGH) {
        // Both buttons pressed: 25% intensity
        intensity = 64;
    } else if (buttonState1 == LOW && buttonState2 == HIGH) {
        // Only button 2 pressed: 50% intensity
        intensity = 128;
    } else if (buttonState1 == HIGH && buttonState2 == LOW) {
        // Only button 1 pressed: 75% intensity
        intensity = 191;
    } else {
        // No button pressed: 100% intensity
        intensity = 255;
    }

    // Apply the determined intensity to the LED
    analogWrite(LED, intensity);
}
