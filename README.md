# Fan-Controller-system
ATmega32 Microcontroller is Used with frequency 1Mhz, Designed and implemented based on the layered architecture model 
The aim of this project is to design a temperature-controlled fan using ATmega32 
microcontroller, in which the fan is automatically turned ON or OFF according to the 
temperature. 
The specifications of the system:
1. The LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it.

2. This analog signal is given to the ADC,which converts the analog values to digital values.

3. The microcontroller will continuously monitor the temperature and based on the 
temperature value, the microcontroller will drive the fan like that:
a. If the temperature is less than 30C turn off the fan.
b. If the temperature is greater than or equal 30C turn on the fan with 25% of its 
maximum speed.
c. If the temperature is greater than or equal 60C turn on the fan with 50% of its 
maximum speed.
d. If the temperature is greater than or equal 90C turn on the fan with 75% of its 
maximum speed.
e. If the temperature is greater than or equal 120C turn on the fan with 100% of its 
maximum speed.

4. The main principle of the circuit is to switch on/off the fan connected to DC motor based 
on temperature value. The DC-Motor rotates in clock-wise direction or stopped based on 
the fan state.

5. the temperature and the fan status is displayed on the LCD.
   
6. the DC-Motor speed is Controlled using PWM signal generated from Timer0.
