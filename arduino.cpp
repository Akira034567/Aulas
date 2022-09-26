//#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>

//LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE); 

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int nQuestao = 10;
int array[10];
int pontos = 0;

int seconds = 0;


byte olho1[8] = {
  B00011,
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
};
byte olho2[8] = {
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111,
  B00011,
  B00000
};
byte olho3[8] = {
  B11000,
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};
byte olho4[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11000,
  B11011,
  B00011,
}; 
byte sorriso1[8] = {
   B11000,
   B01100,
   B00111,
   B00011,
   B00000,
   B00000,
   B00000,
   B00000,
};
byte sorriso2[8] = {
   B00000,
   B00000,
   B11111,
   B11111,
   B00000,
   B00000,
   B00000,
   B00000,
};
byte sorriso3[8] = {
   B00011,
   B00110,
   B11100,
   B11000,
   B00000,
   B00000,
   B00000,
   B00000,
};
byte sorriso4[8] = {
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B11111,
   B11111,
};
byte sorriso5[8] = {
   B11111,
   B11111,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
};

void setup()
{

  lcd.begin(16, 2);
 
  lcd.createChar(1, olho1);
  lcd.createChar(2, olho2);
  lcd.createChar(3, olho3);
  lcd.createChar(4, olho4);
  lcd.createChar(5, sorriso1);
  lcd.createChar(6, sorriso2);
  lcd.createChar(7, sorriso3);
  lcd.createChar(8, sorriso4);                                                                                             
  lcd.createChar(9, sorriso5);

  //geraSequencia();
}

void loop(){
  
  do {
  	lcd.setCursor(6, 0);
  	lcd.write(8);
	lcd.setCursor(6, 1);
  	lcd.write(9);
	lcd.setCursor(7, 0);
  	lcd.write(8);
	lcd.setCursor(7, 1);
  	lcd.write(9);
    
  	lcd.setCursor(14, 0);
 	lcd.write(8);
 	lcd.setCursor(14, 1);
 	lcd.write(9);
 	lcd.setCursor(15, 0);
 	lcd.write(8);
 	lcd.setCursor(15, 1);
  	lcd.write(9);
  
  	delay(1000);
  
  	lcd.setCursor(6, 0);
  	lcd.write(1);
  	lcd.setCursor(6, 1);
  	lcd.write(2);
 	lcd.setCursor(7, 0);
  	lcd.write(3);
 	lcd.setCursor(7, 1);
  	lcd.write(4);
    
  	lcd.setCursor(14, 0);
  	lcd.write(1);
	lcd.setCursor(14, 1);
  	lcd.write(2);
	lcd.setCursor(15, 0);
  	lcd.write(3);
	lcd.setCursor(15, 1);
  	lcd.write(4);
  
  	delay(1000);  
  }while (digitalRead(BotA)==false);
  
  /*
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(12, 0);
  lcd.write(5);
  delay(100);
 
  lcd.setCursor(3, 0);
  lcd.write(byte(6));
  lcd.setCursor(12, 0);
  lcd.write(6);
  delay(100);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(7));
  lcd.setCursor(12, 0);
  lcd.write(7);
  delay(100);
  
  delay(1000);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(6));
  lcd.setCursor(12, 0);
  lcd.write(6);
  delay(100);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(12, 0);
  lcd.write(5);
  delay(100);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(1));
  lcd.setCursor(12, 0);
  lcd.write(1);
  */

  
  for (int i = 0; i < nQuestao; i++){
      SelecionaQuestao(array[i]);
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fim de Jogo!");
  lcd.setCursor(0,1);
  lcd.print("Voce acertou");
  lcd.setCursor(13,1);
  lcd.print(pontos);
  lcd.setCursor(6,2);
  lcd.print("de 10 questoes");
  
  delay(2000);
}

void SelecionaQuestao(int nQuestao){
  
  switch(nQuestao){
    case 0:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Calcule 1+1");
    	lcd.setCursor(0,1);
          lcd.print("a)2 b)3 c)4");
        if(AnalisaBotao()=='A'){
          lcd.clear(); //ou pode ser mais linhas põe na 3
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 1:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 2");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 2:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 3");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 3:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 4");
        if(AnalisaBotao()=='D'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 4:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 5");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 5:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 6");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 6:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 7");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 7:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 8");
        if(AnalisaBotao()=='D'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 8:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 9");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 9:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 10");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
  }
  
}

char AnalisaBotao(){
  bool BotaoPressionado = true;
  
  while(BotaoPressionado){
    if(digitalRead(BotA)){
      BotaoPressionado = false;
      return 'A';
    }else if(digitalRead(BotB)){
      BotaoPressionado = false;
      return 'B';
    }else if(digitalRead(BotC)){
      BotaoPressionado = false;
      return 'C';
    }else if(digitalRead(BotD)){
      BotaoPressionado = false;
      return 'D';
    }
  }
}


void geraSequencia(){
  randomSeed(random(0, 1000));
  for (int i = 0; i < nQuestao; i++){     
    array[i] = i;
  }
  for (int i = 0; i < nQuestao; i++) {    
    int temp = array[i];
    int novoIndice = random(nQuestao);
    array[i] = array[novoIndice];
    array[novoIndice] = temp;
  }
} 


/*#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

//#include <Adafruit_LiquidCrystal.h>

//Adafruit_LiquidCrystal lcd(0);

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int nQuestao = 10;
int array[10];
int pontos = 0;

int seconds = 0;


byte smileyw[8] = {
  B01100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100,
  B00001,
};
byte smileyX[8] = {
  B10000,
  B01000,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
 };
byte smileyp[8] = {
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
 };
byte smileyg[8] = {
  B00001,
  B00010,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
 };
byte smileyu[8] = {
  B00000,
  B11110,
  B11110,
  B11110,
  B11110,
  B11100,
  B00000,
  };
byte smileym[8] = {
  B00000,
  B00000,
  B11110,
  B11110,
  B11110,
  B00000,
  B00000,
   };
byte smileye[8] = {
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
  };
void setup(){
  pinMode(BotA, INPUT);
  pinMode(BotB, INPUT);
  pinMode(BotC, INPUT);
  pinMode(BotD, INPUT);
  
  lcd.init();
  lcd.setBacklight(HIGH);
  
  lcd.createChar(1, smileyw);
  lcd.createChar(2, smileyX);
  lcd.createChar(3, smileyp);
  lcd.createChar(4, smileyg);
  lcd.createChar(5, smileyu);
  lcd.createChar(6, smileym);
  lcd.createChar(7, smileye);
  
   lcd.clear();
  lcd.setCursor(3, 0);
  lcd.write(byte(1));
  lcd.setCursor(12, 0);
  lcd.write(1);
  lcd.setCursor(5, 1);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.write(byte(3));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(3));
  lcd.setCursor(9, 1);
  lcd.write(byte(3));
  lcd.setCursor(10, 1);
  lcd.write(byte(4));
  delay(2500);
  
  
  geraSequencia();
}

void loop(){
  
  do {
  lcd.setCursor(3, 0);
  lcd.write(byte(7));
  lcd.setCursor(12, 0);
  lcd.write(7);
  
  delay(1000);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(1));
  lcd.setCursor(12, 0);
  lcd.write(1);
  
  delay(2500); }
  while (digitalRead(BotA)==false);
  
  /*
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(12, 0);
  lcd.write(5);
  delay(100);
 
  lcd.setCursor(3, 0);
  lcd.write(byte(6));
  lcd.setCursor(12, 0);
  lcd.write(6);
  delay(100);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(7));
  lcd.setCursor(12, 0);
  lcd.write(7);
  delay(100);
  
  delay(1000);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(6));
  lcd.setCursor(12, 0);
  lcd.write(6);
  delay(100);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(5));
  lcd.setCursor(12, 0);
  lcd.write(5);
  delay(100);
  
  lcd.setCursor(3, 0);
  lcd.write(byte(1));
  lcd.setCursor(12, 0);
  lcd.write(1);
  

  
  for (int i = 0; i < nQuestao; i++){
      SelecionaQuestao(array[i]);
  }
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Fim de Jogo!");
  lcd.setCursor(0,1);
  lcd.print("Voce acertou");
  lcd.setCursor(13,1);
  lcd.print(pontos);
  lcd.setCursor(6,2);
  lcd.print("de 10 questoes");
  
  delay(2000);
}

void SelecionaQuestao(int nQuestao){
  
  switch(nQuestao){
    case 0:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Calcule 1+1");
      lcd.setCursor(0,1);
          lcd.print("a)2 b)3 c)4");
        if(AnalisaBotao()=='A'){
          lcd.clear(); //ou pode ser mais linhas põe na 3
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 1:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 2");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 2:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 3");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 3:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 4");
        if(AnalisaBotao()=='D'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 4:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 5");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 5:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 6");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 6:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 7");
        if(AnalisaBotao()=='C'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 7:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 8");
        if(AnalisaBotao()=='D'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 8:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 9");
        if(AnalisaBotao()=='A'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
    case 9:
        lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Questao 10");
        if(AnalisaBotao()=='B'){
          lcd.setCursor(0,1);
          lcd.print("Correto!");
          pontos++;
        }else{
          lcd.setCursor(0,1);
          lcd.print("Errado!");
        }
    break;
  }
  
}

char AnalisaBotao(){
  bool BotaoPressionado = true;
  
  while(BotaoPressionado){
    if(digitalRead(BotA)){
      BotaoPressionado = false;
      return 'A';
    }else if(digitalRead(BotB)){
      BotaoPressionado = false;
      return 'B';
    }else if(digitalRead(BotC)){
      BotaoPressionado = false;
      return 'C';
    }else if(digitalRead(BotD)){
      BotaoPressionado = false;
      return 'D';
    }
  }
}


void geraSequencia(){
  randomSeed(random(0, 1000));
  for (int i = 0; i < nQuestao; i++){     
    array[i] = i;
  }
  for (int i = 0; i < nQuestao; i++) {    
    int temp = array[i];
    int novoIndice = random(nQuestao);
    array[i] = array[novoIndice];
    array[novoIndice] = temp;
  }
} */

/*
byte olho1[8] = {
  B00011,
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
};
byte olho2[8] = {
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00011,
  B00000
};
byte olho3[8] = {
  B11000,
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};

byte olho4[8] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11000,
  B11011,
  B00011,
};

void setup()
{

  lcd.begin(16, 2);
 
     lcd.createChar(1, olho1);
    lcd.createChar(2, olho2);
  lcd.createChar(3, olho3);
 lcd.createChar(4, olho4);

lcd.setCursor(5, 0); 
  lcd.write(1);
lcd.setCursor(5, 1); 
  lcd.write(2);
lcd.setCursor(6, 0); 
  lcd.write(3);
lcd.setCursor(6, 1);
  lcd.write(4);*/

/*#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2,1,0,4,5,6,7,3, POSITIVE); 

//#include <Adafruit_LiquidCrystal.h>

//Adafruit_LiquidCrystal lcd(0);

#define BotA 2
#define BotB 3
#define BotC 4
#define BotD 5

int nQuestao = 10;
int array[10];
int pontos = 0;

int seconds = 0;


byte olho1[10] = {
  B00011,
  B00111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B01111
};
byte olho2[10] = {
  B01111,
  B01111,
  B01111,
  B01111,
  B01111,
  B00111,
  B00011,
  B00000
};
byte olho3[10] = {
  B11000,
  B11100,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
};
byte olho4[10] = {
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11000,
  B11011,
  B00011
}; 
byte sorriso1[10] = {
   B00000,
   B00000,
   B00000,
   B00000,
   B11000,
   B01100,
   B00111,
   B00011
};
byte sorriso2[10] = {
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B11111,
   B11111
};
byte sorriso3[10] = {
   B00000,
   B00000,
   B00000,
   B00000,
   B00011,
   B00110,
   B11100,
   B11000
};
byte olho5[10] = {
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B11111,
   B11111
};
byte olho6[10] = {
   B11111,
   B11111,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000,
   B00000
};


void setup()
{

  lcd.begin(20, 4);

  lcd.clear();
  
lcd.createChar(1, olho1);
lcd.createChar(2, olho2);
lcd.createChar(3, olho3);
lcd.createChar(4, olho4);
lcd.createChar(5, sorriso1);
lcd.createChar(6, sorriso2);
lcd.createChar(7, sorriso3);
lcd.createChar(8, olho5);
lcd.createChar(9, olho6);

lcd.setCursor(5, 0); 
  lcd.write(1);
lcd.setCursor(5, 1); 
  lcd.write(2);
lcd.setCursor(6, 0); 
  lcd.write(3);
lcd.setCursor(6, 1);
  lcd.write(4);
lcd.setCursor(13, 0); 
  lcd.write(1);
lcd.setCursor(13, 1); 
  lcd.write(2);
lcd.setCursor(14, 0); 
  lcd.write(3);
lcd.setCursor(14, 1);
  lcd.write(4);
lcd.setCursor(7, 2); 
  lcd.write(5);
lcd.setCursor(8, 2); 
  lcd.write(6);
lcd.setCursor(9, 2); 
  lcd.write(6);
lcd.setCursor(10, 2);
  lcd.write(6);
lcd.setCursor(11, 2); 
  lcd.write(6);
  lcd.setCursor(12, 2); 
  lcd.write(7);
 delay(2500);
  
  
}

void loop(){
  
  lcd.setCursor(5, 0);
  lcd.write(8);
lcd.setCursor(5, 1);
  lcd.write(9);
lcd.setCursor(6, 0);
  lcd.write(8);
lcd.setCursor(6, 1);
  lcd.write(9);
  lcd.setCursor(13, 0);
 lcd.write(8);
 lcd.setCursor(13, 1);
 lcd.write(9);
 lcd.setCursor(14, 0);
 lcd.write(8);
 lcd.setCursor(14, 1);
  lcd.write(9);
  
  delay(1000);
  
  lcd.setCursor(5, 0);
  lcd.write(1);
  lcd.setCursor(5, 1);
  lcd.write(2);
 lcd.setCursor(6, 0);
  lcd.write(3);
 lcd.setCursor(6, 1);
  lcd.write(4);
  lcd.setCursor(13, 0);
  lcd.write(1);
lcd.setCursor(13, 1);
  lcd.write(2);
lcd.setCursor(14, 0);
  lcd.write(3);
lcd.setCursor(14, 1);
  lcd.write(4);
  
  delay(2500);  }*/