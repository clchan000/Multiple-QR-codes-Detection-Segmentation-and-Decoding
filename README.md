# Multiple QR codes Detection, Segmenation and Decoding

* A real-time multiple QR codes decorder based on C++, openCV, and openMP
[![예제](http://img.youtube.com/vi/QyaFEmmOGdk/0.jpg)](https://youtu.be/QyaFEmmOGdk?t=0s) 
<br>
* Youtube #1 https://youtu.be/QyaFEmmOGdk
* Youtube #2 https://youtu.be/atH0RJN-ODs
* Youtube #3 https://youtu.be/JlwNKRQJ5h0
<br>

## Features

### Works
* Detect Multiple QR codes present on a frame at the same time.
* Detect and Segment detected QR codes.
* Re-detect and Decord them with openCV function(OpenCV detector is not good, it should be fixed.)

### Outputs
* The images of segmented QR codes(mode1: not-aligned, mode2:aligned)
* The positions of segmented QR codes
* The decorded information of segmented QR codes

### Environments
* Windows 10
* C/C++, Visual Studio 2019
* openMP
* openCV 4.1.1
* Webcam

### limitation
* QR Code model1, model2 Only
* No distortion removal

<br>

## Run
1. Download OpenCV 4.1.1(https://sourceforge.net/projects/opencvlibrary/files/4.1.1/opencv-4.1.1-vc14_vc15.exe/download)
2. Decompress it on the path "C:\"
3. Clone this project
4. Open the project file and complie it



