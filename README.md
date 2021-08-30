# rot
## What is Rot cipher?
Rot-N/Rot cipher (for Rotation) is a simple character substitution based on a shift/rotation of N letters in an alphabet. E.g. one letter is replaced by another (always the same) that is located further (exactly N letters further) in the alphabet.

This is the basis of the famous Caesar code and its many variants modifying the shift. The most popular variant is the ROT13 which has the advantage of being reversible with our 26 letters alphabet (the encryption or decryption operations are identical because 13 is half of 26).

## Usage
You can use compiled program with command line arguments:
```sh
rot 13 "hello world"
```
And without command line arguments:
```sh
rot
rot >> 13
input >> hello world
```

## Installation
You need g++ compiler!

On Linux you can install via install.sh:
```sh
sudo sh install.sh
```
or
```sh
g++ -o rot rot.cpp
sudo mv rot /bin
```

On Windows you can install via install.cmd (use admin cmd):
```cmd
.\install.cmd
```
or
```cmd
g++ -o rot.exe rot.cpp
move /y %cd%\rot.exe %windir%\System32\
```
