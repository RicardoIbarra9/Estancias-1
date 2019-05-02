

// MOTOR 1.

int Motor1A = 5;
int Motor1B = 6;
// MOTOR 2.

int Motor2A = 9;
int Motor2B = 10;

int toSend = 'g';

void setup ()
{
Serial.begin(9600);

pinMode( Motor1A, OUTPUT );
pinMode( Motor2A, OUTPUT );
pinMode( Motor1B, OUTPUT );
pinMode( Motor2B, OUTPUT );

digitalWrite( Motor1A, LOW );
digitalWrite( Motor2A, LOW );
digitalWrite( Motor1B, LOW );
digitalWrite( Motor2B, LOW );
}

void loop()
{
 if(Serial.available() > 0){
  toSend = Serial.read();
}
if(toSend == 'S')
{
stopp();
}

if( toSend == 'B')
{
// ESTOS HARAN QUE VAYA PARA ATRAS EL CARRITO.
atras();

}

if(toSend == 'F')
{
// ESTOS HARAN QUE VAYA HACIA DELANTE EL CARRITO.
adelante();

}

if(toSend == 'L')
{
// ESTOS HARAN QUE GIRE HACIA LA IZQUIERDA.
izquierda();

}
else

if(toSend == 'R')
{
// ESTOS HARAN QUE GIRE HACIA LA DERECHA.
derecha();
}
}

void adelante(){
  digitalWrite( Motor1B, HIGH); 
  analogWrite( Motor1A, 0 );
  digitalWrite( Motor2B, HIGH);
  analogWrite( Motor2A, 0 );
}

void atras(){
  digitalWrite( Motor1A, HIGH);
  analogWrite( Motor1B, 0 );
  digitalWrite( Motor2A, HIGH);
  analogWrite( Motor2B, 0 );
}

void derecha(){
  digitalWrite( Motor1B, HIGH);
  analogWrite( Motor1A, 0);
  digitalWrite( Motor2A, 0);
  analogWrite( Motor2B, 0);
}

void izquierda(){
  digitalWrite( Motor2B, HIGH);
  analogWrite( Motor2A, 0 );
  digitalWrite( Motor1A, 0);
  analogWrite( Motor1B, 0 );
  
}

void stopp(){
  digitalWrite( Motor1A, LOW);
  analogWrite( Motor1B, LOW);
  digitalWrite( Motor2A, LOW),
  analogWrite( Motor2B, LOW);
}
