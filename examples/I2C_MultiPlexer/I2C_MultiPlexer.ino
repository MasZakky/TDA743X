#include "TDA743X.h"

TDA7430 uPA;
//TDA7431 uPA;
//TDA7432 uPA;
//TDA7433 uPA;
//TDA7434 uPA;
//TDA7435 uPA;
//TDA7437 uPA;
//TDA7438 uPA;
//TDA7439 uPA;

/*   ___________      ______      _____________       _____________          ___________
 *  | uC / uP   |    |5/3.3v|    |             |     | +5V / +3.3V |        | TDA7430[0]| SALVE 1 ~ n
 *  |       SCL |====| PulUp|===>| SCL    SCL1 |<====|  PulUp      |=======>| SCL       |
 *  |       SDA |<===| PulUp|===>| SDA    SDA1 |<====|  PulUp      |=======>| SDA       |
 *  |           |    |______|    |             |     |_____________|        |___________|
 *  |           |                |    T        |     | +5V / +3.3V |        | TDA7430[1]| SALVE 1 ~ n
 *  |___________|                |    C   SCL2 |<====|  PulUp      |=======>| SCL       |
 *                               |    A   SDA2 |<====|  PulUp      |=======>| SDA       |
 *                               |    9        |     |_____________|        |___________|
 *                               |    5        |     | +5V / +3.3V |        | TDA7430[2]| SALVE 1 ~ n
 *                               |    4   SCL3 |<====|  PulUp      |=======>| SCL       |
 *                               |    8   SDA3 |<====|  PulUp      |=======>| SDA       |
 *                               |    A        |     |_____________|        |___________|
 *                               |             |     | +5V / +3.3V |        | TDA7430[3]| SALVE 1 ~ n
 *                               |        SCL4 |<====|  PulUp      |=======>| SCL       |
 *                               |        SDA4 |<====|  PulUp      |=======>| SDA       |
 *                               |             |     |_____________|        |___________|
 *                               |             |     | +5V / +3.3V |        | TDA7430[4]| SALVE 1 ~ n
 *                               |        SCL5 |<====|  PulUp      |=======>| SCL       |
 *                               |        SDA5 |<====|  PulUp      |=======>| SDA       |
 *                               |             |     |_____________|        |___________|
 *                               |             |     | +5V / +3.3V |        | TDA7430[5]| SALVE 1 ~ n
 *                               |        SCL6 |<====|  PulUp      |=======>| SCL       |
 *                               |        SDA6 |<====|  PulUp      |=======>| SDA       |
 *                               |             |     |_____________|        |___________|
 *                               |             |     | +5V / +3.3V |        | TDA7430[6]| SALVE 1 ~ n
 *                               |        SCL7 |<====|  PulUp      |=======>| SCL       |
 *                               |        SDA7 |<====|  PulUp      |=======>| SDA       |
 *                               |             |     |_____________|        |___________|
 *                               |             |     | +5V / +3.3V |        | TDA7430[7]| SALVE 1 ~ n
 *                               |        SCL8 |<====|  PulUp      |=======>| SCL       |
 *                               |        SDA8 |<====|  PulUp      |=======>| SDA       |
 *                               |_____________|     |_____________|        |___________|
 */



void setup() {
  Wire.begin();
  uPA.begin(0x80);
  uPA.InstalWire(&Wire);
  // Instal Wire

  uPA.setMultiPlexer(Yes_UseSwitch,Use_TCA9548A);
  //                 Value        ,Name IC
  // Default => No_UseSwitch 
  // Value   => No_UseSwitch or Yes_UseSwitch
  
  uPA.setAddressMultiPlexer(0x70   ,0 ,0 ,0 ,0);
  //                        Address,A0,A1,A2,0
  
  uPA.setChannel(0);
  //             Value
  // Value => 0 ~ 7 

}

void loop() {
  // put your main code here, to run repeatedly:
}
