# traffic-crossing

An Arduino Pro Mini project that alternates between a red and green light to simulate a pedestrian traffic crossing.

Tones are Australian based, reversed engineered from a recording.

# Summary

Its been a long time coming (I've had these lights for about a decade) and finally this project is completed!

This is an Arduino based light controller project that uses a single momentary push button to trigger the crossing sequence.

A button push initiate the traffic crossing sequence which cycles through a "wait on red light" to "go on green light" to "don't walk flashing red" to "solid red light".

Sound was added to add authenticity as the lights alone were quite boring. The tones and timings are as close to authentic Australian sounds heard at a real crossing, reversed engineered from a YouTube video recording (not mine, see links).

# Details on the sound

After getting the source audio into the analysis software, there were three distinct sequences that were required. I called these audio functions: playIdle, playChirp and playWoodpecker.

Play Idle uses a 973Hz tone that runs for 25ms, followed by an 1800ms delay in between pulses.

The Chirp sound consists of 11 separate tones, each played for 11ms, totalling 121ms. I calculated 125ms from the spectral analysis so this was close enough. The tones are stored in an array and play in order within a for loop that cycles through each one. 

Play Woodpecker is a fast 500Hz beat. Each tone lasts a very short 30ms, with a delay of 117ms between beats. This lasts a generous 10 seconds, which is frankly a lot longer than most crossings in real life!

The idle tone is used again during the final red flashing sequence and subsequent wait sequence.

Since I didn't want the idle tone to play indefinitely after the completion of a sequence, it is only repeated three times then the sounds ceases and the button detection to kick off the entire sequence commences once again.

# Links

Link to example video of project:
https://www.youtube.com/watch?v=Tf-1cvpUQFY

Link to source recording:
https://www.youtube.com/watch?v=n7N3M4OcoNs

Link to Hack a day page:
https://hackaday.io/project/166957-traffic-light-crossing/

Link to Free Arduino Source Code:
https://github.com/ronnied/traffic-crossing