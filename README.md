# Smart Irrigation System

An ESP8266-based irrigation controller that monitors soil moisture, temperature, humidity, rain level, and reservoir distance, then controls three relays and reports telemetry through Blynk.

## Hardware

- ESP8266 development board
- Two digital soil-moisture sensors
- DHT11 temperature and humidity sensor
- HC-SR04 ultrasonic distance sensor
- Rain sensor on the analog input
- Three relay-controlled outputs

## Data and control flow

The firmware reads the sensors, publishes measurements to Blynk virtual pins, and changes relay states from the two soil-moisture signals. The mobile dashboard provides remote visibility and manual interaction.

| Signal | Pin / channel |
| --- | --- |
| Rain level | `A0` |
| Soil moisture | `D1`, `D2` / Blynk `V1`, `V2` |
| DHT11 | `D3` / Blynk `V6`, `V7` |
| Relays | `D5`, `D6`, `D7` |
| Ultrasonic trigger / echo | `D8`, `D0` / Blynk `V8` |

## Configure credentials safely

Credentials are intentionally excluded from version control.

1. Copy `secrets.example.h` to `secrets.h`.
2. Replace the placeholder Blynk token, Wi-Fi name, and Wi-Fi password.
3. Keep `secrets.h` local; it is listed in `.gitignore`.

```cpp
#define BLYNK_AUTH_TOKEN "replace-with-blynk-token"
#define WIFI_SSID "replace-with-wifi-name"
#define WIFI_PASSWORD "replace-with-wifi-password"
```

## Build

Install the ESP8266 board support and these Arduino libraries:

- Blynk
- DHT sensor library
- ESP8266WiFi
- HCSR04

Open `Final.ino` in the Arduino IDE, select the matching ESP8266 board and port, then build and upload the sketch.

## Scope

This is a hardware prototype. Relay thresholds and fail-safe behavior should be recalibrated for the specific sensors, pumps, and power hardware before unattended use.

## Security note

An earlier commit included development credentials. Those credentials must be considered compromised and rotated even though the current source no longer contains them.
