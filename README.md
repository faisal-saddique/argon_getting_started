# Getting Started with Particle Argon

The Particle Argon is a powerful Wi-Fi and BLE enabled development board that can be programmed with Particle's cloud-based software platform. This guide will walk you through the steps to get started with your Particle Argon.

## Prerequisites

Before getting started, you will need the following:

- A Particle Argon board
- A USB cable
- A computer with an internet connection
- 

## Step 1: Set up your Particle account

1. If you don't already have one, create a Particle account at https://login.particle.io/signup.
2. Verify your email address by clicking the link in the email you receive from Particle.

## Step 2: Set up your Particle Argon

1. Connect your Particle Argon to your computer using the USB cable.
2. Put your Particle Argon into listening mode by holding down the "MODE" button until the RGB LED starts blinking blue.
3. In a web browser, navigate to https://setup.particle.io.
4. Follow the instructions on the page to set up your Particle Argon and connect it to Wi-Fi.
5. You can also follow this video to setup your Particle Argon.
[![A Video guide on setting up Particle Argon](https://img.youtube.com/vi/xK20wrWDduQ/0.jpg)](https://www.youtube.com/watch?v=xK20wrWDduQ)

## Step 3: Use the Official Web IDE to program Particle Argon

1. In a web browser, navigate to https://build.particle.io/build/new to access the Particle Web IDE.
2. Log in to your Particle account.
3. Click on the "Libraries" tab and add any necessary libraries for your project.
4. Create a new project by clicking on the "Create New App" button.
5. Write your code in the editor and save the file.
6. Click the "Devices" button in the left-hand navigation pane and select your Particle Argon.
7. Click the "Flash" button to flash the code to your Particle Argon.
8. The RGB LED on your Particle Argon should now be breathing cyan, indicating that your board is connected to the internet.

## Step 4: Use VS Code Workbench

1. Download and install the Particle Workbench extension for VS Code from the VS Code Marketplace.
2. Open VS Code and log in to your Particle account using the extension.
3. Click on the "Particle: Create New Project" button in the VS Code command palette.
4. Select the "argon" device type and follow the prompts to create a new project.
5. Write your code in the editor and save the file.
6. Click the "Particle: Flash application (local)" button in the VS Code command palette to flash the code to your Particle Argon.
7. The RGB LED on your Particle Argon should now be breathing cyan, indicating that your board is connected to the internet.

Congratulations, you have successfully set up your Particle Argon and programmed it to blink an LED! This is just the beginning of what you can do with your Particle Argon, so keep exploring and have fun!

<br>

# Getting started with Bluefruit Connect App (for testing BLE communication)

## Steps for setting up the app

1. Download the App: Download and install the Adafruit Bluefruit Connect App from your device's app store. The app is available for both Android and iOS devices.
2. Connect your device: Make sure your Bluetooth is turned on and connect your device to the app. Once you open the app, tap the Connect button and select your device from the list of available devices.
3. Explore the App: Once connected, you can explore the various features of the app. The app has several modes, including UART, Controller, and Color Picker.
4. UART Mode: This mode allows you to send and receive data over Bluetooth. You can send text or data to your device and receive data back. To use this mode, you need to set up a UART service on your device. The app has a built-in Terminal feature that allows you to send and receive data. I won't go into the details of the other modes as we won't need them.

## Steps for testing the /codes/4_working_demo_combining_above_all/4_working_demo_combining_above_all.cpp file

To test this code with the Bluefruit Connect app, you will need to follow these steps:

1. Connect your Particle device to your computer using a USB cable.
2. Open the Particle Web IDE and create a new project.
3. Copy and paste the code you want to test into the code editor in the Web IDE.
4. Add the necessary libraries to your project. In this case, we don't have to install any additional libraries.
5. Verify and flash the code to your Particle device.
6. Once the code has been flashed to your device, disconnect the device from your computer.
7. Open the Bluefruit Connect app on your mobile device.
8. Turn on Bluetooth on your mobile device.
9. Select "UART" from the list of available connections in the Bluefruit Connect app.
10. Select your Particle device from the list of available devices in the Bluefruit Connect app.
11. Once connected, you will be able to send and receive data over Bluetooth using the Bluefruit Connect app.
12. To test the code, send the command "ON" or "OFF" to turn the LED on or off, respectively. You should see the LED turn on or off in response to the command.
13. You can also send and receive data in JSON format by modifying the "loop" function in the code. The current implementation sends random temperature and humidity values every 2 seconds. You can modify this to send whatever data you want. To receive data, you will need to modify the "onDataReceived" function in the code to parse the data you receive over BLE.

This code sets up a BLE (Bluetooth Low Energy) service that can send and receive data from a mobile device. The BLE service has two characteristics, one for transmitting data and one for receiving data. When data is received over BLE, the code converts the data to a string and filters out non-alphanumeric characters. If the received data is "ON", the code turns on an LED, and if the received data is "OFF", the code turns off the LED. The code also generates random temperature and humidity values every 2 seconds, formats them in JSON format, and sends them over BLE. The code continuously checks for a BLE connection, and if there is one, it sends the temperature and humidity data.