import time
from time import strftime, sleep
import datetime
import subprocess
import digitalio
import board
from PIL import Image, ImageDraw, ImageFont
import adafruit_rgb_display.st7789 as st7789

# Configuration for CS and DC pins for Raspberry Pi
cs_pin = digitalio.DigitalInOut(board.CE0)
dc_pin = digitalio.DigitalInOut(board.D25)
reset_pin = None

#Configure Button:
buttonA = digitalio.DigitalInOut(board.D23)
buttonB = digitalio.DigitalInOut(board.D24)
buttonA.switch_to_input()
buttonB.switch_to_input()

# Config for display baudrate (default max is 24mhz):
BAUDRATE = 64000000

# Setup SPI bus using hardware SPI:
spi = board.SPI()

# Create the ST7789 display:
disp = st7789.ST7789(
    spi,
    cs=cs_pin,
    dc=dc_pin,
    rst=reset_pin,
    baudrate=BAUDRATE,
    width=135,
    height=240,
    x_offset=53,
    y_offset=40,
)

# Create blank image for drawing.
# Make sure to create image with mode 'RGB' for full color.
height = disp.width  # we swap height/width to rotate it to landscape!
width = disp.height
image = Image.new("RGB", (width, height))
rotation = 90

# Get drawing object to draw on image.
draw = ImageDraw.Draw(image)

# Draw a black filled box to clear the image.
draw.rectangle((0, 0, width, height), outline=0, fill=(0, 0, 0))
disp.image(image, rotation)
# Draw some shapes.
# First define some constants to allow easy resizing of shapes.
padding = -2
top = padding
bottom = height - padding
# Move left to right keeping track of the current x position for drawing shapes.
x = 0

# Alternatively load a TTF font.  Make sure the .ttf font file is in the
# same directory as the python script!
# Some other nice fonts to try: http://www.dafont.com/bitmap.php
font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 18)

# Turn on the backlight
backlight = digitalio.DigitalInOut(board.D22)
backlight.switch_to_output()
backlight.value = True

# button state tracking
buttonA_lastState = False

while True:
    
    draw.rectangle((0, 0, width, height), outline=0, fill=0)  

    #Isolate hours, minutes, and seconds.
    current_time = datetime.datetime.now()
    hour = current_time.hour
    minute = current_time.minute
    second = current_time.second
    milliSecond = current_time.microsecond/1000
    uSecond = current_time.microsecond
    #Debug:
    #print(hour)
    #print(minute)
    #print(second)
    #print(current_time)
    #print(milliSecond)
    #print(uSecond)
    
    #If A button is pressed, show the time
    if buttonA.value and not buttonB.value:
        print("nothing")
        
    #If A button is pressed, show the time
    if buttonB.value and not buttonA.value:
        draw.rectangle((0, 0, width, height), outline=0, fill="#FFFFFF")  
    else:
        dateTime = strftime("%H:%M:%S:")
        r_milliSecond = round(milliSecond)
        milliString = str(r_milliSecond)
        dateTime = dateTime+milliString
        print(buttonA.value)
        y = 100
        x = 60
        draw.text((x, y), dateTime, font=font, fill="#FFFFFF")

    #-----------------------------------------------------------
    #Fixed Constant for all moving squares:
    fixedWidth = 20 
    
    #-----------------------------------------------------------
    #Task: For the millisecond time component, propel rectangle across screen
    #in accordance to visual timekeeping of milliseconds with limit of seconds
    
    #Setup According Constants in section
    #ms stands for milliseconds
    ms_y1 = 0 #Fixed
    ms_y2 = 20 #Fixed
    ms_toSec = 1000 #There are 1000 milliseconds in 1 second
    ms_colorID = "#ffff33" #Yellow
    
    #Dynamically move the shape with respect to time element:    
    ms_scaleFactor = (milliSecond*(width-fixedWidth))/ms_toSec 
    ms_X1 = 0 + ms_scaleFactor #dynamic
    ms_x2 = fixedWidth + ms_scaleFactor #dynamic
    
    #shape = [x0, y0, x1, y1]
    ms_shape = [ms_X1,ms_y1,ms_x2,ms_y2] 
    draw.rectangle(ms_shape, outline=0, fill=ms_colorID)
    
    #-----------------------------------------------------------
    
    #Task: For the second time component, propel rectangle across screen
    #in accordance to visual timekeeping of seconds with limit of minute
    
    # Current Second * width/60
    s_y1 = 20 #Fixed
    s_y2 = 40 #Fixed
    s_toMin = 60 #There are 60 seconds in 1 minute
    s_colorID = "#ff0000"
    
    #Dynamically move the shape with respect to time element:
    sx_scaleFactor = (second*(width-fixedWidth))/s_toMin 
    s_x1 = 0 + sx_scaleFactor     
    s_x2 = fixedWidth + sx_scaleFactor 
    
    #Draw the shape
    s_shape = [s_x1,s_y1,s_x2,s_y2] 
    draw.rectangle(s_shape, outline=0, fill=s_colorID)

    #-----------------------------------------------------------

    #Task: For the minutes time component, propel rectangle across screen
    #in accordance to visual timekeeping of minutes with limit of hour
    m_y1 = 40 
    m_y2 = 60
    m_toHour = 60 #There are 60 minutes in 1 hour
    m_colorID = "#0000ff" #Set color to Blue
    
    m_scaleFactor = (minute*(width-fixedWidth))/m_toHour
    m_x1 = 0 + m_scaleFactor #dynamic
    m_x2 = fixedWidth + m_scaleFactor #dynamic

    s2_shape = [m_x1,m_y1,m_x2,m_y2] #bottom square of 10x10
    draw.rectangle(s2_shape, outline=0, fill=m_colorID)
    
    #-----------------------------------------------------------

    #Task: For the hours time component, propel rectangle across screen
    #in accordance to visual timekeeping of hours with limit of day
    h_y1 = 60 #Fixed
    h_y2 = 80 #Fixed
    h_toDay = 24 #There are 24 hours in 1 day
    h_colorID = "#00ff00" #Set color to Green
    
    h_scaleFactor = (hour*(width-fixedWidth))/h_toDay
    h_x2 = fixedWidth + h_scaleFactor #dynamic
    h_x1 = 0 + h_scaleFactor #dynamic

    
    #[x0, y0, x1, y1]
    s2_shape = [h_x1,h_y1,h_x2,h_y2] #bottom square of 10x10
    draw.rectangle(s2_shape, outline=0, fill=h_colorID)    

    # Display image.
    disp.image(image, rotation)
    time.sleep(.0001)


