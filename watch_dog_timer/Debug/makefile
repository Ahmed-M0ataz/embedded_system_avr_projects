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
watch_dog_timer.lss \

FLASH_IMAGE += \
watch_dog_timer.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: watch_dog_timer.elf secondary-outputs

# Tool invocations
watch_dog_timer.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,watch_dog_timer.map -mmcu=atmega32 -o "watch_dog_timer.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

watch_dog_timer.lss: watch_dog_timer.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S watch_dog_timer.elf  >"watch_dog_timer.lss"
	@echo 'Finished building: $@'
	@echo ' '

watch_dog_timer.hex: watch_dog_timer.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex watch_dog_timer.elf  "watch_dog_timer.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: watch_dog_timer.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 watch_dog_timer.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) watch_dog_timer.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
