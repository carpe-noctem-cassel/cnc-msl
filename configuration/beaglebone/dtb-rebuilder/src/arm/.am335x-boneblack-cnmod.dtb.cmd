cmd_src/arm/am335x-boneblack-cnmod.dtb = cpp -Wp,-MD,src/arm/.am335x-boneblack-cnmod.dtb.d.pre.tmp -nostdinc -Iinclude -Isrc/arm -Itestcase-data -undef -D__DTS__ -x assembler-with-cpp -o src/arm/.am335x-boneblack-cnmod.dtb.dts.tmp src/arm/am335x-boneblack-cnmod.dts ; dtc -O dtb -o src/arm/am335x-boneblack-cnmod.dtb -b 0 -i src/arm -d src/arm/.am335x-boneblack-cnmod.dtb.d.dtc.tmp src/arm/.am335x-boneblack-cnmod.dtb.dts.tmp ; cat src/arm/.am335x-boneblack-cnmod.dtb.d.pre.tmp src/arm/.am335x-boneblack-cnmod.dtb.d.dtc.tmp > src/arm/.am335x-boneblack-cnmod.dtb.d
am335x-boneblack-cnmod.o: src/arm/am335x-boneblack-cnmod.dts \
 src/arm/am33xx.dtsi include/dt-bindings/gpio/gpio.h \
 include/dt-bindings/pinctrl/am33xx.h include/dt-bindings/pinctrl/omap.h \
 src/arm/skeleton.dtsi src/arm/am335x-bone-common.dtsi \
 src/arm/am335x-bone-common-pinmux.dtsi \
 src/arm/am335x-boneblack-emmc.dtsi \
 src/arm/am335x-boneblack-nxp-hdmi-audio.dtsi \
 src/arm/am335x-bone-can1.dtsi src/arm/am335x-can1.dtsi \
 src/arm/am335x-bone-i2c2-cape-eeprom.dtsi \
 src/arm/am335x-bone-spi0-spidev.dtsi src/arm/am335x-bone-robot.dtsi \
 src/arm/am335x-bone-ehrpwm1A.dtsi
src/arm/am335x-boneblack-cnmod.dtb: src/arm/.am335x-boneblack-cnmod.dtb.dts.tmp src/arm/am33xx-clocks.dtsi src/arm/tps65217.dtsi
