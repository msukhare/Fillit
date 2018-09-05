## FILLIT

### What is fillit ?

* Fillit is a software which place tetriminos in the smallest space possible and the fastest way.

### What you need to make work fillit ?

* gcc or clang

* make

### How compile fillit ?

* Use `make` to compile and get `fillit`.

### To execute `fillit`:

* `./fillit filewithTetriminos`

### About Tetriminos

* [Tetriminos](https://en.wikipedia.org/wiki/Tetromino) is piece which you have in tetris

* It needs to be composed `.` and 4 `#`

* The `#` must touch each other

* the piece must be sperate by '\n' in the file which you give as a argument to 'fillit'

some exemples of tetriminos:

1.

`....`

`..##`

`..#.`

`..#.`

2.

`....`

`....`

`..##`

`..##`


3.

`####`

`....`

`....`

`....`

4.

`.#..`

`###.`

`....`

`....`

exemple `filewithTetriminos`:

`...#$`

`...#$`

`...#$`

`...#$`

`$`

`....$`

`....$`

`....$`

`####$`

`$`

`.###$`

`...#$`

`....$`

`....$`

`$`

`....$`

`..##$`

`.##.$`

`....$`

Makefile has 3 rules:

* all: create `fillit`

* clean: delete all objects

* fclean: delete `fillit` and clean
