const int LED_BUILTIN = 2;

int mvm32 = 32;
int mvm12 = 12;
int mvm14 = 14;
int mvm13 = 13;

int mvm23 = 23;
int mvm22 = 22;
int mvm21 = 21;
int mvm19 = 19;
int mvm18 = 18;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(mvm32, OUTPUT);
  pinMode(mvm14, OUTPUT);
  pinMode(mvm12, OUTPUT);
  pinMode(mvm13, OUTPUT);

  pinMode(mvm23, OUTPUT);
  pinMode(mvm22, OUTPUT);
  pinMode(mvm21, OUTPUT);
  pinMode(mvm19, OUTPUT);
  pinMode(mvm18, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // Read the motor number
    int motorNumber = Serial.parseInt();
    Serial.println(motorNumber);

    // Read the speed value
    int speedValue = Serial.parseInt();
    Serial.println(speedValue);

    // Apply the speed to the corresponding motor
    switch (motorNumber) {
      case 1:
        analogWrite(mvm23, speedValue);
        break;
      case 2:
        analogWrite(mvm32, speedValue);
        break;
      case 3:
        analogWrite(mvm14, speedValue);
        break;
      case 4:
        analogWrite(mvm21, speedValue);
        break;
      case 5:
        analogWrite(mvm22, speedValue);
        break;
      case 6:
        analogWrite(mvm12, speedValue);
        break;
      case 7:
        analogWrite(mvm19, speedValue);
        break;
      case 8:
        analogWrite(mvm18, speedValue);
        break;
      case 9:
        analogWrite(mvm13, speedValue);
        break;
      default:
        break;
    }
  }

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}


// const int LED_BUILTIN = 2;

// int mvm32 = 32;
// int mvm12 = 12;
// int mvm14 = 14;
// int mvm13 = 13;

// int mvm23 = 23;
// int mvm22 = 22;
// int mvm21 = 21;
// int mvm19 = 19;
// int mvm18 = 18;

// // int data = 100;
// char data1 = "";
// char data2 = "";
// char data3 = "";
// char data4 = "";
// char data5 = "";
// char data6 = "";
// char data7 = "";
// char data8 = "";
// char data9 = "";

// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);

//   pinMode(mvm32, OUTPUT);
//   pinMode(mvm14, OUTPUT);
//   pinMode(mvm12, OUTPUT);
//   pinMode(mvm13, OUTPUT);

//   pinMode(mvm23, OUTPUT);
//   pinMode(mvm22, OUTPUT);
//   pinMode(mvm21, OUTPUT);
//   pinMode(mvm19, OUTPUT);
//   pinMode(mvm18, OUTPUT);

//   Serial.begin(9600);
// }

// void loop() {
//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(500);
//   digitalWrite(LED_BUILTIN, LOW);

//   analogWrite(mvm23, data1);
//   analogWrite(mvm32, data2);
//   analogWrite(mvm14, data3);
//   analogWrite(mvm21, data4);
//   analogWrite(mvm22, data5);
//   analogWrite(mvm12, data6);
//   analogWrite(mvm19, data7);
//   analogWrite(mvm18, data8);
//   analogWrite(mvm13, data9);
// }


// const int LED_BUILTIN = 2;

// int mvm23 = 23;
// int mvm22 = 22;
// int mvm27 = 27;
// int mvm32 = 26;

// void setup() {
//   Serial.begin(9600);
//   pinMode(LED_BUILTIN, OUTPUT);
//   pinMode(mvm23, OUTPUT);
//   pinMode(mvm22, OUTPUT);
//   pinMode(mvm27, OUTPUT);
//   pinMode(mvm32, OUTPUT);
// }

// void loop() {
//   if (Serial.available() > 0) {
//     String command = Serial.readStringUntil('\n');
//     int commaIndex = command.indexOf(',');
//     int motor = command.substring(0, commaIndex).toInt();
//     int speed = command.substring(commaIndex + 1).toInt();

//     switch (motor) {
//       case 0:
//         analogWrite(mvm23, speed);
//         break;
//       case 1:
//         analogWrite(mvm22, speed);
//         break;
//       case 2:
//         analogWrite(mvm27, speed);
//         break;
//       case 3:
//         analogWrite(mvm32, speed);
//         break;
//     }
//   } else {
//     digitalWrite(LED_BUILTIN, HIGH);
//   }
// }
