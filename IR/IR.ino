#define IR 4
#define LED 5

void setup()
{
    pinMode(IR, INPUT);
    pinMode(LED, OUTPUT);
}
void loop()
{
    int value = digitalRead(IR);
    if (value == 0)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
    }
}