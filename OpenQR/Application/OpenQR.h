




#pragma once
// lib
#include <opencv2/opencv.hpp>
#include <iostream>
#include <omp.h>
#include <algorithm> 


// lib of core num
#include <Windows.h>
#include <process.h>


// Macro
#define WINDOW_NAME "Camrea"		// the name of result window.
#define MARGIN_SIZE_OF_QRCODE 10		// it gives boundary margin of extracted QR codes.


// structures of QR codes
struct SquareContour
{
	cv::Point ptArr[4];		// edge points
	cv::Point2d midPt;
	double length;			// avg length of contours
};
struct PositionPattern
{
	SquareContour outer;
	SquareContour mid;	
	SquareContour inner;
};
struct QrCodePose
{
	// tmp
	std::vector<PositionPattern> tmpPositionPatterns;

	// markers
	PositionPattern positionPatternTopL;
	PositionPattern positionPatternTopR;
	PositionPattern positionPatternBotL;

	// edge points
	cv::Point ptTopL;	
	cv::Point ptTopR;	
	cv::Point ptTopR_neighbor;
	cv::Point ptBotL;	
	cv::Point ptBotL_neighbor;
	cv::Point ptBotR;	
	cv::Point ptMid;

	// boundBox
	cv::Rect boundBox;
};
struct QrCode
{
	bool flagDecoded = false;	// decoded or not
	QrCodePose expectedpose;	// expected pose by proposal
	cv::Mat image;				// segmented image of qr code
	cv::String str;				// decoded string
	cv::Point detectedPose[4];	// expected pose by openCV
	cv::Rect boundBox;
};


// structures for calculation
struct pointFindingHelper
{
	cv::Point pt;
	double distance;
};
struct angleFindingHelper
{
	cv::Point edgePt;
	cv::Point supportingPt;
	double angle;
	PositionPattern tmpPositionPattern;
};


// class 
class OpenQR
{
private:
	// input
	cv::VideoCapture* videoStream;
	int threadNum;

	// images for processing
	cv::Mat imgSource;
	cv::Mat imgGray;
	cv::Mat imgBin;
	cv::Mat imgMorphology;
	cv::Mat imgEdge;

	// Contours for processing
	std::vector<std::vector<cv::Point>> outlineContours;	// bad outline could make bad segments.
	std::vector<std::vector<cv::Point>> inlineContours;
	std::vector<SquareContour> squareContours;
	std::vector<PositionPattern> positionPatterns;
	std::vector<QrCodePose> qrCodeList;						// it could have bad segments or boundary-out .
	std::vector<QrCodePose> expectedQrCodes;				// it could have bad segments.

	// output
	cv::Mat imgOutput;
	std::vector<QrCode> qrcodes;		// it could have bad segments, but it could removed checking decoding flag.

private:
	int GetCoresSize();
	void SortBubble(std::vector<std::vector<cv::Point>>& outlineCoutours);
	void SortBubble(std::vector<SquareContour>& squareContours);
	double GetRotatedAngle(cv::Point center, cv::Point point);
	void RotatePt(cv::Point centerPt, cv::Point targetPt, cv::Point& outputPt, double angle);
	cv::Point GetSlicedPoint(const cv::Point& start, const cv::Point& end, const double sliceNum, const double num);
	int CorrectPtBotR(const cv::Point& ptBotL, const cv::Mat& imgBin, const cv::Point& refPtBotR, cv::Point& predictedPtBotR, const int pos = 0);
	bool GetIntersectionPoint(cv::Point a, cv::Point b, cv::Point c, cv::Point d, cv::Point* outputPt);
	QrCodePose GetQrCodePose(QrCodePose& qrcode, cv::Mat imgBin, int& flag);
	void ExtractQrCode(const cv::Mat& bin, cv::Mat& output, const cv::Point& TopLeft, const cv::Point& BottomLeft, const cv::Point& TopRight, const cv::Point& BottomRight);
	void FindMarginPoint(const cv::Point& orient, const cv::Point& target, cv::Point& out);
public:
	// new & delete & reset
	OpenQR();
	void SetThreadNum(int intputThreadNum);
	void Reset();
	// destroy(auto)

	// controls
	int OpenCamera(int width, int height);
	int ReadFrame();
	int CheckEscKey();

	// detection
	void FindExpectedQrcodes();
	void ConvertGray();
	void ConvertBin();
	void Morphology();
	void FindContours();
	void ExtractSquareContours();
	void FindPositionPatterns();
	void FindQrcodesList();
	void FindQrcodesPose();

	// segmentation
	void FindBoundBox();
	void SegmentWithTransform();
	void SegmentWithNoTransform();

	// decoding with openCV
	void DetectAndDecodeQrcodeWithOpenCV();

	// getter
	int GetExpectedNum();

	// show
	void DrawExpectedQrcodesBoundBox();
	void DrawExpectedQrcodes();
	void DrawDecodedQrcodesOnNoTransform();
	void DrawDecodingFailed();
	void DrawDecodedStr();
	void DrawText(cv::String str, cv::Point pos);
	void ShowOutput();
};