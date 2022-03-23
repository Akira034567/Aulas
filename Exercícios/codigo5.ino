const int led = 3;
const int botao = 5;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
}

int var;

void loop()
{
  var = digitalRead(botao);
  
  if(var == 1) {
    digitalWrite (led, LOW);
  } else {
    digitalWrite (led, HIGH);
  }


}
  
