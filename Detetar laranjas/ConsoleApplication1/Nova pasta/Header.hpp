// ***********************************************************************
// Assembly         : Visao
// Author           : Joaquim Cardoso  && Heitor Campos && Fernando Correia
// Created          : 15/05/2016
// Contact          : joaquimcardoso12@hotmail.com
// Last Modified By : Utilizador
// Last Modified On : 10/06/2016
// ***********************************************************************
// <copyright file="Program.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary>Este Projecto resolve o trabalho prático nº2 proposto pelo professor de visão por computador.</summary>
// ***********************************************************************


#include <stdio.h>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <windows.h>	
#include<iostream>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>	
#include <locale.h>
#include <Lmcons.h>	

#pragma warning(disable : 4996) 


using namespace std;
using namespace cv;

#pragma region Defines

#define PASSAIMAGEM 1
#define PERCENTAGEM 20
#define RADIUS 5
#define CONTORNO 0.7
#define PIXEIS 280
#define MM 55
#define VALOR 100
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define MAX3(a,b,c) (a > b ? (a > c? a: c) : (b > c? b : c))
#define MIN3(a,b,c) (a < b ? (a < c? a: c) : (b < c? b : c))	 
#define XORSWAP (a, b) ((a)^=(b),(b)^=(a),(a)^=(b))

#pragma endregion

#pragma region Estruturas

typedef struct {
	int x, y, width, height;	// Caixa Delimitadora (Bounding Box)
	int area;					// area
	int xc, yc;					// Centro-de-massa
	int perimeter;				// Perimetro
	int label;					// Etiqueta

	float corR;
	float corG;
	float corB;
	long int pixeisLaranja;
	long int pixeisPretos;
	long int pixeisOutros;
} OVC;

//Listas Ligadas
typedef struct nodo {
	unsigned int yMin;
	unsigned int yMax;
	unsigned int pixeis;
	struct nodo *seguinte;
} *Lista, no;

typedef struct {
	unsigned int x;
	unsigned int y;

}Coordenadas;

#pragma endregion

#pragma region Assinatura dos Metodos


int vc_categorize(Mat src, OVC imagem);

int vc_categorize2(Mat src, OVC imagem);

Mat vc_find_contourn(Mat src);

Mat remove_fundo(Mat src);

int vc_bgr_to_hsv(Mat src, int xMin, int yMin, int xMax, int yMax);

int vc_bgr_to_hsv2(Mat src, Mat ref, int xMin, int yMin, int xMax, int yMax, int *pixeisVerde, int *pixeisOutros, float corB, float corG, float corR);

Mat vc_binary_erode(Mat src, OVC objeto, int kernel);

Mat vc_binary_erode2(Mat src, int kernel);

Mat vc_bgr_to_gray(Mat src);

Mat vc_gray_to_binary(Mat src, int lim);

int vc_detect_stuff(Mat src, OVC objecto);

Mat vc_gray_negative(Mat src);

OVC* vc_binary_blob_labelling(Mat src, Mat &dst, int *nlabels, int* auxtable);

int vc_binary_blob_info(Mat src,Mat ref, OVC *blobs, int nblobs, int* auxtable);

void DefinePt();

void Apresentacao(TCHAR* username);

Mat vc_redimention_size(Mat contornos, OVC* objecto, int numero);

#pragma endregion


