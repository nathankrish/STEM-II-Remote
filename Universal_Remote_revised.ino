//Modified the starting code of a button from http://www.instructables.com/id/How-to-control-your-TV-with-an-Arduino/
//Tutorials and examples from https://www.arduino.cc/en/Tutorial/Button were used to help with the code
int IRledPin =  13;    // LED connected to digital pin 13
int buttonPin = 3;      //Button connected to pin 3
//int delayNum[]={790,1680,740}; //initializes the array of the delay numbers --> these numbers are currently place holders
//int pulseNum[]={450,760,940}; //initializes the array of the pulse numbers --> these numbers are currently place holders

int favChannels [] = {4, 5};

int i = 0;           //initializes the counter i to 0
int buttonState;   //initializes the button reader variable

long int four [2][5] = {{10000, 200, 300, 400, 500}, {100, 200, 300, 400, 500}}; //1st array is delays, 2nd array is pulses
long int five [2][5] = {{10000, 200, 300, 400, 500}, {100, 200, 300, 400, 500}};

  // initialize the IR digital pin as an output:
long signals[] = {four, five}; //Modified the starting code of a button from http://www.instructables.com/id/How-to-control-your-TV-with-an-Arduino/
//Tutorials and examples from https://www.arduino.cc/en/Tutorial/Button were used to help with the code 
int channel1[]={740,1680,740}; //Channel Example
int channel2[]={300,10,300,10,300}; //Channel Example 2
int channel3[]={100,100,100,100,100}; //Channel Example 3

 
// The setup() method runs once, when the sketch starts
 
/*
  PURPOSE: Intitalizes the pins for the infrared led and the button
*/
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT); 
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
  Serial.begin(9600);
} 
/*
  PURPOSE: On each clock cycle, checks whether the button to change channels is being pressed.
  If the button is pressed, sends all the channels in the favorite channel array in a cycle.
*/
void loop()                     
{
buttonState=digitalRead(buttonPin);
  if(buttonState==LOW){
    if(i==1){
      for(int c = 0; c<sizeof(channel1); i++){
        if(c%2==0){
          pulseIR(channel1[c]);
        }
        else{
          delayMicroseconds(channel1[c]);
        }
      }
    i++;
    }
    if(i==2){
      for(int c = 0; c<sizeof(channel1); i++){
        if(c%2==1){
          pulseIR(channel2[c]);
        }
        else{
          delayMicroseconds(channel2[c]);
        }
      }
    i++;
    }
    
    else{ 
       for(int c = 0; c<sizeof(channel1); i++){
        if(c%2==1){
          pulseIR(channel3[c]);
        }
        else{
          delayMicroseconds(channel3[c]);
        }
      }
      i=0;
    }
  }
}

 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
