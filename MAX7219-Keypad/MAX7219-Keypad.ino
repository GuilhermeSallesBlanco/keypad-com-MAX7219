#include "LedControl.h" 
#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

typedef struct Snake Snake;
struct Snake{
  int head[2];     
  int body[40][2]; 
  int len;         
  int dir[2];      
};

typedef struct Apple Apple;
struct Apple{
  int rPos; 
  int cPos; 
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

byte pic[8] = {0,0,0,0,0,0,0,0};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LedControl lc=LedControl(12,10,11,1);

unsigned long delaytime = 500;
byte ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte EX[] = {B00000000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000,B00000000};
byte A[] = {B00000000,B00111100,B00100100,B00100100,B00111100,B00100100,B00100100,B00000000};
byte B[] = {B01111000,B01001000,B01001000,B01110000,B01001000,B01000100,B01000100,B01111100};
byte C[] = {B00000000,B00011110,B00100000,B01000000,B01000000,B01000000,B00100000,B00011110};
byte D[] = {B00000000,B00111000,B00100100,B00100010,B00100010,B00100100,B00111000,B00000000};
byte E[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00111100,B00000000};
byte F[] = {B00000000,B00111100,B00100000,B00111000,B00100000,B00100000,B00100000,B00000000};
byte G[] = {B00000000,B00111110,B00100000,B00100000,B00101110,B00100010,B00111110,B00000000};
byte H[] = {B00000000,B00100100,B00100100,B00111100,B00100100,B00100100,B00100100,B00000000};
byte I[] = {B00000000,B00111000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte J[] = {B00000000,B00011100,B00001000,B00001000,B00001000,B00101000,B00111000,B00000000};
byte K[] = {B00000000,B00100100,B00101000,B00110000,B00101000,B00100100,B00100100,B00000000};
byte L[] = {B00000000,B00100000,B00100000,B00100000,B00100000,B00100000,B00111100,B00000000};
byte M[] = {B00000000,B00000000,B01000100,B01101100,B01010100,B01000100,B01000100,B00000000};
byte N[] = {B00000000,B00100010,B00110010,B00101010,B00100110,B00100010,B00000000,B00000000};
byte O[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};
byte P[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100000,B00100000,B00000000};
byte Q[] = {B00000000,B00111100,B01000010,B01000010,B01000010,B01000110,B00111110,B00000001};
byte R[] = {B00000000,B00111000,B00100100,B00100100,B00111000,B00100100,B00100100,B00000000};
byte S[] = {B00000000,B00111100,B00100000,B00111100,B00000100,B00000100,B00111100,B00000000};
byte T[] = {B00000000,B01111100,B00010000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte U[] = {B00000000,B01000010,B01000010,B01000010,B01000010,B00100100,B00011000,B00000000};
byte V[] = {B00000000,B00100010,B00100010,B00100010,B00010100,B00010100,B00001000,B00000000};
byte W[] = {B00000000,B10000010,B10010010,B01010100,B01010100,B00101000,B00000000,B00000000};
byte X[] = {B00000000,B01000010,B00100100,B00011000,B00011000,B00100100,B01000010,B00000000};
byte Y[] = {B00000000,B01000100,B00101000,B00010000,B00010000,B00010000,B00010000,B00000000};
byte Z[] = {B00000000,B00111100,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
byte um[] = {B00000000,B00110000,B00010000,B00010000,B00010000,B00010000,B00111000,B00000000};
byte dois[] = {B00000000,B00111000,B00000100,B00001000,B00010000,B00100000,B00111100,B00000000};
byte tres[] = {B00000000,B00111000,B00000100,B00011000,B00000100,B00000100,B00111000,B00000000};
byte quatro[] = {B00000000,B00100100,B00100100,B00100100,B00011100,B00000100,B00000100,B00000000};
byte cinco[] = {B00000000,B00111100,B00100000,B00111000,B00000100,B00000100,B00111000,B00000000};
byte seis[] = {B00000000,B00111100,B00100000,B00111100,B00100100,B00100100,B00111100,B00000000};
byte sete[] = {B00000000,B00111100,B00000100,B00000100,B00011110,B00000100,B00000100,B00000000};
byte oito[] = {B00000000,B00011000,B00100100,B00011000,B00100100,B00100100,B00011000,B00000000};
byte nove[] = {B00000000,B00111100,B00100100,B00100100,B00111100,B00000100,B00111100,B00000000};
byte zero[] = {B00000000,B00011000,B00100100,B00100100,B00100100,B00100100,B00011000,B00000000};
byte Bum[] = {B00000000,B01100110,B01010010,B01100010,B01010010,B01010010,B01100010,B00000000};
byte Bzero[] = {B00000000,B01100010,B01010101,B01100101,B01010101,B01010101,B01100010,B00000000};

void zeroB(){
      lc.clearDisplay(0);
      lc.setRow(0,0,zero[0]);
      lc.setRow(0,1,zero[1]);
      lc.setRow(0,2,zero[2]);
      lc.setRow(0,3,zero[3]);
      lc.setRow(0,4,zero[4]);
      lc.setRow(0,5,zero[5]);
      lc.setRow(0,6,zero[6]);
      lc.setRow(0,7,zero[7]);
      delay(1000);
      lc.clearDisplay(0);
      delay(200);
}

void umB(){
      lc.clearDisplay(0);
      lc.setRow(0,0,um[0]);
      lc.setRow(0,1,um[1]);
      lc.setRow(0,2,um[2]);
      lc.setRow(0,3,um[3]);
      lc.setRow(0,4,um[4]);
      lc.setRow(0,5,um[5]);
      lc.setRow(0,6,um[6]);
      lc.setRow(0,7,um[7]);
      delay(1000);
      lc.clearDisplay(0);
      delay(200);
}

void bum(){
      lc.clearDisplay(0);
      lc.setRow(0,0,Bum[0]);
      lc.setRow(0,1,Bum[1]);
      lc.setRow(0,2,Bum[2]);
      lc.setRow(0,3,Bum[3]);
      lc.setRow(0,4,Bum[4]);
      lc.setRow(0,5,Bum[5]);
      lc.setRow(0,6,Bum[6]);
      lc.setRow(0,7,Bum[7]);
      delay(500);
      lc.clearDisplay(0);
}

void bzero(){
      lc.clearDisplay(0);
      lc.setRow(0,0,Bzero[0]);
      lc.setRow(0,1,Bzero[1]);
      lc.setRow(0,2,Bzero[2]);
      lc.setRow(0,3,Bzero[3]);
      lc.setRow(0,4,Bzero[4]);
      lc.setRow(0,5,Bzero[5]);
      lc.setRow(0,6,Bzero[6]);
      lc.setRow(0,7,Bzero[7]);
      delay(500);
      lc.clearDisplay(0);
}

float oldTime = 0;
float timer = 0;
float updateRate = 3;

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
  Serial.begin(9600);  
}

bool binario_ativado = 0;

float calculateDeltaTime(){
  float currentTime = millis();
  float dt = currentTime - oldTime;
  oldTime = currentTime;
  return dt;
}

int i,j;

Snake snake = {{1,5},{{0,5}, {1,5}}, 2, {1,0}};
Apple apple = {(int)random(0,8),(int)random(0,8)};

void loop() {
  char key = keypad.getKey();
  switch(binario_ativado);
  if(key == '*'){
    if(binario_ativado == 1){
      binario_ativado = 0;
      Serial.print("VERDADEIRO -> FALSO: ");
      Serial.println(binario_ativado);
      Serial.print("\n");
      bzero();
      return;
    } if(binario_ativado == 0){
      binario_ativado = 1;
      Serial.print("FALSO -> VERDADEIRO: ");
      Serial.println(binario_ativado);
      Serial.print("\n");
      bum();
      return;
    } 
    }
  if(key == 'A'){
    if(binario_ativado == 1){
        umB();
        zeroB();
        umB();
        zeroB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,A[0]);
      lc.setRow(0,1,A[1]);
      lc.setRow(0,2,A[2]);
      lc.setRow(0,3,A[3]);
      lc.setRow(0,4,A[4]);
      lc.setRow(0,5,A[5]);
      lc.setRow(0,6,A[6]);
      lc.setRow(0,7,A[7]);
      }
  if(key == 'B'){
    if(binario_ativado == 1){
        umB();
        zeroB();
        umB();
        umB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,B[0]);
      lc.setRow(0,1,B[1]);
      lc.setRow(0,2,B[2]);
      lc.setRow(0,3,B[3]);
      lc.setRow(0,4,B[4]);
      lc.setRow(0,5,B[5]);
      lc.setRow(0,6,B[6]);
      lc.setRow(0,7,B[7]);
  }
  if(key == 'C'){
      while(key == 'C'){
      float deltaTime = calculateDeltaTime();
      timer += deltaTime;
      char keyS = keypad.getKey();

      if(keyS == '4' && snake.dir[1]==0){
        snake.dir[0] = 0;
        snake.dir[1] = -1;
      }else if(keyS == '6' && snake.dir[1]==0){
        snake.dir[0] = 0;
        snake.dir[1] = 1;
      }else if(keyS == '2' && snake.dir[0]==0){
        snake.dir[0] = -1;
        snake.dir[1] = 0;
      }else if(keyS == '8' && snake.dir[0]==0){
        snake.dir[0] = 1;
        snake.dir[1] = 0;
      }
      if(keyS == '#'){
        return;
      }

      if(timer > 1000/updateRate){
      timer = 0;
      Update();

      Render();
      }
  }
  }
  if(key == 'D'){
      if(binario_ativado == 1){
        umB();
        umB();
        zeroB();
        umB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,D[0]);
      lc.setRow(0,1,D[1]);
      lc.setRow(0,2,D[2]);
      lc.setRow(0,3,D[3]);
      lc.setRow(0,4,D[4]);
      lc.setRow(0,5,D[5]);
      lc.setRow(0,6,D[6]);
      lc.setRow(0,7,D[7]);
  }
  if(key == '1'){
      if(binario_ativado == 1){
        zeroB();
        zeroB();
        zeroB();
        umB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      lc.setRow(0,0,um[0]);
      lc.setRow(0,1,um[1]);
      lc.setRow(0,2,um[2]);
      lc.setRow(0,3,um[3]);
      lc.setRow(0,4,um[4]);
      lc.setRow(0,5,um[5]);
      lc.setRow(0,6,um[6]);
      lc.setRow(0,7,um[7]);
      }
  }
  if(key == '2'){
    if(binario_ativado == 1){
        zeroB();
        zeroB();
        umB();
        zeroB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,dois[0]);
      lc.setRow(0,1,dois[1]);
      lc.setRow(0,2,dois[2]);
      lc.setRow(0,3,dois[3]);
      lc.setRow(0,4,dois[4]);
      lc.setRow(0,5,dois[5]);
      lc.setRow(0,6,dois[6]);
      lc.setRow(0,7,dois[7]);
  }
  if(key == '3'){
    if(binario_ativado == 1){
        zeroB();
        zeroB();
        umB();
        umB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,tres[0]);
      lc.setRow(0,1,tres[1]);
      lc.setRow(0,2,tres[2]);
      lc.setRow(0,3,tres[3]);
      lc.setRow(0,4,tres[4]);
      lc.setRow(0,5,tres[5]);
      lc.setRow(0,6,tres[6]);
      lc.setRow(0,7,tres[7]);
  }
  if(key == '4'){
    if(binario_ativado == 1){
        zeroB();
        umB();
        zeroB();
        zeroB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,quatro[0]);
      lc.setRow(0,1,quatro[1]);
      lc.setRow(0,2,quatro[2]);
      lc.setRow(0,3,quatro[3]);
      lc.setRow(0,4,quatro[4]);
      lc.setRow(0,5,quatro[5]);
      lc.setRow(0,6,quatro[6]);
      lc.setRow(0,7,quatro[7]);
  }
  if(key == '5'){
    if(binario_ativado == 1){
        zeroB();
        umB();
        zeroB();
        umB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,cinco[0]);
      lc.setRow(0,1,cinco[1]);
      lc.setRow(0,2,cinco[2]);
      lc.setRow(0,3,cinco[3]);
      lc.setRow(0,4,cinco[4]);
      lc.setRow(0,5,cinco[5]);
      lc.setRow(0,6,cinco[6]);
      lc.setRow(0,7,cinco[7]);
  }
  if(key == '6'){
    if(binario_ativado == 1){
        zeroB();
        umB();
        umB();
        zeroB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,seis[0]);
      lc.setRow(0,1,seis[1]);
      lc.setRow(0,2,seis[2]);
      lc.setRow(0,3,seis[3]);
      lc.setRow(0,4,seis[4]);
      lc.setRow(0,5,seis[5]);
      lc.setRow(0,6,seis[6]);
      lc.setRow(0,7,seis[7]);
  }
  if(key == '7'){
      if(binario_ativado == 1){
        zeroB();
        umB();
        umB();
        umB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,sete[0]);
      lc.setRow(0,1,sete[1]);
      lc.setRow(0,2,sete[2]);
      lc.setRow(0,3,sete[3]);
      lc.setRow(0,4,sete[4]);
      lc.setRow(0,5,sete[5]);
      lc.setRow(0,6,sete[6]);
      lc.setRow(0,7,sete[7]);
  }
  if(key == '8'){
    if(binario_ativado == 1){
        umB();
        zeroB();
        zeroB();
        zeroB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,oito[0]);
      lc.setRow(0,1,oito[1]);
      lc.setRow(0,2,oito[2]);
      lc.setRow(0,3,oito[3]);
      lc.setRow(0,4,oito[4]);
      lc.setRow(0,5,oito[5]);
      lc.setRow(0,6,oito[6]);
      lc.setRow(0,7,oito[7]);
  }
  if(key == '9'){
      if(binario_ativado == 1){
        umB();
        zeroB();
        zeroB();
        umB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,nove[0]);
      lc.setRow(0,1,nove[1]);
      lc.setRow(0,2,nove[2]);
      lc.setRow(0,3,nove[3]);
      lc.setRow(0,4,nove[4]);
      lc.setRow(0,5,nove[5]);
      lc.setRow(0,6,nove[6]);
      lc.setRow(0,7,nove[7]);
  }
  if(key == '0'){if(binario_ativado == 1){
        zeroB();
        zeroB();
        zeroB();
        zeroB();
      } else if(binario_ativado == 0) {
        lc.clearDisplay(0);
      }
      lc.clearDisplay(0);
      lc.setRow(0,0,zero[0]);
      lc.setRow(0,1,zero[1]);
      lc.setRow(0,2,zero[2]);
      lc.setRow(0,3,zero[3]);
      lc.setRow(0,4,zero[4]);
      lc.setRow(0,5,zero[5]);
      lc.setRow(0,6,zero[6]);
      lc.setRow(0,7,zero[7]);
  }
  if(key == '#'){
    lc.clearDisplay(0);
  }
}

void reset(){
  for(int j=0;j<8;j++){
    pic[j] = 0;
  }
}

void Update(){
  reset();
  
  int newHead[2] = {snake.head[0]+snake.dir[0], snake.head[1]+snake.dir[1]};

  //Handle Borders
  if(newHead[0]==8){
    newHead[0]=0;
  }else if(newHead[0]==-1){
    newHead[0] = 7;
  }else if(newHead[1]==8){
    newHead[1]=0;
  }else if(newHead[1]==-1){
    newHead[1]=7;
  }
  
  //Check If The Snake hits itself
   for(j=0;j<snake.len;j++){
    if(snake.body[j][0] == newHead[0] && snake.body[j][1] == newHead[1]){
      
      delay(1000);
      snake = {{1,5},{{0,5}, {1,5}}, 2, {1,0}};
      apple = {(int)random(0,8),(int)random(0,8)};
      return;
    }
  }

  
  if(newHead[0] == apple.rPos && newHead[1] ==apple.cPos){
    snake.len = snake.len+1;
    apple.rPos = (int)random(0,8);
    apple.cPos = (int)random(0,8);
  }else{
    removeFirst();
  }
  
  snake.body[snake.len-1][0]= newHead[0];
  snake.body[snake.len-1][1]= newHead[1];
  
  snake.head[0] = newHead[0];
  snake.head[1] = newHead[1];
  
  
  for(j=0;j<snake.len;j++){
    pic[snake.body[j][0]] |= 128 >> snake.body[j][1];
  }
  pic[apple.rPos] |= 128 >> apple.cPos;
  
}

void Render(){
  
   for(i=0;i<8;i++){
    lc.setRow(0,i,pic[i]);
   }
}

void removeFirst(){
  for(j=1;j<snake.len;j++){
    snake.body[j-1][0] = snake.body[j][0];
    snake.body[j-1][1] = snake.body[j][1];
  }
}
