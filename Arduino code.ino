char t;
char c;
char k;
char l;
char m;
char h;


void setup() {
pinMode(13,OUTPUT);   //Motores esquerda FRENTE
pinMode(12,OUTPUT);   //Motores esquerda TRÁS
pinMode(11,OUTPUT);   //Motores direita FRENTE
pinMode(10,OUTPUT);   //Motores direira TRÁS
pinMode(9,OUTPUT);    //Besouro
pinMode(8,OUTPUT);    //STOP
pinMode(7,OUTPUT);    //Farol Esquerda
pinMode(6,OUTPUT);    //Farol Direita
pinMode(2, OUTPUT);   //trigPin Frente
pinMode(3, INPUT);    //echoPin Frente
pinMode(4, OUTPUT);   //trigPin Trás
pinMode(5, INPUT);    //echoPin Trás


Serial.begin(9600);
 }
 
void loop() {

long duration, distance;
  digitalWrite(2,HIGH);
  delayMicroseconds(1000);
  digitalWrite(2, LOW);
  duration=pulseIn(3, HIGH);
  distance =(duration/2)/29.1;
  delay(10);

  
long duration1, distance1;
  digitalWrite(4,HIGH);
  delayMicroseconds(1000);
  digitalWrite(4, LOW);
  duration1=pulseIn(5, HIGH);
  distance1 =(duration1/2)/29.1;
  delay(10);

  
if(Serial.available()){
  t = Serial.read();
  //Serial.println(t);
}

if (t== 'li') {
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
}
else if (t=='lo') {
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

if(t == 'w' && (distance>20)){            //Todos os Motores para a frente

  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);
  
  c = 1;
  k = 0;
  l = 0;
  m = 0;
  h = 0;
 
}
 
else if(t == 's' && (distance1>20)){      //Todos os Motores para a trás

  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
  digitalWrite(8,LOW);

  k = 1;
  c = 0;
  l = 0;
  m = 0; 
  h = 0; 
 
}
 
else if(t == 'd'){                       //Virar á direita (Motores esquerda para a frente e os da direita para trás)

  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(13,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);

  k = 0;
  c = 0;
  l = 0;
  m = 1;
  h = 0;
}
 
else if(t == 'a'){                       //Virar á esquerda (Motores esquerda para trás e os da direita para a frente)

  digitalWrite(13,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,LOW);

  k = 0;
  c = 0;
  l = 1;
  m = 0;
  h = 0;
}

else if(t == 'x'){                      //STOP (stop a todos os Motores)

  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);

  k = 0;
  c = 0;
  l = 0;
  m = 0;
  h = 0;
}

else if( c == 1 && distance<=20)  
 {
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);   
  delay(1000);                                      
 }

 else if (k == 1 && distance1 >50)
  {
    tone(9, 1000, 100);
    delay(700);
  }
 else if (k == 1 && distance1 <= 50 && distance1>35)
  {
    tone(9, 1000, 100);
    delay(400);
  }
else if (k == 1 && distance1 <= 35 && distance1>20)
  {
    tone(9, 1000, 100);
     delay(150);
  }
else if (k == 1 && distance1 <= 20)
  {
    tone(9, 1000, 100);
     delay(30);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  delay(1000);  
  }
 
else if (l == 1 ){
  digitalWrite(7,HIGH);
  delay(300);
  digitalWrite(7,LOW);
  delay(300);
}

else if (m == 1 ){
  digitalWrite(6,HIGH);
  delay(300);
  digitalWrite(6,LOW);
  delay(300);
}

else if (t == 'h' && h==0){   
  digitalWrite(6,HIGH);
 h = 2;
 t="";
}

else if (t=='h' && h == 2 ){
  digitalWrite(6,LOW);
  h = 0;
  t="";

   
}
}
