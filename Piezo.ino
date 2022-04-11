const int buzzer = 9; //buzzer to arduino pin 9
String input;
int signalStrength;
bool play;

void setup() {

  Serial.begin(9600);
  delay(1000);

  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  signalStrength = 600;
  play = True;
}

void loop() {

  if (Serial.available()) {
    input = Serial.readString();
  }

  if (input == "S1") {
    play = 1;
    signalStrength = 200;
    Serial.println("s1 strength");
  }
  else if (input == "S2") {
    play = 1;
    signalStrength = 400;
    Serial.println("s2 strength");
  }
  else if (input == "S3") {
    play = 1;
    signalStrength = 600;
    Serial.println("s3 strength");
  }
  else if (input == "S4") {
    play = 1;
    signalStrength = 800;
    Serial.println("s4 strength");
  }
  else if (input == "S5") {
    play = 1;
    signalStrength = 1000;
    Serial.println("s5 strength");
  }
  else {
    play = 0;
    Serial.println(input);
  }

  if(play == 1){
    tone(buzzer, signalStrength); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
  }
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec

}
