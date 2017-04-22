#define LED_PIN 13
#define BUT_PIN_1 2
#define BUT_PIN_2 3

int estado_led;
unsigned long antes;
int tempo;

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_PIN_1, INPUT);
  pinMode(BUT_PIN_2, INPUT);
  estado_led = 0;
  antes = millis();
  tempo = 1000; 
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, estado_led);   
  
  unsigned long agora = millis();

  if(agora >= antes + tempo)
  {
    antes = agora;
    estado_led = !estado_led; 
  }
  
  int but1 = digitalRead(BUT_PIN_1);
  int but2 = digitalRead(BUT_PIN_2);
  
  if (but1 == LOW){
    tempo += 200;
  }
  
  if (but2 == LOW && tempo > 0){
  	tempo -= 200;
  }
  
  if (but1 == LOW && but2 == LOW){
    digitalWrite(LED_PIN, LOW);
    while(1);
  }
}
