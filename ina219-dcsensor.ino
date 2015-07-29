// This #include statement was automatically added by the Particle IDE.
#include "ina129Spark.h"

Adafruit_INA219 ina219_DHT;
Adafruit_INA219 ina219_Shinyei(0x41);
Adafruit_INA219 ina219_MQ131(0x44);


  float shuntvoltage_DHT;
  float busvoltage_DHT;
  float current_mA_DHT;
  float loadvoltage_DHT;

  float shuntvoltage_Shinyei;
  float busvoltage_Shinyei;
  float current_mA_Shinyei;
  float loadvoltage_Shinyei;
  
  float shuntvoltage_MQ131;
  float busvoltage_MQ131;
  float current_mA_MQ131;
  float loadvoltage_MQ131;
  
void setup(void) 
{
  uint32_t currentFrequency;
    
  Serial.begin(115200);
  //delay(3000);                  //Delay to give a chance to start serial monitor

  //Serial.println("Measuring voltage and current with INA219 ...");
  ina219_DHT.begin();  //serial output
  ina219_Shinyei.begin();
  ina219_MQ131.begin();
  
  //pinMode( D0, INPUT);
  
  Spark.variable("shuntVoltageDHT", &shuntvoltage_DHT, DOUBLE);
  Spark.variable("busVoltageDHT", &busvoltage_DHT, DOUBLE);
  Spark.variable("currentmaDHT", &current_mA_DHT, DOUBLE);
  //Spark.variable("loadVoltageDHT", &loadvoltage_DHT, DOUBLE);
  
  Spark.variable("shuntVoltageShinyei", &shuntvoltage_Shinyei, DOUBLE);
  Spark.variable("busVoltageShinyei", &busvoltage_Shinyei, DOUBLE);
  Spark.variable("currentmaShinyei", &current_mA_Shinyei, DOUBLE);
  //Spark.variable("loadVoltageShinyei", &loadvoltage_Shinyei, DOUBLE);
  
  Spark.variable("shuntVoltageMQ", &shuntvoltage_MQ131, DOUBLE);
  Spark.variable("busVoltageMQ", &busvoltage_MQ131, DOUBLE);
  Spark.variable("currentmaMQ", &current_mA_MQ131, DOUBLE);
  //Spark.variable("loadVoltageMQ", &loadvoltage_MQ131, DOUBLE);
}

void loop(void) 
{
 /* float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0; */

  shuntvoltage_DHT = ina219_DHT.getShuntVoltage_mV();
  busvoltage_DHT = ina219_DHT.getBusVoltage_V();
  current_mA_DHT = ina219_DHT.getCurrent_mA();
  //loadvoltage_DHT = busvoltage_DHT + (shuntvoltage_DHT / 1000);
  
  shuntvoltage_Shinyei = ina219_Shinyei.getShuntVoltage_mV();
  busvoltage_Shinyei = ina219_Shinyei.getBusVoltage_V();
  current_mA_Shinyei = ina219_Shinyei.getCurrent_mA();
  //loadvoltage_Shinyei = busvoltage_Shinyei + (shuntvoltage_Shinyei / 1000);
  
  shuntvoltage_MQ131 = ina219_MQ131.getShuntVoltage_mV();
  busvoltage_MQ131 = ina219_MQ131.getBusVoltage_V();
  current_mA_MQ131 = ina219_MQ131.getCurrent_mA();
  //loadvoltage_MQ131 = busvoltage_MQ131 + (shuntvoltage_MQ131 / 1000);
  
  //Serial.print("DHT Bus Voltage:   "); Serial.print(busvoltage_DHT); Serial.println(" V");
  Serial.print("DHT Shunt Voltage: "); Serial.print(shuntvoltage_DHT); Serial.println(" mV");
  Serial.print("DHT Load Voltage:  "); Serial.print(loadvoltage_DHT); Serial.println(" V");
  Serial.print("DHT Current:       "); Serial.print(current_mA_DHT); Serial.println(" mA");
  Serial.println("");
  
  //Serial.print("Shinyei Bus Voltage:   "); Serial.print(busvoltage_Shinyei); Serial.println(" V");
  Serial.print("Shinyei Shunt Voltage: "); Serial.print(shuntvoltage_Shinyei); Serial.println(" mV");
  Serial.print("Shinyei Load Voltage:  "); Serial.print(loadvoltage_Shinyei); Serial.println(" V");
  Serial.print("Shinyei Current:       "); Serial.print(current_mA_Shinyei); Serial.println(" mA");
  Serial.println("");
  
  //Serial.print("MQ131 Bus Voltage:   "); Serial.print(busvoltage_MQ131); Serial.println(" V");
  Serial.print("MQ131 Shunt Voltage: "); Serial.print(shuntvoltage_MQ131); Serial.println(" mV");
  Serial.print("MQ131 Load Voltage:  "); Serial.print(loadvoltage_MQ131); Serial.println(" V");
  Serial.print("MQ131 Current:       "); Serial.print(current_mA_MQ131); Serial.println(" mA");
  Serial.println("");

  delay(2000);
}
