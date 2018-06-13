int speakerPin = 8;
char notes[] = "ccggaagffeeddc ";
unsigned long beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,2,4}; 
int length = sizeof(notes); 
int tempo = 300;
void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode (7,OUTPUT);
}

void loop() {

  for (int i = 0; i < length; i++) {
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); 
    } else {
      playNote(speakerPin,notes[i], beats[i] * tempo);
    } 
    delay(tempo/10); 
  }
}

void playNote(int OutputPin, char note, unsigned long duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 261, 294, 330, 349, 392, 440, 494, 523 };
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      tone(OutputPin,tones[i], duration);
      digitalWrite(7,HIGH);
      delay(duration);
      digitalWrite(7,LOW);
      noTone(OutputPin);
    }
  }
}
