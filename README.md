PhotoChango-OSX
===============

This is a repo of the XCode/OSX-compatible version of the PhotoChango.

How the Chango works

The Chango works by mapping images to sounds. The Chango processes video captured from your camera. Each frame of video is audiolyzed as it is captured by the Chango. That means you see a continuous video stream and hear a continuous audio stream. The Chango divides an image into a grid. Each location in the grid has a pitch associated with it. The Chango determines the average intensity of the light in the image for each cell in the grid. Then the Chango plays a tone for each grid cell. The pitch of the tone is the cell's associated pitch. The volume of the sound is proportional to the average intensity of light in the image in that cell. In the mac version of the Chango, there is also support for using the average intensity of motion in a cell to determine the cell's tone's volume (press 'm' and 'l' for 'l'ight or 'm'otion!).

Playing the Chango

Playing the Chango is an art. The tones are arranged from lowest to highest, from the upper left to the lower right. To play precise tones at precise times it is best to use a primarily dark scene with a point light source. That way the light source only illuminates a few cells in the grid and the Chango only plays a few tones very loudly. Another way to play the Chango is to use a busy scene in fully exposed light. While it is harder to control which tones are played when, a busy scene can often produce the most interesting harmonies. Use a combination of these techniques to create beautiful ambient sounds.

