#define ENA 2
#define ENB 3
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define GREY 50
#include "movement.h" //NON USARE I SIMBOLI DI MAGGIORE O MINORE SE NO ARDUINO SI INCAZZA 
const short Kp=1;
short error;
short reflected(unsigned short pin){
  unsigned short sum;
  for(int i=0;i<4;i++){
    sum+=analogRead(pin);
  }
  return sum/5;
}
void setup(){
  for(int i=2;i<8;i++){
    pinMode(i,OUTPUT);
  }
}
void loop(){
  error=GREY-reflected(0);
  move_robot(50+error*Kp,50-error*Kp);
}
