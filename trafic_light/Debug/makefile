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
trafic_light.lss \

FLASH_IMAGE += \
trafic_light.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: trafic_light.elf secondary-outputs

# Tool invocations
trafic_light.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,trafic_light.map -mmcu=atmega32 -o "trafic_light.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

trafic_light.lss: trafic_light.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S trafic_light.elf  >"trafic_light.lss"
	@echo 'Finished building: $@'
	@echo ' '

trafic_light.hex: trafic_light.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex trafic_light.elf  "trafic_light.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: trafic_light.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 trafic_light.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) trafic_light.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
