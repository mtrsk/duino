ENV ?= uno

build:
	@pio -f -c vim run -c platformio.ini -e $(ENV)

check:
	@find . -regex '.*\.\(cpp\|hpp\)' -exec clang-tidy --config-file=../.clang-tidy {} \;

release:
	@pio -f -c vim run -c platformio.ini -e release

upload:
	@pio run -e uno -t upload -e $(ENV)

clean:
	@pio run --target clean -e $(ENV)

format:
	@find . -regex '.*\.\(cpp\|hpp\)' -exec clang-format -style=file -i {} \;

debug:
	@pio debug --interface=gdb -e $(ENV)

# Monitor the serial output.
monitor:
	@pio device monitor -e $(ENV)


