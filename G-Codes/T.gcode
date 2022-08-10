(Scribbled version of C:\Users\desai\AppData\Local\Temp\ink_ext_XXXXXX.svgFO9VN1 @ 3500.00)
( unicorn.py --tab="pen_reg" --pen-up-angle=50 --pen-down-angle=30 --start-delay=150 --stop-delay=150 --xy-feedrate=3500 --z-feedrate=150 --z-height=0 --finished-height=0 --register-pen=true --x-home=0 --y-home=0 --num-copies=1 --continuous=false --pause-on-layer-change=false C:\Users\desai\AppData\Local\Temp\ink_ext_XXXXXX.svgFO9VN1 )
G21 (metric ftw)
G90 (absolute mode)
G92 X0.00 Y0.00 Z0.00 (you are here)

M300 S30 (pen down)
G4 P150 (wait 150ms)
M300 S50 (pen up)
G4 P150 (wait 150ms)
M18 (disengage drives)
M01 (Was registration test successful?)
M17 (engage drives if YES, and continue)

(Polyline consisting of 2 segments.)
G1 X-15.50 Y13.47 F3500.00
M300 S30.00 (pen down)
G4 P150 (wait 150ms)
G1 X-15.50 Y9.92 F3500.00
G1 X-15.50 Y6.37 F3500.00
G1 X-10.60 Y6.37 F3500.00
G1 X-5.69 Y6.37 F3500.00
G1 X-5.69 Y-3.93 F3500.00
G1 X-5.69 Y-14.23 F3500.00
G1 X-0.03 Y-14.23 F3500.00
G1 X5.61 Y-14.23 F3500.00
G1 X5.61 Y-3.93 F3500.00
G1 X5.61 Y6.37 F3500.00
G1 X10.22 Y6.37 F3500.00
G1 X14.85 Y6.37 F3500.00
G1 X14.85 Y9.92 F3500.00
G1 X14.85 Y13.47 F3500.00
G1 X-0.33 Y13.47 F3500.00
G1 X-15.50 Y13.47 F3500.00
G1 X-15.50 Y13.47 F3500.00
M300 S50.00 (pen up)
G4 P150 (wait 150ms)

(Polyline consisting of 2 segments.)
G1 X-14.62 Y12.80 F3500.00
M300 S30.00 (pen down)
G4 P150 (wait 150ms)
G1 X-0.33 Y12.80 F3500.00
G1 X13.95 Y12.80 F3500.00
G1 X13.95 Y9.92 F3500.00
G1 X13.95 Y7.04 F3500.00
G1 X9.38 Y7.04 F3500.00
G1 X4.80 Y7.04 F3500.00
G1 X4.80 Y-3.26 F3500.00
G1 X4.80 Y-13.56 F3500.00
G1 X0.00 Y-13.56 F3500.00
G1 X-4.80 Y-13.56 F3500.00
G1 X-4.80 Y-3.26 F3500.00
G1 X-4.80 Y7.04 F3500.00
G1 X-9.71 Y7.04 F3500.00
G1 X-14.62 Y7.04 F3500.00
G1 X-14.62 Y9.92 F3500.00
G1 X-14.62 Y12.80 F3500.00
M300 S50.00 (pen up)
G4 P150 (wait 150ms)


(end of print job)
M300 S50.00 (pen up)
G4 P150 (wait 150ms)
M300 S255 (turn off servo)
G1 X0 Y0 F3500.00
G1 Z0.00 F150.00 (go up to finished level)
G1 X0.00 Y0.00 F3500.00 (go home)
M18 (drives off)
