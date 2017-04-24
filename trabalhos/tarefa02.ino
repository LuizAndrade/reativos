#define LED_PIN 13
#define BUT_PIN_1 2
#define BUT_PIN_2 3

int estado_led;
int tempo;

bool press1 = false;
bool press2 = false;

unsigned long pushFirst;
unsigned long pushSecond;
unsigned long antes;


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
    
    press1 = true;
    tempo += 200;
    
    if(press2){
      
      pushSecond = millis();
      if (pushSecond < pushFirst + 500){
        
            digitalWrite(LED_PIN, LOW);
    		while(1);
        
      }else{
        
        press2 = false;
      }
    }else{
    
    pushFirst = millis();
  }
  }
  

  if (but2 == LOW && tempo > 0){
    press2 = true;
  	tempo -= 200;
    if(press1){
      
      pushSecond = millis();
      if (pushSecond < pushFirst + 500){
        
            digitalWrite(LED_PIN, LOW);
    		while(1);
        
      }else{
        
        press1 = false;
      }
    }else{
    
    pushFirst = millis();
  }
  }

  

}
