# 🎵 Music Manipulation

A **C++ audio processing project** that reads digital audio data into arrays and performs several fundamental audio manipulation operations.

The project demonstrates how raw audio samples can be represented and processed using **arrays, functions, file handling, and basic digital signal processing (DSP) techniques**.

---

## 📌 Features

The program currently supports the following operations:

1. 🎧 **Read Audio File**
2. 📈 **Up-Sample Audio**
3. 📉 **Down-Sample Audio**
4. 🔊 **Apply Moving Average Filter**
5. 🎶 **Mix Two Audio Files**
6. ▶️ **Play Audio File**

---

## 🧠 Project Overview

Digital audio can be represented as a sequence of numerical samples.

This project reads audio data from a WAV file and stores the samples in arrays. These arrays are then manipulated using different audio-processing techniques.

The project provides a basic understanding of how audio processing works at the data level without relying on high-level audio-processing libraries.

### Basic Workflow

```text
             WAV Audio File
                    │
                    ▼
             Read Audio Data
                    │
                    ▼
              Store in Array
                    │
          ┌─────────┼─────────┐
          ▼         ▼         ▼
      Up-Sample  Down-Sample  Filter
          │         │         │
          └─────────┼─────────┘
                    ▼
               Mix Audio
                    │
                    ▼
              Output WAV File
                    │
                    ▼
                Play Audio
```

---

## ⚙️ Operations

### 1. Read Audio File

The program reads audio information from a WAV file and stores its samples in an array.

The audio data can then be accessed and manipulated programmatically.

**Input:**

* WAV audio file

**Output:**

* Audio samples stored in an array
* Audio metadata such as sample rate and number of samples

---

### 2. Up-Sampling

Up-sampling increases the number of samples in an audio signal.

For example:

```text
Original:
[10, 20, 30, 40]

After Up-Sampling:
[10, 10, 20, 20, 30, 30, 40, 40]
```

This project performs up-sampling directly on the audio sample array.

---

### 3. Down-Sampling

Down-sampling reduces the number of samples in an audio signal.

For example:

```text
Original:
[10, 20, 30, 40, 50, 60]

After Down-Sampling:
[10, 30, 50]
```

This demonstrates how the number of samples in a digital signal can be reduced.

---

### 4. Moving Average Filter

A **Moving Average Filter** is a basic digital signal processing technique used to smooth an audio signal.

The filter calculates the average of neighboring samples using a selected window size.

Example:

```text
Input samples:

[10, 20, 30, 40, 50]

Moving Average Window = 3

Average:
(10 + 20 + 30) / 3 = 20
(20 + 30 + 40) / 3 = 30
(30 + 40 + 50) / 3 = 40
```

The project supports different filter window sizes, allowing the effect of filtering to be observed.

---

### 5. Mix Two Audio Files

The program can combine two audio signals into a single audio signal.

Conceptually:

```text
Audio A ──────┐
              ├──► Mix ───► Output Audio
Audio B ──────┘
```

The samples from both audio files are processed to produce the final mixed signal.

---

### 6. Play Audio File

The program can play the generated WAV audio file.

On Windows, audio playback can be handled using the **Windows Multimedia API (`winmm`)**.

---

## 🛠️ Technologies Used

* **C++**
* **WAV File Format**
* **Arrays**
* **Functions**
* **File Handling**
* **Digital Signal Processing (DSP)**
* **Windows Multimedia API**
* **MSYS2 / MinGW**
* **Visual Studio Code**

---

## 📂 Project Structure

A typical project structure is:

```text
music-manipulation/
│
├── main.cpp
├── sound.cpp
├── sound.h
├── wavfile.cpp
├── wavfile.h
│
├── input.wav
├── output.wav
│
└── README.md
```

### File Description

| File          | Description                                            |
| ------------- | ------------------------------------------------------ |
| `main.cpp`    | Contains the main program and user interaction         |
| `sound.cpp`   | Contains audio manipulation and playback functionality |
| `sound.h`     | Header file containing function declarations           |
| `wavfile.cpp` | Handles WAV file reading and writing                   |
| `wavfile.h`   | Header file for WAV file operations                    |
| `README.md`   | Project documentation                                  |

> File names may vary depending on the final project structure.

---

## 🚀 Getting Started

### Prerequisites

Make sure you have the following installed:

* C++ compiler
* MinGW / MSYS2
* Visual Studio Code or another C++ IDE
* Windows operating system for the `winmm` playback functionality

---

## 🔧 Compilation

If you are using **g++**, compile the project using:

```bash
g++ main.cpp sound.cpp wavfile.cpp -o main -lwinmm
```

Then run:

```bash
./main
```

On Windows, you can also run:

```bash
main.exe
```

---

## 🎮 How to Use

1. Compile the program.
2. Run the executable.
3. Select the required audio operation from the menu.
4. Provide the required WAV file or parameters.
5. The program processes the audio samples.
6. The resulting audio can be saved as a WAV file.
7. Play the generated file using the playback option.

Example menu:

```text
=================================
       MUSIC MANIPULATION
=================================

1. Read Audio File
2. Up Sample Audio
3. Down Sample Audio
4. Moving Average Filter
5. Mix Two Audio Files
6. Play Audio File
7. Exit

Enter your choice:
```

---
## 📋 Input and Output

### 🎧 Input Audio Files

The program works with `.wav` audio files.

A sample `.wav` file is included in the repository for testing purposes. **You can also add your own `.wav` files** to the project directory and provide their filename/path when prompted by the program.

For example:

```text
music-manipulation/
│
├── main.cpp
├── sound.cpp
├── sound.h
├── wavfile.cpp
├── wavfile.h
│
├── test.wav          ← Included sample file
├── dhani.wav         ← Your own WAV file or any extra WAV file
│
└── README.md
```

> **Note:** Only WAV files are supported by the current implementation. Make sure your audio file is in `.wav` format before using it with the program.

### 📤 Output Audio Files

Depending on the selected operation, the program can generate a processed WAV file such as:

```text
upsampled.wav
downsampled.wav
filtered.wav
mixed.wav
```

You can also use these generated files as input for further audio manipulation operations.


## 🎯 Learning Objectives

This project was developed to understand the relationship between **programming concepts and digital audio processing**.

Through this project, the following concepts are practiced:

* Working with arrays
* Passing arrays to functions
* File input/output
* Binary file handling
* WAV file structure
* Function decomposition
* Audio sample manipulation
* Digital signal processing fundamentals
* Up-sampling and down-sampling
* Moving average filtering
* Audio mixing
* Multimedia programming
* Modular C++ programming

---

## 🔬 Digital Signal Processing Concepts

The project provides a practical introduction to several DSP concepts.

### Sampling

Digital audio represents a continuous sound signal using discrete samples.

```text
Analog Sound
     │
     ▼
 Sampling
     │
     ▼
Digital Samples
     │
     ▼
[12, 18, 25, 31, 28, 20, ...]
```

### Up-Sampling

```text
Fewer Samples
     │
     ▼
More Samples
```

### Down-Sampling

```text
More Samples
     │
     ▼
Fewer Samples
```

### Filtering

```text
Noisy Signal
     │
     ▼
Moving Average Filter
     │
     ▼
Smoothed Signal
```

---

## 📋 Input and Output

### Input

The program primarily works with:

```text
.wav
```

audio files.

### Output

Depending on the selected operation, the program can generate a processed WAV file such as:

```text
upsampled.wav
downsampled.wav
filtered.wav
mixed.wav
```

---

## ⚠️ Limitations

This project is designed primarily for educational purposes.

Current limitations may include:

* WAV files are required as input.
* Audio processing is performed using arrays in memory.
* Playback functionality is primarily intended for Windows.
* The implementation focuses on fundamental audio-processing concepts rather than production-grade DSP.
* Large audio files may require significant memory because samples are stored in arrays.

---

## 🔮 Future Improvements

Possible future improvements include:

* [ ] Support for stereo audio
* [ ] Support for additional audio formats
* [ ] More advanced digital filters
* [ ] Volume control
* [ ] Echo effect
* [ ] Reverb effect
* [ ] Noise reduction
* [ ] Reverse audio
* [ ] Fade-in and fade-out
* [ ] Audio waveform visualization
* [ ] Graphical user interface
* [ ] Real-time audio processing
* [ ] Improved error handling
* [ ] Cross-platform audio playback

---

## 👨‍💻 Purpose

This project was developed as an educational implementation of **audio manipulation and basic digital signal processing using C++**.

The main goal is to understand how digital audio can be represented as numerical data and how programming techniques can be used to manipulate those samples.

---

## 📜 License

This project is intended for **educational and learning purposes**.

You are free to study, modify, and extend the project for your own learning.

---

## ⭐ Acknowledgements

This project was created as part of a C++ / programming coursework project focusing on:

**Arrays • File Handling • Audio Processing • Digital Signal Processing • C++ Programming**
