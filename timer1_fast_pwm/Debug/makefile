################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
timer1_fast_pwm.lss \

FLASH_IMAGE += \
timer1_fast_pwm.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: timer1_fast_pwm.elf secondary-outputs

# Tool invocations
timer1_fast_pwm.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,timer1_fast_pwm.map -mmcu=atmega32 -o "timer1_fast_pwm.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

timer1_fast_pwm.lss: timer1_fast_pwm.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S timer1_fast_pwm.elf  >"timer1_fast_pwm.lss"
	@echo 'Finished building: $@'
	@echo ' '

timer1_fast_pwm.hex: timer1_fast_pwm.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex timer1_fast_pwm.elf  "timer1_fast_pwm.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: timer1_fast_pwm.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 timer1_fast_pwm.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) timer1_fast_pwm.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
