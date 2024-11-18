#include <NimBLEDevice.h>
static NimBLEClient* pClient;

void setup() {
// put your setup code here, to run once:
Serial.begin(115200);
Serial.println("Starting NimBLE Client");
NimBLEDevice::init("");
NimBLEDevice::setPower(ESP_PWR_LVL_P9);

pClient = NimBLEDevice::createClient(NimBLEAddress("55:88:89:14:96:83", 1));
Serial.println("New client created");
pClient->connect();
Serial.print("Connected to: ");
Serial.println(pClient->getPeerAddress().toString().c_str());
Serial.print("RSSI: ");
Serial.println(pClient->getRssi());
}

void loop() {
// put your main code here, to run repeatedly:
if (!pClient->isConnected()) {
pClient->connect();
} else {
Serial.println("Connected");
}
delay(1000);
}