# M5StickCPlus Temperature and Humidity Display

This project demonstrates how to use an M5StickCPlus and a DHT22 sensor to display temperature and humidity data on the M5StickCPlus screen, and send the data to a Blynk app using virtual pins V0 and V1. The project uses PlatformIO for development and deployment.


## Hardware Requirements
- M5StickCPlus
- DHT22 sensor
- Jumper wires
- 10kΩ resistor (for pull-up)

## Wiring
- Connect the VCC pin of the DHT22 sensor to the 5V pin of the M5StickCPlus.
- Connect the GND pin of the DHT22 sensor to the GND pin of the M5StickCPlus.
- Connect the DATA pin of the DHT22 sensor to the G26 pin of the M5StickCPlus.
- Add a 10kΩ pull-up resistor between the DATA pin and the VCC pin of the DHT22 sensor.

## Blynk Configuration
- Add a new device in the Blynk app and obtain the authentication token.
- In the Blynk app, add two Value Display widgets.
  - Set one widget to display the temperature from virtual pin V0.
  - Set the other widget to display the humidity from virtual pin V1.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
