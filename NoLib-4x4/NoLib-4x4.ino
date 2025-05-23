const byte ROWS = 4;  
const byte COLS = 4;

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 11, 10, 9, 8 };
byte colPins[COLS] = { 7, 6, 5, 4 };

void setup() {
  Serial.begin(9600);

  // Set row pins as OUTPUT and column pins as INPUT
  for (byte i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  
  for (byte i = 0; i < COLS; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }
}

void loop() {
  char key = scanKeypad();

  if (key) {
    Serial.println("Key Pressed : " + String(key));
  }

  delay(10);
}

char scanKeypad() {
  for (byte row = 0; row < ROWS; row++) {
    digitalWrite(rowPins[row], LOW);
    
    for (byte col = 0; col < COLS; col++) {
      if (digitalRead(colPins[col]) == LOW) {
        while (digitalRead(colPins[col]) == LOW);  // Wait for key release
        digitalWrite(rowPins[row], HIGH);
        return keys[row][col];
      }
    }
    
    digitalWrite(rowPins[row], HIGH);
  }
  
  return '\0';  // No key pressed
}
