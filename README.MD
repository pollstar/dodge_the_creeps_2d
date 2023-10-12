# Dodge the Creeps with GDExtention C++ (Visual Studio, Godot 4.1)

This is an adaptation for GDExtention and C++, a completed version of the game presented in the textbook for the documentation
["Your first 2D game"](https://docs.godotengine.org/en/latest/getting_started/first_2d_game/index.html).

The project was developed in Visual Studio for Windows platform only.

## Screenshots

![GIF](/screenshots/video.gif)
![sh1](/screenshots/Screenshot%202023-10-14%20152827.png)
![sh2](/screenshots/Screenshot%202023-10-14%20152915.png)

## Requirements
1. Install **Python**, version 3.6 or higher (https://www.python.org/downloads/)

*Attention!!! During the Python installation process, you need to set the "Add to PATH" flag.*

2. Install **scons** (https://scons.org/doc/production/HTML/scons-man.html)
```
pip install scons
```

## Build
1. Clone repository
```
git clone https://github.com/pollstar/dodge_the_creeps_2d.git
cd dodge_the_creeps_2d
cd godot-cpp
git submodule update --init
scons platform=windows generate_bindings=yes target=template_release
scons platform=windows generate_bindings=yes target=template_debug
cd ..
```
2. Download and unzip Godot_v4.1.2-stable_win64.exe to **godot** directory

3. Star VS, and open **sln** file

4. Build project

5. Start project from VS
