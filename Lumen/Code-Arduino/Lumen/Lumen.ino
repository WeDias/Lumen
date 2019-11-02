int leds[] = {6, 5, 3}; // | Vermelho = 6 | Verde = 5 | Azul = 3 |
int buzzer = 9;
int Intensidade_Led = 255;
int Intensidade_Vent = 255;
int ligado;
bool som = true; 

// Função para ligar o LED
int Ligar_Led(int led){
  for (int cont = 0; cont < 3; cont++){
    analogWrite(leds[cont], 0);
  }
  analogWrite(led, Intensidade_Led);
  return (led);
}


void setup() {
  Serial.begin(9600);
  for (int cont = 0; cont < 3; cont++){
    pinMode(leds[cont], OUTPUT);
  }
  pinMode(10, OUTPUT);
}


void loop() {
  analogWrite(ligado, Intensidade_Led);
  analogWrite(10, Intensidade_Vent);
  if (Serial.available()){
    char comando = Serial.read();
    if (som){
      tone(buzzer, 1500, 100);
    }
    // Alterar a intensidade do brilho do LED
    if (comando  == '-' and Intensidade_Led <= 255 and Intensidade_Led > 0){
      Intensidade_Led = Intensidade_Led - 15;
    }
    if (comando  == '+' and Intensidade_Led >= 0 and Intensidade_Led < 255){
      Intensidade_Led = Intensidade_Led + 15;
    }


    // Alterar a intensidade da ventoinha
    if (comando  == '<' and Intensidade_Vent <= 255 and Intensidade_Vent > 0){
      Intensidade_Vent = Intensidade_Vent - 15;
    }
    if (comando  == '>' and Intensidade_Vent >= 0 and Intensidade_Vent < 255){
      Intensidade_Vent = Intensidade_Vent + 15;
    }

     // Ligar ventoinha 
     if (comando  == 'V'){
      Intensidade_Vent = 255;
     }

     // Desliigar ventoinha 
     if (comando  == 'd'){
      Intensidade_Vent = 0;
     }

    
    // Alterar a cor do LED
    if (comando  == 'R'){
      Intensidade_Led = 255;
      ligado = Ligar_Led(6);
    }
    if (comando  == 'G'){
      Intensidade_Led = 255;
      ligado = Ligar_Led(5);
    }
    if (comando == 'B'){
      Intensidade_Led = 255;
      ligado = Ligar_Led(3);
    }
    // Desligar o LED
    if (comando == 'D'){Intensidade_Led = 0;}

    if (comando == 'x'){som = false;}
    if (comando == 'X'){som = true;}
  }
}
