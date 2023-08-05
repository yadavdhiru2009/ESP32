/*
Author:dharmendra Kumar Yadav
*/

#define vRef 3.30
#define ADC_Resolution 4095
#define LM35_Per_Degree_Volt 0.01
#define Zero_Deg_ADC_Value 879.00

const int lm35_pin = A0;                /* Connect LM35 out pin to A0 of ESP32*/
float _temperature, temp_val, ADC_Per_Degree_Val;
int temp_adc_val;

void setup(void){
  Serial.begin(9600);
  ADC_Per_Degree_Val = (ADC_Resolution/vRef)*LM35_Per_Degree_Volt;
}

void loop(void){ 
  for (int i = 0; i < 10; i++) {
    temp_adc_val += analogRead(lm35_pin);  /* Read ADC value */
    delay(10);
  }
  temp_adc_val = temp_adc_val/10.0;

  temp_adc_val = temp_adc_val - Zero_Deg_ADC_Value;
  temp_adc_val=(temp_adc_val/ADC_Per_Degree_Val);
  Serial.print("LM35 Temperature = ");
  Serial.print(temp_adc_val);           /* Print Temperature on the serial window */
  Serial.print("°C\n");
  delay(100);
}