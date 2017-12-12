///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////MOSELEY MIRANDA GOES/////////
/////////////////////////////////////////////30-11-2017  TO 31-11-2017/////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
int val = 0; 
int lastVal = 0;
int val1 = 0; 
int lastVal1 = 0;
int val2 = 0;
int lastVal2 = 0;
int val3 = 0;
int lastVal3 = 0;
int val4 = 0;
int lastVal4 = 0;
int val5 = 0;
int lastVal5 = 0;
int val6 = 0;
int lastVal6 = 0;
int val7 = 0;
int lastVal7 = 0;
int val8 = 0;
int lastVal8 = 0;
const int ledPinSerial =  10; // LED SERIAL
const int NbrLEDs1 = 9;
     const int ledPins1[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1};
     const int wait = 30;
         const boolean LED_ON = LOW;
         const boolean LED_OFF = HIGH;
     int sensorValue1 = 0; // value read from the sensor     
                int ledLevel1 = 0;         
                 const int analogInPin1 = 0;    
void setup(){
  for (int led = 0; led < NbrLEDs1; led++)
{
pinMode(ledPins1[led], OUTPUT); // make all the LED pins outputs
}

     Serial.begin(9600); 

   pinMode(ledPinSerial, OUTPUT); // LED ON
}
void loop()
{ 
  
   val = analogRead(0)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val != lastVal) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
   MIDImessage(176,1,val);}         // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   lastVal = val;
   //////////////erro no meu arduino//////////
    val2 = analogRead(1)/8;   // Divide by 8 to get range of 0-127 for midi
     if (val2 != lastVal2) 
     {
     MIDImessage(176,2,val2);}         // 176 = CC command, 2 = Which Control, val = value read from Potentionmeter 2
     lastVal2 = val2;
   
   val3 = analogRead(2)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val3 != lastVal3) 
   {
   MIDImessage(176,3,val3);}         // 176 = CC command, 3 = Which Control, val = value read from Potentionmeter 3
   lastVal3 = val3;
   
   val4 = analogRead(3)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val4 != lastVal4) 
   {
   MIDImessage(176,4,val4);}         // 176 = CC command, 4 = Which Control, val = value read from Potentionmeter 4
   lastVal4 = val4;
   
   val5 = analogRead(4)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val5 != lastVal5) 
   {
   MIDImessage(176,5,val5);}         // 176 = CC command, 5 = Which Control, val = value read from Potentionmeter 5
   lastVal5 = val5;
   
   val6 = analogRead(5)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val6 != lastVal6) 
   {
   MIDImessage(176,6,val6);}         // 176 = CC command, 6 = Which Control, val = value read from Potentionmeter 6
   lastVal6 = val6;
   
   val7 = analogRead(6)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val7 != lastVal7) 
   {
   MIDImessage(176,7,val7);}         // 176 = CC command, 7 = Which Control, val = value read from Potentionmeter 7
   lastVal7 = val7;
   
   val8 = analogRead(7)/8;   // Divide by 8 to get range of 0-127 for midi
   if (val8 != lastVal8) 
   {
   MIDImessage(176,8,val8);}         // 176 = CC command, 8 = Which Control, val = value read from Potentionmeter 8
   lastVal8 = val8;
  delay(1);

              digitalWrite(ledPinSerial, HIGH);   // turn the LED on (HIGH is the voltage level)
              delay(10);                       // wait for a second
              digitalWrite(ledPinSerial, LOW);    // turn the LED off by making the voltage LOW
              delay(100);                       // wait for a second
 /////////////////////////////////////////////////////////////////
///////////////LED VOLUME INTERNAL BAR///////////////////////////
/////////////////////////////////////////////////////////////////

sensorValue1 = analogRead(analogInPin1); // read the analog in value
ledLevel1 = map(sensorValue1 , 0, 1023, 0, NbrLEDs1); // map to the number of LEDs
for (int led = 0; led < NbrLEDs1; led++)
{
if (led > ledLevel1 ) {
digitalWrite(ledPins1[led], LED_ON); // turn on pins less than the level
}
else {
digitalWrite(ledPins1[led], LED_OFF); // turn off pins higher than the


}
}
}

//////////////////////////////////FIM//////////////////////////////////////////
void MIDImessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}

