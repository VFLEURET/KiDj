#include <Audio.h>
#include <Wire.h>
#include <battery.h>

#define ACOK 34

static void charger_write(uint8_t reg_add, uint16_t data, uint8_t length)
{
    Wire.beginTransmission(CHARGER_ADD << 1);
    Wire.write(reg_add);
    Wire.write((uint8_t)(data & 0xFF)); 
    if (length > 1)
        Wire.write((uint8_t)(data >> 8)); 
    Wire.endTransmission();    // stop transmitting
}

static void fuel_gauge_write(uint8_t reg_add, uint16_t data, uint8_t length)
{
    Wire.beginTransmission(FUEL_GAUGE_ADD << 1);
    Wire.write(reg_add);
    Wire.write((uint8_t)(data & 0xFF)); 
    if (length > 1)
        Wire.write((uint8_t)(data >> 8)); 
    Wire.endTransmission();    // stop transmitting  
}

static uint16_t fuel_gauge_read(uint8_t reg_add, uint8_t length) 
{
    uint8_t c1, c2 = 0;
    Wire.beginTransmission(FUEL_GAUGE_ADD << 1);
    Wire.write(reg_add);
    c1 = Wire.read();
    if (length > 1)
        c2 = Wire.read();
    Wire.endTransmission();    // stop transmitting  
	return (c1 + (c2 << 8));
}


void init_charger(void) {

    charger_write(CHARGE_OPTION0_ADRR, 0x8202, 2);
    charger_write(CHARGE_OPTION1_ADRR, 0x0211, 2);
    charger_write(MAX_CHARGE_VOLT_ADRR, 8400, 2);
    charger_write(MIN_SYSTEM_VOLT_ADRR, (6200 >> 8) & 0xFF, 1);
    charger_write(CHARGE_CURRENT_ADRR, 1000, 2);
    charger_write(INPUT_CURRENT_ADRR, (2500 >>6), 1);
    //info();
}

void init_fuel(void) {
    uint16_t HibCFG, Status;

    HibCFG = fuel_gauge_read(0xBA, 2);  //Store original HibCFG value

    fuel_gauge_write(0x60, 0x90, 1); // Exit Hibernate Mode step 1
    fuel_gauge_write(0xBA, 0x00, 1);  // Exit Hibernate Mode step 2
    fuel_gauge_write(0x60, 0x00, 1);  // Exit Hibernate Mode step 3

    fuel_gauge_write(0x18, DesignCap, 2);
    fuel_gauge_write(0x1E, IChgTerm, 2);
    fuel_gauge_write(0x3A, VEmpty, 2);
    fuel_gauge_write(0x28, LearnCfg, 2);
    fuel_gauge_write(0x13, FullSocThr, 2);
    fuel_gauge_write(0xDB, ModelCfg, 2);

    //Poll ModelCFG.Refresh(highest bit)
    //until it becomes 0 to confirm IC completes model loading
    do {
        Status = fuel_gauge_read(0xDB, 2);
        delay(10);
    }while(Status & 0x8000);

    fuel_gauge_write(0x38, RComp0, 2);
    fuel_gauge_write(0x39, TempCo, 2);
    fuel_gauge_write(0x12, QRTable00, 2);
    fuel_gauge_write(0x22, QRTable10, 2);
    fuel_gauge_write(0x32, QRTable20, 2);
    fuel_gauge_write(0x42, QRTable30, 2);
    fuel_gauge_write(0xBA, HibCFG, 2);

    Status = fuel_gauge_read(0x00, 2);
    Status = Status & 0xFFFD;
    fuel_gauge_write(0x00, Status, 2);
}

void update_fuel(bool print_flag) {
    uint16_t buffer, volt, Temp, capa, soc;
    int16_t current;
    static uint16_t previous_status, previous_cap, previous_SOC, previous_Volt, previous_Temp;
    static int16_t previous_Current;
    static boolean previous_state_charger;
    boolean state_charger;

    // buffer = fuel_gauge_read(0x00, 2);
    // if (buffer != previous_status) {
    //     previous_status= buffer;
    //     console_printf("Fuel gauge status 0x%04X\r\n", buffer >> 1);
    // }
    state_charger = digitalRead(ACOK);
    if (state_charger != previous_state_charger) {
      Serial.printf("state change %d\r\n", state_charger);
      previous_state_charger = state_charger;
      init_charger();
      //info_charger();
    }

    volt = (fuel_gauge_read(0x19, 2) >> 7 ) & 0x1FF;
    current = (int16_t)(fuel_gauge_read(0x0A, 2))/8;
    //Temp = (fuel_gauge_read(0x16, 2) >> 8) & 0xFF;
    //capa = fuel_gauge_read(0x05, 2);
    soc = (fuel_gauge_read(0x06, 2) >> 8) & 0xFF;
    if ((volt != previous_Volt) ||
        (current != previous_Current) ||
        (Temp != previous_Temp) ||
        (capa != previous_cap) ||
        (soc != previous_SOC)) {
        previous_Volt = volt;
        previous_Current = current;
        previous_Temp = Temp;
        previous_cap = capa;
        previous_SOC = soc;
       /* if (current > 200)
          //led_state(CHARGE_LED);
        else if (soc < 10)
          //led_state(EMPTY_BATT_LED);
        else if (state_charger)
          //led_state(PSU_EXT_LED);
        else
          //led_state(PSU_BATT_LED);
*/
        if (print_flag)
          Serial.printf("Fuel gauge : %d0mV %dmA %d%%\r\n", volt, current, soc);
//          Serial.print("Fuel gauge : %d0mV %dmA %d*C %dmAh %d%%\r\n", volt, current, Temp, capa, soc);
    }
}