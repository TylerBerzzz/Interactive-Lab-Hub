
# from https://elinux.org/RPi_Text_to_Speech_(Speech_Synthesis)
espeak -ven+f1 -k3 -s150 -a35 --stdout  "What do you want" | aplay
arecord -D hw:2,0 -f cd -c1 -r 16000 -d 3 -t wav recorded_mono.wav
python3 test_words_Custom_P2.py recorded_mono.wav

#echo "some data for the file" >> fileName.txt
