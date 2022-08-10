WIRELESS CNC PLOTTER
Working:

1. Generating G-Code file in Inkscape:
	a. First open the "cnc-plotter-template.svg" file on the software.
	b. Drag and Drop the desired image onto the canvas and adjust its dimention to fit into the square box with the thick outline.
	c. Select the image, go to "path"->Select "Trace Bitmap"->Click on "Update" and then click on "ok".
	d. Close the bitmap window -> Drag the image out of the box to see the bitmap of the image -> delete the image.
	e. Select the bitmap -> Go to "Path" -> Select "Object to Path" -> Again go to "Path" and select "Dynamic Offset".
	f. Save the file with the name "gcodefile" and the type as "MakerBot Unicorn G-Code(*.gcode)" from the dropdown.

2. Simulating the plotting of the image:
	a. For simulating the plotting, we use CAMotics software. It is an open source software available to download for free.
	b. Start CAMotics -> Open project -> Select the G-Code file.
	c. If you want to hide the blue background on the simulation area, go to View -> Hide Surface.
	d. You can adjust the orientation of the surface by dragging the surface in any direction.
	e. To simulate, click on the play symbol from the toolbar.

3. Starting the CNC Plotter:
	a. Connect the power adapter to the L293D motor driver in the following way:
		-> The cable with the black wire wrapped around it is the positive terminal. Connect it to the "M+" terminal on the motor driver.
		-> The cable with no wire wrapped around it is the ground terminal. Connect it to the "Gnd" terminal on the motor driver.
	b. Plug in the power adapter to a power socket.

4. ESP8266 connections:
	a. The black wire from the motor driver is the ground pin. Connect it to the "GND" pin of the ESP.
	b. The red and white wire from the motor driver is the 3.3V pin. Connect it to the "3V3" pin of the ESP.
	c. The green wire is the "Rx" pin of the Arduino. Therefore, it should be connected to the "Tx" pin of the ESP.
	d. The yellow wire is the "Tx" pin of the Arduino. Therefore, it should be connected to the "Rx" pin of the ESP.
	
	Once you turn on the power supply to the machine, the ESP8266 starts a server by connecting to a network named "Cncplotter" with password "Invoker2000".
	These credentials can be changed on the ESP8266 program where you can replace it to your network credentials.
	The ESP is configured for mDNS, meaning, no matter what network you connect to(i.e, no matter what IP address it is assgined)you can connect to it 
							using the address - "cncplotter.local/upload".

5. Setting up the plotter:
	a. The plotting area of the plotter is 40mmX40mm. Therefore, place a 6cm X 6cm paper onto the surface and fix it there using paper clips.
	b. The initial position of the plotter should be:
		-> The X-Axis stepper motor (mounted on the vertical part of the plotter) should be at the leftmost position.
		-> The Y-Axis stepper motor (mounted on the horiizontal part of the plotter) should be outwards from you ,i.e, it should be at the innermost position.
	c. Make sure that the initial position of the marker should be on the bottom left part of the paper from your POV.

6. Sending the G-Code file:
	a. Connect to the same network the CNC plotter is connected to.
	b. Open the web browser and go to "cncplotter.local/upload".
	c. You should be directed to an upload webpage where you can upload the G-Code file.
	d. Select the G-Code file with the name "gcodefile.gcode" and upload it. Click on "Print".

You should automatically see that the plotter starts plotting the image. After the entire image is plotted, the image is deleted from the server making space
for a new image and a "Printed Successfully" page is sent to the browser.
This marks the successful plotting of the image.

In case of any queries or issues, contact : "desai.achyutha2000@gmail.com" (Achyuth Desai)