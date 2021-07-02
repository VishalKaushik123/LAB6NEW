/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/Vishal/Documents/CTDProjects/LAB6NEW/src/LAB6NEW.ino"
/*
 * Project LAB6
 * Description:
 * Author:
 * Date:
 */
#include "oled-wing-adafruit.h"
void setup();
void loop();
#line 8 "c:/Users/Vishal/Documents/CTDProjects/LAB6NEW/src/LAB6NEW.ino"
OledWingAdafruit display;
uint64_t reading;
double voltage;
double temperature;

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
// setup() runs once, when the device is first turned on.
void setup()
{
	// Put initialization like pinMode and begin functions here.
	pinMode(A5, INPUT); // sets A5 as input to the TMP36
	display.setup();
	display.setTextSize(1);
	display.setCursor(0, 0);
	display.setTextColor(WHITE);
	display.display();
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
	// The core of your code will likely live here.
	display.loop();
	display.clearDisplay();
	reading = analogRead(A5);
	voltage = (reading * 3.3) / 4095.0; //converts the reading to a voltage value
	temperature = (voltage - 0.5) * 100; //converts the voltage value to temperature in celsius
	display.clearDisplay();
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
	display.print(temperature);
	display.println(" C");
	display.print(temperature * 1.8 + 32);
	display.println(" F");
	display.display();
}