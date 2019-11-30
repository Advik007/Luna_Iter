# Luna Iter

Our team is happy to present our code - regarding circuitry in our Pod using Arduino. Our initial circuitry has been shown in our Deliverable 3. Connecting various sensors and analog data in various aspects - such as, Soil Moisture, Temperature, O2 Content and CO2 content - we plan to efficiently control systems of the Pod.

Over time, we will be upgrading our code and connecting more sensor systems over time. Updates related to code are given below:

## Circuitry 
Credits to Circuito.io

### Main Chamber Circuitry
![Luna Iter - Isolation Chamber's Circuitry](https://github.com/Advik007/Luna-Iter---NYAS-Junior-Academy/blob/master/Luna%20Iter%20-%20Arduino%20Circuitry.png)

### CO2 Relevant Circuit for Ventilation from KOH in atmosphere
![Luna Iter - Added DC Motor Circuit](https://github.com/Advik007/Luna_Iter/blob/master/Luna%20Iter%20-%20DC.png)


Circuit Diagram not to Scale - not as per Code as well!

## Materials Required
1. Arduino MEGA
2. LM35 - Temperature
3. Grove Gas Sensor - O2
4. SparkFun - Soil Moisture Sensor
5. K3O - CO2 Sensor
6. Breadboard
7. Wires
8. I2C 20x4
9. DC Motor (150 RPM)

## Updates
22/11/2019 - Initial Upload of Pod Code & Isolation Chamber Code
30/11/2019 - If CO2 levels falls below 400ppm, a ventilation door opens, increasing CO2 gradually!

## Credits
Special Thanks to the following sources for their help:
1. http://wiki.seeedstudio.com/Grove-Gas_Sensor-O2/
2. https://create.arduino.cc/projecthub/alfred333/co2-monitoring-with-k30-sensor-86f6d9
3. https://create.arduino.cc/projecthub/electropeak/complete-guide-to-use-soil-moisture-sensor-w-examples-756b1f?ref=similar&ref_id=142021&offset=0
4. https://www.tutorialspoint.com/arduino/arduino_temperature_sensor.htm
5. https://www.circuito.io
6. https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/ - LCD Library
7. https://fifthseasongardening.com/regulating-carbon-dioxide


## Conclusion
With the help of this system and Arduino's electronics, we would simplify life and make it convenient during the astronaut's period in the Pod!
