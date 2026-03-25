# Math Game (C++ Console Application)

## Demo

<img src="Math_game.gif" width="600">
> “Clarity beats complexity.”



# MathMaster CLI

A structured, object-oriented arithmetic training application built for the command line.

---

## Overview

**MathMaster CLI** is a C++ console application designed to help users practice arithmetic in a structured way. It applies Object-Oriented Programming (OOP) principles and uses the modern C++ `<random>` library to generate reliable and varied question sets.

The goal of the project is to improve calculation speed and accuracy through repeated, customizable practice sessions.

---

## Key Features

* **Tiered Difficulty System**
  Supports Easy (single-digit), Medium (double-digit), and Hard (triple-digit), along with a Mix mode for randomized difficulty.

* **Arithmetic Operations**
  Includes Addition, Subtraction, Multiplication, and Division, with a Mix mode for random operations.

* **Real-time Feedback**
  Uses Windows console coloring to indicate correct (green) and incorrect (red) answers.

* **Session Statistics**
  Tracks performance across questions and games, including wins, losses, and draws.

* **Modern Randomization**
  Uses `std::mt19937` from `<random>` instead of `rand()` for better randomness.

---

## Technical Specifications

* **Language**: C++11 or higher
* **Platform**: Windows (required for `Windows.h`)
* **Libraries Used**: `<random>`, `<thread>`, `<chrono>`, `<iostream>`, `<string>`

---

## Installation and Execution

### Prerequisites

A C++ compiler such as MSVC, MinGW, or Clang installed on a Windows system.

### Compilation

```bash
g++ main.cpp -o MathGame.exe
```

### Running the Application

```bash
./MathGame.exe
```

---

## Class Architecture

### Question Class

* **Responsibility**: Handles question generation and validation
* **Key Functions**:

  * Generates numbers based on difficulty
  * Selects operations
  * Computes correct answers

### Math_Game Class

* **Responsibility**: Controls the game flow and session logic
* **Key Functions**:

  * Manages game loops
  * Tracks scores
  * Displays results and summaries

---

## Configuration Reference

| Setting          | Range/Options      | Description                  |
| ---------------- | ------------------ | ---------------------------- |
| Games Count      | 1 – 10             | Number of games per session  |
| Question Count   | 1 – 100            | Questions per game           |
| Difficulty Level | 0 (Easy) – 3 (Mix) | Controls number range        |
| Operator Type    | 0 (Plus) – 4 (Mix) | Selects arithmetic operation |

---

## Limitations

* Windows-only due to `Windows.h`
* Division is integer-based (no floating-point results)
* Limited input validation (non-numeric input may cause issues)

---

## Example Output

```
Question (1 / 5)
3 + 7 = ?
> 10
Right Answer
```

---

## Summary

This project demonstrates the use of OOP, random number generation, and basic console UI handling in C++. It is suitable as a practice project for students learning structured program design.

---


## Author

Ahmed Waheed
IT Student
