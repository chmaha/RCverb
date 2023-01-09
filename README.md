# RCVerb
A reverb suitable for classical music based on zita-rev1

![image](https://user-images.githubusercontent.com/120390802/211276686-df5f40dc-0b60-4d50-8cc8-b9ae812e2215.png)

#### Controls

Delay = Delay in ms  
LowFreq X = Low frequency Crossover point in Hz  
RT60 = Decay time in seconds  
HF Damping = High frequency damping in Hz  
Wet/Dry Mix = Wetter to the left, drier to the right.  

Plugin defaults to 40ms delay, 250Hz crossover, 2 seconds, 3Khz damping and 50/50 wet/dry mix. This is ready to use as an insert. As a send (with dedicated reverb bus) simply move the wet/dry slider all the way to the left and adjust the channel fader to taste. 

#### Building

```
$ git clone --recursive https://github.com/chmaha/RCverb.git
$ cd RCVerb
$ make
```

