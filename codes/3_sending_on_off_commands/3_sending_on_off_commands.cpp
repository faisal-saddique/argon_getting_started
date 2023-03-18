#include "Particle.h"

const int LED_PIN = D7;

// This example does not require the cloud so you can run it in manual mode or
// normal cloud-connected mode
// SYSTEM_MODE(MANUAL);

void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context);

// These UUIDs were defined by Nordic Semiconductor and are now the defacto standard for
// UART-like services over BLE. Many apps support the UUIDs now, like the Adafruit Bluefruit app.
const BleUuid serviceUuid("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid rxUuid("6E400002-B5A3-F393-E0A9-E50E24DCCA9E");
const BleUuid txUuid("6E400003-B5A3-F393-E0A9-E50E24DCCA9E");

BleCharacteristic txCharacteristic("tx", BleCharacteristicProperty::NOTIFY, txUuid, serviceUuid);
BleCharacteristic rxCharacteristic("rx", BleCharacteristicProperty::WRITE_WO_RSP, rxUuid, serviceUuid, onDataReceived, NULL);

void onDataReceived(const uint8_t* data, size_t len, const BlePeerDevice& peer, void* context) {
    String receivedData = "";
    for (int i = 0; i < len; i++) {
      if (isAlphaNumeric(data[i])) {
        receivedData += (char)data[i];
      }
    }
    // String receivedData = String((char*)data);
    Serial.println("Received data: " + receivedData);
    if (receivedData == "ON") {
        Serial.println("Turning the LED on...");
        digitalWrite(LED_PIN, HIGH);
    } else if (receivedData == "OFF") {
        Serial.println("Turning the LED off...");
        digitalWrite(LED_PIN, LOW);
    }
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    Serial.begin(115200);

	BLE.on();

    BLE.addCharacteristic(txCharacteristic);
    BLE.addCharacteristic(rxCharacteristic);

    BleAdvertisingData data;
    data.appendServiceUUID(serviceUuid);
    BLE.advertise(&data);
}

void loop() {
    if (BLE.connected()) {
        static unsigned long previousMillis = 0;
        unsigned long currentMillis = millis();

        if (currentMillis - previousMillis >= 2000) {
            previousMillis = currentMillis;

            // Generate random temperature and humidity values
            int temp = random(0, 100);
            int hum = random(0, 100);

            // Format the data in the desired format
            String data = "{\"temp\": " + String(temp) + ", \"hum\":" + String(hum) + "}\n";

            // Convert the data to a char array and send it over BLE
            const char* txBuf = data.c_str();
            txCharacteristic.setValue(txBuf);
        }
    }
}
