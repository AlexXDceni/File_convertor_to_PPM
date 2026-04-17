# Image to PPM Converter

<p align="center">
  <img src="https://img.shields.io/badge/C++-17-blue" alt="C++">
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-green" alt="Platform">
  <img src="https://img.shields.io/badge/License-MIT-yellow" alt="License">
</p>

> Convert images to PPM or PGM format with customizable dimensions.

---

## Features

- Convert images to **PPM** (color) or **PGM** (grayscale)
- Customizable output dimensions
- Automatic quality calculation based on input/output size
- Supports common image formats (PNG, JPG, BMP, TGA, GIF, etc.)
- Cross-platform (Windows & Linux)
- Output files saved to `images/` folder

---

## Installation

### Build from Source

```bash
g++ -O2 -Wall -std=c++17 main.cpp -o main.exe -I sources
```

---

## Usage

```
main.exe -i <input> [options]
main.exe -i <input> -o <output> [options]
```

### Arguments

| Argument | Description | Default |
|----------|-------------|---------|
| `-i, --input <file>` | Input image file | Required |
| `-o, --output <file>` | Output file | `images/timestamp.type` |
| `-w, --width <px>` | Target width | 28 |
| `-h, --height <px>` | Target height | 28 |
| `-t, --type <type>` | Output type: `ppm`, `pgm` | `ppm` |

### Output Formats

| Type | Format | Description |
|------|--------|-------------|
| `ppm` | P6 | Full color (24-bit RGB) |
| `pgm` | P5 | Grayscale (8-bit) |

### Examples

```bash
# Basic (28x28 color)
main.exe -i photo.png

# Grayscale
main.exe -i photo.jpg -t pgm

# Custom size
main.exe -i photo.png -w 64 -h 32

# Square output
main.exe -i photo.png -w 100

# Custom output name
main.exe -i photo.png -o myoutput -t ppm

# Display help
main.exe --help
```

---

## How It Works

1. **Load Image** - Reads input using stb_image library
2. **Calculate Quality** - Automatically computes block size
3. **Resize** - Averages pixels in each block
4. **Convert** - Transforms to selected format
5. **Save** - Writes output file

### Quality Calculation

```
Input:  640x480
Output: 64x48

Quality X = 640 / 64 = 10 pixels per block
Quality Y = 480 / 48 = 10 pixels per block

Each 10x10 block becomes 1 pixel
```

---

## Project Structure

```
File_converter_to_PPM/
├── main.cpp           # Main source code
├── sources/
│   └── stb_image.h   # Image loading library (header-only)
├── images/           # Output folder (created automatically)
├── .gitignore
└── README.md
```

---

## Supported Input Formats

- PNG, JPEG, BMP, TGA, GIF, PSD, HDR, and more...

---

## License

MIT License
