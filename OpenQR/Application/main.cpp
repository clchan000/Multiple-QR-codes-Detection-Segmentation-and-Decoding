/*****************************************************************
* 2019. 10. 29.
* QR code detector
* close key: ESC, Ctrl+C
*****************************************************************/

// Header
#include <iostream>
#include <stdio.h>
#include <time.h>

// Header
#include "OpenQR.h"

// main
int main(void)
{
	// object
	OpenQR openQR;

	// vals
	clock_t timeStarting;		// ms timer
	const int mode = 1;			// segmentation mode(1 = without transformation, 2 = with transformation)

	// set thread num
	// If you want to set thread, use this function
	// openQR.SetThreadNum(threadNum);

	// open camera
	if (openQR.OpenCamera(1920, 1080) == -1)	// open camera 1920 x 1080 resolution
		return -1;

	// infinite loop
	while (1)
	{
		// ESC key detection (END condition)
		if (openQR.CheckEscKey() == 1)
			break;

		// Check reading error
		if (openQR.ReadFrame() == -1)
			return -1;

		// Set timer
		timeStarting = clock();

		// Detect QR codes
		openQR.FindExpectedQrcodes();

		// Segment detected QR codes
		if (mode == 1)
			openQR.SegmentWithNoTransform();
		else if(mode == 2)
			openQR.SegmentWithTransform();

		// Decoding(OpenCV need to re-detect...)
		openQR.DetectAndDecodeQrcodeWithOpenCV();

		// Show
		// openQR.DrawExpectedQrcodesBoundBox();
		// openQR.DrawDecodedQrcodesOnNoTransform(); // this function works only on SegmentWithNoTransform()
		// openQR.DrawDecodingFailed();
		openQR.DrawExpectedQrcodes();
		openQR.DrawDecodedStr();
		openQR.DrawText(cv::format("Processing: %.3f sec/frame", ((double)clock() - (double)timeStarting) / 1000.0), cv::Point(10, 20));
		openQR.DrawText(cv::format("* QR codes: %d", openQR.GetExpectedNum()), cv::Point(10, 40));
		openQR.ShowOutput();
		
		// Reset data
		openQR.Reset();

	} // while()

	// end
	return 0;

}	// main()

