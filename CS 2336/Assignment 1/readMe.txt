How to run:
Execute Java code by pressing "Run Java"

Sample Test Case:

Test Case 1:

1. Picked option 5. Convert Inch to Centimeters.
2. Inputted -50, Outputted Error Message for Invalid Input (value must be positive)
3. Inputted 50
4. Outputted Display Message with Calculated Centimeters: 127.00cm.

Test Case 2:

1. Picked option 1. Convert Fahrenheit to Celsius.
2. Inputted -10, Valid Input because Degrees can be negative.
3. Outputted Display Message with Calculated Celsius: -23.33 degrees Celsius.


Psuedocode:

Start
Call Method Menu in Main Method
Output Menu options
Get User Input
Store User input into integar variable Choice
Check if User input is valid, Number must be in range of 1-7
Call Method MenuChoice and input Users choice as an parameter
Close scanner input

Method MenuChoice create a new scanner input
If else statement, check user input and depending on integar value run the block associated
For conversions for lengths/weights, check if user input is negative
Call Menu method again after calculating conversion to loop program

End program if user picks option 7, System Exit.

