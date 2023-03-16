## Getting Started with Particle Argon

The Particle Argon is a powerful Wi-Fi and BLE enabled development board that can be programmed with Particle's cloud-based software platform. This guide will walk you through the steps to get started with your Particle Argon.

## Prerequisites

Before getting started, you will need the following:

- A Particle Argon board
- A USB cable
- A computer with an internet connection

## Step 1: Set up your Particle account

1. If you don't already have one, create a Particle account at https://login.particle.io/signup.
2. Verify your email address by clicking the link in the email you receive from Particle.

## Step 2: Set up your Particle Argon

1. Connect your Particle Argon to your computer using the USB cable.
2. Put your Particle Argon into listening mode by holding down the "MODE" button until the RGB LED starts blinking blue.
3. In a web browser, navigate to https://setup.particle.io.
4. Follow the instructions on the page to set up your Particle Argon and connect it to Wi-Fi.

## Step 3: Install Particle CLI

1. Download and install the Particle CLI tool by following the instructions for your operating system at https://docs.particle.io/tutorials/developer-tools/cli/.
2. Open a terminal or command prompt and run the command particle login to log in to your Particle account.

## Step 4: Blink an LED

1. Create a new directory for your project.
2. In the terminal, navigate to the new directory.
3. Run the command particle create argon to create a new Particle Argon project.
4. Run the command cd argon to navigate into the project directory.
5. Run the command particle compile argon . to compile the project code.
6. Run the command particle flash --serial argon . to flash the code to your Particle Argon.
7. The RGB LED on your Particle Argon should now be blinking green, indicating that your code is running.

Congratulations, you have successfully set up your Particle Argon and programmed it to blink an LED! This is just the beginning of what you can do with your Particle Argon, so keep exploring and have fun!