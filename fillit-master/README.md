# Fillit

This project was completed in december 2018 as part of the 42 school cursus. The instructions were to create a program that could arrange a set of 1 to 26 tetriminos in the smallest square possible and print the result. The complete instructions can be found in the *resources* folder.

🍌 This was a group project, completed with [Xeska](https://github.com/Xeska).

![path to fillit](https://i.imgur.com/b0dXXwo.png "Cursus start > 42 Commandements > Piscine Reloaded > Libft > Get_Next_Line > Fillit")

*Basic algorithms, input/output*

## Solving the problem

This project was the first introduction to **parsing**, as we had to extract information about the tetriminos from a file, and return an error in case the tetriminos were not properly formated.
The way the tetriminos are stored in our project, is by the coordinates of the 3 other parts of the piece respective to the top-left-most square.

<p align="center"><img src="https://i.imgur.com/J4AvErv.png" /></p>

In order to find the disposition of tetriminos that gives the smallest square, our algorithm:
1. Chooses a smallest size possible, depending on the number of tetriminos, knowing that all tetriminos are made of 4 parts.
2. Places the first tetrimino in the top-left-most position.
3. Tries to place the second tetrimino in the top-left-most position, and if the position in invalid, moves it to the right, and then down when the end of the line is reached.
4. When a valid position, it tries to position the third tetrimino in the same fashion.

In the end, either it will no be possible to find a valid position for the next tetrimino, or there will be no tetrimino left. In this last case, the smallest square was found, and the algorithm ends.
In the first case, the algorithm uses **backtracking** to try a different position for the previous tetrimino, backtracking as far as necessary to either find a solution or try every possible combination. If no combination was found, the size of the square is incremented by 1 and the same process starts over.

## Getting Started

Run the command `make` to create the **fillit** executable.

## Running the tests

```
./fillit tetriminos_file
```
Provided tetriminos_file is a valid file and the tetriminos inside it are valid, the program will print the smallest square possible filled with the given tetriminos, identified by a letter.

### Tetriminos file

Tetriminos file should follow certain rule. Each piece should be reprensented by 4 '#' characters placed in a 4 by 4 table ('.' represents an empty space). The pieces should be separated from one another by a new line. The only allowed pieces are those which exist in the tetris game. The orientation of the pieces matters since the program does not allow for a tetrimino to be rotated.
Example:
```
.##.
.##.
....
....

....
.##.
.#..
.#..

....
####
....
....
```

Examples of invalid files:
```
$> cat resources/invalid_files/test1
....
##..
..##
....

#...
#...
#...
#...
$> ./fillit resources/invalid_files/test1
error
```

```
$> cat resources/invalid_files/test2
....
##..
.##.
....

....
####
.....
....
$> ./fillit resources/invalid_files/test2
error
```

### Examples

```
$> ./fillit resources/valid_files/test1
AAAAB.
CCCDBB
FC.D.B
F.DDGG
F.EGG.
FEEE..
```

```
$> ./fillit resources/valid_files/test2
AAAA.
BB.C.
.BBC.
DD.CC
DD...
```

## Authors

🍌Team Unbananable:
* **[anaiel](https://github.com/anaiel)**
* **[Xeska](https://github.com/Xeska)**

<img align="right" src="https://i.imgur.com/hReuUFV.png" />
