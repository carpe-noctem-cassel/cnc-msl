cmd_src/arm/dra7-evm-lcd10.dtb = cpp -Wp,-MD,src/arm/.dra7-evm-lcd10.dtb.d.pre.tmp -nostdinc -Iinclude -Isrc/arm -Itestcase-data -undef -D__DTS__ -x assembler-with-cpp -o src/arm/.dra7-evm-lcd10.dtb.dts.tmp src/arm/dra7-evm-lcd10.dts ; dtc -O dtb -o src/arm/dra7-evm-lcd10.dtb -b 0 -i src/arm -d src/arm/.dra7-evm-lcd10.dtb.d.dtc.tmp src/arm/.dra7-evm-lcd10.dtb.dts.tmp ; cat src/arm/.dra7-evm-lcd10.dtb.d.pre.tmp src/arm/.dra7-evm-lcd10.dtb.d.dtc.tmp > src/arm/.dra7-evm-lcd10.dtb.d
dra7-evm-lcd10.o: src/arm/dra7-evm-lcd10.dts src/arm/dra7-evm.dts \
 src/arm/dra74x.dtsi src/arm/dra7.dtsi \
 include/dt-bindings/interrupt-controller/arm-gic.h \
 include/dt-bindings/interrupt-controller/irq.h \
 include/dt-bindings/pinctrl/dra.h src/arm/skeleton.dtsi \
 src/arm/omap5-cpu-thermal.dtsi include/dt-bindings/thermal/thermal.h \
 include/dt-bindings/gpio/gpio.h include/dt-bindings/clk/ti-dra7-atl.h \
 src/arm/dra7xx-evm-lcd10.dtsi
src/arm/dra7-evm-lcd10.dtb: src/arm/.dra7-evm-lcd10.dtb.dts.tmp src/arm/dra7xx-clocks.dtsi
