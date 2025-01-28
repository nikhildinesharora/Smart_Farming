Smart Irrigation System

Description

The Smart Irrigation System is an IoT-based project that monitors environmental conditions like soil moisture, temperature, humidity, and water levels. It automates irrigation using relays connected to pumps and provides real-time data and control through the Blynk IoT platform.

Features
	•	Measures:
	•	Soil Moisture: Two sensors to monitor soil conditions.
	•	Temperature and Humidity: Using a DHT11 sensor.
	•	Water Level: Using an ultrasonic sensor (HC-SR04).
	•	Automates irrigation using relays based on soil moisture readings.
	•	Sends real-time data to the Blynk IoT platform.
	•	Allows remote monitoring and control through a mobile app.

Hardware Requirements
	•	ESP8266 microcontroller
	•	DHT11 temperature and humidity sensor
	•	HC-SR04 ultrasonic sensor
	•	Soil Moisture Sensors (2 units)
	•	Relays (3 units)
	•	Jumper wires and a breadboard
	•	Power supply

Software Requirements
	•	Arduino IDE
	•	Blynk library
	•	ESP8266WiFi library
	•	DHT library
	•	HC-SR04 library

Wiring Diagram

Connect the components as follows:
	•	Soil Moisture Sensors: D1, D2
	•	DHT11 Sensor: D3
	•	Ultrasonic Sensor: D8 (Trig), D0 (Echo)
	•	Relays: D5, D6, D7

Configuration
	1.	Replace the placeholders in the code with your Blynk authentication token, WiFi SSID, and password:

        #define BLYNK_AUTH_TOKEN "your_auth_token"
        char ssid[] = "your_wifi_ssid";
        char pass[] = "your_wifi_password";

    2.	Install the required libraries in the Arduino IDE:
	•	Blynk
	•	DHT
	•	ESP8266WiFi

Usage
	1.	Upload the code to the ESP8266 using the Arduino IDE.
	2.	Open the Blynk app and configure widgets for:
	•	Soil Moisture (V1, V2)
	•	Temperature (V6)
	•	Humidity (V7)
	•	Distance (V8)
	3.	Monitor sensor readings and control relays via the Blynk app.

Functionality
	•	Automatically turns on/off relays based on soil moisture levels.
	•	Sends distance, temperature, and humidity data to the Blynk app.
	•	Provides manual override for relays through the Blynk interface.




    