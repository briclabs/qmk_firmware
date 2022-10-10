# MCU name
MCU = STM32F303

BOOTLOADER = stm32-dfu

# LED Configuration
LED_MATRIX_ENABLE = yes
LED_MATRIX_DRIVER = IS31FL3731

# Build Options
#   comment out to disable the options.
#
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration.
MOUSEKEY_ENABLE = no	# Mouse keys. Not used by this keyboard.
EXTRAKEY_ENABLE = yes	# Audio control and System control.
CONSOLE_ENABLE = no	# Enable hid_listen output. Only turn on when needed. Enabling this makes the kbd unresponsive unless hid_listen is running. Resolved in QMK PR#12576.
COMMAND_ENABLE = yes    # Commands for debug and configuration.
NKRO_ENABLE = yes	# USB Nkey Rollover.
AUDIO_ENABLE = no	# This keyboard doesn't use audio.
