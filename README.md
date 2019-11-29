# Bluetooth-AVO-Meter-based-on-Atmega16-uC

Ciao guys, 
I always wanted a small convenient Avo meter that measures Voltage, current and resistance with the results being printed by on the smartphone, It's going to be cheap too since we wont need a display for the device.
The project uses the ADC peripheral to measure the voltage, current and resistance, Then the result is sent to a bluetooth module where the results are recieved by a smartphone App.
Here is the schematic from proteues:


Some future work for those interested : 
  - currently only DC voltage are supported, to support AC and wider range of DC voltage we might need a bridge circuit and Op-amp circuits.
  - this project uses the ADC peripheral of the ATmega16, Which is has 10-bit resolution, for more sensitive measurement, We can use Digital Multimer IC.

E-mail:Karimhamdymo@gmail.com
