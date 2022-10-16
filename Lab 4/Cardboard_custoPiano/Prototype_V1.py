import time
import board
import busio
import adafruit_mpr121
import musicalbeeps


player = musicalbeeps.Player(volume = 0.3,
                            mute_output = False)

i2c = busio.I2C(board.SCL, board.SDA)
mpr121 = adafruit_mpr121.MPR121(i2c)

#I need to put the button code in here
Octave = ["1","2","3","4","5","6"]
            
while True:
    # Loop through all 12 inputs (0-11).
    for i in range(12):
        # Call is_touched and pass it then number of the input.  If it's touched
        # it will return True, otherwise it will return False.
        if mpr121[i].value:
            print("Input {} touched!".format(i))
            if("Input {} touched!".format(i) == "Input 0 touched!"):
                player.play_note("C", 0.2)
                print("YES")
            if("Input {} touched!".format(i) == "Input 1 touched!"):
                player.play_note("D", 0.2)
                print("YES")
            if("Input {} touched!".format(i) == "Input 2 touched!"):
                player.play_note("E", 0.2)
                print("YES")
            if("Input {} touched!".format(i) == "Input 3 touched!"):
                player.play_note("F", 0.2)
                print("YES")
            if("Input {} touched!".format(i) == "Input 4 touched!"):
                player.play_note("G", 0.2)
                print("YES")
            if("Input {} touched!".format(i) == "Input 5 touched!"):
                player.play_note("A", 0.2)
                print("YES")
            if("Input {} touched!".format(i) == "Input 6 touched!"):
                player.play_note("B", 0.2)
                print("YES")
            if("Input {} touched!".format(i) == "Input 7 touched!"):
                player.play_note("C5", 0.2)
                print("YES")
            
    time.sleep(0.1)  # Small delay to keep from spamming output messages.