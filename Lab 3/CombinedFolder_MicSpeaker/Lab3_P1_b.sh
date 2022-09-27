
# from https://elinux.org/RPi_Text_to_Speech_(Speech_Synthesis)

#Prompt the question
espeak -ven+m1 -k3 -s150 -a35 --stdout  "What's your zip code" | aplay

#Record the answer in wav
arecord -D hw:2,0 -f cd -c1 -r 16000 -d 5 -t wav recorded_mono.wav

#Analyze the recorded file
python3 test_words.py recorded_mono.wav

