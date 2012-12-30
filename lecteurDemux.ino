int pinIn = 8;
int pinRck = 9;
int pinSck = 10;
int pinClear = 11;

int pinSend = 4;
int pinOne = 5;

int demi = 250;

void setup(){
  
  Serial.begin(9600);
  
  pinMode(pinIn, OUTPUT);
  pinMode(pinRck, OUTPUT);
  pinMode(pinSck, OUTPUT);
  pinMode(pinClear, OUTPUT);
  pinMode(pinSend, INPUT);
  pinMode(pinOne, INPUT);
  
  digitalWrite(pinClear, LOW);
  digitalWrite(pinIn, LOW);
  digitalWrite(pinRck, LOW);
  digitalWrite(pinSck, LOW);
  
}

int count = 0;

void loop(){
  Serial.println("test");
  if (count == 0){
    initReg();
  }
  
  // Wait until we press the button
  while(analogRead(0) < 600){}
  
  //while(digitalRead(pinSend) == LOW){Serial.println("Rien de lu");}
  Serial.println("Capt");
  // Read input and report it on the in for shift register
  int val =analogRead(1);
  Serial.println(val);
  if (val<400){
    digitalWrite(pinIn, LOW);
    Serial.println("Write low");
  }else{
    digitalWrite(pinIn, HIGH);
    Serial.println("Write high");
  }
  
  delay(demi);
  
  digitalWrite(pinSck, LOW);
  digitalWrite(pinRck, HIGH);
  
  periode();
  count = (count +1) %3;  
}

/*
 * Initialize a new word (3 bit)
 */
void initReg(){
  digitalWrite(pinClear, LOW);
  digitalWrite(pinRck, LOW);
  digitalWrite(pinClear, HIGH);
  digitalWrite(pinSck, HIGH);
  
}

void periode(){
  delay(demi);
  digitalWrite(pinSck,HIGH);
  digitalWrite(pinRck,LOW);
  delay(demi);
  digitalWrite(pinSck,LOW);
  digitalWrite(pinRck,HIGH);
}
