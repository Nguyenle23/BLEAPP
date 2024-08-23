uint8_t led1 = 8;
uint8_t led2 = 10;
String data = "";

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();
    if (incomingChar != '\n') {
      data += incomingChar;  
    } else {
      Serial.print("Received data: ");
      Serial.println(data);
      processReceivedData(data);
      data = "";  
    }
  }
  
  delay(10);
}

void processReceivedData(String receivedData) {
  int commaIndex = receivedData.indexOf(',');

  if (commaIndex != -1) {
    String led1State = receivedData.substring(0, commaIndex);
    String led2State = receivedData.substring(commaIndex + 1);

    // Remove any leading/trailing spaces
    led1State.trim();
    led2State.trim();

    Serial.println(led1State);
    Serial.println(led2State);

    
    if (led1State == "1" && led2State == "0") {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
    }

    if (led1State == "0" && led2State == "1") {
      digitalWrite(led2, HIGH);
      digitalWrite(led1, LOW);
    }
  }
}
