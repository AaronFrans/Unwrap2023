# Gamejam
Vs code for lib

# Install Guide

## scons
- instal python: [Python page](https://www.python.org/) (Make sure to add python to path)  
- open command prompt  
- type "pip install scons"  

## godot
- download godot from: [Godot page](https://godotengine.org/) (Should be 3.5.1)
- put the downloaded file somewhere 
- add godot to env variables: [Tutorial](https://stackoverflow.com/questions/4822400/register-an-exe-so-you-can-run-it-from-any-command-line-in-windows#:~:text=In%20the%20Environment%20Variables%20tab,folder%20and%20it%20should%20work.) (BE SURE TO NAME TO VARIABLE GODOT)

## project
- clone the project to somewhere on your computer  
- via vs native command line(X64!!!) go to the location of the project folder  
- cd to \includes\godot-cpp  
- run scons bits=64 and scons bits=64 target=release
- cd back to the prject folder  
- run scons platform=windows  

