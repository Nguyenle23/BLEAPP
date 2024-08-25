int int1 = 8;
int int2 = 9;
int ena = 10;

int int3 = 6;
int int4 = 7;
int enb = 5;

char data = "";
unsigned long startTime = 0;
bool motorRunning = false;

void setup() {
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(ena, OUTPUT);

  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  pinMode(enb, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print(data);
    
    if (data == '1' || data == '0') {
      motorRunning = true;
      startTime = millis();  // Record the time the motor starts running
    }
  }

  if (motorRunning) {
    if (data == '1') {
      digitalWrite(int1, LOW);
      digitalWrite(int2, HIGH);
      analogWrite(ena, 255);

      digitalWrite(int3, LOW);
      digitalWrite(int4, HIGH);
      analogWrite(enb, 255);
    } else if (data == '0') {
      digitalWrite(int1, HIGH);
      digitalWrite(int2, LOW);
      analogWrite(ena, 255);

      digitalWrite(int3, HIGH);
      digitalWrite(int4, LOW);
      analogWrite(enb, 255);
    }

    // Check if 2 minutes (120,000 milliseconds) have passed
    if (millis() - startTime >= 2000) {
      stopMotor();  // Stop the motor after 2 minutes
      motorRunning = false;
    }
  }
}

void stopMotor() {
  digitalWrite(int1, LOW);
  digitalWrite(int2, LOW);
  analogWrite(ena, 0);

  digitalWrite(int3, LOW);
  digitalWrite(int4, LOW);
  analogWrite(enb, 0);
}


// int int1 = 8;
// int int2 = 9;
// int ena = 10;

// int int3 = 6;
// int int4 = 7;
// int enb = 5;

// // uint8_t led1 = 11;
// // uint8_t led2 = 12;
// char data = "";

// // void processReceivedData(String receivedData) {
// //   int commaIndex = receivedData.indexOf(',');

// //   if (commaIndex != -1) {
// //     String led1State = receivedData.substring(0, commaIndex);
// //     String led2State = receivedData.substring(commaIndex + 1);

// //     // Remove any leading/trailing spaces
// //     led1State.trim();
// //     led2State.trim();

// //     Serial.println(led1State);
// //     Serial.println(led2State);


// //     if (led1State == "1" && led2State == "0") {
// //       digitalWrite(led1, HIGH);
// //       digitalWrite(led2, LOW);
// //     }

// //     if (led1State == "0" && led2State == "1") {
// //       digitalWrite(led2, HIGH);
// //       digitalWrite(led1, LOW);
// //     }
// //   }
// // }

// void setup() {
//   pinMode(int1, OUTPUT);
//   pinMode(int2, OUTPUT);
//   pinMode(ena, OUTPUT);

//   pinMode(int3, OUTPUT);
//   pinMode(int4, OUTPUT);
//   pinMode(enb, OUTPUT);

//   Serial.begin(9600);
// }

// void loop() {
//   if (Serial.available() > 0) {
//     data = Serial.read();
//     Serial.print(data);
//   }

//   switch (data) {
//     case '1':
//       digitalWrite(int1, LOW);
//       digitalWrite(int2, HIGH);
//       analogWrite(ena, 255);

//       digitalWrite(int3, LOW);
//       digitalWrite(int4, HIGH);
//       analogWrite(enb, 255);

//       delay(1000);
//       break;

//     case '0':
//       digitalWrite(int1, HIGH);
//       digitalWrite(int2, LOW);
//       analogWrite(ena, 255);

//       digitalWrite(int3, HIGH);
//       digitalWrite(int4, LOW);
//       analogWrite(enb, 255);

//       delay(1000);
//       break;

//     default:
//       break;
//   }

//   // digitalWrite(int1, HIGH);
//   // digitalWrite(int2, LOW);
//   // analogWrite(ena, 255);

//   // digitalWrite(int3, HIGH);
//   // digitalWrite(int4, LOW);
//   // analogWrite(enb, 255);
//   // delay(4000);

//   // digitalWrite(int1, LOW);
//   // digitalWrite(int2, LOW);
//   // analogWrite(ena, 255);

//   // digitalWrite(int3, LOW);
//   // digitalWrite(int4, LOW);
//   // analogWrite(enb, 255);
//   // delay(4000);

//   // digitalWrite(int1, LOW);
//   // digitalWrite(int2, HIGH);
//   // analogWrite(ena, 255);

//   // digitalWrite(int3, LOW);
//   // digitalWrite(int4, HIGH);
//   // analogWrite(enb, 255);
//   // delay(4000);
// }
