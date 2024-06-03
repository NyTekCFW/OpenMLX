# OpenMLX
☕A implementation of OpenGL features on 42 minilibx☕

![-----------------------------------------------------](https://raw.githubusercontent.com/NyTekCFW/NyTekCFW/master/assets/line.png)

## Introduction:

OpenMLX is an extension of the minilibx graphics library that let you setup  more faster.

### Why the name OpenMLX?
Because some graphics features come from OpenGL or be inspired from this and this extension work only with minilibx.

### Warning
This project is still a **WIP** (Work in progress), some bugs can still occur and i will correct all of them when i can.
If you see a major bug or a minor bug you can still report it the only thing that i ask you before report it is to be sure the problem is not your functions.

![-----------------------------------------------------](https://raw.githubusercontent.com/NyTekCFW/NyTekCFW/master/assets/line.png)

## Its Authorized ?

Yes, all codes respect 42 norm.
The functions used is in the list of functions authorized in graphics projects.

### How to bypass So_Long restrictions:
The statement specifies that the use of the mlx_pixel_put function is prohibited, and that you must use images.
So how to proceed?
In OpenMLX, an image management system is available, as well as an alternative to the mlx_pixel_put function. When the window is created, 255 images of 1x1 dimension are generated.

By adding:
#define SO_LONG_PROJECT 1

you activate the custom version of mlx_pixel_put, which simply displays these 255 previously created images.
So it simulates the behavior of put_pixel using 1x1 images. In addition, a code makes it possible to recover each pixel of the image to display, then to store this pixel on the generated images. So yes its authorized, since you only display images and not a pixel

Warning! Don't have fun doing the full rendering of your game with it, firstly because it will be terribly long in certain cases and also because it was created in order to display your player without necessarily having to display a ground texture or other in the background . And in the event that your corrector can be understanding about the use of this function for the player, I don't think he will appreciate the fact that it is used everywhere.

And yes, you can have a function that contain mlx_pixel_put as long the function is not called.
but if you are sceptic you can remove the function that contain mlx_pixel_put.


![-----------------------------------------------------](https://raw.githubusercontent.com/NyTekCFW/NyTekCFW/master/assets/line.png)

## Introduction To OpenMLX :

### Basics of OpenMLX :
- [🏗️ French: Introduction to OpenMLX](https://github.com/NyTekCFW/OpenMLX/blob/main/assets/document/fr_openmlx_introduction.pdf)
- [🏗️ English: Introduction to OpenMLX](https://github.com/NyTekCFW/OpenMLX/blob/main/assets/document/eng_openmlx_introduction.pdf)

## Vertex / Vertices Rendering :
*UPCOMING*

<div align="center">
<img src="https://raw.githubusercontent.com/NyTekCFW/OpenMLX/master/assets/images/FDF%20mode.png" alt="fdf" width="20%">
<img src="https://raw.githubusercontent.com/NyTekCFW/OpenMLX/master/assets/images/ML_PRIM_POLYGON.png" alt="polygon" width="20%">
<img src="https://raw.githubusercontent.com/NyTekCFW/OpenMLX/master/assets/images/ML_PRIM_QUAD_STRIP.png" alt="quadstrip" width="20%">
<img src="https://raw.githubusercontent.com/NyTekCFW/OpenMLX/master/assets/images/filled.png" alt="filled" width="20%">
</div>



