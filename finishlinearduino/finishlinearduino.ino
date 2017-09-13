/*
 * Dog timing finish line module
 */
int resetPin = 8;
int lurePin = 7;                // lurePin
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int IRval = 0;                  // variable for reading the pin status
int raceStart =0;
int lureLED = 6;
int counter = 0;                //0 is reset state, 1 is timing state, 2 is timed state, cannot re-time until in reset state - 0
int reset = 0;
int postBdDelay = 3000;        //Delay after beam break in ms to allow stabilisation
int timeLimit = 3000;          //Time limit from last lure press before resetting; used to assume a failed time
float startTime;
float finishTime;
float raceTime;
unsigned long timeFromLP;
 
void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(lurePin, INPUT);      // declare lurePin as imput
  pinMode(lureLED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Lure Crazy dog timing");
  Serial.println("============================================================= ");
  Serial.println("Ensure finish line is clear and sensor does not have view of people or other dogs during timing");
  delay (3000);
  Serial.println(" ");
  Serial.println("Sensor will now take three seconds to stabilise");
  Serial.print("3,");
  delay(1000);
  Serial.print("2,");
  delay(1000);
  Serial.println("1...");
  delay(1000);
  Serial.println(" ");
  Serial.println("Timing is now armed, press lure to begin timing");
  Serial.println(" ");
  Serial.println("Waiting for lure press...");
  Serial.println(" ");
}
 
void loop(){
  IRval = digitalRead(inputPin); 
  raceStart = digitalRead(lurePin);
  reset = digitalRead(resetPin);

if ((raceStart == HIGH) && (counter == 0))  {
  startTime=millis();
  Serial.println(" ");
  Serial.println("Lure pressed, timing started...");
  Serial.println(" ");
  counter=1;
}


if (raceStart == HIGH)
  timeFromLP = millis();
  
if ((millis() - timeFromLP > timeLimit) && (counter == 1)){
   Serial.println ("*************************************************************");
   Serial.println ("Timing taken too long! Assuming finish line not crossed.");
   Serial.println ("*************************************************************");
   delay (3000);
   counter = 2;
 }


if (raceStart == HIGH) {
  digitalWrite(lureLED, HIGH);}
  else{
  digitalWrite(lureLED, LOW);
}
  
  
if ((IRval == HIGH) && (counter == 1)) {            
  digitalWrite(ledPin, HIGH);  
  if (pirState == LOW) {
    Serial.println("Finish line beam broken");
    finishTime = millis();
    raceTime = (finishTime - startTime);
    Serial.println(" ");
    Serial.println("============================================================= ");
    Serial.print ("Dog ran course in: ");
    Serial.print (raceTime/1000);
    Serial.println (" seconds");
    Serial.println("============================================================= ");
    Serial.println(" ");
    delay (postBdDelay);
    counter = 2;
    pirState = HIGH;
  }
} 
  else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH){
      Serial.println("Finish line clear, waiting for sensor to stabilise");
      Serial.print("3,");
      delay(1000);
      Serial.print("2,");
      delay(1000);
      Serial.println("1...");
      delay(1000);
      Serial.println(" ");
      Serial.println ("Timing reset and armed");
      Serial.println(" ");
      Serial.println("Waiting for lure press...");
      counter = 0;
      pirState = LOW;
    }
  }
if ((reset == HIGH) && (counter == 1) || (counter == 5)){
  counter = 0;
  Serial.println(" ");
  Serial.println ("Timing reset and armed");
  Serial.println(" ");
  Serial.println ("Waiting for lure press...");
}


if ((IRval == HIGH) && (counter == 0)) {            
  digitalWrite(ledPin, HIGH);  
  if (pirState == LOW) {
    Serial.println("*************************************************************");
    Serial.println("Finish line beam broken before lure moved!!!");
    Serial.println("Please ensure finish line is clear before timing.");
    Serial.println("*************************************************************");
    delay (postBdDelay);
    Serial.println(" ");
    counter = 2;
    pirState = HIGH;
    }
  } 
  else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH){
      Serial.println("Finish line clear, waiting for sensor to stabilise");
      Serial.print("3,");
      delay(1000);
      Serial.print("2,");
      delay(1000);
      Serial.println("1...");
      delay(1000);
      Serial.println(" ");
      Serial.println ("Timing reset and armed");
      Serial.println(" ");
      Serial.println("Waiting for lure press...");
      counter = 0;
      pirState = LOW;
    }
  }
}
