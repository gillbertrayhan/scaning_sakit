// Include library untuk sensor denyut nadi
#include <PulseSensorPlayground.h>

// Pin untuk sensor denyut nadi
const int PulseSensorPin = A0;

// Membuat objek PulseSensor
PulseSensorPlayground pulseSensor;

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);

  // Mengatur pin untuk PulseSensor
  pulseSensor.analogInput(PulseSensorPin);

  // Jika sensor tidak terdeteksi, tampilkan pesan kesalahan
  if (!pulseSensor.begin()) {
    Serial.println("Pulse sensor tidak terdeteksi!");
    while (true);
  }
}

void loop() {
  // Mengambil data denyut nadi
  int myBPM = pulseSensor.getBeatsPerMinute();

  // Jika ada detak jantung yang terdeteksi
  if (pulseSensor.sawStartOfBeat()) {
    Serial.print("Detak jantung: ");
    Serial.print(myBPM);
    Serial.println(" BPM");
  }

  // Tunggu sebentar sebelum membaca ulang
  delay(20);
}