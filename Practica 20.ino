# AutomatismoXanelaDeCoche
Xanela de coche con 2 motores
/*
Programa para simular a funcion dunha xanela de automovil 
de maneira simplificada. O motor acciona o motor se subida 
ao ser premido, Unha segunda pulsacion fai que se accione
o motor de baixada. o motor sube durante 7 sg despois pode baixar tamen 7sg 

Entrada: Pulsador (dixital)
Saídas:  Relé (2xdixital)

Autor:..... Comunidade
Data: Febreiro'23

Sempre despois de cada orde hay que poñer ; non telo da erro
*/

#define motorArriba 11 // no levan igual nin levan punto e coma
#define motorAbaixo 12
#define pulsador     7

//int motorArriba = 11; //quitamos esto con doble barra pero so queda inutilizado por se o necesitamos no futuro so temos que quitar as barras
//int motorAbaixo = 12;  

int estado = 0;
int contador = 100; // contador de sinais ao motor

/// adicion int pulsador = 0;

void setup() {
  pinMode(motorArriba, OUTPUT);// pinMode e digitalMode ven sendo o mesmo so diferentes modos de nomear "sinónimos"
  pinMode(motorAbaixo, OUTPUT);
  pinMode(pulsador, INPUT);
  
  Serial.begin(9600); //poñemos o monitor seri en funcionamento

  // int estado; //con "bool" no sitio de "int" funciona igual COMPROVAR MAIS ADIANTE
    
 // Serial.println(estado);  // si poñemos " o monitor di o que ten escrito se non ponnos o valor da variable dada
  
}

void loop() {
  // lectura do pulsador
  if(digitalRead(pulsador)) {
      estado = !estado; // !significa o contrario da variable
      contador = 100; //cada vez que pulse o contador resetea
   while(digitalRead(pulsador)) { //quitado momentaneamente
      delay(20);  //espera 20 ,milisegundos e comprova segue asi ata que solte o pulsador, no momento no que solte o pulsador cambia
   }
  }
  // fin da lectura do pulsador
  
    Serial.println(contador);
  
  // Arrancamos motores
  if(contador > 0) {
    if(estado == 0) {
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(50); // usamos un numero pequeno para que de tempo a pulsacion asi lee cada 50 msg
      contador --;  //- 1; non me funcionou o -1 xq?
    }
    else {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
      delay(50); 
      contador --; //-- é igual a -1
      }
}
  else {      //senon esta accionado lee 10 veces por sg
      digitalWrite(motorArriba, LOW); // aqui si introducindo aqui os dous motores en baixa o chegar o contador a 0 os motores deteñense,
      digitalWrite(motorAbaixo, LOW);
      Serial.print("xanela parada"); 
      delay(100);
}
  //fin de accionamento de motores, por que?, cando pase o tempo non podemos volver a activar?
delay(5); // con este delay final conseguimos que o contador vaia mais lento e asi danos tempo de ver o proceso e poder usar o pulsador
}


/* Agora o proceso esta rematado de aqui en diante son datos innecesarios para o programa da xanela
  so foron parte do traballo realizado e queda aqui para posibles consutas no futuro



/* quero que cando acabe o recorrido da xanela os motores permanezan parados a espera de pulso
  
  parece que con este sistema non sirve  
    if(contador == 0) {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, LOW);
}
    
// de momento continuame o problema de que o chegar a 0 non podo volver accionar     
     
/********     
     /* repetimos todo este proceso   
 /* Serial.println(estado);
  delay(20000); Borramos esto ( de momento)
  */
/*     
   }
  }
} // ESTA sobraba
/*
OLLO AQUI /*   if(estado == 0) {
  digitalWrite(motorArriba, HIGH);
  digitalWrite(motorAbaixo, LOW);
   while(digitalRead(pulsador)) { 
      delay(20); 
  }
}
}
  // ollo levar o control de parenteses e chaves abertas e cerralas todas
     
     
     
     
     
/*
 Estructura de funcións if, else
        if()

        {

        }

        else()

        {

        }
*/
