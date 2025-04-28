# Chem-E-Car Controller
Driver code for the arduino in the Chem-E-Car

## Editing
- Open `sketch/sketch.ino` with a text editor
- or open `sketch` with the arduino ide

## Compiling/Uploading
- Using arduino-cli
  - edit `makefile` and set `PORT` to whatever port the arduino is on
  - if needed set the `BOARD_FQBM` to whatever board you are using
  -  make sure arduino:avr is installed (run `$ arduino-cli core install arduino:avr`)  
  - run `$ make upload` to upload or `$ make compile` to compile
- Using arduino ide
 - Open `sketch` folder with arduino ide and click upload 

# TODO
- possibly setup ci/cd using wokwi-cli (https://docs.wokwi.com/wokwi-ci/getting-started)
