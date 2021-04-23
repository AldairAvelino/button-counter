#define led1 2 //Define Pino 2 do arduino para o led 1.
#define led2 3 //Define Pino 3 do arduino para o led 2.
#define led3 4 //Define Pino 4 do arduino para o led 3.
#define led4 5 //Define Pino 5 do arduino para o led 4.
#define bot 6 //Define Pino 6 do arduino para o botão.

int estadobot; // Variavel que armazena o estado do botão, se pressionado ou não. 
int cont = 0; // Variavel que armazena quantas vezes o botão foi pressionado.

void setup(){
  pinMode(led1, OUTPUT); //Define pino do led 1 como saida.
  pinMode(led2, OUTPUT); //Define pino do led 2 como saida.
  pinMode(led3, OUTPUT); //Define pino do led 3 como saida.
  pinMode(led4, OUTPUT); //Define pino do led 4 como saida.
  pinMode(bot, INPUT_PULLUP); //Define pino botão como entrada, utilizando resistor de pullup interno. 
}

void acionamento(void){ // Função que faz o acionamento dos leds.
  switch (cont){
    case 0: //Caso valor da variavel "cont" for igual a 0.
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW); //Todos os leds apagados.
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    break;

    case 1: //Caso valor da variavel "cont" for igual a 1.
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW); //Somente led 1 aceso.
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    break;

    case 2: //Caso valor da variavel "cont" for igual a 2.
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH); //Somente led 2 aceso.
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    break;

    case 3: //Caso valor da variavel "cont" for igual a 3.
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW); //Somente led 3 aceso.
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    break;
    
    case 4: //Caso valor da variavel "cont" for igual a 4.
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW); //Somente led 4 aceso.
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    break;
    
    case 5: //Caso valor da variavel "cont" for igual a 5.
    cont = 0; //Zera a variavel "cont" novamente, apagando todos os leds, voltando pro primeiro caso.
    break;
  }
}

void contador(void){ 
  //Função que soma 1 a variavel "cont" toda vez que o botão é pressionado.
  if (estadobot == 0){
    delay(200); //Alterar aqui o valor do delay caso o botão estaja com resposta lenta.
    cont = cont+1;
  }
}

void loop(){
  //Executa as funções declaradas em looping.
  estadobot = digitalRead(bot); //Lê constantemente se o botão foi pressionado.
  contador();
  acionamento();
}
