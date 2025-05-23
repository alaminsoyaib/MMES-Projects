#define volt A5

void setup()
{
    pinMode(volt, INPUT);
    Serial.begin(9600);
}

void loop()
{
    float v = analogRead(volt) * 5.058;
    Serial.println("Voltage : " + String(v) + " mV\n");
    delay(500);
}