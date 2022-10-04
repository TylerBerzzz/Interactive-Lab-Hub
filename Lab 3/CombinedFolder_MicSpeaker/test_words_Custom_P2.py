#!/usr/bin/env python3

from vosk import Model, KaldiRecognizer
import sys
import os
import wave
import subprocess
import random
import board
import digitalio
from adafruit_apds9960.apds9960 import APDS9960
from subprocess import call

if not os.path.exists("model"):
    print ("Please download the model from https://github.com/alphacep/vosk-api/blob/master/doc/models.md and unpack as 'model' in the current folder.")
    exit (1)

wf = wave.open(sys.argv[1], "rb")
if wf.getnchannels() != 1 or wf.getsampwidth() != 2 or wf.getcomptype() != "NONE":
    print ("Audio file must be WAV format mono PCM.")
    exit (1)

model = Model("model")
# You can also specify the possible word list
rec = KaldiRecognizer(model, wf.getframerate(), "what is sensor value four the nine [unk]")

#Sensor Setup
i2c = board.I2C()
apds = APDS9960(i2c)
apds.enable_proximity = True


while True:
    data = wf.readframes(4000)
    if len(data) == 0:
        break
    if rec.AcceptWaveform(data):
        print("test")
        #print(rec.Result())
        
    #else:
        #print(rec.PartialResult())

number = rec.Result()
print("-----------------------------------------------")
print(number)
#print(number)
#correctingString = number[-6:]
correctingString = number[-27:-3]

print(correctingString)

if correctingString == "what is the sensor value":
    print("----")
    print(correctingString)
    currentDistance = apds.proximity
    print(currentDistance)
    call(["espeak","-s140 -ven+18 -z","The sensor 0 to 255 value is"])
    call(["espeak","-s140 -ven+18 -z",str(currentDistance)])
    call(["espeak","-s140 -ven+18 -z","units"])
