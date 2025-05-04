BOARD_FQBN=arduino:avr:uno
PORT=/dev/ttyACM0

.PHONY: compile upload

compile:
	arduino-cli compile --fqbn $(BOARD_FQBN) ./sketch

upload:
	arduino-cli upload -p $(PORT) --fqbn $(BOARD_FQBN) ./sketch



