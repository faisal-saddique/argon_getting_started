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

1. Download the App: Download and install the Adafruit Bluefruit Connect App from your device's app store. The app is available for both Android and iOS devices.
2. Connect your device: Make sure your Bluetooth is turned on and connect your device to the app. Once you open the app, tap the Connect button and select your device from the list of available devices.
3. Explore the App: Once connected, you can explore the various features of the app. The app has several modes, including UART, Controller, and Color Picker.
4. UART Mode: This mode allows you to send and receive data over Bluetooth. You can send text or data to your device and receive data back. To use this mode, you need to set up a UART service on your device. The app has a built-in Terminal feature that allows you to send and receive data. I won't go into the details of the other modes as we won't need them.