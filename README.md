# Humidity_serialcomm
Uses the SparkFunHTU21D library to display the current humidity and temperature on a serial monitor.
Open serial monitor at 9600 baud to see readings. Errors 998 if not sensor is detected. Error 999 if CRC is bad.
Hardware Connections (Breakoutboard to Arduino):
-VCC = 3.3V
-GND = GND
-SDA = A4 (use inline 330 ohm resistor if your board is 5V)
-SCL = A5 (use inline 330 ohm resistor if your board is 5V)
Configuration and reading from the serial monitor
