
# from https://elinux.org/RPi_Text_to_Speech_(Speech_Synthesis)
espeak -ven+m1 -k3 -s150 -a35 --stdout  "test" | aplay
 
