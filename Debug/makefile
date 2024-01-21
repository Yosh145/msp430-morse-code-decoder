################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./adc12_b.obj" \
"./aes256.obj" \
"./comp_e.obj" \
"./crc.obj" \
"./crc32.obj" \
"./cs.obj" \
"./dma.obj" \
"./esi.obj" \
"./eusci_a_spi.obj" \
"./eusci_a_uart.obj" \
"./eusci_b_i2c.obj" \
"./eusci_b_spi.obj" \
"./framctl.obj" \
"./gpio.obj" \
"./lcd_c.obj" \
"./main.obj" \
"./mpu.obj" \
"./mpy32.obj" \
"./pmm.obj" \
"./ram.obj" \
"./ref_a.obj" \
"./rtc_b.obj" \
"./rtc_c.obj" \
"./sfr.obj" \
"./sysctl.obj" \
"./timer_a.obj" \
"./timer_b.obj" \
"./tlv.obj" \
"./wdt_a.obj" \
"./myfunctions/myClocksWithCrystals.obj" \
"./myfunctions/myGpio.obj" \
"./myfunctions/myLcd.obj" \
"../lnk_msp430fr6989.cmd" \
$(GEN_CMDS__FLAG) \
-llibmpu_init.a \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include myfunctions/subdir_vars.mk
-include subdir_rules.mk
-include myfunctions/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
ECE796FinalProject.out \

EXE_OUTPUTS__QUOTED += \
"ECE796FinalProject.out" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "ECE796FinalProject.out"

# Tool invocations
ECE796FinalProject.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --advice:power=all --advice:hw_config=all --define=__MSP430FR6989__ --define=_MPU_ENABLE -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 -z -m"ECE796FinalProject.map" --heap_size=160 --stack_size=160 --cinit_hold_wdt=on -i"C:/ti/ccs1250/ccs/ccs_base/msp430/include" -i"C:/ti/ccs1250/ccs/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"C:/ti/ccs1250/ccs/ccs_base/msp430/lib/FR59xx" -i"C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/lib" -i"C:/ti/ccs1250/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --priority --reread_libs --define=_MPU_ENABLE --diag_wrap=off --display_error_number --warn_sections --xml_link_info="ECE796FinalProject_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "ECE796FinalProject.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)
	-$(RM) "adc12_b.obj" "aes256.obj" "comp_e.obj" "crc.obj" "crc32.obj" "cs.obj" "dma.obj" "esi.obj" "eusci_a_spi.obj" "eusci_a_uart.obj" "eusci_b_i2c.obj" "eusci_b_spi.obj" "framctl.obj" "gpio.obj" "lcd_c.obj" "main.obj" "mpu.obj" "mpy32.obj" "pmm.obj" "ram.obj" "ref_a.obj" "rtc_b.obj" "rtc_c.obj" "sfr.obj" "sysctl.obj" "timer_a.obj" "timer_b.obj" "tlv.obj" "wdt_a.obj" "myfunctions\myClocksWithCrystals.obj" "myfunctions\myGpio.obj" "myfunctions\myLcd.obj" 
	-$(RM) "adc12_b.d" "aes256.d" "comp_e.d" "crc.d" "crc32.d" "cs.d" "dma.d" "esi.d" "eusci_a_spi.d" "eusci_a_uart.d" "eusci_b_i2c.d" "eusci_b_spi.d" "framctl.d" "gpio.d" "lcd_c.d" "main.d" "mpu.d" "mpy32.d" "pmm.d" "ram.d" "ref_a.d" "rtc_b.d" "rtc_c.d" "sfr.d" "sysctl.d" "timer_a.d" "timer_b.d" "tlv.d" "wdt_a.d" "myfunctions\myClocksWithCrystals.d" "myfunctions\myGpio.d" "myfunctions\myLcd.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

