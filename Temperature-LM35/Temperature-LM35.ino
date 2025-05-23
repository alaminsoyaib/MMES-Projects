// LAB 1

#define Heater 13
#define AC 12
#define Temperature A0

void setup()
{
    pinMode(Heater, OUTPUT);
    pinMode(AC, OUTPUT);
    pinMode(Temperature, INPUT);
    Serial.begin(9600);
}

void loop()
{

    float val = analogRead(Temperature);

    val = val * (3.3 / 1024) * 100; // conversion

    Serial.print("Temperature : ");
    Serial.println(val);
    if (val < 28)
    {
        digitalWrite(AC, LOW);
        digitalWrite(Heater, HIGH);
    }
    else
    {
        digitalWrite(Heater, LOW);
        digitalWrite(AC, HIGH);
    }
    delay(2000);

    // for (int i = 0; i < 5; i++)
    // {
    //     digitalWrite(AC, LOW);
    //     digitalWrite(Heater, HIGH);
    //     delay(30);
    //     digitalWrite(Heater, LOW);
    //     digitalWrite(AC, HIGH);
    //     delay(30);
    // }
    // delay(500);
    // for (int i = 0; i < 5; i++)
    // {
    //     digitalWrite(Heater, LOW);
    //     digitalWrite(AC, HIGH);
    //     delay(30);
    //     digitalWrite(AC, LOW);
    //     digitalWrite(Heater, HIGH);
    //     delay(30);
    // }

    delay(200);
}