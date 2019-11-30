#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <K30_I2C.h>

const int O2Sensor = A0; //Attachment of Grove - Gas Sensor (O2) to A0
const float VRefer = 3.3; //O2 Sensor Voltage - Reference
float temp; //Temperature - Variable
int temperaturePin = A3; //Temperature Sensor (LM-35) to A3
int co2 = 0; //CO2 - Variable
int CO2Error = 1; //CO2 - Reference
int DCMotorPin= 3; //DC Motor for Ventilation Area Door - intake of CO2 into the chamber using KOH regarded in Deliverable 2

double starttime,starttimec,endtime,endtimec; //MILLIS Function Variables

K30_I2C k30_i2c = K30_I2C(0x68); //Initalisation of CO2 Sensor @ Address - 0x68
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //Positions of placement of LCD Screen @ Address - 0x27

void setup() {
 pinMode(DCMotorPin, OUTPUT);
 Serial.begin(9600);
}

void CO2Testing(){
  CO2Error=k30_i2c.readCO2(co2); //Data from CO2 Sensor
  if(CO2Error == 0){
    lcd.setCursor(0,2); //Column 0, Row 2
    lcd.print("CO2 Content: ");
    lcd.print(co2);

    delay(1000); //Sleep for 1 seconds
  }
}

float readO2Vout() //Regardless to code, processing for O2 Sensor Data
{
    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(O2Sensor);
    }

    sum >>= 5;

    float MeasuredVout = sum * (VRefer / 1023.0);
    return MeasuredVout;
}

float O2Content()
{
    // Voltage samples are with reference to 3.3V
    float MeasuredVout = readO2Vout();

    //when its output voltage is 2.0V,
    float Concentration = MeasuredVout * 0.21 / 2.0;
    float Concentration_Percentage=Concentration*100;

    //Regardless - display
    lcd.setCursor(0,3); //Column 0, Row 3
    lcd.print("O2 Content: ");
    lcd.print(Concentration_Percentage);

    delay(1000); //Sleep for 1 seconds
    
}

void TemperatureSet(){
  temp = analogRead(temperaturePin); //Reading of Data
   temp = temp * 0.48828125; // Conversion of analog volt to its temperature equivalent
   lcd.setCursor(0,4); //Column 0, Row 4
   lcd.print("Temperature :");
   lcd.print(temp);
   lcd.print("*C");

   delay(1000); //Sleep for 1 seconds
}
void loop() {
  lcd.clear(); //Clearing LCD once accomplished
 //Implementation and Calling of Classes
 CO2Testing();
 O2Content();
 TemperatureSet();
 
 if(co2<400){ //Test that if CO2 Content is less than 400ppm, open Ventilation Door (KOH)- connected to a Motor to open it up!
  //estimate that it takes 100 turns to open the door
  //DC Motor is 150 RPM
  starttime = millis();

 while ((millis() - starttime) <=(40000)) // Do this loop for up to 40sec
{
  int DCspeed = 150; //ClockwiseRPM
  analogWrite(DCMotorPin, DCspeed);
 } 

 delay(1000);
 if(co2>=400){
  starttimec=millis();

  while((millis()-starttimec)<=40000){ //Do for 40sec
   int DCSpeed2=-150; //AnticlockwiseRPM
  analogWrite(DCMotorPin, DCSpeed2);
  }
 }
 
 }
}

