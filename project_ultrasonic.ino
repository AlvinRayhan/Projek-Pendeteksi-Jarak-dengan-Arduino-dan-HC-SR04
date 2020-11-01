const int pingPin = 7; //Pin Trigger Sensor Ultrasonic
const int echoPin = 6; //Pin Echo Sensor Ultrasonic
const int ledPin = 13; //LED
long duration; 
long cm; //Variabel untuk menyimpan hasil konversi dari Us ke CM

//Fungsi untuk mengubah dari mikrosekon ke cm
long microsecondsToCentimeters(long microseconds){
  return microseconds*0.034/2; //Konversi dari microsecond ke cm
}
  
void setup(){
  Serial.begin(9600); //Starting Serial Terminal
  pinMode(ledPin, OUTPUT);
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop(){
  /*Variable duration untuk menyimpan lama waktu saat sensor
   * memancarkan gelombang ultrasonik sampai memantul pada 
   * benda dan diterima kembali oleh echoPin (pin 6) dalam
   * satuan microsecond
   */

  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  //Pemanggilan fungsi microsecondsToCentimeters
  cm = microsecondsToCentimeters(duration);
  if(cm<=200){
    digitalWrite(ledPin, HIGH);
  } else{
    digitalWrite(ledPin, LOW);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}
