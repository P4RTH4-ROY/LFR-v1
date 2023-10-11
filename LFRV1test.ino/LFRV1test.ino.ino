// Define sensor pins
int A = A1;
int B = A2;
int C = A3;
int D = A4;
int E = A5;
// Define motor control pins
int LM1 = 3;
int LM2 = 6;
int RM1 = 10;
int RM2 = 9;

int s = 255, s1 = 200, s2 = 150, s3 = 100, s4 = 0;

// Set the black line threshold
int th = 500;  // Adjust this value according to your sensors

void setup() {
  Serial.begin(9600);

  // Initialize motor control pins as outputs
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  // Initialize sensor input
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  pinMode(C, INPUT);
  pinMode(D, INPUT);
  pinMode(E, INPUT);
}


  void loop() {
  int LA = analogRead(A);
  int LB = analogRead(B);
  int CC = analogRead(C);
  int RD = analogRead(D);
  int RE = analogRead(E);

  // To Communicate with sensor monitor
  Serial.println(String(LA) + "\t" + String(LB) + "\t" + String(CC) + "\t" + String(RD) + "\t" + String(RE) + "\t");

  
  //line followin logic
  if(CC < th){
    forward();
    Serial.println("forward");
    } else if(RD < th || RE < th){
        turnRight();
      Serial.println("turnRightt");
    }else if(LA < th || LB < th){
    turnLeft();
      Serial.println("turnLeft");
    }else if(LA<th && LB <th && CC< th && RD < th && RE < th){
      stop();
    }else if(LA>th && LB >th && CC> th && RD > th && RE > th){
      goforward();
    }else if (LA > th && LB >th && CC > th){
      extremeleftturn();
    }
    else if (CC > th && RD >th && RE > th){
      extremerightturn();
    }
    else{
    stop();
    Serial.println("turnRightt");
  }
  }




/*
  // Check if all sensors see a black line
  if (LA > th && LB > th && CC > th && RD > th && RE > th) {
    stopMotors();
    Serial.println("STOP");
  } else if (CC > th) {
    forward();
    Serial.println("FORWARD");
  } else if (LB > th) {
    turnLeft();
    Serial.println("LEFT");
  } else if (RD > th) {
    turnRight();
    Serial.println("RIGHT");
  } else {
    stopMotors();
    Serial.println("STOP");
  }
}*/



void forward() {
  analogWrite(LM1, 200);
  analogWrite(LM2, 0);
  analogWrite(RM1, 255);
  analogWrite(RM2, 0);
  delay(100);
}

void turnLeft() {
  analogWrite(LM1, 0);
  analogWrite(LM2, 150);
  analogWrite(RM1, 100);
  analogWrite(RM2, 0);
   delay(10);
}

void turnRight() {
  analogWrite(LM1, 150);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 100);
  delay(10);
}

void stop() {
  analogWrite(LM1, 0);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 0);
}
void brack(){
   analogWrite(LM1, 150);
  analogWrite(LM2, 150);
  analogWrite(RM1, 150);
  analogWrite(RM2, 150);

}
void goforward(){
  analogWrite(LM1, 120);
  analogWrite(LM2, 0);
  analogWrite(RM1, 120);
  analogWrite(RM2, 0);
  delay(100);
}
void extremeleftturn(){
   analogWrite(LM1, 0);
  analogWrite(LM2, 255);
  analogWrite(RM1, 200);
  analogWrite(RM2, 0);
   delay(2000);
}

void extremerightturn(){
  analogWrite(LM1, 255);
  analogWrite(LM2, 0);
  analogWrite(RM1, 0);
  analogWrite(RM2, 200);
  delay(2000);

}