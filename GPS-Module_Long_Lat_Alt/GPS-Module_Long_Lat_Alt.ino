
#include <TinyGPS++.h>
#include <SoftwareSerial.h>


// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(12, 11);

void setup(){
  Serial.begin(38400);
  ss.begin(9600);
}

void loop(){
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      // Latitude
      Serial.print("Latitude = "); 
      Serial.println(gps.location.lat(), 6);
      // Longitude
      Serial.print("Longitude = "); 
      Serial.println(gps.location.lng(), 6);
      // Speed in meters per hour (double)
      Serial.print("Speed in m/s = ");
      Serial.println(gps.speed.mps());
      // Altitude in meters (double)
      Serial.print("Altitude in meters = "); 
      Serial.println(gps.altitude.meters()); 
      // Horizontal Dim. of Precision (100ths-i32)
      Serial.print("HDOP = "); 
      Serial.println(gps.hdop.value()); 
    }
  }
  /*
    #ifdef OUTPUT_GPS_MODULE_SD
    myFile.print("Latitude = "); 
      myFile.println(gps.location.lat(), 6);
      myFile.print("Longitude = "); 
      myFile.println(gps.location.lng(), 6);
      myFile.print("Speed in m/s = ");
      myFile.println(gps.speed.mps());
      myFile.print("Altitude in meters = "); 
      myFile.println(gps.altitude.meters()); 
      myFile.print("HDOP = "); 
      myFile.println(gps.hdop.value()); 
    #endif
*/
  /*    #ifdef OUTPUT_GPS_MODULE_SERIAL
        while (ss.available() > 0){
        gps.encode(ss.read());
        if (gps.location.isUpdated()){
        Serial.print("Latitude = "); 
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude = "); 
        Serial.println(gps.location.lng(), 6);
        Serial.print("Speed in m/s = ");
        Serial.println(gps.speed.mps());
        Serial.print("Altitude in meters = "); 
        Serial.println(gps.altitude.meters()); 
        Serial.print("HDOP = "); 
        Serial.println(gps.hdop.value()); 

        }
    }
    #endif
    */
}
