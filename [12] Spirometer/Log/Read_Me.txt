2 pressure sensor is used to find the difference between those. 
Since the  pressure moudles are identical and Uses I2C, dedicated MCU are used.
LCD 16*2 is added to show the O/P.
Communication is done between the MCU by 1 wire system. Sender makes a digital pin from 0V-5V according to the pressure. Reciever uses analogRead function to get the value.[Worst method, i know. But i couldn't find another soln in this time]