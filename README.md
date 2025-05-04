# Chem-E-Car Controller
Driver code for the arduino in the Chem-E-Car

## Editing
- Open `sketch/sketch.ino` with a text editor
- or open `sketch` with the arduino ide

## Compiling/Uploading
- Using arduino-cli
  - edit `makefile` and set `PORT` to whatever port the arduino is on  (usually `/dev/ttyACM0`)
  - if needed set the `BOARD_FQBM` to whatever board you are using (Ours is `arduino:avr:uno`)
  -  make sure arduino:avr is installed (run `$ arduino-cli core install arduino:avr`)  
  - run `$ make upload` to upload or `$ make compile` to compile
  - If on linux use `$ cat <arduio-port>` to see the output of the arduino
- Using arduino ide
 - Open `sketch/sketch.ino` file with arduino ide and click upload 

## TODO
- possibly setup ci/cd using wokwi-cli (https://docs.wokwi.com/wokwi-ci/getting-started)

## Circut layout

- Light Sensor Pin: A0
- Motor Pin: D13
- Batery Voltage: TBD

### Light sensor

- 5V to one side of photoresistor
- Other Side of photoresistor to the analog pin
- 10k Ohm resistor between photoresistor and analog pin to ground

```
Arduino 5V ---> [Photoresistor] ---> +--- Analog Pin (e.g., A0)
                                     |
                                     +--- [10k Ohm Resistor] ---> Arduino GND
```



### MOSFET motor controller
This setup uses the MOSFET as a "low-side switch" (between the motor and ground).

1. Connect the Source (S) pin of the FQP30N06 MOSFET to GND on your Arduino. IMPORTANT: You MUST also connect the negative (-) terminal of your separate Motor Power Supply to the same Arduino GND. All grounds must be connected together.
2. Connect the Drain (D) pin of the FQP30N06 MOSFET to one terminal of your DC Motor.
3. Connect the other terminal of the DC Motor to the positive (+) terminal of your separate Motor Power Supply.
4. Connect the Gate (G) pin of the FQP30N06 MOSFET to one leg of the 220 Ohm (or similar) Gate Resistor.
5. Connect the other leg of the 220 Ohm Gate Resistor to a digital output pin on your Arduino (e.g., pin 9).
6. (Optional but Recommended) Connect one leg of the 10k Ohm Pulldown Resistor to the Gate (G) pin of the MOSFET (the same leg the Gate resistor is connected to).
7. (Optional but Recommended) Connect the other leg of the 10k Ohm Pulldown Resistor to GND (the common ground point). This ensures the MOSFET is off when the Arduino pin is low or floating.
8. Connect the Flyback Diode: Connect the diode across the motor terminals. The band (cathode) on the diode should point towards the positive (+) terminal of the Motor Power Supply (where the motor connects to the supply). The non-banded side (anode) connects to the Drain of the MOSFET (where the motor connects to the MOSFET). This diode allows the inductive kickback voltage to safely dissipate when the motor is switched off. 


```
                      +---------------------+
                      | Motor Power Supply  |
                      |       (+)           | -----------------+
                      +---------------------+                  |
                                                               |
                               +-------+                     +---+
                               | Motor |---------------------| D | MOSFET (FQP30N06)
                               +-------+         Motor (-)   +---+
                                   ^                           |
          Flyback Diode (e.g., 1N4001)                         | MOSFET Source (S)
          (Band/Cathode) >---+  (Anode) <---+                  |
                             |              |                  |
                             |              |                  |
                             |              |                  | Common GND
                             |              |                  |
                             |              |                  |
+--------------------------+ | +------------+--------------+ | +-------------------------------+
|                          | | |            |              | | |                               |
|  Arduino                 | | |            |              | | |  Motor Power Supply (-)       |
|                          | | |            |              | | |          (Connects to GND)    |
|                 Digital  | | |  R_Gate    |   R_Pulldown | | |                               |
|                 Pin (e.g. 9) o--[~220R]---+---[~10kR]-----+---o GND                          |
|                          | |              |              | | |                               |
|                          | |              +--- MOSFET Gate (G)                               |
|                          | |                                                                 |
+--------------------------+ +-----------------------------------------------------------------+

```
