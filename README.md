# CPP-Reminder

A lightweight, terminal-based reminder system that plays random audio files at randomized intervals. Built using C++ and the Windows Multimedia API.

<p align="left">
  <a href="https://isocpp.org/">
    <img src="https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++ 17">
  </a>
  <a href="https://www.microsoft.com/windows/">
    <img src="https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white" alt="Windows">
  </a>
  <a href="#">
    <img src="https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge" alt="License">
  </a>
</p>

---

## Features

* **Dynamic Playlist:** Automatically scans the `sound_assets` folder for `.mp3` and `.wav` files on startup.
* **Randomized Intervals:** Keeps reminders unpredictable by generating a random duration (default: 22s to 360s) for every loop.
* **Robust Audio Engine:** Uses `mciSendString` with absolute path conversion to reliably play audio formats that standard `PlaySound` cannot handle.

---

## Prerequisites

To compile and run this project, you need:

1.  **Operating System:** Windows (Required for `windows.h` and `winmm.lib`).
2.  **Compiler:** GCC (MinGW) or MSVC with support for **C++17**.

---

## Getting Started

### 1. Installation

Clone the repository to your local machine:

```bash
git clone [https://github.com/Aru-gxtx/CPP-Reminder.git](https://github.com/Aru-gxtx/CPP-Reminder.git)
cd CPP-Reminder
```

### 2. Folder Structure

Ensure your directory looks like this. The program relies on the `sound_assets` folder existing in the same directory as the executable.

```text
CPP-Reminder/
├── sound_assets/          <-- Put your mp3/wav files here
│   ├── hatsune-miku-levan-polkka.mp3
│   ├── alert.wav
│   └── ...
├── main.cpp
├── build.bat
└── README.md
```

### 3. Compilation

Simply run the included batch file to compile the project automatically:

```cmd
.\build.bat
```

---

## Usage

### Running the Reminder
Once compiled, run the executable from your terminal:

```powershell
.\main.exe
```

The program will:
1.  Load all audio files from `sound_assets`.
2.  Start a countdown for a random duration.
3.  Play a random sound when the timer hits 0.

### Customization
You can adjust the timing intervals by editing the variables in `main.cpp`:

```cpp
// main.cpp

int min_sec = 22;   // Minimum wait time (seconds)
int max_sec = 360;  // Maximum wait time (seconds)
```

---

## License

Distributed under the MIT License.
