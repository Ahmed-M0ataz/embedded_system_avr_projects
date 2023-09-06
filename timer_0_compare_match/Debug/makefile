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
timer_0_compare_match.lss \

FLASH_IMAGE += \
timer_0_compare_match.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: timer_0_compare_match.elf secondary-outputs

# Tool invocations
timer_0_compare_match.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,timer_0_compare_match.map -mmcu=atmega32 -o "timer_0_compare_match.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

timer_0_compare_match.lss: timer_0_compare_match.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S timer_0_compare_match.elf  >"timer_0_compare_match.lss"
	@echo 'Finished building: $@'
	@echo ' '

timer_0_compare_match.hex: timer_0_compare_match.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex timer_0_compare_match.elf  "timer_0_compare_match.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: timer_0_compare_match.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 timer_0_compare_match.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) timer_0_compare_match.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
