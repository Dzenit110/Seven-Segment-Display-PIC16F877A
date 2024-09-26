## Seven-Segment-Display-PIC16F877A

Here are the tasks and smaller projects involving the 7-segment display. All three smaller tasks (projects) are briefly described.
## Microcontroller - 7 - Segment Display the digits from 0 to 9 and in reverse

This C and assembly code for a microcontroller enables displaying numbers on a 7-segment display. (Flowcode)
## Features

- **Initialization**: Configures necessary registers for operation.
- **Number Display**: Sets the initial value of `FCV_BROJ` to 0 and shows the current number on the display every second.
- **Counting Cycle**: When the number reaches 9, it decrements to 0, then increments again.

The program continuously repeats this process. An interrupt routine is defined but not implemented.

<br>

## 7-Segment Display Counter (0-9)

This C code for a microcontroller implements a simple counter displayed on a 7-segment display.

## Functionality

- **Initialization**: Configures the necessary registers and sets the initial value of the counter (`FCV_BROJAC`) to 0.
- **Infinite Loop**: Continuously displays the current value of the counter.
- **Counting Logic**: Increments the counter by 1 every second until it reaches 9, at which point it resets back to 0.

The program creates a simple up-counter that cycles between 0 and 9 on the 7-segment display.

<br>

## 7-Segment Display Up/Down Counter With Up and Down Buttons

This C code for a microcontroller implements an up/down counter displayed on a 7-segment display.

## Functionality

- **Initialization**: Sets the initial value of the counter (`FCV_BROJAC`) to 5 and configures button inputs for incrementing and decrementing the counter.
- **Infinite Loop**: Continuously checks the state of two buttons (Up and Down):
  - **Up Button**: Increments the counter by 1 each time the button is pressed, wrapping around to 0 when the counter exceeds 9.
  - **Down Button**: Decrements the counter by 1 each time the button is pressed, wrapping around to 9 when the counter reaches 0.
- **Display Update**: The current counter value is shown on the 7-segment display after each button press.

This program allows for interactive counting within the range of 0 to 9, controlled by user input.

<br>

## User Interface Examples

<img width="730" alt="seg1" src="https://github.com/user-attachments/assets/8f15943a-1dfc-4189-aa21-2b8f2c5c75cb">
<br>
Figure 1  Segment Display the digits from 0 to 9 and in reverse (Flowcode - Simulation)

<br><br>

<img width="771" alt="seg2" src="https://github.com/user-attachments/assets/e5315dac-d6a0-4399-8166-a19b308a15f5">

<br>

Figure 2  Segment Display the digits from 0 to 9 and in reverse, display implementation of further counting (Display Counter)

<br><br>

<img width="772" alt="rucno1" src="https://github.com/user-attachments/assets/49bb63d6-937e-4ca8-9bb5-4c58fc2f3ca5">

<br>

Figure 3  Up/down counter displayed on a 7-Segment Display (Flowcode)

<br><br>

<img width="794" alt="ruc2" src="https://github.com/user-attachments/assets/ff475f81-cc3e-4ec2-9eab-3dbfe00503e8">

<br>

Figure 4 Up/Down Counter displayed on a 7-Segment Display (Flowcode) simulation display



<br><br>

## 🧰 Languages & Tools 

<div style="display: inline;">
    <img src="https://skillicons.dev/icons?i=arduino,cpp"style="margin-right: 10px;" />
    <img src="https://github.com/user-attachments/assets/c53560da-cbab-4f95-89c7-f80b95beca2c" width="47" height="47" />
    <img src="https://github.com/user-attachments/assets/f29a2b13-cfc7-4e15-a0b6-1180dc7ba9ca" width="70" height="70"  &nbsp; &nbsp; >
    <img src="https://github.com/user-attachments/assets/cf1d8532-3d73-4eed-9139-c02b9aa10ddb" width="65" height="65" &nbsp; &nbsp;/>
    <img src="https://github.com/user-attachments/assets/906cc158-0e38-420f-b0b4-64fc227677e7" width="65" height="65" &nbsp; &nbsp;/>

</div>
