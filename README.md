# Advent of Code 2024 C++

A repository housing my attempts to solve AOC 24 in C++.

## Usage

To set up a new day:

1. Create a new directory in the root of the repository with the name `dayXX`, where `XX` is the day number.
```bash
mkdir dayXX
```

2. Download the input file for the day and place it in the directory created in step 1.

3. Create subdirectories for parts 1 and 2.
```bash
mkdir dayXX/part1
mkdir dayXX/part2
```
4. Copy the Makefile template into each of the subdirectories, replacing 'PARTX' with 'part1' or 'part2'.
```bash
cp Makefile.template dayXX/part1/Makefile
cp Makefile.template dayXX/part2/Makefile
```

5. Create a new C++ source file in each subdirectory called `main.cpp`.
```bash
touch dayXX/part1/main.cpp
touch dayXX/part2/main.cpp
```

6. Write your solution in the `main.cpp` files, add other source files and headers as needed, ensuring to update the Makefile.