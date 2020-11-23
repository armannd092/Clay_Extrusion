/*     Simple Stepper Motor Control Exaple Code

    by Dejan Nedelkovski, www.HowToMechatronics.com

*/

// defines pins numbers
#define stepPin 3
#define dirPin 2
#define Signal 7
#define Enable 5

int speedretraction  = 1000;
int speedextruding = 1000;
int retractionamount = 100;
int robotIO = 0;

void setup() {
  Serial.begin(115200);
  // Sets the two pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode (Signal, INPUT);
  pinMode (Enable, OUTPUT);
}
void loop() {
  int robotIO = digitalRead(Signal);

  if (robotIO == HIGH) {
    digitalWrite(Enable, HIGH); // // ALLOW ON EXTRUSION
    digitalWrite(dirPin, LOW); // // ROTATE CW
    // Code to extrude (produce the steps)
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(speedextruding);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(speedextruding);
    Serial.println("extrusion mode");
  }
  else if (robotIO == LOW) {
    digitalWrite (dirPin, HIGH); // ROTATE CCW
    Serial.println("MOTOR STOPPER");
    //Code to extrude (produce the steps) Makes 200 pulses for making one full cycle rotation
    for (int i = 0; i <= retractionamount ; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(speedretraction);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(speedretraction);

    }
    Serial.println("retractionmode");
    digitalWrite(Enable, LOW); // // ALLOW ON EXTRUSION
  }
}



/* delay(1000); // One second delay

  digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
  for(int x = 0; x < 400; x++) {
   digitalWrite(stepPin,HIGH);
   delayMicroseconds(500);
   digitalWrite(stepPin,LOW);
   delayMicroseconds(500);
  }
  delay(1000);
  }
*/
