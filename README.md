# RCVerb ("ReaClassical Verb")
A reverb suitable for classical music based on zita-rev1

![image](https://user-images.githubusercontent.com/120390802/211276686-df5f40dc-0b60-4d50-8cc8-b9ae812e2215.png)

#### Controls

Initial Delay = Delay in ms  
LowFreq X = Low frequency Crossover point in Hz  
Decay (RT60) = Decay time in seconds  
HF Damping = High frequency damping in Hz  
Wet/Dry Mix = Wetter to the left, drier to the right.  

Plugin defaults to 40ms delay, 250Hz crossover, 2 seconds, 3Khz damping and 50/50 wet/dry mix. This is ready to use as an insert. As a send (with dedicated reverb bus) simply move the wet/dry slider all the way to the left and adjust the channel fader to taste. 



https://user-images.githubusercontent.com/120390802/211299438-6c6fad9a-ff35-4949-b681-41ad7c0ffd5c.mp4

https://user-images.githubusercontent.com/120390802/211299492-0a6b58b3-b1e7-44c6-99a4-ebb7eedcca23.mp4

## Building

```
$ git clone --recursive https://github.com/chmaha/RCverb.git
$ cd RCVerb
$ make
```
## Author

This software is by *chmaha* (a revision of https://github.com/SpotlightKid/dfzitarev1).


## License

This plugin is released under the *GPLv3 License*. Please see the
[LICENSE](./LICENSE) file for details.


## Acknowledgements

The DSP code is generated from the FAUST sources via the [faustpp]
pre-processor and uses my modified version of the [dm.zita_rev1] demo from the FAUST library, written
by Julius O. Smith III [^1], which is a re-implementation of [zita-rev1] by Fons
Adriaensen, writen in C++.

The project is built using the DISTRHO Plugin Framework ([DPF]) and set up
with the [cookiecutter-dpf-faust] project template.
