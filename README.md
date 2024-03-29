# WaveGuide
<br/>
<p align="center">
<img src="./resources/waveguide.png" width="400" height="350">
  </p>
<br/>

<!-- ![GitHub contributors](https://img.shields.io/github/contributors/jeasonmaliyekkal/WaveGuide?style=for-the-badge)  -->

[![contributors correction](https://img.shields.io/badge/contributors-4%20-orange.svg?style=for-the-badge)](https://github.com/organization)
![](https://avatars.githubusercontent.com/u/63003253?s=29&v=4)
![](https://avatars.githubusercontent.com/u/90235331?s=29&v=4)
![](https://avatars.githubusercontent.com/u/123407842?s=29&v=4)
![](https://avatars.githubusercontent.com/u/123407779?s=29&v=4)
 
<br>

 ![GitHub closed pull requests](https://img.shields.io/github/issues-pr-closed-raw/jeasonmaliyekkal/WaveGuide?style=for-the-badge) ![GitHub repo file count](https://img.shields.io/github/directory-file-count/jeasonmaliyekkal/WaveGuide?style=for-the-badge) ![GitHub last commit](https://img.shields.io/github/last-commit/jeasonmaliyekkal/WaveGuide?style=for-the-badge)


WaveGuide is a utility that allows you to control the cursor using hand gestures. It uses a Raspberry Pi camera module to capture your hand movements and translates them into cursor actions. You can perform various operations such as moving, clicking, dragging, scrolling and more with simple gestures.

WaveGuide is developed by a team of four students from the University of Glasgow as a part of their ENG5220 Real-time Embedded Programming project. It uses OpenCV for image processing and X11 for cursor manipulation. It runs on Raspberry Pi 4B with Raspbian OS (based on Debian Buster).

## Dependencies

To build and run waveGuide, you need the following dependencies:

- CMake (2.8 or greater)
- OpenCV (4.5 or greater)
- X11 library
- XTest Extention

- To do anything further, clone this repository to your Raspberry Pi using the `git clone` command or by downloading the repository as a .zip file.
```
>$ git clone https://github.com/jeasonmaliyekkal/WaveGuide.git
```

- Navigate to the 'WaveGuide' directory.
```
>$ cd WaveGuide
```
- Make the ``` install_dependencies.sh ``` executable.
```
>$ chmod +x install_dependencies.sh
```
- Now run the executable.
```
>$ ./install_dependencies.sh
```

<br>

## Installation

- Navigate to the 'WaveGuide' directory. 
 ``` 
 >$ cd WaveGuide
  ```

```
- Run `cmake .` to generate the Makefile
- Run `make` to compile the source code
- Run `./waveguide` to start the program
```
```
>$ cmake ..
>$ make
>$ ./waveguide 
```
## Demonstration

![demonstration-video](resources/demonstration-video.mp4 "demonstration-video")

## Usage

To use waveGuide, you need to attach a Raspberry Pi camera module to your device and point it towards your hand. Make sure there is enough light and contrast in the background.

You can perform the following gestures to control the cursor:

- Move your open palm hand left, right, up or down to move the cursor accordingly  ![tracking](resources/tracking.gif "tracking") 

- Make your thumb touch your index finger ( or alternatively hold up 2 fingers) to click the left mouse button. ![left-click](resources/left-click.gif "left-click") 

- Open your palm to release the left mouse button.
- Hold all fingers together ( or alternatively, make a fist) to click the right mouse button.![right-click](resources/right-click.gif "right-click") 
- That's it! Moreover, you can combine these operations. For instance, to drag objects, keep your hand in the left mouse click gesture and move your plam around!![drag](resources/drag.gif "drag") 



- Open palm to release the right mouse button

<br> <br>
## Schematic Diagram

![schematic diagram](resources/schematicDiagram_updated.jpeg "SchematicDiagram")

## Documentation

Information regarding our journey and the specifics of our final product can be found in [WaveGuide](https://jeasonmaliyekkal.github.io/WaveGuide/Website/index.html).

## Limitations, Scope, and Future Work

The WaveGuide has certain limitations.
- The hand detection and tracking is not perfect. Its performance depends on the lighting condition of the room.
- Tracking is most efficient when the background is static.
- It works in raspbian buster, and is not compatible with the latest version Bulleye, which is based on Debian 11.
- Only supports Xorg display server and does not work in Debian systems.
- It can only control the cursor of the Raspberry Pi and not other systems connected to it.

To address these limitations, future work on the WaveGuide includes,
- Incorporating deep learning to improve the detection of the palm area.
- Connect the utility to other systems as a network device using sockets and provide support for Wayland systems. 

WaveGuide is still in development and may have some bugs or errors. Please report any issues or feedback on GitHub.

## Social Media
 [![Twitter](https://img.shields.io/badge/Twitter-WaveGuide-blue?style=flat-square&logo=twitter&logoColor=white)](<https://twitter.com/WaveGuide20>) <br>
 [![Instagram](https://img.shields.io/badge/Instagram-WaveGuide-E4405F?style=flat-square&logo=instagram&logoColor=white)](<https://instagram.com/waveguide._>)



