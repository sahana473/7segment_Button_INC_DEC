/*Interfacing 7 Segment(Common Cathode) display to Arduino Uno to perform 
 *increment and decrement operation by using push buttons.
 * 
 * Hardware Components:
 *  Sevensegment Display(Common Cathode)
 *  Arduino Uno   
 *  Push Buttons
 * 
 * Hardware Connection:
 *  Arduino Uno - Seven segment display connection
 *  D2-D8 are connected to pin of seven segment display
 *  To display digit:
 *                        a b c d e f g 
 *                   0 = {0,1,1,1,1,1,1}
 *                   1 = {0,0,0,0,1,1,0}
 *                   2 = {1,0,1,1,0,1,1}
 *                   3 = {1,0,0,1,1,1,1}
 *                   4 = {1,1,0,0,1,1,0}
 *                   5 = {1,1,0,1,1,0,1}
 *                   6 = {1,1,1,1,1,0,1}
 *                   7 = {0,0,0,0,1,1,1}
 *                   8 = {1,1,1,1,1,1,1}
 *                   9 = {1,1,0,1,1,1,1}
 *                   
 * D11-D12 of Arduino Uno is connected to Buttons                  
 * D11 of Arduino Uno is connected to Button 1 for Increment operation.
 * D12 of Arduino Uno is connected to Button 2 for Decrement operation
 *                   
 *  Author : Sahana B G
 *  Date   : 01 May 2021 
  */

// Pin configuration
const byte FIRSTPIN = 2;
const byte LASTPIN = 8;
const int BUTTON1 = 11;
const int BUTTON2 = 12; 

// Global variable to store count value
unsigned int count = 0;

// Defining an array to store led pattern from 0 to 9
bool myArray[10][7] = {{0,1,1,1,1,1,1},{0, 0, 0, 0, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {1, 1, 0, 0, 1, 1, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 1, 0, 1},
  {0, 0, 0, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 0, 1, 1, 1, 1}};

  
void setup()
{
   // Configure data pins to output 
   for(int i = FIRSTPIN ; i<=LASTPIN; i++ )
   {
    pinMode(i,OUTPUT); 
   }
   
    // Configure Button pins to output
    pinMode(BUTTON1,OUTPUT);
    pinMode(BUTTON2,OUTPUT);
}

void loop()
{
 // Read the button status
 if(digitalRead(BUTTON1)== HIGH)
 {
  while(digitalRead(BUTTON1)== HIGH);
 count++; // Increment
 }
 else if(digitalRead(BUTTON2)== HIGH)
 {
  while(digitalRead(BUTTON2)== HIGH);
  count--; // Decrement
 }
 
 // Reset count 
 if(count>9||count<0)
 {
  count = 0;
 }
 displayCount();
}

void displayCount()
 {
  int pin = FIRSTPIN ;
  
    // Iterates for column data
    for(int i = 0 ; i<7; i++)
     {
       digitalWrite(pin,myArray[count][i]); // Set the digital pins to display given array
       pin++;
     }
  }





 
