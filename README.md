# OpenMLX
☕*(WIP*) OpenMLX a implementation of OpenGL features on 42 minilibx☕

![-----------------------------------------------------](https://raw.githubusercontent.com/NyTekCFW/NyTekCFW/master/assets/line.png)

## Introduction:

OpenMLX is a way to setup everything from minilibx more faster.

You want a window with a specified size and a special initial color ?
You can do it in 3 lines.

You want to change the purge color ?
Call one "if (lx)" and a specified function.

Adding a external image or build directly a image into the software ?
Just call register_img(char *path) or create_img(t_ui ui, void (*func)(), char *name).

Want to draw a polygon or a other form quickly filled or in FDF mode ?
You can use vertex / vertices to render what you want!

This project is still a *WIP* (Work in progress)

![-----------------------------------------------------](https://raw.githubusercontent.com/NyTekCFW/NyTekCFW/master/assets/line.png)

## Its Authorized ?

Yes, all codes respect 42 norm, and the function used is the functions authorized in graphics projets,
the only thing that u have to change is the render method, like if you are on the so long project you
cannot use put_pixels function but you can use the rebuild method you have to specify by adding #define SO_LONG_PROJECT 1 to use the right render method (or you can remove the whole part that contain the original put_pixel function).

And yes, you can have a function that contain put_pixel at the moment the function is not called.

![-----------------------------------------------------](https://raw.githubusercontent.com/NyTekCFW/NyTekCFW/master/assets/line.png)

## Window Usage

*UPCOMING*

## Vertex / Vertices Rendering

*UPCOMING*
