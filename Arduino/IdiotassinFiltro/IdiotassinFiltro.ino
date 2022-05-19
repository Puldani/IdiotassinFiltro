const int salida_rojo = 2;
const int salida_verde = 5;
const int salida_bocina= 6;
const int salida_azul = 3;
const int salida_naranja = 7;
const int entrada_verde= 9;
const int entrada_rojo= 8;
const int entrada_azul= 10;
const int entrada_naranja= 11;
bool statusverde,lectura1,lectura2,lectura3,lectura4;
bool statusrojo,statusazul,statusnaranja;
bool statusboton,okverde,okrojo;
bool okazul,oknaranja;

void setup() {
  Serial.begin(9600);
  pinMode(salida_rojo,OUTPUT);
  pinMode(salida_verde,OUTPUT);
  pinMode(salida_azul,OUTPUT);
  pinMode(salida_naranja,OUTPUT);
  pinMode(salida_bocina,OUTPUT);
  pinMode(entrada_verde,INPUT);
  pinMode(entrada_rojo,INPUT); 
  pinMode(entrada_azul,INPUT); 
  pinMode(entrada_naranja,INPUT); 
  statusverde= LOW;
  statusrojo=LOW;
  statusazul=LOW;
  statusnaranja=LOW;
  statusboton=LOW;
  okverde=HIGH;
  okrojo=HIGH;
  okazul=HIGH;
  oknaranja=HIGH;
  
}

void loop() {
 lectura1 = digitalRead(entrada_verde);
 lectura2 =digitalRead(entrada_rojo);
 lectura3 =digitalRead(entrada_azul);
 lectura4 =digitalRead(entrada_naranja);
 // PARA ENCENDER EL LED VERDE 
 Serial.print("0");
 if(okverde==1){
  if(lectura1==HIGH && statusverde==LOW){
    statusverde=HIGH;
    okverde=0;
    Serial.write(1);
    delay(100);
  }else if(lectura1==HIGH && statusverde==HIGH){
    statusverde=LOW;
    okverde=0;
    delay(100);
  }
  digitalWrite(salida_verde,statusverde);
  digitalWrite(salida_bocina,statusverde);
  delay(100);
  }
 if(okverde==0 && lectura1==LOW){
  okverde=1;
 }


 //PARA ENCENDER EL LED ROJO Y LA BOCINA 
  if(okrojo==1){
  if(lectura2==HIGH && statusrojo==LOW){
    statusrojo=HIGH;
    okrojo=0;
    Serial.write(2);
    delay(100);
  }else if(lectura2==HIGH && statusrojo==HIGH){
    statusrojo=LOW;
    okrojo=0;
    delay(100);
  }
  digitalWrite(salida_rojo,statusrojo);
  digitalWrite(salida_bocina,statusrojo);
  delay(200);
  }
 if(okrojo==0 && lectura2==LOW){
  okrojo=1;
 }

  // PARA ENCENDER EL LED AZUL 
 if(okazul==1){
  if(lectura3==HIGH && statusazul==LOW){
    statusazul=HIGH;
    okazul=0;
    Serial.write(3);
    delay(100);
  }else if(lectura3==HIGH && statusazul==HIGH){
    statusazul=LOW;
    okazul=0;
    delay(100);
  }
  digitalWrite(salida_azul,statusazul);
  digitalWrite(salida_bocina,statusazul);
  delay(300);
  }
 if(okazul==0 && lectura3==LOW){
  okazul=1;
 }
 
    // PARA ENCENDER EL LED NARANJA 
 if(oknaranja==1){
  if(lectura4==HIGH && statusnaranja==LOW){
    statusnaranja=HIGH;
    oknaranja=0;
    Serial.write();
    delay(100);
  }else if(lectura4==HIGH && statusnaranja==HIGH){
    statusnaranja=LOW;
    oknaranja=0;
    delay(100);
  }
  digitalWrite(salida_naranja,statusnaranja);
  digitalWrite(salida_bocina,statusnaranja);
  delay(400);
  }
 if(oknaranja==0 && lectura4==LOW){
  oknaranja=1;
 }


 
}
  
