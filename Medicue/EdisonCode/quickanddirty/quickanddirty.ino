
#if 0
#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_SPI pn532spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532spi);
#else

#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc = NfcAdapter(pn532_i2c);
#endif

void vibeInt(void) {
  
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
  
}

void vibeOn(void) {
  
 digitalWrite(10, HIGH);
 digitalWrite(11, HIGH);
  
}

void vibeOff(void) {
  
 digitalWrite(10, LOW);
 digitalWrite(11, LOW);
  
}


void setup(void) {
    
    Serial.begin(9600);
    Serial.println("NDEF Reader");
    nfc.begin();
    vibeInt();
}

void light_green_flash() {
  strip.WS2812SetHSV(0, 0, 0, (1 + sin(((float)millis())/1000))*127);
  strip.WS2812Send();
}


void loop(void) {
    Serial.println("\nScan a NFC tag\n");
    if (nfc.tagPresent())
    {
        NfcTag tag = nfc.read();
        tag.print();
        vibeOn();
        delay(5000);
        vibeOff();
    }
    delay(5000);
}




