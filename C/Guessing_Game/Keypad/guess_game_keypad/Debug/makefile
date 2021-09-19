################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include keypad/subdir.mk
-include MCAL/subdir.mk
-include LCD/subdir.mk
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
guess_game_keypad.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: guess_game_keypad.elf secondary-outputs

# Tool invocations
guess_game_keypad.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,guess_game_keypad.map -mmcu=atmega16 -o "guess_game_keypad.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

guess_game_keypad.lss: guess_game_keypad.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S guess_game_keypad.elf  >"guess_game_keypad.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: guess_game_keypad.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 guess_game_keypad.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) guess_game_keypad.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
