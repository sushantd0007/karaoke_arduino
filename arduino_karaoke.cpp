#include <SPI.h>
#include <SD.h>
#include <TMRpcm.h>

TMRpcm audio;

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);

  // Initialize SD Card
  if (!SD.begin(10)) {
    Serial.println("SD Card initialization failed!");
    return;
  }

  // Initialize audio playback
  audio.speakerPin = 9; // Connect the XC3748 module's speaker pin to Arduino pin 9
}

void loop() {
  // Check if there's a button press or another trigger to play a song
  // You can use digitalRead() to check a button press or any other trigger
  // For simplicity, let's assume you trigger song playback using a button press on pin 2
  int buttonState = digitalRead(2);

  if (buttonState == HIGH) { // Change this condition according to your trigger mechanism
    playSong("song1.wav");  // Replace "song1.wav" with the name of your audio file
  }
}

void playSong(const char* filename) {
  if (SD.exists(filename)) {
    Serial.print("Playing: ");
    Serial.println(filename);
    audio.play(filename);
    delay(100); // Adjust the delay as needed
  } else {
    Serial.println("File not found.");
  }
}