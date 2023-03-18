# Particle Argon LED Status

This guide explains the different LED light patterns that the Particle Argon device displays for various modes.

## Standard Modes
- Breathing cyan: device is connected to the internet
- Blinking magenta: device is updating its firmware or loading an app
- Blinking green: device is trying to connect to Wi-Fi
- Rapidly blinking cyan: device is in the process of connecting to the cloud
- Breathing white: Wi-Fi module is off
- Breathing magenta: device is in safe mode and not running any application firmware

## Listening Mode
- Blinking blue: device is in listening mode and waiting for mesh network configuration
- Rapidly blinking blue: erases stored network settings on the device

## DFU Mode (Device Firmware Upgrade)

- Flashing yellow: triggers the on-board bootloader that accepts firmware binary files via dfu-util

## Troubleshooting Modes

The troubleshooting modes are used to identify and troubleshoot issues that your device might be experiencing. These modes can help you diagnose and resolve problems with your device quickly and efficiently.

### Cloud Not Connected

If your device is connected to Wi-Fi but not to the cloud, it will be breathing green.
For more information, consult the Particle Device Cloud documentation.

### Rainbows/Nyan

Using the Signal option in the Web IDE or the particle cloud nyan CLI command, you can display a rainbow pattern on a device's status LED. This is useful when you have multiple devices nearby and are not sure which one is which.

### Red Blink Basic Errors

Blinking red indicates various errors. While connecting to the cloud, the RGB LED will be blinking cyan followed by:

- 1 orange blink: Decryption error.
- 2 orange blinks: Could not reach the internet.
- 3 orange blinks: Connected to the internet, but could not reach the Particle Device Cloud. This sometimes is seen as yellow or red and indicates bad server keys.
- 1 magenta blink: Authentication error.
- 1 red blink: Generic handshake error. The device could have the wrong keys or has just encountered a generic error in the handshake process.
For repair instructions, consult the Particle Device Cloud documentation.

### Red Flash SOS

If your device is blinking red, it's likely that the firmware has crashed. The pattern is 3 short blinks, 3 long blinks, 3 short blinks (SOS pattern), followed by a number of blinks that depend on the error, then the SOS pattern again.

To recover from this issue, enter safe mode, tweak your firmware, and try again. Follow the reset instructions provided in the Particle Device Cloud documentation.

There are a number of other red blink codes that may be expressed after the SOS blinks. Some of the most common ones include:

- Hard fault (1 blink between 2 SOS patterns)
- Exit (7 blinks between 2 SOS patterns)
- Out of heap memory (8 blinks between 2 SOS patterns)
- Assertion failure (10 blinks between 2 SOS patterns)
- Stack overflow (13 blinks between 2 SOS patterns)
- Heap error (14 blinks between 2 SOS patterns)
- For more information on these errors and how to troubleshoot them, consult the Particle Device Cloud documentation.

### Solid Colors

Solid colors are rare and are usually the result of a bug. The only expected situation is a solid magenta color if you are loading code in ymodem serial mode.

For more information on how to troubleshoot solid colors, consult the Particle Device Cloud documentation.