
# from https://elinux.org/RPi_Text_to_Speech_(Speech_Synthesis)
espeak -ven+f1 -k3 -s150 -a35 --stdout  "what number am I thinking of? It's between 1 and 3" | aplay
arecord -D hw:2,0 -f cd -c1 -r 44100 -d 2 -t wav recorded_mono.wav
python3 test_words_Custom.py recorded_mono.wav

#echo "some data for the file" >> fileName.txt
