# fdf

**Lightweight 3D wire‑frame viewer that turns height‑map data into interactive isometric landscapes with MiniLibX.**

---

## ✨ Overview

`fdf` is a graphical project from **École 42**.
Given a plain‑text height‑map, the program renders a real‑time **wire‑frame model** in an isometric (or parallel) projection using the minimalist graphics library **MiniLibX**.
The viewer supports zoom, pan, rotation, altitude scaling and colour gradients.

> **Goal :** write a clean C program with no external dependencies besides MiniLibX & X11/GLFW hooks.

---

## 📑 Table of Contents

1. [Features](#features)
2. [Installing MiniLibX](#installing-minilibx)
3. [Directory Structure](#directory-structure)
4. [Build](#build)
5. [Usage](#usage)
6. [Controls](#controls)
7. [Project Context](#project-context)

---

<a id="features"></a>

## ⚙️ Features

| Category        | Details                                                                                                    |
| --------------- | ---------------------------------------------------------------------------------------------------------- |
| **Input**       | `.fdf` / plain‑text file containing *rows* of *space‑separated* integers (heights) + optional hex colours. |
| **Projection**  | Default **isometric**; toggle to **parallel** with `P`.                                                    |
| **Interaction** | keyboard & mouse: zoom, pan, rotate (x/y/z), altitude scale.                                               |
| **Colour**      | gradient based on altitude or explicit colour codes per point.                                             |
| **Performance** | Bresenham line‑drawing, integer maths where possible, double buffering to avoid flicker.                   |

---

<a id="installing-minilibx"></a>

## 🛠️ Installing MiniLibX

MiniLibX (often called **mlx**) is the tiny graphics wrapper used in 42 projects.
Below are the common installation paths.

### macOS (Homebrew)

```bash
brew update
brew install mlx
```

Homebrew places headers in `/opt/homebrew/include` and the static library in `/opt/homebrew/lib`.
Add these flags to your `Makefile` if Homebrew is not in a default search path:

```make
LDFLAGS += -L/opt/homebrew/lib -lmlx -framework OpenGL -framework AppKit
CFLAGS  += -I/opt/homebrew/include
```

### Ubuntu 22.04 (apt package)

```bash
sudo apt-get update
sudo apt-get install libmlx42-dev libxext-dev libbsd-dev
```

Package `libmlx42-dev` installs headers to `/usr/include` and the static lib to `/usr/lib/x86_64-linux-gnu`.
Link with:

```make
LDFLAGS += -lmlx42 -lXext -lX11 -lm -lz
```

### Manual build (any Linux distro)

```bash
# Clone the official 42 fork
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
sudo make install      # installs to /usr/local/lib & /usr/local/include
```

Then add in your project `Makefile` :

```make
CFLAGS  += -I/usr/local/include
LDFLAGS += -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz
```

> **Tip :** ensure you have X11 dev headers (`sudo apt-get install libxext-dev libx11-dev`) and `pkg-config` installed for a smooth build.

---

<a id="directory-structure"></a>

## 🗂️ Directory Structure

```text
fdf/
├── inc/            # headers (fdf.h, mlx wrappers)
├── libft/          # embedded libft (static library)
├── srcs/           # source files
│   ├── functions
├── maps/           # sample height‑maps (.fdf)
├── Makefile
└── README.md
```

---

<a id="build"></a>

## 🚀 Build

```bash
# Clone repository
git clone https://github.com/Kirotan/fdf.git
cd fdf

# Compile binary + libft (expects mlx installed system‑wide)
make                # produces ./fdf
```

### Clean targets

```bash
make clean          # remove objects
make fclean         # + remove binary & libs
make re             # full rebuild
```

---

<a id="usage"></a>

## 📚 Usage

```bash
./fdf maps/42.fdf          # open sample map
./fdf path/to/heightmap.fdf
```

The program opens a window (default 1280 × 720) with the rendered wire‑frame.

---

<a id="controls"></a>

## 🎮 Controls

| Key / Action   | Function                           |
| -------------- | ---------------------------------- |
| `Scroll ⬆ / ⬇` | zoom in / out                      |
| `Arrow keys`   | pan view                           |
| `Q / E`        | rotate around **Z** axis           |
| `W / S`        | rotate around **X** axis           |
| `A / D`        | rotate around **Y** axis           |
| `+ / -`        | increase / decrease altitude scale |
| `ESC`          | quit                               |

---

<a id="project-context"></a>

## 🏛️ Project Context

*Part of the 42 common‑core graphics track.*
Objectives:

* parse ASCII height‑maps safely (error handling & zero leaks) ;
* implement Bresenham algorithm & basic matrix transforms ;
* manage graphical loop, events & redraw with MiniLibX ;
* write a portable Makefile linking *libft* & *mlx*.
