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
led_blenk_lab.lss \

FLASH_IMAGE += \
led_blenk_lab.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: led_blenk_lab.elf secondary-outputs

# Tool invocations
led_blenk_lab.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,led_blenk_lab.map -mmcu=atmega32 -o "led_blenk_lab.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

led_blenk_lab.lss: led_blenk_lab.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S led_blenk_lab.elf  >"led_blenk_lab.lss"
	@echo 'Finished building: $@'
	@echo ' '

led_blenk_lab.hex: led_blenk_lab.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex led_blenk_lab.elf  "led_blenk_lab.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: led_blenk_lab.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 led_blenk_lab.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) led_blenk_lab.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
