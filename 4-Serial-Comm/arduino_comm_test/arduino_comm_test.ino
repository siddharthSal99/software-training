char buffer[4];

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void shiftBuffer() {
  for(int i = 0; i < 3; i++) {
    buffer[i] = buffer[i+1];
  } 
}

void loop() {
  if(Serial.available() > 0) {
    shiftBuffer();
    buffer[3] = Serial.read();
    if(strcmp(buffer, "stop") == 0) {
      digitalWrite(13, LOW);
    }
  }
}
