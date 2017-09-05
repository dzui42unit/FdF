# FdF

In this project you will discover the basics of graphic programming, and in particular how
to place points in space, how to join them with segments and most importantly how to
observe the scene from a particular viewpoint.

It includes

* Realization a Bresenham's line algorithm drawing
* Isometric projection of a grid
* Rotation of an object around x, y, z axis
* Scaling a grid

How to compile: gcc *.c -lmlx -lXext -lX11 -L ./libmlx/ -I ./libmlx/ -lm


This project is about creating a simplified graphic “wireframe” (“fils de fer” in french,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as
a parameter to your program. Here is an example:

![file_example](https://user-images.githubusercontent.com/28359156/30071280-ce6bb3dc-926e-11e7-8dbf-1a12a04fc74c.png)

Each number corresponds to a point in space:

* The horizontal position corresponds to its axis.
* The vertical position corresponds to its ordinate.
* The value corresponds to its altitude.

Examples of execution:

![42](https://user-images.githubusercontent.com/28359156/30071664-3b3af13e-9270-11e7-92d9-3d26a7917c43.png)

![pylone](https://user-images.githubusercontent.com/28359156/30071668-3d427754-9270-11e7-98b7-aa60f5d38f00.png)

![mars](https://user-images.githubusercontent.com/28359156/30071673-3ed352dc-9270-11e7-8eed-ed76f0cb8e8a.png)
