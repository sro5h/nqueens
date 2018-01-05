# Test cases
Each test case starts by opening the program with the default settings unless
further mentioned.

## Case 1
* 'Exit'
=> Program exits

## Case 2
* 'Begin'
=> Steps through solutions

## Case 3
* 'Save mode'
=> Toggles save mode, save mode on

## Case 4
* 'Save mode'
* 'Begin'
=> Steps through solutions, saves each solution to 'default.txt'

## Case 5
* 'Save mode'
* 'Save mode'
=> Toggles save mode twice, save mode off

## Case 6
* 'App mode'
=> Toggles app mode, app mode continuous

## Case 7
* 'App mode'
* 'Begin'
=> Calculates all solutions continuously

## Case 8
* 'App mode'
* 'App mode'
=> Toggles app mode twice, app mode step

## Case 9
* 'App mode'
* 'Save mode'
* 'Begin'
=> Calculates all solutions continuously and saves them to 'default.txt'

## Case 10
* 'Change file'
* Input 'test.txt'
=> Displays 'filename: test.txt' in status line

## Case 11
* 'Change file'
* Input 'test.txt'
* Begin
=> Steps through solutions and saves each one in 'test.txt'

## Case 12
* 'Board size'
* Input '6'
=> Displays 'board size: 6' in status line

## Case 13
* 'Board size'
* Input '7'
=> Steps through solutions for 7x7

## Case 14
* 'Board size'
* Input '7'
* 'App mode'
* 'Save mode'
=> Calculates all 7x7 solutions continuously and saves them to 'default.txt'

## Case 15
* 'Board size'
* Input '13'
=> Asks for valid board size again

## Case 16
* 'Board size'
* Input 'test'
=> Asks for valid board size again

## Case 17
* 'Begin'
* 'Exit'
=> Program exits while solve running

## Case 18
* 'Begin'
* 'Stop'
=> Program stops solving

## Case 19
* 'App mode'
* 'Begin'
* 'Exit'
=> Program exits while solving continuously

## Case 20
* 'App mode'
* 'Begin'
* 'Stop'
=> Program stops solving continuously

## Case 21
* 'Board size'
* Input '7'
* 'App mode'
* 'Begin'
=> Program solves continuously, measures runtime (0.020s)

## Case 22
* 'Board size'
* Input '7'
* 'Begin'
* Press any key 39 times
=> Steps through solutions, finds 40, measures runtime (0.029s)

## Case 23
* 'App mode'
* 'Begin'
* Press any key
* 'Begin'
=> Solves 4x4 solutions twice

## Case 24
* 'App mode'
* 'Board size'
* Input '12'
* 'Begin'
* 'Stop'
* 'Begin'
=> Starts solving 12x12 solutions, stops, solves 12x12 solutions

## Case 25
* 'Board size'
* Input '11'
* 'Begin'
* Wait
* Press any key
=> Displays first solution and waits for input, waiting time is not added to
   runtime

## Case 26
* 'Board size'
* Input '4'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 2 solutions

## Case 27
* 'Board size'
* Input '5'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 10 solutions

## Case 28
* 'Board size'
* Input '6'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 4 solutions

## Case 29
* 'Board size'
* Input '7'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 40 solutions

## Case 30
* 'Board size'
* Input '8'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 92 solutions

## Case 31
* 'Board size'
* Input '9'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 352 solutions

## Case 32
* 'Board size'
* Input '10'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 724 solutions

## Case 33
* 'Board size'
* Input '11'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 2680 solutions

## Case 34
* 'Board size'
* Input '12'
* 'App mode'
* 'Begin'
=> Program solves continuously, finds 14200 solutions
