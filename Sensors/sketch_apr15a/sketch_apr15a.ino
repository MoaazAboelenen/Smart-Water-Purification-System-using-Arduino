// Turbidity Sensor connected to analog pin A0
const int turbidityPin = A0;
int sensorValue = 0;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(turbidityPin, INPUT);
}

void loop() {
  sensorValue = analogRead(turbidityPin); // Read the analog value

  // Optional: Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Print raw value and voltage
  Serial.print("Turbidity Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("  |  Voltage: ");
  Serial.println(voltage, 2);

  delay(1000); // Read every second
}
