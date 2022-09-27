#!/usr/bin/env python3

from vosk import Model, KaldiRecognizer
import sys
import os
import wave
import subprocess
import random
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
rec = KaldiRecognizer(model, wf.getframerate(), "zero oh one two three four five six seven eight nine [unk]")

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
#print(number)
#correctingString = number[-6:]
correctingString = number[-6:-2]

print(correctingString)

numArray = ['one"','two"','ree"']
randomNum = random.randint(0,2)
thinkingOf = numArray[randomNum]
print(thinkingOf)

if correctingString == thinkingOf:
    print("----")
    print(correctingString)
    print(thinkingOf)
    call(["espeak","-s140 -ven+18 -z","You win"])
    
else:
    print("----")
    print(correctingString)
    print(thinkingOf)
    call(["espeak","-s140 -ven+18 -z","You lose"])
#print(rec.FinalResult())
