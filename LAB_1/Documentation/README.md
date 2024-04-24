# ECE16 Lab 1 Report #
## Camille Phares 4/14/2024 ##
[Tutorial 2](https://docs.google.com/document/d/1DbRq9kKQD4QH2wAT2ptI-NIDW1gkpW3JhiZ4eN19LFw/edit) was on digitally reading and writing with buttons and LEDs. I set up the arduino to light up the built-in LED 
when I hit the push button, and then I set it up to blink an LED. 
[Tutorial 3](https://docs.google.com/document/d/1GS6T4dkxKuKogOQRAuzY6sgiHNudb0nfYY3tG7wNvEc/edit) was on serial communication-- using the serial monitor and reading and writing with it. \
**Challenge 1** was on blinking an LED.
**Part 1** I had the light turn on and off such that each on/off cycle would take 1/the required number of Hz of a second \ 
a. Blink a red LED at 1 Hz \
![c1_part1_a](https://github.com/flowerwallpaper/ECE_16_Camille_Final/blob/main/LAB_1/Documentation/figs/c1_part1_a.gif) \
b. Blink a blue LED at 5 Hz \
![c1_part1_b](https://github.com/flowerwallpaper/ece16-assignment-flowerwallpaper/assets/103080777/c5579636-3641-4c36-9255-a8045c634e13) \
c. Blink a yellow LED at 10 Hz \
![c1_part1_c](https://github.com/flowerwallpaper/ece16-assignment-flowerwallpaper/assets/103080777/c53eea24-f9fd-49f5-8302-78530225ccc6) \
**Part 2** I set the light to be on and off for the required amount of time \
a. Blink a red LED with 1s on and 100ms off \
![c1_part2_a](https://github.com/flowerwallpaper/ece16-assignment-flowerwallpaper/assets/103080777/a2bf3be3-c5a2-4197-83e9-7d0adae014c1) \
b. Blink a blue LED with 200ms on and 50ms off \
![c1_part2_b](https://github.com/flowerwallpaper/ece16-assignment-flowerwallpaper/assets/103080777/2b7980f4-6e57-4fc7-bc33-0d1542b22137) \
c. Blink a yellow LED with 20ms on and 10ms off \
![c1_part2_c](https://github.com/flowerwallpaper/ece16-assignment-flowerwallpaper/assets/103080777/135b4715-c276-4f26-a6c9-4a1df9070638) \

**Challenge 2** involves creating a stopwatch, and printing the count in seconds every 100 ms. My code checks to see if the button has been pushed, whether that starts or stops the stopwatch, and iterates or doesn't iterate count, and prints count every 100 ms. \
![c2](https://github.com/flowerwallpaper/ece16-assignment-flowerwallpaper/assets/103080777/b1900976-2867-4613-b678-e2528aa60d04) \

**Challenge 3** involves counting the number of button pushes, and decrementing every second if the button hasn't been pushed for three seconds. My code increments count when the button is pushed, and checks to see if it has been pushed in the last three seconds. If it hasn't, count is decremented once per second. Count is printed every 100 ms.

![c3](https://github.com/flowerwallpaper/ece16-assignment-flowerwallpaper/assets/103080777/00e481cd-d24c-428a-9cf3-affd140f3d1c)




