# Collision Avoidance

Implemented a Collision avoidance system (pre-crash system), to determine the car's vicinity to nearby obstacles and notify the driver of potential car crash situations.  
Using 2 PIC microcontrollers  
PIC 1 is connected to a LED and a Buzzer.  
PIC 2 is connected to a sensor.  
The two PICs communicate with each other using UART communication.  

 * If the sensor reads a value less than or equals 50:  
1. Toggle the Led each half second. 
2. Toggle the Buzzer for (10*distance measured from sensor) in milli seconds with a 50% Duty Cycle. ex. (if the sensor reads 45, activate the buzzer for 450ms then deactivate it for 450ms and so on)   
* Created a simulation of this circuit using proteus.
