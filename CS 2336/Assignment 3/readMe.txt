How to Run:

Unzip and extract all three .java files (Assignment3.java, Triangle.java, GeometricObject.java).

Make sure terminal is in the correct folder before running

Run main (Assignment3.java)

Pseudocode:

PROGRAM Start (main method):

Create a list for 100 Triangles

Loop:

Call displayMenu() and get user's choice (1-4)

Use a switch statement on the choice:

Case 1: Call createTriangle()

Case 2: Call printSortedTriangles()

Case 3: Call printByColor()

Case 4: Print "Goodbye!"


Keep looping until choice is 4


FUNCTION displayMenu():

Print all menu options (1-4)

Loop:

Call getValidInt() to get a choice

If choice is between 1 and 4, return the choice

If not, print an error and loop again


FUNCTION createTriangle():

If triangle list is full, print error and exit function

Call getValidDouble() 3 times for s1, s2, s3

Call getValidInt() for color

TRY:

If s1, s2, or s3 is 0, create a default Triangle()

Else, create a new Triangle(s1, s2, s3, color)

Add the new triangle to the list

Increment the count of triangles

CATCH (IllegalArgumentException):

Print the error message (e.g., "Sides cannot be negative")

Tell the user the triangle was not added


FUNCTION printSortedTriangles():

If triangle count is 0, print "No triangles" and exit

Create a new, smaller array (size = triangleCount)

Copy all triangles from the big list to the small array

Use Arrays.sort() on the small array (Java will use Triangle's compareTo method)

Call printHeader()

Loop through the sorted small array and call printTriangle() for each one


FUNCTION printByColor():

If triangle count is 0, print "No triangles" and exit

Loop:

Call getValidInt() to get a color choice

If color is between 1 and 7, break loop

If not, print error and loop again

Call printHeader()

Loop through the main triangle list from 0 to triangleCount:

If a triangle's color matches the chosen color, call printTriangle()

FUNCTION getValidDouble(prompt):

Loop:

Print the prompt

If user input is a double, read it and return it

If not, print error and clear the bad input


FUNCTION getValidInt(prompt):

Loop:

Print the prompt

If user input is an int, read it and return it

If not, print error and clear the bad input