/*
Hello folks! Here is a simple basic sketch for those who are learning Arduino.
It turns 3 different LED's as you turn the potentiometer knob. 
I hope it helps. 

For suggestions, doubts and comments, fell free to send me an e-mail: andre_ranulfo@hotmail.com

*/


//Analogic pin A0 will receive the potenciometer data.
//O pino analógico A0 que receberá os dados do potenciômetro.
const int ANALOG_PIN_IN = A0;

//wait and see.
//Aguarde e veja.
int valor;

//Here follows the digital pins which will turn on/off the LED's
//Segue os pinos digitais que ligarão e desligação os LED's.
const int   LED_GREEN     = 7; // LED Gree/Verde
const int   LED_YELLOW    = 6; // LED Yellow/Amarelo
const int   LED_RED       = 5; // LED Red/Vermelho


void setup() {

//Liga o serial monitor
//Turn on serial motinor 
  Serial.begin (9600);

//Pin modes
// Modo dos pinos  
 pinMode (LED_GREEN,OUTPUT);
 pinMode (LED_YELLOW,OUTPUT);
 pinMode (LED_RED ,OUTPUT);
 pinMode ( ANALOG_PIN_IN,INPUT);


//Turn on the LED's for 2sec. just to make sure it is working properly.
//Liga todos os LED's só para ter certeza se está funcionando e fica ligado por 2 seg..
 digitalWrite (LED_GREEN,HIGH);
 digitalWrite(LED_YELLOW,HIGH);
 digitalWrite (LED_RED,HIGH);  
 delay(2000);
  
 
}

void loop() {
  
  //The variable "valor" receives the potenciometer values via pin A0.
  //A variávél "valor" recebe constantemente o valor do potenciômetro via pin A0.
  valor= map( analogRead(ANALOG_PIN_IN),0,1023,1,99);
 
 //After receive the value, the function is called which checks the potentiometer values and turn on/off the LED's.
 //Após receber o valor, é chamada a função que checa o valor do potenciômetro e lig/desliga LED's.   
  checkPotenciometerValueToTurnLED();


}

//The function checkPotenciometerValToTurnLED()tests the potentiometer value
// According to the value, it turns on/off de LED's.

//A função checkPotenciometerValToTurnLED() testa o valor do potenciômetro.
//Dependendo do valor, liga/Desliga os LED's.
void checkPotenciometerValToTurnLED(){

    if((valor >=1) && (valor <=33 )){
        digitalWrite (LED_GREEN,HIGH);
        digitalWrite(LED_YELLOW,LOW);
        digitalWrite (LED_RED,LOW); 
        Serial.write("1" );//Apenas para fins de debug no monitor serial.
  }
  
  if((valor>=34)&& (valor <=66 )){
        digitalWrite (LED_GREEN,LOW);
        digitalWrite(LED_YELLOW,HIGH);
        digitalWrite (LED_RED,LOW); 
        Serial.write("2");//Apenas para fins de debug no monitor serial.
  }
  
  if(valor>=67){
        digitalWrite (LED_GREEN,LOW);
        digitalWrite(LED_YELLOW,LOW);
        digitalWrite (LED_RED,HIGH); 
        Serial.write("3");//Apenas para fins de debug no monitor serial.
  }
  
  }
