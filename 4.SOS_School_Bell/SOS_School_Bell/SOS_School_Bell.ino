#include <Firmata.h>
#include "RTClib.h"
#include <Wire.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
RTC_DS1307 RTC;

#define BELL 17       //Relay

char daysOfTheWeek[7][12] = {"SUN ", "MON ", "TUES", "WED ", "THUR", "FRI ", "SAT "};

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  lcd.begin(16, 2);
  pinMode(BELL, OUTPUT);

  if (!RTC.isrunning())
  {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & TIME this sketch was compiled
    //RTC.adjust(DateTime(__DATE__, __TIME__)); // Use ONCE then comment out and reload
    //RTC.adjust(DateTime(2019, 15, 7, 17, 45, 0)); // Set TIME manually ONCE as above
  }
}

void loop ()
{
  DateTime now = RTC.now();
  printTime();
  
  //************************ DAY SELECTION ******************************

  //******************** AUTOMATIC MODE ****************************
    Serial.print("AUTOMATIC MODE")  ;
    //******************Monday, Tuesday, Wednesday, Thursday******************
    if(  daysOfTheWeek[now.dayOfTheWeek()] == daysOfTheWeek[1] 
      || daysOfTheWeek[now.dayOfTheWeek()] == daysOfTheWeek[2] 
      || daysOfTheWeek[now.dayOfTheWeek()] == daysOfTheWeek[3] 
      || daysOfTheWeek[now.dayOfTheWeek()] == daysOfTheWeek[4] )
    {
      Serial.println("   ****    FULL_DAY   *****");
      FULL_DAY ();
    }

    //*************** HALF_DAY (Friday) *****************************
    if (daysOfTheWeek[now.dayOfTheWeek()] == daysOfTheWeek[5] )
    {
      Serial.println("   ****    FRIDAY   *****");
      FRIDAY ();
    }

    //*******************SATURDAY*****************************
    if (daysOfTheWeek[now.dayOfTheWeek()] == daysOfTheWeek[6])
    {
      Serial.println("   ****    SATURDAY   *****");
      SATURDAY ();
    }

    //**********************SUNDAY*****************************
    if (daysOfTheWeek[now.dayOfTheWeek()] == daysOfTheWeek[0])
    {
      Serial.println("   ****    SUNDAY    *****");
      SUNDAY ();
    }
 }


void FULL_DAY ()
{
  DateTime now = RTC.now();

  int TIME = 05;
  int TIME2 = 10;

  //******** Wake UP
  if (now.hour() == 5 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 5 && now.minute() == 00 && now.second() == TIME2) { digitalWrite(BELL, LOW);    }

  //******** Preps
  if (now.hour() == 5 && now.minute() == 50 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 5 && now.minute() == 50 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //******** Tea & Assembly
  if (now.hour() == 7 && now.minute() == 30 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 7 && now.minute() == 30 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //==========================
  //******** 1st Hour Period 
  if (now.hour() == 8 && now.minute() == 25 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 8 && now.minute() == 25 && now.second() == TIME) { digitalWrite(BELL, LOW);    }
  
  //==========================
  //******** 2nd Hour Period 
  if (now.hour() == 9 && now.minute() == 10 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 9 && now.minute() == 10 && now.second() == TIME) { digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** 3rd Hour Period 
  if (now.hour() == 9 && now.minute() == 50 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 9 && now.minute() == 50 && now.second() == TIME) { digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** Tea Break 
  if (now.hour() == 10 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 10 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** 4th Hour Period 
  if (now.hour() == 10 && now.minute() == 50 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 10 && now.minute() == 50 && now.second() == TIME){ digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** 5th Hour Period 
  if (now.hour() == 11 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 11 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //========================== 
  //******** LUNCH TIME & Long Break 
  if (now.hour() == 12 && now.minute() == 10 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 12 && now.minute() == 10 && now.second() == TIME){ digitalWrite(BELL, LOW);   }
 
  //==========================  
  //******** 6th Hour Period 
  if (now.hour() == 13 && now.minute() == 25 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 13 && now.minute() == 25 && now.second() == TIME2){ digitalWrite(BELL, LOW);    }

  //==========================  
  //******** 7th Hour Period 
  if (now.hour() == 14 && now.minute() == 05 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 14 && now.minute() == 05 && now.second() == TIME){ digitalWrite(BELL, LOW);   }

  //==========================  
  //******** 8th Hour Period 
  if (now.hour() == 14 && now.minute() == 45 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 14 && now.minute() == 45 && now.second() == TIME){ digitalWrite(BELL, LOW);   }

  //==========================    
  //******** Break
  if (now.hour() == 15 && now.minute() == 25 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 15 && now.minute() == 25 && now.second() == TIME){ digitalWrite(BELL, LOW);   }
  
  //==========================    
  //******** 9th Hour Period 
  if (now.hour() == 15 && now.minute() == 40 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 15 && now.minute() == 40 && now.second() == TIME){ digitalWrite(BELL, LOW);   }
  
  //==========================  
  //******** 10th Hour Period 
  if (now.hour() == 16 && now.minute() == 20 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 16 && now.minute() == 20 && now.second() == TIME){ digitalWrite(BELL, LOW);   }

  //========================== 
  //******** END of Day Class
  if (now.hour() == 17 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 17 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** Cleaning
  if (now.hour() == 18 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 18 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** 1st Preps
  if (now.hour() == 18 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 18 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** DINNER Time
  if (now.hour() == 20 && now.minute() == 15 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 20 && now.minute() == 15 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** BED Time
  if (now.hour() == 21 && now.minute() == 15 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 21 && now.minute() == 15 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** SILENT SLEEPING
  if (now.hour() == 21 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 21 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);     }
}

void FRIDAY ()
{
  DateTime now = RTC.now();

  int TIME = 05;
  int TIME2 = 10;

    //******** Wake UP
  if (now.hour() == 5 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 5 && now.minute() == 00 && now.second() == TIME2) { digitalWrite(BELL, LOW);    }

  //******** Preps
  if (now.hour() == 5 && now.minute() == 50 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 5 && now.minute() == 50 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //******** Tea & Assembly
  if (now.hour() == 7 && now.minute() == 30 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 7 && now.minute() == 30 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //==========================
  //******** 1st Hour Period 
  if (now.hour() == 8 && now.minute() == 25 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 8 && now.minute() == 25 && now.second() == TIME) { digitalWrite(BELL, LOW);    }
  
  //==========================
  //******** 2nd Hour Period 
  if (now.hour() == 9 && now.minute() == 10 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 9 && now.minute() == 10 && now.second() == TIME) { digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** 3rd Hour Period 
  if (now.hour() == 9 && now.minute() == 50 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 9 && now.minute() == 50 && now.second() == TIME) { digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** Tea Break 
  if (now.hour() == 10 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 10 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** 4th Hour Period 
  if (now.hour() == 10 && now.minute() == 50 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 10 && now.minute() == 50 && now.second() == TIME){ digitalWrite(BELL, LOW);   }
  
  //==========================
  //******** 5th Hour Period 
  if (now.hour() == 11 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 11 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //========================== 
  //******** LUNCH TIME & Long Break 
  if (now.hour() == 12 && now.minute() == 10 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 12 && now.minute() == 10 && now.second() == TIME){ digitalWrite(BELL, LOW);   }

  //==========================    
  //******** 6th Hour Period 
  if (now.hour() == 13 && now.minute() == 25 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 13 && now.minute() == 25 && now.second() == TIME2){ digitalWrite(BELL, LOW);    }

  //==========================  
  //******** 7th Hour Period 
  if (now.hour() == 14 && now.minute() == 05 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 14 && now.minute() == 05 && now.second() == TIME){ digitalWrite(BELL, LOW);   }

  //==========================  
  //******** 8th Hour Period 
  if (now.hour() == 14 && now.minute() == 45 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 14 && now.minute() == 45 && now.second() == TIME){ digitalWrite(BELL, LOW);   }

  //==========================     
  //******** END of Day Class
  if (now.hour() == 17 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 17 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** 1st Preps
  if (now.hour() == 18 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 18 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** DINNER Time
  if (now.hour() == 19 && now.minute() == 45 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 19 && now.minute() == 45 && now.second() == TIME){ digitalWrite(BELL, LOW);     }

  //******** BED Time
  if (now.hour() == 20 && now.minute() == 45 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 20 && now.minute() == 45 && now.second() == TIME){ digitalWrite(BELL, LOW);     }
  
  //******** SILENT SLEEPING
  if (now.hour() == 21 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);    }
  if (now.hour() == 21 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);     }
}

void SATURDAY ()
{
  DateTime now = RTC.now();

  int TIME = 05;
  int TIME2 = 10;

  //********
  if (now.hour() == 6 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 6 && now.minute() == 00 && now.second() == TIME2) { digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 7 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 7 && now.minute() == 00 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 8 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 8 && now.minute() == 00 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 10 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 10 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 11 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 11 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 12 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 12 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }
  
  //********
  if (now.hour() == 15 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 15 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 16 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 16 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);    }


  //********
  if (now.hour() == 17 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 17 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 19 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 19 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 21 && now.minute() == 45 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 21 && now.minute() == 45 && now.second() == TIME){ digitalWrite(BELL, LOW);    }
  
  //********
  if (now.hour() == 22 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 22 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);    }
}

void SUNDAY ()
{
  DateTime now = RTC.now();

  int TIME = 05;
  int TIME2 = 10;

  //********
  if (now.hour() == 6 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 6 && now.minute() == 00 && now.second() == TIME2) { digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 7 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 7 && now.minute() == 00 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 8 && now.minute() == 00 && now.second() == 00)   { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 8 && now.minute() == 00 && now.second() == TIME) { digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 10 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 10 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 12 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 12 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

//********
  if (now.hour() == 13 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 13 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 16 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 16 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 17 && now.minute() == 00 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 17 && now.minute() == 00 && now.second() == TIME){ digitalWrite(BELL, LOW);    }
  //********
  if (now.hour() == 19 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 19 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 20 && now.minute() == 15 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 20 && now.minute() == 15 && now.second() == TIME){ digitalWrite(BELL, LOW);    }

  //********
  if (now.hour() == 20 && now.minute() == 30 && now.second() == 00)  { digitalWrite(BELL, HIGH);   }
  if (now.hour() == 20 && now.minute() == 30 && now.second() == TIME){ digitalWrite(BELL, LOW);    }
}


void printTime()
{
  DateTime now = RTC.now();
  lcd.setCursor(0 , 0);
  lcd.print("SOS-THS");
  lcd.setCursor(11, 0);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print("");
  lcd.setCursor(0, 1);
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);
  lcd.print(' ');
  lcd.setCursor(11, 1);
  if (now.hour() < 10)
    // lcd.print("   ")
    lcd.print('0');
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  if (now.minute() < 10)
    lcd.print('0');
  lcd.print(now.minute(), DEC);
}
