from pypiano import Piano
from mingus.containers import Note

p = Piano()

# Play a simple C-4 via audio
p.play("C-4")

# Play a mingus Note
note = Note("C-4")
p.play(note)

# Record a Note to a wav file
p.play(note, recording_file="my_first_recording.wav", record_seconds=2)

# Use a different instrument
p.load_instrument("Honky-tonk Piano")
p.play(note)