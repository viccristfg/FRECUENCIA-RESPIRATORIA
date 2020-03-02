int sensor = 0;
int mayor = 0;
int menor = 0;
void setup() {
 Serial.begin(9600);
 pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
 digitalWrite(8, LOW);
 digitalWrite(7, LOW);
 pinMode(A0, INPUT);
 Serial.begin(9600);
 Serial.println("- MEDIDOR DE FRECUENCIA RESPIRATORIA -");
 Serial.println("");
 Serial.println("");
 Serial.println("");

}
void loop() {
 delay(500);
 sensor = analogRead(A0);

 menor = sensor;
Serial.println("Detectando pico minimo de respiración, espere...");
for(int k = 0; k <90; k++)
{
 delay(100);
 sensor = analogRead(A0);
 if (sensor < menor)
 {
 menor = sensor;
 }

 if(sensor > menor)
 {
 k = 90;
 }
 delay(100);
}
 Serial.println("Pico minimo detectado, comenzando medición");

 sensor = analogRead(A0);
 //Serial.println(sensor);
 double contador = 0;
 mayor = sensor;
 Serial.println("Midiendo tiempo de exhalación");
 
for(int i = 0; i <90; i++)
{
 delay(100);
 sensor = analogRead(A0);
// Serial.println(sensor);
 if (sensor > mayor)
 {
 mayor = sensor;
 }

 if(sensor < mayor)
 {
 i = 90;
 }
 delay(100);
 contador++;
}
Serial.println("Midiendo tiempo de inhalación");
 sensor = analogRead(A0);
double contador2 = 0;
menor = sensor;
for(int j = 0; j <90; j++)
{
 delay(100);
 sensor = analogRead(A0);
 if (sensor < menor)
 {
 menor = sensor;
 }

 if(sensor > menor)
 {
 j = 90;
 }
 delay(100);
 contador2++;
}
double tiempo = (contador + contador2)*0.2;
double freq1 = 60/tiempo;
double freq=round(freq1);

if (freq<12)
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  Serial.print("");
Serial.print("Respiraciones por minuto: "); Serial.println(freq);
Serial.println("ALERTA: PACIENTE PRESENTA BRADIPNEA");
delay (2000);
Serial.print("");
Serial.print("");
Serial.print("");
Serial.println();
  
  }

if (freq>20)
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);

Serial.print("");
Serial.print("Respiraciones por minuto: "); Serial.println(freq);
Serial.println("ALERTA: PACIENTE PRESENTA TAQUIPNEA");
delay (2000);
Serial.print("");
Serial.print("");
Serial.print("");
Serial.println();
  
  }

if (freq<21 && freq>11)
  {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

Serial.print("");
Serial.print("Respiraciones por minuto: "); Serial.println(freq);
delay (2000);
Serial.print("");
Serial.print("");
Serial.print("");
Serial.println();
  }

}
