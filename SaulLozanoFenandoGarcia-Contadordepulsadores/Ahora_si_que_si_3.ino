int a=0;
int b=0;
int c=0;
int d=0;
int pinPulsador= A1; //definimos el pulsador 1
int pinPulsador2=A2; //definimos el pulsador 2
int pulsador2=0; //indicamos que el estado inicial del pulsador es apagado 
int pulsador=0; //indicamos que el estado inicial del pulsador es apagado 
#define L 4 //puerto de comunicación
#define C 7 //puerto para reloj
#define D 8 //puerto de datos
const byte MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
const byte POSICION[] = {0xF1,0xF2,0xF4,0xF8};
void setup (){
pinMode(L,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(pinPulsador, INPUT);
pinMode(pinPulsador2, INPUT);// indicamos que el pulsador
}
void loop(){
Escribe(0 , d);
Escribe(1 , c);
Escribe(2 , b);
Escribe(3 , a);
pulsador=digitalRead(pinPulsador);
if (pulsador==LOW){
 a=a+1;
 delay(1);
}
else (pulsador==HIGH);{
  a=a;
}
pulsador2=digitalRead(pinPulsador2);
if (pulsador2==LOW){
 a=a-1;
 delay(1);
}
else (pulsador2==HIGH);{
  a=a;
}
if(a>9){
  b=b+1;
  a=0;
}
if(b>9){
c=c+1;
b=0;
a=0;
b=0;
}
if(c>9){
  d=d+1;
  a=0;
  b=0;
  c=0;
}
if(d>9){
  b=0;
  a=0;
  c=0;
  d=0;
}
if(a<0){
  b=b-1;
  a=9;
}
if(b<0){
  c=c-1;
  b=9;
}
if(c<0){
  d=d-1;
  c=9;
}
if(d<0){
  d=9;
  a=9;
  b=9;
  c=9;
}
}
void Escribe(byte Segmento, byte Valor){
digitalWrite(L,LOW); 
shiftOut(D, C, MSBFIRST, MAP[Valor]);
shiftOut(D, C, MSBFIRST, POSICION[Segmento] );
digitalWrite(L,HIGH);
}

