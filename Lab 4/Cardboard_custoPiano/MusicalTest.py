from psonic import *
import time
from subprocess import call
from synthesizer import Player, Synthesizer, Waveform
#play(C5)
#sleep(0.5)
#play(72)
#call(["espeak","-s140 -ven+18 -z",synth(SINE, note=D4)])
#sleep(1)

player = Player()
player.open_stream()
synthesizer = Synthesizer(osc1_waveform=Waveform.sine, osc1_volume=1.0, use_osc2=False)

#Play A4
player.play_wave(synthesizer.generate_constant_wave(440.0, 3.0))