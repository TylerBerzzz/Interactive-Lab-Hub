# Inspiration & Need:

My father has a pool in Florida and currently scoops out items on the surface by manually swooping a butterfly net across the pool. This is bad for his back, boring, and takes a long time to do a good job. Thus, there is a need to develop a controllable aquatic vehical to capture debris.

![image](https://user-images.githubusercontent.com/30520534/206319954-3f09ea07-08f3-4c4a-996f-c6462ef12abf.png)

# Goals:
1. To prove I can build a boat that floats on water
2. To prove I can communicate with the boat from a distance effectively
3. Incorporate forward thinking in iterating off of a built prototype. 

# Previously Submitted Project Plan
![image](https://user-images.githubusercontent.com/30520534/206780269-684acab9-24ee-4d10-9673-7a4d53f5cd89.png)
![image](https://user-images.githubusercontent.com/30520534/206780281-22ff919f-d667-4ef0-816d-4c10e1fd4ee2.png)


# Storyboard: 

![image](https://user-images.githubusercontent.com/30520534/206777969-39ca0333-7100-4325-94bc-3046b0f46487.png)

# Paper Prototype:

![image](https://user-images.githubusercontent.com/30520534/206779013-293d5c9e-f886-4e6e-bcad-64fa8a5e06e3.png)


# Design Approach:
**1. Physics**
![image](https://user-images.githubusercontent.com/30520534/206320059-0dcfddd6-a985-4594-ab5c-49d9ea87beb4.png)
![image](https://user-images.githubusercontent.com/30520534/206320071-85f08ea9-19ed-47cb-a18b-0a6a8e83e5c4.png)

**2. System**
![image](https://user-images.githubusercontent.com/30520534/206320134-90b65567-e11b-4768-adab-516de3347409.png)

# Derisking: 
![image](https://user-images.githubusercontent.com/30520534/206320264-6dc306fc-7e7d-49b7-b33f-ade6b398fb12.png)

![image](https://user-images.githubusercontent.com/30520534/206320280-11366dbb-e6ac-42ab-9d4a-5dae17e665ac.png)

# Rapid Prototyping:
1. From the Derisking step, Prove that I can control servos and motors using a tethered microcontroller: https://youtu.be/NyBV2msOd8c 
2. Prove that I can identify "blobs" on the surface of water
![image](https://user-images.githubusercontent.com/30520534/206321396-904bf5ce-d0db-4e0e-a1ee-044af769cd89.png)
**Using the OPENCV library in python for blob detection:**
![image](https://user-images.githubusercontent.com/30520534/206325947-648905d3-6feb-4661-80c4-e835f8a0b031.png)
3.Prove wireless (Radio) Communication: 
https://drive.google.com/file/d/1tiYHBXwHc78OS9yToECbyxECfWwvj2Mj/view?usp=share_link

# Prototype 1:
**Electronics System Design**
![image](https://user-images.githubusercontent.com/30520534/206327584-f6b07bae-854b-4a17-9e16-181b0bcaea04.png)

**Manufacturing the boat**
![image](https://user-images.githubusercontent.com/30520534/206772924-91cdfa04-8836-4121-8a72-7db9de4de1a1.png)
![image](https://user-images.githubusercontent.com/30520534/206773780-bdb47093-72cb-4a48-8853-9e2edc817609.png)

Polystyrene foam was used because of its low density. A hot wire, nichrome, cutter enabled shaping the foam to the desired shape of interest. Using the physics equations in the prior sections, I was able to be certain that the design was displacing enough water to float. 

![image](https://user-images.githubusercontent.com/30520534/206773600-03d9478c-c211-4618-8c37-084a6fbad567.png)

**Radio Controller** 

![image](https://user-images.githubusercontent.com/30520534/206774214-4cb8b398-20e4-4ffe-a4eb-f0a64bd303ba.png)

The radio sender was connected to a joystick and tethered to a computer to provide power. 

**Float and Propulsion Test with Interaction driving the boat**

![image](https://user-images.githubusercontent.com/30520534/206770511-b0af42a3-6034-4830-80ae-8aa322c970f9.png)


Video Link: https://drive.google.com/file/d/1zhyq8YiV5g2q668cihxcUEzAEmSBbmOi/view?usp=share_link
Note: 5V battery current was unable to support the current required from the 12V motor, even after boosting it to 12 Volts. For this reason, a wired power supply was needed to sustain motion of the watercraft.
