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
switch_on_or_off.lss \

FLASH_IMAGE += \
switch_on_or_off.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: switch_on_or_off.elf secondary-outputs

# Tool invocations
switch_on_or_off.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,switch_on_or_off.map -mmcu=atmega32 -o "switch_on_or_off.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

switch_on_or_off.lss: switch_on_or_off.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S switch_on_or_off.elf  >"switch_on_or_off.lss"
	@echo 'Finished building: $@'
	@echo ' '

switch_on_or_off.hex: switch_on_or_off.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex switch_on_or_off.elf  "switch_on_or_off.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: switch_on_or_off.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 switch_on_or_off.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) switch_on_or_off.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
