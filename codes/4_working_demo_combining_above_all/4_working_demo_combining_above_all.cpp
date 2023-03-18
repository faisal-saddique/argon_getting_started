#include "Particle.h"

// Pin used for the LED
const int LED_PIN = D7;

// UUIDs used for the BLE service
const BleUuid serviceUuid("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid rxUuid("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid txUuid("6E400003-B5A3-F393-E0A9-E50E24DCCA9E");

// BLE characteristics for receiving and transmitting data
BleCharacteristic txCharacteristic("tx", BleCharacteristicProperty::NOTIFY, txUuid, serviceUuid);
BleCharacteristic rxCharacteristic("rx", BleCharacteristicProperty::WRITE_WO_RSP, rxUuid, serviceUuid, onDataReceived, NULL);

// Callback function for when data is received over BLE
void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context) {
    String receivedData = "";
    // Convert the data to a String, filtering out non-alphanumeric characters
    for (int i = 0; i < len; i++) {
      if (isAlphaNumeric(data[i])) {
        receivedData += (char)data[i];
      }
    }
    // Print the received data to the serial console
    Serial.println("Received data: " + receivedData);
    // If the received data is "ON", turn on the LED
    if (receivedData == "ON") {
        Serial.println("Turning the LED on...");
        digitalWrite(LED_PIN, HIGH);
    // If the received data is "OFF", turn off the LED
    } else if (receivedData == "OFF") {
        Serial.println("Turning the LED off...");
        digitalWrite(LED_PIN, LOW);
    }
}

void setup() {
    // Set the LED pin to output mode and turn it on
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    // Start the serial console
    Serial.begin(115200);
    // Turn on BLE
    BLE.on();
    // Add the BLE characteristics
    BLE.addCharacteristic(txCharacteristic);
    BLE.addCharacteristic(rxCharacteristic);
    // Advertise the BLE service
    BleAdvertisingData data;
    data.appendServiceUUID(serviceUuid);
    BLE.advertise(&data);
}

void loop() {
    // If there is a BLE connection
    if (BLE.connected()) {
        static unsigned long previousMillis = 0;
        unsigned long currentMillis = millis();
        // Send data every 2 seconds
        if (currentMillis - previousMillis >= 2000) {
            previousMillis = currentMillis;
            // Generate random temperature and humidity values
            int temp = random(0, 100);
            int hum = random(0, 100);
            // Format the data in JSON format
            String data = "{\"temp\": " + String(temp) + ", \"hum\":" + String(hum) + "}\n";
            // Convert the data to a char array and send it over BLE
            const char* txBuf = data.c_str();
            txCharacteristic.setValue(txBuf);
        }
    }
}
