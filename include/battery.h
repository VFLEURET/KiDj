#ifndef __BATTERY_H
#define __BATTERY_H

#define CHARGER_ADD (uint8_t)(0x6A)

#define CHARGE_OPTION0_ADRR         0x00
#define CHARGE_OPTION0_LENGTH       (2)

#define CHARGE_OPTION1_ADRR         0x02
#define CHARGE_OPTION1_LENGTH       (2)

#define CHARGE_OPTION2_ADRR         0x10
#define CHARGE_OPTION2_LENGTH       (2)

#define PROCHOT_OPTION0_ADRR        0x04
#define PROCHOT_OPTION0_LENGTH      (2)

#define PROCHOT_OPTION1_ADRR        0x06
#define PROCHOT_OPTION1_LENGTH      (2)

#define CHARGE_CURRENT_ADRR         0x0A
#define CHARGE_CURRENT_LENGTH       (2)

#define MAX_CHARGE_VOLT_ADRR        0x0C
#define MAX_CHARGE_VOLT_LENGTH      (2)

#define MIN_SYSTEM_VOLT_ADRR        0x0E
#define MIN_SYSTEM_VOLT_LENGTH      (1)

#define INPUT_CURRENT_ADRR          0x0F
#define INPUT_CURRENT_LENGTH        (1)

#define FUEL_GAUGE_ADD (uint8_t)(0x36)

#define ModelCfg        0x0400
#define DesignCap       0x1E00
#define FullCapNom      0x1E00
#define FullCapRep      0x26AF
#define FullSocThr      0x5F00
#define IChgTerm        0x0300
#define LearnCfg        0x44B6
#define QRTable00       0x1050
#define QRTable10       0x2013
#define QRTable20       0x0199
#define QRTable30       0x0A7F
#define RComp0          0x0700
#define TempCo          0x223E
#define VEmpty          0xA561
#define Config2         0x3658



void init_charger(void);
void info_charger(void);
void init_fuel(void);
void update_fuel(bool print_flag);


#endif
