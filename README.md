# 🧨 Minesweeper in C

[![C](https://img.shields.io/badge/Language-C-blue)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Platform](https://img.shields.io/badge/Platform-Terminal-lightgrey)](https://en.wikipedia.org/wiki/Command-line_interface)
[![License](https://img.shields.io/badge/License-MIT-green)](LICENSE)

A classic console-based Minesweeper game written in C, featuring three difficulty levels and a 16x16 board. Reveal cells, avoid mines, and challenge your logic skills!

---

## 🎮 Features
- 3 difficulty levels: Easy, Medium, Hard
- Automatic mine placement
- Recursive reveal of empty cells
- Victory and defeat detection
- Simple and intuitive console interface

---

## 📦 Requirements
- C compiler (e.g. gcc)
- Compatible with Windows, Linux, or macOS terminal

---

## 🚀 How to Run
1. Clone the repository:  
   ```bash
   git clone https://github.com/your-username/minesweeper-c.git
   cd minesweeper-c
   ```
2. Compile the code:
   ```bash  
   gcc -o minesweeper minesweeper.c
   ```
3. Run the game:  
   ```bash
   ./minesweeper
   ```

---

## 🧠 Gameplay
- Choose your difficulty level at the start.
- Enter coordinates in the format: `row column` (e.g. `3 5`)
- Cells with no adjacent mines will reveal surrounding areas automatically.
- Revealing a mine ends the game.
- Reveal all non-mine cells to win!

---

## 🛠️ Future Improvements
- Add flagging system
- Save/load game state
- GUI version using SDL or ncurses
- Score tracking

---

## 📄 License
This project is open-source and available under the MIT License.
