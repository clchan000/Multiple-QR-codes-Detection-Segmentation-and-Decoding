# Real-time multiple QR codes detection and segmentation

* This is a experimental project for "Advanced Parallel Computing 2019-2" and "Vision System 2018-1".
* The project's basic algorithm was made in "Vision System 2018-1."
* And then, Parallel processing and multiple detection were applied in "Advanced Parallel Computing 2019-2".

<br>

## Features

### Works
* Detect Multiple QR codes present on a frame at the same time.
* Segment detected QR codes.
* Re-detect and Decord them with openCV function(OpenCV detector is not good, it should be fixed.)

### Outputs
* The images of Segmented QR codes(mode1: not-aligned, mode2:aligned)
* The positions of Segmented QR codes
* The decorded information of Segmented QR codes

### Environments
* Windows 10
* C/C++, Visual Studio 2019
* openMP
* openCV 4.1.1
* Webcam

### limitation
* QR Code model1, model2 Only

<br>

## Youtube
### 20191221 Multple QR codes detection and decoding using openCV
[![예제](http://img.youtube.com/vi/QyaFEmmOGdk/0.jpg)](https://youtu.be/QyaFEmmOGdk?t=0s) 
<br>

* https://youtu.be/QyaFEmmOGdk
* Bounding boxs shows detected QR code positions.
* The Blue lines show the bottom of QR codes.

<br>

### 20191216 Real-time multiple QR codes detection and segmentation
[![예제](http://img.youtube.com/vi/atH0RJN-ODs/0.jpg)](https://youtu.be/atH0RJN-ODs?t=0s) 
<br>

* https://youtu.be/atH0RJN-ODs
* Bounding boxs shows detected QR code positions.
* The Blue lines show the bottom of QR codes.

<br>
<br>

### 20180503 Basic Algorithims(single detection, Korean)
[![예제](http://img.youtube.com/vi/JlwNKRQJ5h0/0.jpg)](https://youtu.be/JlwNKRQJ5h0?t=0s) 
<br>

* https://youtu.be/JlwNKRQJ5h0
* 
<br>
<br>

## Run
1. Download OpenCV 4.1.1(https://sourceforge.net/projects/opencvlibrary/files/4.1.1/opencv-4.1.1-vc14_vc15.exe/download)
2. Decompress it on the path "C:\"
3. Clone this project
4. Open the project file and complie it



