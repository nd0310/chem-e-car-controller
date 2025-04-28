BOARD_FQBN=arduino:avr:nano
PORT=/dev/tty/ACM0


.PHONY: compile upload

compile:
	arduino-cli compile --fqbn $(BOARD_FQBN) ./sketch

upload:
	arduino-cli upload -p $(PORT) --fqbn $(BOARD_FQBN) ./sketch



