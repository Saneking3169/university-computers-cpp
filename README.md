# University Computers (C++)

A console application that manages the computers of a university using a **singly linked list**, written in C++ as a college assignment (variant 3).

## Features

- Load computers from a text file (`calculatoare.txt`)
- Add a computer at the beginning or at the end of the list
- Insert a computer at a given position
- Print all computers
- Search and print computers by monitor type
- Sort the list by processor speed (ascending)
- Delete all computers with memory below 124

## Data model

Each node of the list stores:

| Field       | Type     | Description            |
|-------------|----------|------------------------|
| `monitor`   | `string` | Monitor type           |
| `procesor`  | `double` | Processor speed (GHz)  |
| `ram`       | `int`    | RAM                    |
| `placa`     | `string` | Graphics card          |
| `hdd`       | `string` | Hard disk              |
| `next`      | `Calc*`  | Link to next node      |

## Build and run

Requires a C++ compiler (g++, clang++ or MSVC).

```bash
make
./app
```

Or without `make`:

```bash
g++ -std=c++11 -Wall -Wextra -o app main.cpp
./app
```

Run the program from the folder that contains `calculatoare.txt`.

## Input file format

One computer per line, fields separated by spaces (no spaces inside a value; use `_` instead):

```
monitor processor_GHz ram graphics_card hard_disk
```

Example (`calculatoare.txt`):

```
Samsung 3.2 256 GTX1050 500GB
Dell 2.4 64 Intel_UHD 250GB
LG 3.6 128 RTX2060 1TB
Dell 2.8 512 GTX1660 2TB
Acer 2.0 32 Intel_HD 120GB
```

## Usage

```
1. Citirea listei din fisier
2. Adaugare la inceput
3. Adaugare la sfarsit
4. Inserare pe pozitie
5. Afisarea tuturor calculatoarelor
6. Afisare dupa tip monitor
7. Sortare dupa capacitatea procesorului
8. Stergere calculatoare cu memorie < 124
0. Iesire
```

Example: load the file (`1`), sort by processor (`7`), print (`5`):

```
Acer | 2 | 32 | Intel_HD | 120GB
Dell | 2.4 | 64 | Intel_UHD | 250GB
Dell | 2.8 | 512 | GTX1660 | 2TB
Samsung | 3.2 | 256 | GTX1050 | 500GB
LG | 3.6 | 128 | RTX2060 | 1TB
```

Then delete low-memory machines (`8`) and print again (`5`):

```
Dell | 2.8 | 512 | GTX1660 | 2TB
Samsung | 3.2 | 256 | GTX1050 | 500GB
LG | 3.6 | 128 | RTX2060 | 1TB
```

> The menu and messages are in Romanian, as in the original assignment.

## Project structure

```
.
├── main.cpp           # source code
├── calculatoare.txt   # sample input data
├── Makefile
└── README.md
```

## What I practised

- Singly linked lists (insertion at head, tail and arbitrary position, deletion of matching nodes)
- Sorting a linked list by swapping node data
- File input with `ifstream`
- Menu-driven console programs with `switch`
