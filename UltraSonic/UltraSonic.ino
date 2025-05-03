// LAB 2

const int trigPin = 7;
#define echoPin 8
#define Buzzer 11

double time, distance;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(Buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    time = pulseIn(echoPin, HIGH); // the time returned is in MicroSecond (μs)
    // Sound travels at ~343 m/s or 0.034 cm/μs which is (343*1000)cm/(1*10^6)μs
    distance = time * 0.0343 / 2; // Time * Speed of Sound / 2

    Serial.println("Distance : " + String(distance) + "cm");

    // if (distance < 100)
    // {
    //     digitalWrite(Buzzer, HIGH);
    //     delay(500);
    //     digitalWrite(Buzzer, LOW);
    // }

    delay(1000);
}