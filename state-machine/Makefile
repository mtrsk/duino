TARGET ?= uno

build:
	@pio -f -c vim run

upload:
	@pio run -e uno -t upload

clean:
	@pio run --target clean

format:
	@find . -regex '.*\.\(cpp\|hpp\)' -exec clang-format -style=file -i {} \;

# Monitor the serial output.
monitor:
	@pio device monitor 


