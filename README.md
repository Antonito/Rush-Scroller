# Rush-Scroller
An igraph rush in C

The goal of this rush was to create a Demo like crackers did during the 80's - 90's.

We started on Friday at 8pm, and finished  on Sunday at 11pm. We used the LibLapin 1.7 (Epitech's graphic lib)

The delay between each effect is defined by the macro TIMER_DELAY in include/tools/common.h (if set to 0, no timer)

If you compile in DEBUG mode (just change a few things in the Makefile) and if a malloc fails, you will know its location (file and line).

We have 13 effects, you can access the next / previous effect with N and P keys.

The plasma:

      - A moving plasma
      - You can zoom / dezoom with O and L keys
      - You can increase / decrease speed with UP and DOWN arrows
      - You can change the gradient with I and K
![Plasma](/assets/screenshots/plasma.png?raw=true "Basic view")
The NyanWolf :

      - An animated wolf (sprite)
      - The wolf is resized manually
      - Transparency
      - Randomly colored background
      - Awesome NyanCat music
![NyanWolf](/assets/screenshots/wolf.png?raw=true "Basic view")
Starfield:

    - Rotating space travel
    - Colored stars (blue or white)
    - South Park's "Heavy Metal" song
![Starfield](/assets/screenshots/starfield.png?raw=true "Basic view")
Flag:

    - Moving flag (wind)
    - You can change the speed of the wind with UP and DOWN arrows
    - You can reverse the flag with the spacebar
    - Song from Star Wars Battlefront 2
![Flag](/assets/screenshots/flag.png?raw=true "Basic view")
Checkerboard:

    - The same image mixed with a checkboard image
    - When accessing the next / previous effect, the image fades to black
    - Song "Fade To Black" by Metallica
![Checkerboard](/assets/screenshots/checkerboard.png?raw=true "Basic view")
Scroller:

    - A rabbit jumps stupidly from the left to the right of the screen
    - The grass, the mountains, the cloud and the rabbit move at different speeds.
    - Benny Hill song
![Scroller](/assets/screenshots/scroller.png?raw=true "Basic view")
Particles tunnel :

    - Random direction
    - Rainbow colors
    - Music is from a PiZZADOX's trainer
![Tunnel](/assets/screenshots/tunnel.png?raw=true "Basic view")
Sampler :

    - Pitch shifting with UP and DOWN arrows
    - Rainbow circle
![Sampler](/assets/screenshots/sampler.png?raw=true "Basic view")
IceBerg :

    - A blue iceberg image
    - Gradient from the image to a red background
    - Titanic's music
![Iceberg](/assets/screenshots/iceberg.png?raw=true "Basic view")    
Rotozoom :

    - Repeated image 
    - Spaghetti monster
    - Rotation on Z and X axis
    - Random zoom
    - Manual transformation (matrix)
    - Spaghetti monster song
![Rotozoom](/assets/screenshots/rotozoom.png?raw=true "Basic view")    
![Rotozoom](/assets/screenshots/rotozoom2.png?raw=true "Far view")
Text :

    - Text moving on all axis
    - Rum by Alestorm lyrics and song
![Text](/assets/screenshots/text.png?raw=true "Basic view")    
Corruption :

    - Rotating text, on all axis (matrix)
    - Moving rainbow gradiant in background
    - Attempt to corrupt our grader with food
 ![Corruption](/assets/screenshots/corruption.png?raw=true "Basic view")   
Fire :

    - Flames
    - You can change the intensity with UP and DOWN arrows
    - IRL effect : let it a few minuts, and your computer will expire hot air
    - Fire sound
![Fire](/assets/screenshots/fire.png?raw=true "Basic view")

Realized with Arthur Arnaud and Ludovic Petrenko.

Grade : 44.75 / 20
