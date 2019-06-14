
.PHONY: all
all: emulib gameboy

.PHONY: emulib
emulib:
	make -C emucore/

.PHONY: gameboy
gameboy: emulib
	make -C gameboy/

.PHONY: clean
clean:
	make -C gameboy/ clean
	make -C emucore/ clean
