// Define pump control pins (2 pins per pump)
const int pump1_pinA = 2;
const int pump1_pinB = 3;
const int pump2_pinA = 4;
const int pump2_pinB = 5;
const int pump3_pinA = 6;
const int pump3_pinB = 7;
const int pump4_pinA = 8;
const int pump4_pinB = 9;

// L298N Enable pins
const int enA = 10; // Enable for pump1 & pump2
const int enB = 11; // Enable for pump3 & pump4

int loopCounter = 0;
const int maxLoops = 5;

// Turbidity tracking
unsigned long turbidityStartTime;
const unsigned long turbidityInterval = 5000;       // 5 seconds
const unsigned long turbidityTotalDuration = 600000; // 10 minutes in ms

void setup() {
  // Set all pump control pins as output
  pinMode(pump1_pinA, OUTPUT); pinMode(pump1_pinB, OUTPUT);
  pinMode(pump2_pinA, OUTPUT); pinMode(pump2_pinB, OUTPUT);
  pinMode(pump3_pinA, OUTPUT); pinMode(pump3_pinB, OUTPUT);
  pinMode(pump4_pinA, OUTPUT); pinMode(pump4_pinB, OUTPUT);

  // Set enable pins as output and activate them
  pinMode(enA, OUTPUT); digitalWrite(enA, HIGH);
  pinMode(enB, OUTPUT); digitalWrite(enB, HIGH);

  // Start serial monitor
  Serial.begin(9600);
  Serial.println("Water Filtration System Initialized...");

  // Start turbidity timer
  turbidityStartTime = millis();
}

void loop() {
  if (loopCounter >= maxLoops) {
    Serial.println("All cycles completed. System halted.");
    while (true);  // Stop execution
  }

  Serial.print("Starting cycle ");
  Serial.println(loopCounter + 1);

  runPump1();
  waitWithTurbidity(100000);  // Wait 5 minutes

  runPump2();
  waitWithTurbidity(160000);  // Wait 10 minutes

  // In the 5th cycle (loopCounter == 4), run Pump 4 instead of Pump 3
  if (loopCounter == maxLoops - 1) {
    runPump4();
    Serial.println("Pump 4 activated in final cycle.");
  } else {
    runPump3();
    Serial.println("Pump 3 activated.");
  }

  waitWithTurbidity(280000);  // Wait 15 minutes
  loopCounter++;
}

// ---------------- Pump Functions ----------------

void runPump1() {
  Serial.println("Pump 1 activated");
  digitalWrite(pump1_pinA, HIGH);
  digitalWrite(pump1_pinB, LOW);
  delay(50000);  // Run for 50 seconds
  digitalWrite(pump1_pinA, LOW);
  digitalWrite(pump1_pinB, LOW);
}

void runPump2() {
  Serial.println("Pump 2 activated");
  digitalWrite(pump2_pinA, HIGH);
  digitalWrite(pump2_pinB, LOW);
  delay(50000);  // Run for 50 seconds
  digitalWrite(pump2_pinA, LOW);
  digitalWrite(pump2_pinB, LOW);
}

void runPump3() {
  digitalWrite(pump3_pinA, HIGH);
  digitalWrite(pump3_pinB, LOW);
  delay(50000);  // Run for 50 seconds
  digitalWrite(pump3_pinA, LOW);
  digitalWrite(pump3_pinB, LOW);
}

void runPump4() {
  digitalWrite(pump4_pinA, HIGH);
  digitalWrite(pump4_pinB, LOW);
  delay(50000);  // Run for 50 seconds
  digitalWrite(pump4_pinA, LOW);
  digitalWrite(pump4_pinB, LOW);
}

// ---------------- Turbidity Simulation ----------------

float getSimulatedTurbidity() {
  unsigned long elapsed = millis() - turbidityStartTime;
  if (elapsed >= turbidityTotalDuration) return 15.0;

  float progress = (float)elapsed / turbidityTotalDuration;  // 0.0 to 1.0
  float baseValue = 100.0 - (85.0 * progress);                // 100 → 15 NTU
  float noise = random(-10, 10) / 10.0;                       // ±1.0 NTU
  float turbidity = baseValue + noise;

  return (turbidity < 15.0) ? 15.0 : turbidity;
}

// ---------------- Custom Delay With Turbidity ----------------

void waitWithTurbidity(unsigned long waitDuration) {
  unsigned long start = millis();
  unsigned long lastPrint = 0;

  while (millis() - start < waitDuration) {
    if (millis() - lastPrint >= turbidityInterval) {
      float turbidity = getSimulatedTurbidity();
      Serial.print("Turbidity = ");
      Serial.print(turbidity, 1);
      Serial.println(" NTU");
      lastPrint = millis();
    }
  }
}
