//Motion Sensor
const int buzzer = 2;
const int echo = 4;
const int trig = 5;
float distance, duration;

void setup() {
  // put your setup code here, to run once:  pinMode(buzzer, OUTPUT);
  
 pinMode(buzzer, OUTPUT);
 pinMode(echo, INPUT);
 pinMode(trig, OUTPUT);

 
}

void loop() {
   // put your main code here, to run repeatedly:
Serial.begin(9600);
 digitalWrite(echo, HIGH);
 delay(1000);
 digitalWrite(echo, LOW);
 
 digitalWrite(trig, HIGH);
 delay(1000);
 digitalWrite(trig, LOW);
 
  duration = pulseIn(echo, HIGH);
 Serial.print("Duration :");
 Serial.println(duration);
 distance = (duration*0.343)/2;
 Serial.print("Distance: ");
 Serial.println(distance);
 if (distance < 1200) {
  digitalWrite(buzzer, HIGH);
 }

else{
  digitalWrite(buzzer, LOW);
  
  } 
  delay(100);
 } 
