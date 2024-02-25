#include <virtuabotixRTC.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

int CLK_PIN = 13;
int DAT_PIN = 12;
int RST_PIN = 11;
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);

LiquidCrystal_I2C ekran(0x27,16,2);

DHT11 dht(7);

void setup() {
ekran.init();
ekran.backlight();
ekran.clear();
}

void loop() {
  int temp = dht.readTemperature(),hum = dht.readHumidity();
  myRTC.updateTime();

// Sıcaklık - Nem
  ekran.setCursor(13,1); ekran.print("%"); ekran.print(hum);// Nem
  ekran.setCursor(0,1); ekran.print(temp); ekran.print(" C");// Sıcaklık

// Tarih
  if(myRTC.month < 9){ekran.setCursor(12,0);}
  else{ekran.setCursor(11,0);}
  
  ekran.print(myRTC.dayofmonth);
  ekran.print("/");
  ekran.print(myRTC.month);
  
// Saat
   //am sabah
   //pm öğlen
  if(myRTC.hours > 12){ ekran.setCursor(0,0); ekran.print(myRTC.hours - 12); ekran.print(":"); ekran.print(myRTC.minutes); ekran.print("pm");}
    
  else{ ekran.setCursor(0,0); ekran.print(myRTC.hours); ekran.print(":"); ekran.print(myRTC.minutes); ekran.print("am");}
    
      delay(1000);
  }