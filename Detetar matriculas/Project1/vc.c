// ***********************************************************************
// Assembly         : Visao
// Author           : Joaquim Cardoso
// Created          : 15/03/2016
// Contact          : joaquimcardoso12@hotmail.com
// Last Modified By : Joaquim Cardoso
// Last Modified On : 16/04/2016
// ***********************************************************************
// <copyright file="Program.cs" company="">
//     Copyright ©  2016
// </copyright>
// <summary>Este Projecto resolve o trabalho prático proposta pelo professor de visão por computador.</summary>
// ***********************************************************************

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "vc.h"
#pragma warning(disable : 4996)



#pragma region Minhas

	#pragma region Imagens

	int imagem_um(IVC *imageSrc, IVC *imageDst)
	{
		int r=1;

		IVC *imageTmp;
		IVC *imageTmpD;

		imageTmp = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmpD = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

	
		r &= vc_rgb_to_gray(imageSrc, imageTmp);
		vc_write_image("Novas_Imagens\\Polo\\polo_RGB_to_GRAY.pgm", imageTmp);
		
		r &= vc_gray_to_binary(imageTmp, 100);
		vc_write_image("Novas_Imagens\\Polo\\polo_GRAY_to_BINARY.pbm", imageTmp);
		
		r &= vc_focus_area(imageTmp, 20,PRETO);
		vc_write_image("Novas_Imagens\\Polo\\polo_FOCUS_AREA.pbm", imageTmp);
		
		r &= vc_clear_missing_pixels(imageTmp, 2, 0, 0); // limpar o conjunto no maximo de 3 pixeis sendo que estes possam nao ter espaço
		vc_write_image("Novas_Imagens\\Polo\\polo_CLEAR_MISSING_PIXEIS.pbm", imageTmp);
		
		r &= vc_clear_lines(imageTmp, 0, 5.0);		     // maior que a percentagem logo apaga
		vc_write_image("Novas_Imagens\\Polo\\polo_CLEAR_LINES.pbm", imageTmp);
		
		r &= vc_gray_negative(imageTmp);
		vc_write_image("Novas_Imagens\\Polo\\polo_NEGATIVE.pbm", imageTmp);
		
		r &= vc_binary_open(imageTmp, imageDst, 3);
		vc_write_image("Novas_Imagens\\Polo\\polo_BINARY_OPEN.pbm", imageDst);
		
		r &= vc_segment_area(imageDst, 50, 220, 255); // defenir uma area Ex: 100x100  e o conjunto minimo de numeros para que nao seja apagada neste caso 200
		vc_write_image("Novas_Imagens\\Polo\\polo_SEGMENT_AREA.pbm", imageDst);
	
		r &= vc_only_live_greatter_zona(imageDst, BRANCO);
		vc_write_image("Novas_Imagens\\Polo\\polo_ONLY_BIG_AREA.pbm", imageDst);
	
		r &= vc_binary_erode(imageDst, imageTmpD, 3);
		vc_write_image("Novas_Imagens\\Polo\\polo_BINARY_ERODE.pbm", imageTmpD);

		r &= vc_clear_missing_pixels(imageTmpD, 1, imageTmpD->width / 2, 255);
		r &= vc_clear_missing_pixels(imageTmpD, 20, imageTmpD->width / 2, 255);
		vc_write_image("Novas_Imagens\\Polo\\polo_CLEAR_LINES2.pbm", imageTmpD);
		
		r &= vc_binary_dilate(imageTmpD, imageDst, 3);
		vc_write_image("Novas_Imagens\\Polo\\polo_BINARY_DILATE.pbm", imageDst);

		
		printf("\n\n------------\n%s\n------------\n", str_reverse(vc_identify_plate(imageDst, BRANCO)));
		
		r &= vc_rentangle(imageDst, EspacoMatricula,BRANCO);

		vc_image_free(imageTmp);
		vc_image_free(imageTmpD);

		return r; 	
	}

	int imagem_dois(IVC *imageSrc, IVC *imageDst)
	{
		int r = 1;

		IVC *imageTmp;
		IVC *imageTmpD;

		imageTmp = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmpD = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

	
		r &= vc_rgb_to_gray(imageSrc, imageTmp);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_RGB_to_GRAY.pgm", imageTmp);
	
		r &= vc_gray_to_binary(imageTmp, 70);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_GRAY_to_BINARY.pbm", imageTmp);
		
		r &= vc_focus_area(imageTmp, 15, PRETO);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_FOCUS_AREA.pbm", imageTmp);
	
		r &= vc_clear_missing_pixels(imageTmp, 2, 0, 0); // limpar o conjunto no maximo de 3 pixeis sendo que estes possam nao ter espaço
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_CLEAR_MISSING_PIXEIS.pbm", imageTmp);
	
		r &= vc_clear_lines(imageTmp, 0, 5.0);		     // maior que a percentagem logo apaga
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_CLEAR_LINES.pbm", imageTmp);		  
	
		r &= vc_gray_negative(imageTmp);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_NEGATIVE.pbm", imageTmp);
		
		r &= vc_binary_open(imageTmp, imageDst, 3);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_BINARY_OPEN.pbm", imageDst);
		  
		r &= vc_segment_area(imageDst, 90, 500, 255); // defenir uma area Ex: 100x100  e o conjunto minimo de numeros para que nao seja apagada neste caso 200
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_SEGMENT_AREA.pbm", imageDst);
		
		r &= vc_only_live_greatter_zona(imageDst, BRANCO);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_ONLY_BIG_AREA.pbm", imageDst);
		
		r &= vc_binary_erode(imageDst, imageTmpD, 3);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_BINARY_ERODE.pbm", imageTmpD);

		r &= vc_clear_missing_pixels(imageTmpD, 1, 0, 255);
		r &= vc_clear_missing_pixels(imageTmpD, 20, imageTmpD->width/2, 255);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_CLEAR_MISSING_PIXEIS2.pbm", imageTmpD);
		
		r &= vc_binary_dilate(imageTmpD, imageDst, 3);
		vc_write_image("Novas_Imagens\\Mercedes_estranho\\mercedes_estranho_BINARY_DILATE.pbm", imageDst);
		
		printf("\n\n------------\n%s\n------------\n", str_reverse(vc_identify_plate(imageDst, BRANCO)));
		
		r &= vc_rentangle(imageDst, EspacoMatricula, BRANCO);
		
		vc_image_free(imageTmp);
		vc_image_free(imageTmpD);
		

		return r;

	}

	int imagem_tres(IVC *imageSrc, IVC *imageDst)
	{
		int r = 1;

		IVC *imageTmp;
		IVC *imageTmpD;

		imageTmp = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmpD = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

		r &= vc_rgb_to_gray(imageSrc, imageTmp);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_RGB_to_GRAY.pgm", imageTmp);
		
		r &= vc_gray_to_binary(imageTmp, 190);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_GRAY_to_BINARY.pbm", imageTmp);
		
		r &= vc_focus_area(imageTmp, 20,PRETO);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_FOCUS_AREA.pbm", imageTmp);
		
		r &= vc_clear_missing_pixels(imageTmp, 2, 0, 0); // limpar o conjunto no maximo de 2 pixeis sendo que estes possam nao ter espaço
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_CLEAR_MISSING_PIXEIS.pbm", imageTmp);
		
		r &= vc_clear_lines(imageTmp, 0, 5.0);		     // maior que a percentagem logo apaga
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_CLEAR_LINES.pbm", imageTmp);
		
		r &= vc_gray_negative(imageTmp);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_NEGATIVE.pbm", imageTmp);
		
		r &= vc_binary_open(imageTmp, imageTmpD, 3);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_BINARY_OPEN.pbm", imageTmp);
		
		r &= vc_segment_area(imageTmpD, 65, 200, 255); // defenir uma area Ex: 100x100  e o conjunto minimo de numeros para que nao seja apagada neste caso 200
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_SEGMENT_AREA.pbm", imageTmpD);
		
		r &= vc_only_live_greatter_zona(imageTmpD, BRANCO);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_ONLY_BIG_AREA.pbm", imageTmpD);
		
		r &= vc_binary_erode(imageTmpD, imageTmp, 3);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_BINARY_ERODE.pbm", imageTmp);
		
		r &= vc_clear_missing_pixels(imageTmp, 1, 100, 255); // limpar o conjunto no maximo de 3 pixeis sendo que estes possam nao ter espaço
		r &= vc_clear_missing_pixels(imageTmpD, 20, imageTmpD->width / 2, 255);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_CLEAR_MISSING_PIXEIS2.pbm", imageTmp);
		
		r &= vc_binary_dilate(imageTmp, imageDst, 3);
		vc_write_image("Novas_Imagens\\Mercedes\\mercedes_BINARY_DILATE.pbm", imageDst);
		
		printf("\n\n------------\n%s\n------------\n", str_reverse(vc_identify_plate(imageDst, BRANCO)));
		
		r&=vc_rentangle(imageDst, EspacoMatricula, BRANCO);


		vc_image_free(imageTmp);
		vc_image_free(imageTmpD);


		return r;

	}

	int imagem_quatro(IVC *imageSrc, IVC *imageDst)
	{
		int r = 1;

		IVC *imageTmp;
		IVC *imageTmpD;

		imageTmp = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmpD = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

		r &= vc_rgb_to_gray(imageSrc, imageTmp);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_RGB_to_GRAY.pgm", imageTmp);
		
		r &= vc_gray_to_binary(imageTmp, 100);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_GRAY_to_BINARY.pbm", imageTmp);
		
		r &= vc_focus_area(imageTmp, 20, PRETO);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_FOCUS_AREA.pbm", imageTmp);
		
		r &= vc_clear_missing_pixels(imageTmp, 2, 0, 0); // limpar o conjunto no maximo de 3 pixeis sendo que estes possam nao ter espaço
		vc_write_image("Novas_Imagens\\Volvo\\volvo_CLEAR_MISSING_PIXEIS.pbm", imageTmp);
		
		r &= vc_clear_lines(imageTmp, 0, 5.0);		     // maior que a percentagem logo apaga
		vc_write_image("Novas_Imagens\\Volvo\\volvo_CLEAR_LINES.pbm", imageTmp);
		
		r &= vc_gray_negative(imageTmp);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_NEGATIVE.pbm", imageTmp);
		
		r &= vc_binary_open(imageTmp, imageTmpD, 3);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_BINARY_OPEN.pbm", imageTmpD);
			   
		r &= vc_segment_area(imageTmpD, 65, 200, 255); // defenir uma area Ex: 100x100  e o conjunto minimo de numeros para que nao seja apagada neste caso 200
		vc_write_image("Novas_Imagens\\Volvo\\volvo_SEGMENT_AREA.pbm", imageTmpD);
		
		r &= vc_only_live_greatter_zona(imageTmpD, BRANCO);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_ONLY_BIG_AREA.pbm", imageTmpD);
		
		r &= vc_binary_erode(imageTmpD, imageTmp, 3);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_BINARY_ERODE.pbm", imageTmp);
		
		r &= vc_clear_missing_pixels(imageTmp, 1, 100, 255); // limpar o conjunto no maximo de 3 pixeis sendo que estes possam nao ter espaço
		r &= vc_clear_missing_pixels(imageTmpD, 20, imageTmpD->width / 2, 255);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_CLEAR_MISSING_PIXEIS2.pbm", imageTmp);
		
		r &= vc_binary_dilate(imageTmp, imageDst, 3);
		vc_write_image("Novas_Imagens\\Volvo\\volvo_BINARY_DILATE.pbm", imageDst);
		
		printf("\n\n------------\n%s\n------------\n", str_reverse(vc_identify_plate(imageDst, BRANCO)));
		
		r&=vc_rentangle(imageDst, EspacoMatricula, BRANCO);


		vc_image_free(imageTmp);
		vc_image_free(imageTmpD);


		return r;

	}

	int imagem_cinco(IVC *imageSrc, IVC *imageDst)
	{
		int r = 1;

		IVC *imageTmp;
		IVC *imageTmpD;

		imageTmp = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmpD = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

		r &= vc_rgb_to_gray(imageSrc, imageTmp);
		vc_write_image("Novas_Imagens\\Branco\\branco_RGB_to_GRAY.pgm", imageTmp);

		r &= vc_gray_to_binary(imageTmp, 70);
		vc_write_image("Novas_Imagens\\Branco\\branco_GRAY_to_BINARY.pbm", imageTmp);

		r &= vc_focus_area(imageTmp, 29, PRETO);
		vc_write_image("Novas_Imagens\\Branco\\branco_FOCUS_AREA.pbm", imageTmp);

		r &= vc_clear_missing_pixels(imageTmp, 1, 0, 0); // limpar o conjunto no maximo de 3 pixeis sendo que estes possam nao ter espaço
		vc_write_image("Novas_Imagens\\Branco\\branco_CLEAR_MISSING_PIXEIS.pbm", imageTmp);

		r &= vc_clear_lines(imageTmp, 0, 5.0);		     // maior que a percentagem logo apaga
		vc_write_image("Novas_Imagens\\Branco\\branco_CLEAR_LINES.pbm", imageTmp);

		r &= vc_gray_negative(imageTmp);
		vc_write_image("Novas_Imagens\\Branco\\branco_NEGATIVE.pbm", imageTmp);

		r &= vc_binary_open(imageTmp, imageTmpD, 3);
		vc_write_image("Novas_Imagens\\Branco\\branco_BINARY_OPEN.pbm", imageTmpD);

		r &= vc_segment_area(imageTmpD, 65, 200, 255); // defenir uma area Ex: 100x100  e o conjunto minimo de numeros para que nao seja apagada neste caso 200
		vc_write_image("Novas_Imagens\\Branco\\branco_SEGMENT_AREA.pbm", imageTmpD);

		r &= vc_only_live_greatter_zona(imageTmpD, BRANCO);
		vc_write_image("Novas_Imagens\\Branco\\branco_ONLY_BIG_AREA.pbm", imageTmpD);

		r &= vc_binary_erode(imageTmpD, imageTmp, 3);
		vc_write_image("Novas_Imagens\\Branco\\branco_BINARY_ERODE.pbm", imageTmp);

		r &= vc_clear_missing_pixels(imageTmp, 1, 100, 255); // limpar o conjunto no maximo de 3 pixeis sendo que estes possam nao ter espaço
		r &= vc_clear_missing_pixels(imageTmp, 20, imageTmp->width / 2, 255);
		vc_write_image("Novas_Imagens\\Branco\\branco_CLEAR_MISSING_PIXEIS2.pbm", imageTmp);
		
		r &= vc_binary_dilate(imageTmp, imageDst, 3);
		vc_write_image("Novas_Imagens\\Branco\\branco_BINARY_DILATE.pbm", imageDst);

		printf("\n\n------------\n%s\n------------\n", str_reverse(vc_identify_plate(imageDst, BRANCO)));

		r &= vc_rentangle(imageDst, EspacoMatricula, BRANCO);


		vc_image_free(imageTmp);
		vc_image_free(imageTmpD);


		return r;
	}

	int imagem_todas(char * filenew, char* fileold)
	{
		int r = 1;
		float mean;
		IVC *imageSrc;
		IVC *imageDst;
		IVC *imageTmp;
		IVC *imageTmpD;

		imageSrc = vc_read_image(fileold);
		imageDst = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmp = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmpD = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

		int* pontos = (int*)calloc(4, sizeof(int));
		int percentagem = ((imageDst->width) * PERCENTAGEM) / 100;

		r &= vc_rgb_to_gray(imageSrc, imageTmp);
	
		r &= vc_gray_edge_sobel(imageTmp, imageTmpD,0.97);
		
		r &= vc_focus_area(imageTmpD, 17, PRETO);
		
		r &= vc_segment_area(imageTmpD, 50, 50, BRANCO);
		
		r &= vc_only_live_greatter_zona(imageTmpD, BRANCO);
		
		r &= vc_clear_missing_pixels(imageTmpD, 2, imageTmpD->width / 6, BRANCO);
		
		mean = vc_line_mean(imageTmpD,BRANCO);		
		r &= vc_line_mean_compare(imageTmpD, mean*1.1, BRANCO);
		
		r &= vc_clear_colluns(imageTmpD,BRANCO,1);//apaga tudo menor que 1%
		
		pontos = vc_area(imageTmpD,BRANCO);
		pontos = vc_white_histogram(imageTmp, pontos);
		
		imageSrc = vc_read_image(fileold);


		pontos[0] -= EspacoMatricula;
		pontos[1] -= EspacoMatricula;
		pontos[2] += EspacoMatricula;
		pontos[3] += EspacoMatricula;
		r &= vc_rentangleRGB(imageSrc,pontos,EspacoMatricula, PRETO);

		pontos[0] -= EspacoMatricula;
		pontos[1] -= EspacoMatricula;
		pontos[2] += EspacoMatricula;
		pontos[3] += EspacoMatricula;
		r &= vc_rentangleRGB(imageSrc, pontos, EspacoMatricula, BRANCO);

		pontos[0] -= EspacoMatricula;
		pontos[1] -= EspacoMatricula;
		pontos[2] += EspacoMatricula;
		pontos[3] += EspacoMatricula;
		r &= vc_rentangleRGB(imageSrc, pontos, EspacoMatricula, PRETO);
		r &= vc_write_image(filenew, imageSrc);

		return r;
	}

	int imagem_todas_retangle(char * filenew, char* fileold)
	{
		int r = 1;
		float mean;
		IVC *imageSrc;
		IVC *imageDst;
		IVC *imageTmp;
		IVC *imageTmpD;
		int label;

		imageSrc = vc_read_image(fileold);
		imageDst = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmp = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
		imageTmpD = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

		int* pontos = (int*)calloc(4, sizeof(int));
		int percentagem = ((imageDst->width) * PERCENTAGEM) / 100;

		r &= vc_rgb_to_gray(imageSrc, imageTmp);
		r &= vc_gray_edge_sobel(imageTmp, imageTmpD, 0.92);
		r &= vc_focus_area(imageTmpD, 17, PRETO);
		r &= vc_segment_area(imageTmpD, 50, 100, BRANCO);
		label =vc_binary_blob_labelling(imageTmpD, imageDst);
		
		pontos = vc_find_retangle(imageDst, imageSrc, label);
		
		imageSrc = vc_read_image(fileold);


		pontos[0] -= EspacoMatricula;
		pontos[1] -= EspacoMatricula;
		pontos[2] += EspacoMatricula;
		pontos[3] += EspacoMatricula;
		r &= vc_rentangleRGB(imageSrc, pontos, EspacoMatricula, PRETO);

		pontos[0] -= EspacoMatricula;
		pontos[1] -= EspacoMatricula;
		pontos[2] += EspacoMatricula;
		pontos[3] += EspacoMatricula;
		r &= vc_rentangleRGB(imageSrc, pontos, EspacoMatricula, BRANCO);

		pontos[0] -= EspacoMatricula;
		pontos[1] -= EspacoMatricula;
		pontos[2] += EspacoMatricula;
		pontos[3] += EspacoMatricula;
		r &= vc_rentangleRGB(imageSrc, pontos, EspacoMatricula, PRETO);
		r &= vc_write_image(filenew, imageSrc);

		return r;
	}

	#pragma endregion

	#pragma region Não serve para nada

	void DesenhoNegativo()
	{
		IVC *image;
		int formula;

		image = vc_read_image("C:\Users\Utilizador\Dropbox\\LESI-PL\\2o Ano\\2o Semestre\\Visão por Computador\\2-Imagens\\Images\\FLIR\\flir-01.pgm");

		if (image == NULL)
		{
			printf_s("Error -> File not found");
			getchar();
			return 0;
		}

		formula = image->bytesperline * image->height;


		for (size_t i = 0; i < formula; i += image->channels)
		{
			image->data[i] = 255 - image->data[i];

		}

		vc_write_image("Novas Imagens\\vc-0001.pgm", image);
		vc_image_free(image);
	}

	void DesenhoBinario()
	{
		IVC *image;
		int formula;
		long int pos;

		image = vc_image_new(320, 280, 1, 1);

		if (image == NULL)
		{
			printf_s("Error -> File not found");
			getchar();
			return 0;
		}

		formula = image->bytesperline * image->height;


		for (size_t x = 0; x < image->width; x++)
		{
			for (size_t y = 0; y < image->height; y++)
			{
				pos = y * image->bytesperline + x * image->channels;

				if ((x <= image->width / 2) && (y <= image->height / 2)) image->data[pos] = 1;
				else if ((x > image->width / 2) && (y > image->height / 2)) image->data[pos] = 1;
				else image->data[pos] = 0;
			}
		}

		vc_write_image("Novas Imagens\\vc-0001.pbm", image);
		vc_image_free(image);
	}

	void DesenhoCinzentosCimaBaixo()
	{
		IVC *image;
		int formula;
		long int pos;

		image = vc_image_new(256, 256, 1, 255);

		if (image == NULL)
		{
			printf_s("Error -> File not found");
			getchar();
			return 0;
		}

		formula = image->bytesperline * image->height;


		for (size_t x = 0; x < image->width; x++)
		{
			for (size_t y = 0; y < image->height; y++)
			{
				pos = y * image->bytesperline + x * image->channels;

				image->data[pos] = 255 - y;
			}
		}

		vc_write_image("Novas Imagens\\vc-0001.pgm", image);
		vc_image_free(image);
	}

	void DesenhoCinzentosBaixoCima()
	{
		IVC *image;
		int formula;
		long int pos;

		image = vc_image_new(256, 256, 1, 255);

		if (image == NULL)
		{
			printf_s("Error -> File not found");
			getchar();
			return 0;
		}

		formula = image->bytesperline * image->height;


		for (size_t x = 0; x < image->width; x++)
		{
			for (size_t y = 0; y < image->height; y++)
			{
				pos = y * image->bytesperline + x * image->channels;

				image->data[pos] = y - 255;
			}
		}

		vc_write_image("Novas Imagens\\vc-0001.pgm", image);
		vc_image_free(image);
	}

	void DesenhoCinzentosEsquerdaDireita()
	{
		IVC *image;
		int formula;
		long int pos;

		image = vc_image_new(256, 256, 1, 255);

		if (image == NULL)
		{
			printf_s("Error -> File not found");
			getchar();
			return 0;
		}

		formula = image->bytesperline * image->height;


		for (size_t x = 0; x < image->width; x++)
		{
			for (size_t y = 0; y < image->height; y++)
			{
				pos = y * image->bytesperline + x * image->channels;

				image->data[pos] = 255 - x;
			}
		}

		vc_write_image("Novas Imagens\\vc-0001.pgm", image);
		vc_image_free(image);
	}

	void DesenhoCinzentosDiagonal()
	{
		IVC *image;
		int formula;
		long int pos;

		image = vc_image_new(256, 256, 1, 255);

		if (image == NULL)
		{
			printf_s("Error -> File not found");
			getchar();
			return 0;
		}

		formula = image->bytesperline * image->height;


		for (size_t x = 0; x < image->width; x++)
		{
			for (size_t y = 0; y < image->height; y++)
			{
				pos = y * image->bytesperline + x * image->channels;

				image->data[pos] = ((y + x) / 2) - 255;
			}
		}

		vc_write_image("Novas Imagens\\vc-0001.pgm", image);
		vc_image_free(image);
	}

	#pragma endregion 

	#pragma region RGB
	  
	int vc_rgb_negative(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				data[pos] = 255 - data[pos];
				data[pos + 1] = 255 - data[pos + 1];
				data[pos + 2] = 255 - data[pos + 2];
			}
		}
		return 1;
	}

	int vc_rgb_with_only_r(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				data[pos + 1] = 0;
				data[pos + 2] = 0;
			}

		}
		return 1;
	}

	int vc_rgb_with_only_g(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				data[pos] = 0;

				data[pos + 2] = 0;
			}

		}
		return 1;
	}

	int vc_rgb_with_only_b(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				data[pos] = 0;
				data[pos + 1] = 0;

			}

		}
		return 1;
	}

	int vc_rgb_get_red_gray(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				data[pos] = data[pos];
				data[pos + 1] = data[pos];
				data[pos + 2] = data[pos];
			}

		}
		return 1;
	}

	int vc_rgb_get_green_gray(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				data[pos] = data[pos + 1];
				data[pos + 1] = data[pos + 1];
				data[pos + 2] = data[pos + 1];
			}

		}
		return 1;
	}

	int vc_rgb_get_blue_gray(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				data[pos] = data[pos + 2];
				data[pos + 1] = data[pos + 2];
				data[pos + 2] = data[pos + 2];
			}

		}
		return 1;
	}

	int vc_rgb_to_gray(IVC *src, IVC *dst)
	{
		unsigned char *data_src = (unsigned char*)src->data;
		int width_src = src->width, height_src = src->height;
		int channels_src = src->channels;
		int levels_src = src->levels;
		int bytesperline_src = src->bytesperline;

		unsigned char *data_dst = (unsigned char*)dst->data;
		int width_dst = dst->width, height_dst = dst->height;
		int channels_dst = dst->channels;
		int levels_dst = dst->levels;
		int bytesperline_dst = dst->bytesperline;

		float rf, gf, bf;
		long int pos_src, pos_dst;

		if ((width_src <= 0) || (height_src <= 0) || (data_src == NULL) || (channels_src != 3))
			return 0;
		if ((width_src != width_dst) || (height_src != height_dst) || (channels_dst != 1))
			return 0;


		for (size_t y = 0; y < height_src; y++)
		{
			for (size_t x = 0; x < width_src; x++)
			{
				pos_src = y* bytesperline_src + x *channels_src;
				pos_dst = y* bytesperline_dst + x *channels_dst;

				rf = (float)data_src[pos_src];
				gf = (float)data_src[pos_src + 1];
				bf = (float)data_src[pos_src + 2];

				data_dst[pos_dst] = (unsigned char)((rf*0.299) + (gf*0.587) + (bf * 0.114));
			}

		}
		return 1;
	}

	int vc_rgb_to_hsv(IVC *src, IVC *dst)
	{
		unsigned char *data_src = (unsigned char*)src->data;
		int width_src = src->width, height_src = src->height;
		int channels_src = src->channels;
		int levels_src = src->levels;
		int bytesperline_src = src->bytesperline;

		unsigned char *data_dst = (unsigned char*)dst->data;
		int width_dst = dst->width, height_dst = dst->height;
		int channels_dst = dst->channels;
		int levels_dst = dst->levels;
		int bytesperline_dst = dst->bytesperline;

		float r, g, b, maior, menor;
		long int pos_src, pos_dst;

		if ((width_src <= 0) || (height_src <= 0) || (data_src == NULL) || (channels_src != 3))
			return 0;
		if ((width_src != width_dst) || (height_src != height_dst) || (channels_dst != 3))
			return 0;


		for (size_t y = 0; y < height_src; y++)
		{
			for (size_t x = 0; x < width_src; x++)
			{
				pos_src = y* bytesperline_src + x *channels_src;
				pos_dst = y* bytesperline_dst + x *channels_dst;

				r = (float)data_src[pos_src];
				g = (float)data_src[pos_src + 1];
				b = (float)data_src[pos_src + 2];

				maior = MAX3(r, g, b);
				menor = MIN3(r, g, b);

	#pragma region Hue 

				if ((maior - menor) != 0)
				{
					if (maior == r && g >= b)
						data_dst[pos_dst] = (unsigned char)((60.0f * (g - b) / (maior - menor)) / 360.0f * 255.0f);

					else if (maior == r && b > g)
						data_dst[pos_dst] = (unsigned char)((360.0f + 60.0f * (g - b) / (maior - menor)) / 360.0f * 255.0f);

					else if (maior == g)
						data_dst[pos_dst] = (unsigned char)((120.0f + 60.0f * (b - r) / (maior - menor)) / 360.0f * 255.0f);

					else if (maior == b)
						data_dst[pos_dst] = (unsigned char)((240.0f + 60.0f * (r - g) / (maior - menor)) / 360.0f * 255.0f);

				}

				else
					data_dst[pos_dst] = (unsigned char)0;

	#pragma endregion     

	#pragma region Saturation

				if (maior != 0)
					data_dst[pos_dst + 1] = (unsigned char)(((maior - menor) / (maior))*255.0f);

				else
					data_dst[pos_dst + 1] = 0;

	#pragma endregion

	#pragma region Value 

				data_dst[pos_dst + 2] = (unsigned char)(maior);

	#pragma endregion 
			}

		}
		return 1;
	}

	int vc_rgb_to_hsv_filter_yellow(IVC *srcdst, int hueMin, int hueMax, int satMin, int satMax, int valueMin, int valueMax)
	{
		unsigned char *data = (unsigned char *)srcdst->data;
		int width = srcdst->width;
		int height = srcdst->height;
		int bytesperline = srcdst->bytesperline;
		int channels = srcdst->channels;
		float r, g, b, hue, saturation, value;
		float rgb_max, rgb_min;
		int i, size;

		// Verificao de erros
		if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;
		if (channels != 3) return 0;

		size = width * height * channels;

		for (i = 0; i<size; i = i + channels)
		{
			//pos = y* bytesperline + x *channels;
			// (1602 * 231) + (3* 335)
			r = (float)data[i];
			g = (float)data[i + 1];
			b = (float)data[i + 2];

			// Calcula valores mximo e mnimo dos canais de cor R, G e B
			rgb_max = MAX3(r, g, b);
			rgb_min = MIN3(r, g, b);

			// Value toma valores entre [0,255]
			value = rgb_max;
			if (value == 0.0)
			{
				hue = 0.0;
				saturation = 0.0;
			}
			else
			{
				// Saturation toma valores entre [0,255]
				saturation = ((rgb_max - rgb_min) / rgb_max)* (float) 255.0;

				if (saturation == 0.0)
				{
					hue = 0.0;
				}
				else
				{
					// Hue toma valores entre [0,360]
					if ((rgb_max == r) && (g >= b))
					{
						hue = 60.0f * (g - b) / (rgb_max - rgb_min);
					}
					else if ((rgb_max == r) && (b > g))
					{
						hue = 360.0f + 60.0f * (g - b) / (rgb_max - rgb_min);
					}
					else if (rgb_max == g)
					{
						hue = 120.0f + 60.0f * (b - r) / (rgb_max - rgb_min);
					}
					else /* rgb_max == b */
					{
						hue = 240.0f + 60.0f * (r - g) / (rgb_max - rgb_min);
					}
				}
			}

			if ((hue >= hueMin  && hue <= hueMax) && (value >= valueMin && value <= valueMax) && (saturation >= satMin && saturation <= satMax)) // 
			{
				data[i] = 0;
				data[i + 1] = 0;
				data[i + 2] = 0;
			}

			else
			{
				data[i] = 255;
				data[i + 1] = 255;
				data[i + 2] = 255;
			}
		}
		return 1;
	}

	int vc_rgb_to_hsv_filter_red(IVC *src, IVC *dst)

	{
		unsigned char *data_src = (unsigned char*)src->data;
		int width_src = src->width, height_src = src->height;
		int channels_src = src->channels;
		int levels_src = src->levels;
		int bytesperline_src = src->bytesperline;

		unsigned char *data_dst = (unsigned char*)dst->data;
		int width_dst = dst->width, height_dst = dst->height;
		int channels_dst = dst->channels;
		int levels_dst = dst->levels;
		int bytesperline_dst = dst->bytesperline;

		float r, g, b, maior, menor;
		long int pos_src, pos_dst;

		if ((width_src <= 0) || (height_src <= 0) || (data_src == NULL) || (channels_src != 3))
			return 0;
		if ((width_src != width_dst) || (height_src != height_dst) || (channels_dst != 3))
			return 0;


		for (size_t y = 0; y < height_src; y++)
		{
			for (size_t x = 0; x < width_src; x++)
			{
				pos_src = y* bytesperline_src + x *channels_src;
				pos_dst = y* bytesperline_dst + x *channels_dst;

				r = (float)data_src[pos_src];
				g = (float)data_src[pos_src + 1];
				b = (float)data_src[pos_src + 2];

				maior = MAX3(r, g, b);
				menor = MIN3(r, g, b);
				float hue;
				float saturacao = (((maior - menor) / (maior))*255.0f);



				if (r >= 140 && g <= 40 && b <= 40)
				{
					data_dst[pos_dst] = (unsigned char)(0);
					data_dst[pos_dst + 1] = (unsigned char)(10);
					data_dst[pos_dst + 2] = (unsigned char)(255);
				}
				else
				{
					data_dst[pos_dst] = (unsigned char)(r);
					data_dst[pos_dst + 1] = (unsigned char)(g);
					data_dst[pos_dst + 2] = (unsigned char)(b);
				}
			}

		}
		return 1;
	}
	
	int* vc_rgb_to_hsv_filter_colors(IVC *srcdst, int contaPixeis[3], int pontos[4])
	{
		unsigned char *data = (unsigned char *)srcdst->data;
		int width = srcdst->width;
		int height = srcdst->height;
		int bytesperline = srcdst->bytesperline;
		int channels = srcdst->channels;
		float r, g, b, hue, saturation, value;
		float rgb_max, rgb_min;
		int y, x;
		long int pos;

		contaPixeis[0] = 0;
		contaPixeis[1] = 0;
		contaPixeis[2] = 0;

		// Verificao de erros
		if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;
		if (channels != 3) return 0;


		//percorre a area dos pontos
		for (y = pontos[1]; y <= pontos[3]; y++)
		{
			for (x = pontos[0]; x <= pontos[2]; x++)
			{
				pos = y* srcdst->bytesperline + x *srcdst->channels;

				r = (float)data[pos];
				g = (float)data[pos + 1];
				b = (float)data[pos + 2];

				// Calcula valores mximo e mnimo dos canais de cor R, G e B
				rgb_max = MAX3(r, g, b);
				rgb_min = MIN3(r, g, b);

				// Value toma valores entre [0,255]
				value = rgb_max;
				if (value == 0.0)
				{
					hue = 0.0;
					saturation = 0.0;
				}
				else
				{
					// Saturation toma valores entre [0,255]
					saturation = ((rgb_max - rgb_min) / rgb_max) * (float) 255.0;

					if (saturation == 0.0)
					{
						hue = 0.0;
					}
					else
					{
						// Hue toma valores entre [0,360]
						if ((rgb_max == r) && (g >= b))
						{
							hue = 60.0f * (g - b) / (rgb_max - rgb_min);
						}
						else if ((rgb_max == r) && (b > g))
						{
							hue = 360.0f + 60.0f * (g - b) / (rgb_max - rgb_min);
						}
						else if (rgb_max == g)
						{
							hue = 120.0f + 60.0f * (b - r) / (rgb_max - rgb_min);
						}
						else /* rgb_max == b */
						{
							hue = 240.0f + 60.0f * (r - g) / (rgb_max - rgb_min);
						}
					}
				}

				//comparação dos valores padrao de HSV
				if ((value >= HSVVALUEWHITE) && (saturation <= HSVSATWHITE))
					contaPixeis[2]++;//branco

				else if (((hue >= HSVHUEMINBLUE) || (hue <= HSVHUEMAXBLUE)) && ((value >= HSVVALUEMINBLUE) && (value <= HSVVALUEMAXBLUE)) && ((saturation >= HSVSATMINBLUE) && (saturation <= HSVSATMAXBLUE)))
					contaPixeis[1]++; //azul

				else if (((value >= HSVVALUEMINBLACK) && (value <= HSVVALUEMAXBLACK)) && ((saturation >= HSVSATMINBLACK) && (saturation <= HSVSATMAXBLACK)))
					contaPixeis[0]++; //preto
			}
		}
		return &contaPixeis;
	}

	#pragma endregion

	#pragma region Gray

	int vc_gray_negative(IVC *srcdst)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				data[pos] = 255 - data[pos];
			}

		}
		return 1;
	}

	int vc_scale_gray_to_rgb(IVC *src, IVC *dst)
	{
		unsigned char *data_src = (unsigned char*)src->data;
		int width_src = src->width, height_src = src->height;
		int channels_src = src->channels;
		int levels_src = src->levels;
		int bytesperline_src = src->bytesperline;

		unsigned char *data_dst = (unsigned char*)dst->data;
		int width_dst = dst->width, height_dst = dst->height;
		int channels_dst = dst->channels;
		int levels_dst = dst->levels;
		int bytesperline_dst = dst->bytesperline;

		float cor;
		long int pos_src, pos_dst;

		if ((width_src <= 0) || (height_src <= 0) || (data_src == NULL) || (channels_src != 1))
			return 0;
		if ((width_src != width_dst) || (height_src != height_dst) || (channels_dst != 3))
			return 0;


		for (size_t y = 0; y < height_src; y++)
		{
			for (size_t x = 0; x < width_src; x++)
			{
				pos_src = y* bytesperline_src + x *channels_src;
				pos_dst = y* bytesperline_dst + x *channels_dst;

				cor = (int)data_src[pos_src];

				if (cor <= 64)
				{
					data_dst[pos_dst] = (unsigned char)0;
					data_dst[pos_dst + 1] = (unsigned char)((cor * 64));
					data_dst[pos_dst + 2] = (unsigned char)(255);

				}

				else if (cor > 64 && cor <= 128)
				{
					data_dst[pos_dst] = (unsigned char)0;
					data_dst[pos_dst + 1] = (unsigned char)(255);
					data_dst[pos_dst + 2] = (unsigned char)((int)(cor / 64));


				}

				else if (cor > 128 && cor <= 192)
				{
					data_dst[pos_dst] = (unsigned char)(cor * 64);
					data_dst[pos_dst + 1] = (unsigned char)(255);
					data_dst[pos_dst + 2] = (unsigned char)0;

				}


				else if (cor > 192)
				{
					data_dst[pos_dst] = (unsigned char)(255);
					data_dst[pos_dst + 1] = (unsigned char)((int)(cor / 64));
					data_dst[pos_dst + 2] = (unsigned char)(0);


				}
			}


		}  return 1;
	}

	int vc_gray_to_binary(IVC *src, int threshold)
	{
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				if (data[pos]>threshold)
					data[pos] = 255;

				else
					data[pos] = 0;
			}

		}
		return 1;
	}

	int vc_gray_to_binary_global_mean(IVC *src)

	{
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos;
		long int threshold = 0;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (size_t i = 0; i < height * width; i++)
		{
			threshold += (int)data[i];
		}

		threshold /= (height * width);

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				if (data[pos]>threshold)
					data[pos] = 255;

				else
					data[pos] = 0;
			}

		}
		return 1;
	}

	int vc_gray_to_binary_midpoint(IVC *src, IVC *dst, int kernel)
	{
		unsigned char *datasrc = (unsigned char *)src->data;
		unsigned char *datadst = (unsigned char *)dst->data;
		int width = src->width;
		int height = src->height;
		int bytesperline = src->bytesperline;
		int channels = src->channels;
		int x, y;
		int xx, yy;
		int xxyymax = (kernel - 1) / 2;
		int xxyymin = -xxyymax;
		int max, min;
		long int pos, posk;
		unsigned char threshold;

		// Verificao de erros
		if ((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0;
		if ((src->width != dst->width) || (src->height != dst->height) || (src->channels != dst->channels)) return 0;
		if (channels != 1) return 0;

		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				pos = y * bytesperline + x * channels;

				max = datasrc[pos];
				min = datasrc[pos];

				// NxM Vizinhos
				for (yy = xxyymin; yy <= xxyymax; yy++)
				{
					for (xx = xxyymin; xx <= xxyymax; xx++)
					{
						if ((y + yy >= 0) && (y + yy < height) && (x + xx >= 0) && (x + xx < width))
						{
							posk = (y + yy) * bytesperline + (x + xx) * channels;

							if (datasrc[posk] > max) max = datasrc[posk];
							if (datasrc[posk] < min) min = datasrc[posk];
						}
					}
				}

				threshold = (unsigned char)((float)(max + min) / (float)2);

				if (datasrc[pos] > threshold) datadst[pos] = 255;
				else datadst[pos] = 0;
			}
		}

		return 1;
	}

	// Detecção de contornos pelos operadores Sobel
	int vc_gray_edge_sobel(IVC *src, IVC *dst, float th)
	{
		unsigned char *datasrc = (unsigned char *)src->data;
		unsigned char *datadst = (unsigned char *)dst->data;
		int width = src->width;
		int height = src->height;
		int bytesperline = src->bytesperline;
		int channels = src->channels;
		int x, y;
		long int posX, posA, posB, posC, posD, posE, posF, posG, posH;
		int i, size;
		int histmax, histthreshold;
		int sumx, sumy;
		int hist[256] = { 0 };

		// Verificação de erros
		if ((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0;
		if ((src->width != dst->width) || (src->height != dst->height) || (src->channels != dst->channels)) return 0;
		if (channels != 1) return 0;

		size = width * height;

		//formula dos vizinho
		for (y = 1; y<height - 1; y++)
		{
			for (x = 1; x<width - 1; x++)
			{
				posA = (y - 1) * bytesperline + (x - 1) * channels;
				posB = (y - 1) * bytesperline + x * channels;
				posC = (y - 1) * bytesperline + (x + 1) * channels;
				posD = y * bytesperline + (x - 1) * channels;
				posX = y * bytesperline + x * channels;
				posE = y * bytesperline + (x + 1) * channels;
				posF = (y + 1) * bytesperline + (x - 1) * channels;
				posG = (y + 1) * bytesperline + x * channels;
				posH = (y + 1) * bytesperline + (x + 1) * channels;

				sumx = datasrc[posA] * -1;
				sumx += datasrc[posD] * -2;
				sumx += datasrc[posF] * -1;

				sumx += datasrc[posC] * +1;
				sumx += datasrc[posE] * +2;
				sumx += datasrc[posH] * +1;
				sumx = sumx / 4; // 4 = 1 + 2 + 1

				sumy = datasrc[posA] * -1;
				sumy += datasrc[posB] * -2;
				sumy += datasrc[posC] * -1;

				sumy += datasrc[posF] * +1;
				sumy += datasrc[posG] * +2;
				sumy += datasrc[posH] * +1;
				sumy = sumy / 4; // 4 = 1 + 2 + 1

				datadst[posX] = (unsigned char)sqrt((double)(sumx*sumx + sumy*sumy));
			}
		}

		//receber os dados para um histograma
		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				hist[datadst[y * bytesperline + x * channels]]++;
			}
		}

		// Threshold at the middle of the occupied levels
		histmax = 0;
		for (i = 0; i <= 255; i++)
		{
			histmax += hist[i];

			// th = Sobel Threshold
			if (histmax >= (((float)size) * th))
				break;
		}
		histthreshold = i;

		//recebe a cor [1,255]

		// Apply the threshold
		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				posX = y * bytesperline + x * channels;

				if (datadst[posX] >= histthreshold)
					datadst[posX] = 255;

				else 
					datadst[posX] = 0;
			}
		}

		return 1;
	}

	// Detecção de contornos pelos operadores Prewitt
	int vc_gray_edge_prewitt(IVC *src, IVC *dst, float th)
	{
		unsigned char *datasrc = (unsigned char *)src->data;
		unsigned char *datadst = (unsigned char *)dst->data;
		int width = src->width;
		int height = src->height;
		int bytesperline = src->bytesperline;
		int channels = src->channels;
		int x, y;
		long int posX, posA, posB, posC, posD, posE, posF, posG, posH;
		int i, size;
		int histmax, histthreshold;
		int sumx, sumy;
		float val;
		int hist[256] = { 0 };

		// Verificação de erros
		if ((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0;
		if ((src->width != dst->width) || (src->height != dst->height) || (src->channels != dst->channels)) return 0;
		if (channels != 1) return 0;

		size = width * height;

		for (y = 1; y<height - 1; y++)
		{
			for (x = 1; x<width - 1; x++)
			{
				posA = (y - 1) * bytesperline + (x - 1) * channels;
				posB = (y - 1) * bytesperline + x * channels;
				posC = (y - 1) * bytesperline + (x + 1) * channels;
				posD = y * bytesperline + (x - 1) * channels;
				posX = y * bytesperline + x * channels;
				posE = y * bytesperline + (x + 1) * channels;
				posF = (y + 1) * bytesperline + (x - 1) * channels;
				posG = (y + 1) * bytesperline + x * channels;
				posH = (y + 1) * bytesperline + (x + 1) * channels;

				sumx = datasrc[posA] * -1;
				sumx += datasrc[posD] * -1;
				sumx += datasrc[posF] * -1;

				sumx += datasrc[posC] * +1;
				sumx += datasrc[posE] * +1;
				sumx += datasrc[posH] * +1;
				sumx = sumx / 3; // 3 = 1 + 1 + 1

				sumy = datasrc[posA] * -1;
				sumy += datasrc[posB] * -1;
				sumy += datasrc[posC] * -1;

				sumy += datasrc[posF] * +1;
				sumy += datasrc[posG] * +1;
				sumy += datasrc[posH] * +1;
				sumy = sumy / 3; // 3 = 1 + 1 + 1



				val = sqrt((float)(sumx*sumx + sumy*sumy));

				datadst[posX] = (unsigned char)val;
				//datadst[posX] = (unsigned char) (sqrt((double) (sumx*sumx + sumy*sumy)) / 4.0);

			}
		}

		// Compute a grey level histogram
		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				hist[datadst[y * bytesperline + x * channels]]++;
			}
		}

		// Threshold at the middle of the occupied levels
		histmax = 0;
		for (i = 0; i <= 255; i++)
		{
			histmax += hist[i];

			// th = Prewitt Threshold
			if (histmax >= (((float)size) * th)) break;
		}
		histthreshold = i;

		// Apply the threshold
		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				posX = y * bytesperline + x * channels;

				if (datadst[posX] >= histthreshold) datadst[posX] = 255;
				else datadst[posX] = 0;
			}
		}

		return 1;
	}

	//gera um histograma
	int vc_gray_histogram(IVC* src, IVC* srcD)
	{
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos;
		long int size = src->width * src->height;
		int contaPixeis[256] = { 0 };
		float pdf[256];

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				contaPixeis[(int)src->data[pos]]++;
			}

		}
		double max = 0;

		for (size_t i = 0; i < 256; i++)
		{
			pdf[i] = (float)((float)contaPixeis[i] / (float)size);
			if (pdf[i] > max)
				max = pdf[i];
		}

		double temp;

		int x, y;

		for (x = 0; x < srcD->width; x++)
		{
			temp = (float)((((float)pdf[x] * (float)255) / ((float)max)));
			for (y = 255; y >= 0; y--)
			{
				pos = y* srcD->bytesperline + x *srcD->channels;

				if (temp >= (double)(255) - (double)y)
					srcD->data[pos] = (unsigned char)255;

				else
					srcD->data[pos] = (unsigned char)0;

			}

		}
		return  1;
	}

	int vc_gray_histogram_equalization(IVC *srcdst)
	{
		unsigned char *data = (unsigned char *)srcdst->data;
		int width = srcdst->width;
		int height = srcdst->height;
		int bytesperline = srcdst->bytesperline;
		int channels = srcdst->channels;
		long int npixels = width * height;
		double pdf[256] = { 0.0 };
		double cdf[256] = { 0.0 };
		double cdfmin;
		int hist[256] = { 0 };
		double myval = 0;
		unsigned char myval2 = 0;

		int state_hst[256] = { 0 };
		long int pos;
		int x, y, i;
		unsigned char k;

		// Verificação de erros
		if ((srcdst->width <= 0) || (srcdst->height <= 0) || (srcdst->data == NULL)) return 0;
		if (channels != 1) return 0;

		// Percorre todos os pixeis da imagem
		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				pos = y * bytesperline + x * channels;

				// Conta o número de ocorrências (ni) de cada um dos tons de cinzentos (i)
				hist[data[pos]]++;
			}
		}

		// Calcula a pdf da imagem
		// pdf(i) = ni / n
		for (i = 0; i<256; i++)
		{
			pdf[i] = (double)hist[i] / (double)npixels;
		}

		// Calcula a cdf da imagem
		// cdf(i) = sum pdf(i) , i=[0, L-1]
		cdf[0] = pdf[0];
		for (i = 1; i<256; i++)
		{
			cdf[i] = cdf[i - 1] + pdf[i];
		}

		for (cdfmin = 1.0 /*Valor máximo*/, i = 1; i<256; i++)
		{
			if ((cdf[i] > 0.0) && (cdf[i] < cdfmin))
				cdfmin = cdf[i];
		}

		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				pos = y * bytesperline + x * channels;

				k = data[pos];
				//data[pos] = (unsigned char) floor(cdf[k] * 255.0);
				myval = (cdf[k] - cdfmin) / (1.0 - cdfmin);
				myval = myval*255.0;

				data[pos] = (unsigned char)myval;

			}
		}

		return 1;
	}


	#pragma endregion

	#pragma region Binary

	//dilatação
	int vc_binary_dilate(IVC *src, IVC *dst, int kernel)
	{
		unsigned char *datasrc = (unsigned char *)src->data;
		unsigned char *datadst = (unsigned char *)dst->data;
		int width = src->width;
		int height = src->height;
		int bytesperline = src->bytesperline;
		int channels = src->channels;
		int x, y;
		int xx, yy;
		int xxyymax = (kernel - 1) / 2;
		int xxyymin = -xxyymax;
		int max, min;
		long int pos, posk;
	
		int cont = 0;

		// Verificao de erros
		if ((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0;
		if ((src->width != dst->width) || (src->height != dst->height) || (src->channels != dst->channels)) return 0;
		if (channels != 1) return 0;

		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				cont = 0;
				pos = y * bytesperline + x * channels;

				max = datasrc[pos];
				min = datasrc[pos];

				// NxM Vizinhos
				for (yy = xxyymin; yy <= xxyymax; yy++)
				{
					for (xx = xxyymin; xx <= xxyymax; xx++)
					{
						if ((y + yy >= 0) && (y + yy < height) && (x + xx >= 0) && (x + xx < width))
						{
							posk = (y + yy) * bytesperline + (x + xx) * channels;

							if (datasrc[posk] == 255) cont++;
						}
					}
				}

				if (cont > 0)
					dst->data[pos] = 255;

				else
					dst->data[pos] = 0;

			}
		}

		return 1;
	}

	//erosão
	int vc_binary_erode(IVC *src, IVC *dst, int kernel)
	{
		unsigned char *datasrc = (unsigned char *)src->data;
		unsigned char *datadst = (unsigned char *)dst->data;
		int width = src->width;
		int height = src->height;
		int bytesperline = src->bytesperline;
		int channels = src->channels;
		int x, y;
		int xx, yy;
		int xxyymax = (kernel - 1) / 2;
		int xxyymin = -xxyymax;
		int max, min;
		long int pos, posk;
	
		int cont = 0;

		// Verificao de erros
		if ((src->width <= 0) || (src->height <= 0) || (src->data == NULL)) return 0;
		if ((src->width != dst->width) || (src->height != dst->height) || (src->channels != dst->channels)) return 0;
		if (channels != 1) return 0;

		for (y = 0; y<height; y++)
		{
			for (x = 0; x<width; x++)
			{
				cont = 0;
				pos = y * bytesperline + x * channels;

				max = datasrc[pos];
				min = datasrc[pos];

				// NxM Vizinhos
				for (yy = xxyymin; yy <= xxyymax; yy++)
				{
					for (xx = xxyymin; xx <= xxyymax; xx++)
					{
						if ((y + yy >= 0) && (y + yy < height) && (x + xx >= 0) && (x + xx < width))
						{
							posk = (y + yy) * bytesperline + (x + xx) * channels;

							if (datasrc[posk] == 255) cont++;
						}
					}
				}

				if (cont == kernel*kernel)
					dst->data[pos] = 255;

				else
					dst->data[pos] = 0;

			}
		}

		return 1;
	}

	//abertura
	int vc_binary_open(IVC *src, IVC *dst, int kernel)
	{
		IVC* temp = vc_image_new(src->width, src->height, src->channels, 1);
		vc_binary_erode(src, temp, kernel);
		vc_binary_dilate(temp, dst, kernel);
		vc_image_free(temp);

		return 1;
	}

	//fecho
	int vc_binary_close(IVC *src, IVC *dst, int kernel)
	{
		IVC* temp = vc_image_new(src->width, src->height, src->channels, 1);
		vc_binary_dilate(src, temp, kernel);
		vc_binary_erode(temp, dst, kernel);
		vc_image_free(temp);

		return 1;
	}
	
	//demora um bocado de tempo dependento da quantidade de blobs
	int vc_binary_blob_labelling(IVC *src, IVC *dst)
{

	unsigned char *data_src = (unsigned char *)src->data;
	int bytesperline_src = src->width * src->channels;
	int channels_src = src->channels;

	unsigned char *data_dst = (unsigned char *)dst->data;
	int bytesperline_dst = src->width * dst->channels;
	int channels_dst = dst->channels;

	int width = src->width;
	int height = src->height;
	int ABCD[4] = { 0 };

	long int pos_src, pos_dst, pos_A, pos_B, pos_C, pos_D, label_pos = 1;
	int xmax = 0, xmin = width, ymax = 0, ymin = height;
	int x, y, i, j;
	int menor = 255;
	int menor_temp = 0;
	int maiorLabelRegistada = 0;   

	// verificação de erros
	if ((src->width <= 0) || (src->height <= 0) || (src->data == NULL) || (channels_src != 1) || (channels_dst != 1))
		return 0;

	// colocar as extermidades a 0
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;

			if (x == 0 || y == 0 || x == (width - 1) || y == (height - 1))
			{
				data_src[pos_src] = 0;
			}

			// inicialização da imagem destino
			data_dst[pos_src] = 0;
		}
	}

	// etiquecação de objetos
	for (y = 1; y < height - 1; y++)
	{
		for (x = 1; x < width - 1; x++)
		{
			pos_A = (y - 1) * bytesperline_src + (x - 1) * channels_src;
			pos_B = (y - 1) * bytesperline_src + x * channels_src;
			pos_C = (y - 1) * bytesperline_src + (x + 1) * channels_src;
			pos_D = y * bytesperline_src + (x - 1) * channels_src;
			pos_src = y * bytesperline_src + x * channels_src;
			menor = 254;


			// se todos os vizinhos forem zero atribuimos a X uma nova etiqueta
			if (data_src[pos_src] == 255)
				if (data_src[pos_A] == 0 && data_src[pos_B] == 0 && data_src[pos_C] == 0 && data_src[pos_D] == 0)
				{
					data_dst[pos_src] = label_pos;
					label_pos++;   					
				}

				else
				{
					int xx[4] = { data_dst[pos_A], data_dst[pos_B], data_dst[pos_C], data_dst[pos_D] };
					menor = menor_array(xx, 4); // menor excepto o zero e 255, valores unicos numa imagem binaria

					data_dst[pos_src] = menor;
				}

		}

	}

	int *label = (int*)calloc(label_pos, sizeof(int));

	// inicializa o array
	for (j = 1; j < label_pos; j++)
	{
		if (j >= 254)
			label[j] = (int)254;

		else
			label[j] = (int)j;
	}

	// actualização das etiquetas
	for (y = 1; y < (height - 1); y++)
	{
		for (x = 1; x < (width - 1); x++)
		{
			pos_A = (y - 1) * bytesperline_src + (x - 1) * channels_src;
			pos_B = (y - 1) * bytesperline_src + x * channels_src;
			pos_C = (y - 1) * bytesperline_src + (x + 1) * channels_src;
			pos_D = y * bytesperline_src + (x - 1) * channels_src;
			pos_src = y * bytesperline_src + x * channels_src;

			int xx[4] = { label[data_dst[pos_A]], label[data_dst[pos_B]], label[data_dst[pos_C]], label[data_dst[pos_D]] };

			//saca o menor
			menor = menor_array(xx, 4);


			ABCD[0] = label[data_dst[pos_A]];
			ABCD[1] = label[data_dst[pos_B]];
			ABCD[2] = label[data_dst[pos_C]];
			ABCD[3] = label[data_dst[pos_D]];


			//atualiza os valores das label
			for (i = 0; i < 4; i++)
			{
				if (ABCD[i] != menor)
					for (j = 1; j < label_pos; j++)
					{
						if (label[j] == ABCD[i])
							label[j] = menor;
					}
			}
		}
	}


	//actualiza valores das etiquetas
	for (y = 1; y < height - 1; y++)
	{
		for (x = 1; x < width - 1; x++)
		{
			pos_src = y * bytesperline_src + x * channels_src;

			// nao limpa zeros e a posicao 255 nao existe
			if (data_dst[pos_src] < 255 && data_dst[pos_src] != 0)
				data_dst[pos_src] = label[data_dst[pos_src]] + VALOR;
		}
	}

	free(label);
	return label_pos;
}
	

	#pragma endregion

	#pragma region Criativas

	//redimensiono o retangulo
	int* vc_white_histogram(IVC *src, int pontos[4])
	{
		unsigned char *data = (unsigned char*)src->data;
		long int pos;
		int yMin = pontos[1], yMax = pontos[3];
		int x, y, i = 0;

		int *contaPixeis = (int*)calloc((pontos[3] - pontos[1]) + 1, sizeof(int));


		if ((src->width <= 0) || (src->height <= 0) || (src->data == NULL) || (src->channels != 1) || (src->width >= 1000))
			return pontos;


		//basicamento guardo valores para um histograma
		for (y = pontos[1]; y <= pontos[3]; y++)
		{
			for (x = pontos[0]; x <= pontos[2]; x++)
			{
				pos = y* src->bytesperline + x *src->channels;
				if ((int)src->data[pos] >= DEFINEWHITE)
				{
					contaPixeis[i]++;
				}
			}
			i++;
		}


		float mean = 0.0f;
		int aux = 0, auxStuff = 1;

		//extraiu a media
		for (x = 0; x <= (pontos[3] - pontos[1]); x++) {
			mean += (float)contaPixeis[x];
		}

		mean /= (float)(pontos[3] - pontos[1]);
		mean /= (float)2;

		//conto os considerados pixeis brancos
		for (y = pontos[1]; y <= pontos[3]; y++)
		{
			for (x = pontos[0]; x <= pontos[2]; x++)
			{
				pos = y* src->bytesperline + x *src->channels;

				if (src->data[pos] >= DEFINEWHITE)
					aux++;
			}

			//menor que a a media entao redimensiona o rectangulo
			if (aux < mean)
			{
				if (auxStuff != 3)
					yMin++;

				else
					yMax--;
			}

			if (aux == 0)
				auxStuff = 3;

			aux = 0;
		}

		pontos[1] = yMin;
		pontos[3] = yMax;

		return pontos;
	}
	
	//maior que a media entao apaga, introduzida a cor que queremos apagar
	int vc_line_mean_compare(IVC *srcdst, float mean,int color)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int cont = 0;
		int i = 0, y;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				if (srcdst->data[pos] == color)    //procura a cor que quer contar
					cont++;
			}
			//maior que a a média inverte a cor
			if ((float)cont >=mean)
			{
				for (size_t x = 0; x < width; x++)
				{
					pos = y* bytesperline + x *channels;
					srcdst->data[pos] = 255 - color;						
				}
			}
			cont = 0;
		}

		return 1;
	}

	//retorna a média de uma cor por linhas que contenham essa cor
	float vc_line_mean(IVC *srcdst, int color)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int *cont = (int*)calloc(width, sizeof(int));
		int i = 0, y;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0.0f;

		for (y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				if (srcdst->data[pos] == color)    //procura a cor que quer contar
					cont[y]++;			
			}
		}
		float mean=0.0f;
		i = 0;
		for (y = 0; y < width; y++)
		{
			if (cont[y] == 0) {
			
				i++;
			}
			mean += cont[y];


		}

		mean /= (width -i);

		return mean;
	}

	//retorna a média de uma cor por colunas que contenham essa cor
	float vc_collun_mean(IVC *srcdst, int color)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int *cont = (int*)calloc(width, sizeof(int));
		int i = 0, y;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0.0f;

		for (size_t x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
			
				pos = y* bytesperline + x *channels;
				if (srcdst->data[pos] == color)    //procura a cor que quer contar
				cont[x]++;
			}
		}
		float mean = 0.0f;
		i = 0;
		for (y = 0; y < height; y++)
		{
			if (cont[y] == 0)
				i++;

			mean += cont[y];
		}

		mean /= (height - i);

		return mean;
	}

	//tons de cinza ou binario, limpa uma linha com determinada percentagem de dimensão
	int vc_clear_lines(IVC *srcdst, int color, float percentagem)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int *cont = (int*)calloc(height, sizeof(int));
		int i = 0, y;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				//vai contando
				if (srcdst->data[pos] == color)    //procura a cor que quer eliminar
				{
					cont[y]++;
					cont[y] == 1 ? i = x : NULL;
				}

				else
				{
					//verifica se o conjunto de pixeis é maior que uma percentagem
					if ((float)((cont[y] * 100) / width) >= percentagem)
					{
						for (; i < x; i++)
						{
							pos = y* bytesperline + i *channels;
							//branco
							srcdst->data[pos] = 255 - color;

						}
					}
					cont[y] = 0;
				}
			}
		}

		//feito para eliminar os casos particulares
		//se uma linha for até ao final da width
		for (y = 0; y < height; y++)
		{
			// para ter a certeza que nada foi deixado para tras
			for (i = width - cont[y]; i < width; i++)
			{
				pos = y* bytesperline + i *channels;
				srcdst->data[pos] = 255 - color;

			}
		}


		return 1;
	}

	//tons de cinza ou binario, limpa uma coluna com determinada percentagem de dimensão
	int vc_clear_colluns(IVC *srcdst, int color, float percentagem)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int *cont = (int*)calloc(width, sizeof(int));
		int i = 0, y;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;
									
		for (size_t x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
				pos = y* bytesperline + x *channels;
				if (srcdst->data[pos] == color)    //procura a cor que quer eliminar
					cont[x]++;				
			}

			if ((float)((cont[x] * 100) / height) < percentagem)
			{
				for (y = 0; y < height; y++)
				{
					pos = y* bytesperline + x *channels;
					srcdst->data[pos] = 255 - color;
				}
			}
		}
					
		free(cont);

		return 1;
	}

	//eliminar o contorno da imagem, pois a matricula não vai estar numa esquina ...
	int vc_focus_area(IVC *srcdst, float percentagem, int cor )
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int pontos = (int)((percentagem * width) / 100);
		int y;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				if ((pontos >= x) || (pontos >= y) || (height - pontos <= y))
					srcdst->data[pos] = cor;

				if (((width - pontos) <= x))
					srcdst->data[pos] = cor;
			}
		}
		return 1;
	}

	//limpar pixeis perdidos 
	int vc_clear_missing_pixels(IVC *srcdst, int quantidade, int espacamento, int cor)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int contPixeis = 0, contEspacos = 0;
		int i = 0, y, x;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (x = 0; x < width; x++)
			{
				//saca a quantidade dos pixeis
				pos = y* bytesperline + x *channels;
				if (srcdst->data[pos] == cor)
					contPixeis++;

				//tenta apagalo
				else
				{
					if (contPixeis > quantidade || contPixeis == 0);

					else
					{
						contEspacos = 0;
						for (i = x; (i < width); i++)
						{
							pos = y* bytesperline + i *channels;
							if (srcdst->data[pos] == 255 - cor)
								contEspacos++;
							else
								break;
						}

						if (contEspacos < espacamento);

						else
						{
							//inverte a cor
							for (size_t j = (x - contPixeis);j <= (x); j++)
							{
								pos = y* bytesperline + j *channels;
								srcdst->data[pos] = 255 - cor;
							}
						}

					}

					contPixeis = 0;
				}
			}
		}


		return 1;
	}

	//segmenta a imagem em areas, elimina as areas que não teêm um conjunto de pontos
	int vc_segment_area(IVC *src, int area, int numeroPontos, int cor)
	{
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos = 0;
		int cont = 0, y = 0, x = 0, calcx = 0, calcy = 0;
		float horizontal = width, vertical=height;
		int quantosQuadrados = ((height*width) / (area*area));
		
	
		horizontal = horizontal / area;
		vertical = vertical / area;

		horizontal > ((int)horizontal) ? horizontal++ : horizontal;
		vertical > ((int)vertical) ? vertical++ : vertical;

		quantosQuadrados = (int)horizontal * (int)vertical;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;


		for (size_t i = 0; i < quantosQuadrados; i++)
		{

			calcx = i % (int)(width / area);

			if (calcx == 0)
				calcy = ((i / ((int)(width / area))) % (int)(height / area));

			#pragma region Conta
			for (y = (area*calcy); y < area + (area* calcy); y++)
			{
				for (x = (area*calcx); x < area + (area* calcx); x++)
				{
					if ((y >= 0) && (y < height) && (x >= 0) && (x < width))
					{
						pos = y* bytesperline + x *channels;
						if (src->data[pos] == cor)
							cont++;
					}
					else
						break;
				}
			}
			#pragma endregion

			#pragma region Apaga
			if (cont <= numeroPontos)
			{
				for (y = (area*calcy); y < area + (area* calcy); y++)
				{
					for (x = (area*calcx); x < area + (area* calcx); x++)
					{
						if ((y >= 0) && (y < height) && (x >= 0) && (x < width))
						{
							pos = y* bytesperline + x *channels;
							src->data[pos] = 255 - cor;

						}
						else
							break;
					}
				}
			}
			#pragma endregion
			
			cont = 0;
		}		

		return 1;
	}
	
	//não utilizado
	int vc_segment_area_horizontal(IVC *src, int area, int numeroPontos, int cor)
	{
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos = 0;
		int cont = 0, y = 0, x = 0, calcx = 0, calcy = 0;
		float horizontal = width ;
		int quantosQuadrados = ((width) / (area));


		horizontal = horizontal / area;

		horizontal > ((int)horizontal) ? horizontal++ : horizontal;

		quantosQuadrados = (int)horizontal;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;


		for (size_t i = 0; i < quantosQuadrados; i++)
		{

			calcx = i % (int)(width / area);

			if (calcx == 0)
				calcx = (i / (int)(width / area));

#pragma region Conta
			for (y = 0; y < height; y++)
			{
				for (x = (area*calcx); x < area + (area* calcx); x++)
				{
					if ((y >= 0) && (y < height) && (x >= 0) && (x < width))
					{
						pos = y* bytesperline + x *channels;
						if (src->data[pos] == cor)
							cont++;
					}
					else
						break;
				}
			}
#pragma endregion

#pragma region Apaga
			if (cont >= numeroPontos)
			{
				for (y = 0; y < height; y++)
				{
					for (x = (area*calcx); x < area + (area* calcx); x++)
					{
						if ((y >= 0) && (y < height) && (x >= 0) && (x < width))
						{
							pos = y* bytesperline + x *channels;
							src->data[pos] = 255 - cor;

						}
						else
							break;
					}
				}
			}
#pragma endregion

			cont = 0;
		}

		return 1;
	}

	//não utilizado
	int vc_segment_area_vertical(IVC *src, int area, int numeroPontos, int cor)
	{
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos = 0;
		int cont = 0, y = 0, x = 0, calcx = 0, calcy = 0;
		float vertical = height;
		int quantosQuadrados = ((width) / (area));


		vertical = vertical / area;

		vertical > ((int)vertical) ? vertical++ : vertical;

		quantosQuadrados = (int)vertical;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;


		for (size_t i = 0; i < quantosQuadrados; i++)
		{

			calcy = i % (int)(height / area);

			if (calcy == 0)
				calcy = (i / (int)(height / area));

#pragma region Conta
			for (y = (area*calcy); y < area + (area* calcy); y++)
			{
				for (x = 0; x < width; x++)
				{
					if ((y >= 0) && (y < height) && (x >= 0) && (x < width))
					{
						pos = y* bytesperline + x *channels;
						if (src->data[pos] == cor)
							cont++;
					}
					else
						break;
				}
			}
#pragma endregion

#pragma region Apaga
			if (cont >= numeroPontos)
			{
				for (y = (area*calcy); y < area + (area* calcy); y++)
				{
					for (x = 0; x < width; x++)
					{
						if ((y >= 0) && (y < height) && (x >= 0) && (x < width))
						{
							pos = y* bytesperline + x *channels;
							src->data[pos] = 255 - cor;

						}
						else
							break;
					}
				}
			}
#pragma endregion

			cont = 0;
		}

		return 1;
	}

	//maior que a quantidade  entao apaga
	int vc_clear_missing_lines(IVC *srcdst, int quantidade, int cor)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int contPixeis = 0, contEspacos = 0;
		int i = 0, y, x;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				if (srcdst->data[pos] == cor)
					contPixeis++;

			}
			if (contPixeis < quantidade || contPixeis == 0);

			else
			{
				for (size_t j = 0;j < width; j++)
				{
					pos = y* bytesperline + j *channels;
					srcdst->data[pos] = 255 - cor;
				}
			}

			contPixeis = 0;
		}


		return 1;
	}

	//não utilizado
	int vc_clear_missing_lines_major(IVC *srcdst, int quantidade, int cor)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int contPixeis = 0, contEspacos = 0;
		int i = 0, y, x;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				if (srcdst->data[pos] == cor)
					contPixeis++;

			}
			if (contPixeis > quantidade || contPixeis == 0);

			else
			{
				for (size_t j = 0; j < width; j++)
				{
					pos = y* bytesperline + j *channels;
					srcdst->data[pos] = 255 - cor;
				}
			}

			contPixeis = 0;
		}


		return 1;
	}

	//calcula uma area para desenhar o retangulo
	int vc_rentangle(IVC *srcdst, int espaco, int cor)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos; 
		unsigned int *pontos = (int*)calloc(4, sizeof(unsigned int));
		int y;
		int cont = 0;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				if (srcdst->data[pos] == cor)
				{
					if (cont == 0)
					{
						pontos[0] = x;
						pontos[1] = y;
					}
					cont = 1;
					if (x > pontos[2])
						pontos[2] = x;

					if (y > pontos[3])
						pontos[3] = y;

					if (x < pontos[0])
						pontos[0] = x;

					if (y < pontos[1])
						pontos[1] = y;
				}
			}
		}


		if ((pontos[0] <= 0) || (pontos[0] >= width))
			return 0;

		else if ((pontos[1] <= 0) || (pontos[1] >= width))
			return 0;

		else if ((pontos[2] <= 0) || (pontos[2] >= height))
			return 0;

		else if ((pontos[3] <= 0) || (pontos[3] >= height))
			return 0;

		pontos[0] -= espaco;
		pontos[1] -= espaco;
		pontos[2] += espaco;
		pontos[3] += espaco;
		PintRetangulo(srcdst, pontos[0], pontos[1], pontos[2], pontos[3], cor);

		return 1;
	}	  

	//vai desenhar um retangulo recebendo pontos
	int vc_rentangleRGB(IVC *srcdst, int pontos[4],int espaco, int cor)
	{
		int r = 1;
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int y;
		int cont = 0;
		espaco = 0;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;

		pontos[0] -= espaco;
		pontos[1] -= espaco;
		pontos[2] += espaco;
		pontos[3] += espaco;
		
		r &= PintRetangulo(srcdst, pontos[0], pontos[1], pontos[2], pontos[3], cor);

		return r;
	}

	//retorna os pontos de uma area se esta foi demasiado grande redimensiona-la
	int* vc_area(IVC *srcdst, int cor)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		unsigned int *pontos = (int*)calloc(4, sizeof(unsigned int));
		int y;
		int cont = 0;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				if (srcdst->data[pos] == cor)
				{
					if (cont == 0)
					{
						pontos[0] = x;
						pontos[1] = y;
					}
					cont = 1;
					if (x > pontos[2])
						pontos[2] = x;

					if (y > pontos[3])
						pontos[3] = y;

					if (x < pontos[0])
						pontos[0] = x;

					if (y < pontos[1])
						pontos[1] = y;
				}
			}
		}

		//pontos[0] x min 
		//pontos[1] y min
		//pontos[2] x max
		//pontos[3] y max

		if ((pontos[2] - pontos[0]) > (srcdst->width/2))
		{
			pontos[0] += (srcdst->width / 5);
			pontos[2] -= (srcdst->width / 5);
		}

		if ((pontos[3] - pontos[1]) > (srcdst->height / 4))
		{
			if ((pontos[3] - pontos[1]) / 2 > srcdst->height) {
				pontos[3] -= (srcdst->height / 6);
			}
			else
				pontos[1] += (srcdst->height / 6);
		}

		return pontos;
	}
	
	//saca os pontos de um possivel rectangulo e tenta verificar se este é mesmo um rectangulo
	int* vc_find_retangle(IVC *srcdst, IVC *RGB, int label)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		unsigned int *pontos = (int*)calloc(4, sizeof(unsigned int));
		int y;
		int cont = 0;
		int aux;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (size_t i = 0; i < (label+VALOR); i++)
		{
			aux = i; // obtenho a cor que vou procurar na imagem
			cont = 0;

			pontos[0] = 0;
			pontos[1] = 0;
			pontos[2] = 0;
			pontos[3] = 0;

			if (aux == 0)
				continue;

			for (y = 0; y < height; y++)
			{
				for (size_t x = 0; x < width; x++)
				{
					pos = y* bytesperline + x *channels;

					if (srcdst->data[pos] == aux)
					{
						if (cont == 0)
						{
							pontos[0] = x;
							pontos[1] = y;
						}
						cont = 1;
						if (x > pontos[2])
							pontos[2] = x;

						if (y > pontos[3])
							pontos[3] = y;

						if (x < pontos[0])
							pontos[0] = x;

						if (y < pontos[1])
							pontos[1] = y;
					}
				}
			}
			

			//tenho um objecto de uma cor agora tenho que verificar se é um rectangulo
			if (vc_is_rectangle(srcdst, aux, pontos) && vc_contem_cores(RGB, pontos))
				return pontos;
		}
		

		//pontos[0] x min 
		//pontos[1] y min
		//pontos[2] x max
		//pontos[3] y max

		
		return pontos;
	}

	//saca o menor valor do array
	int menor_array(int array[], int size)
	{
		int i;
		int menor = 255;
		for (i = 0; i < size; i++)
		{
			if (array[i] != 0 && array[i] != 255 && menor > array[i])  menor = array[i];
		}
		return menor;
	}

	//verifica se tem uma area que poderá ser um rectangulo e a largura e comprimento
	int vc_is_rectangle(IVC *srcdst, int cor, int pontos[4])
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		int y;
		int cont = 0;
		int aux;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;


		for (y = pontos[1]; y <= pontos[3]; y++)
		{
			for (size_t x = pontos[0]; x <= pontos[2]; x++)
			{
				pos = y* bytesperline + x *channels;
				cont++;
			}
		}

		return ( ((cont * 100) / (srcdst->width*srcdst->height) >= 3 ) && ((cont * 100) / (srcdst->width*srcdst->height) <= 6)  && (pontos[2] - pontos[0]) > (( pontos[3] - pontos[1])*2.5));
	}

	//verifica se tem determinadas cores 
	int vc_contem_cores(IVC *RGB, int pontos[4])
	{
		long int pos;
		int yMin = pontos[1], yMax = pontos[3];
		int x, y;

		int contaPixeis[3] = {0};

		//	contaPixeis[0] BLACK
		//	contaPixeis[1] BLUE
		//	contaPixeis[2] WHITE		
		

		 *contaPixeis = vc_rgb_to_hsv_filter_colors(RGB,contaPixeis, pontos);

		if ((contaPixeis[2] > contaPixeis[1]) && (contaPixeis[0] > contaPixeis[1]))
			return 1;
		
		return 0;
	}

	//deixa apenas a maior area com pixeis de determinada cor
	int vc_only_live_greatter_zona(IVC *srcdst, int cor)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int yMin, yMax, pixeis = 0;
		int bytesperline = srcdst->bytesperline;
		long int pos;
		Lista lista = NULL;
		lista = (Lista)calloc(1, sizeof(struct nodo));
		int y, x, i;
		int contU = 0, contD = 0;
		int temPixeisemX = 0;


		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (y = 0; y < height; y++)
		{
			for (x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				if (srcdst->data[pos] == cor)
				{
					lista->pixeis++;

					if (contU == contD)
					{
						contU++;
						lista->yMin = y;
					}

					else if (lista->yMin == 0)
						lista->yMin = y;

				}
				else
					temPixeisemX++;

			}

			if (temPixeisemX == width)
			{
				if (contD != contU  &&  lista->yMin != y - 1 && lista->pixeis != 0)
				{
					//lista->pixeis = pixeis;
					lista->yMax = y - 1;

					lista = Inserir(lista, 0, 0, 0);
					contD++;
				}
			}
			temPixeisemX = 0;
		}

	#pragma region Fica com o Maior



		Lista aux = NULL;
		aux = (Lista)calloc(1, sizeof(struct nodo));
		aux = lista;
		pixeis = width* height;
		temPixeisemX = 0;

		for (i = 0;aux->yMin >= 0 && aux->yMax < height;)
		{
			if (aux->pixeis > 0 && aux->pixeis < pixeis && aux->pixeis > temPixeisemX && (aux->yMax - aux->yMin) >= MINLATERAL)
			{
				yMin = aux->yMin;
				yMax = aux->yMax;
				temPixeisemX = aux->pixeis;
			}
			aux = aux->seguinte;
			if (aux == NULL)
				break;

		}
		Liberta(aux);

	#pragma endregion                      

		if (lista == NULL)
			return 0;

		else
		{
			for (i = 0;lista->yMin >= 0 && lista->yMax < height;)
			{					  
				if (temPixeisemX == lista->pixeis || lista->yMin == lista->yMax);

				else
				{
					for (y = lista->yMin; y <= lista->yMax; y++)
					{
						for (size_t x = 0; x < width; x++)
						{
							pos = y* bytesperline + x *channels;
							srcdst->data[pos] = 0;
						}
					}
				}


				 
				lista = lista->seguinte;
				if (lista == NULL)
					break;

			}
			Liberta(lista);
			return 1;
		}

		
		
	}

	char* vc_identify_plate(IVC *srcdst, int cor)
	{
		const int linhas = 35, colunas = 25;
		char* dados = (char*)malloc(9 * sizeof(char));
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int pixeis = 0;
		int bytesperline = srcdst->bytesperline;
		long int pos, posx;
		ListaCompleta lista = NULL;
		
		lista = (ListaCompleta)calloc(1, sizeof(struct nodoC));
		int y, x, hh=0;
		unsigned int i = 0;;
		int contU = 0, contD = 0;
		int temPixeisemX = 0;
		



		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		#pragma region Encontra as letras da matricula | Insere numa lista ligada

		for (x = 0; x < width; x++)
		{
			for (y = 0; y < height; y++)
			{
				pos = y* bytesperline + x *channels;

				if (srcdst->data[pos] == cor)
				{
					if (contU == contD)
					{
						contU++;
						lista->xMin = x;
						lista->yMin = y;
					}

					if (x > lista->xMax)
						lista->xMax = x;

					if (y > lista->yMax)
						lista->yMax = y;

					if (x < lista->xMin)
						lista->xMin = x;

					if (y < lista->yMin)
						lista->yMin = y;

					lista->pixeis++;
				}

				else
					temPixeisemX++;

			}

			if (temPixeisemX == height)
			{
				if (contD != contU  &&  lista->xMin != x - 1 && lista->pixeis != 0)
				{
					//lista->pixeis = pixeis;
					lista->xMax = x - 1;
					lista = InserirCompleta(lista, 0, 0, 0, 0, 0);
					contD++;
				}
			}
			temPixeisemX = 0;
		}
#pragma endregion			   								
					  
		

		#pragma region Gera imagens das letras _ numeros

		while (lista != NULL)
		{		  
			if (lista->pixeis == 0);

			else {
				vc_save_image_plate(srcdst, lista->yMin, lista->yMax, lista->xMin, lista->xMax, i);

				// Redimensiona essa mesma imagem
				vc_resize_image(colunas, linhas,i);
				i++;  
			}
			lista = lista->seguinte;
		}
		#pragma endregion

		int auxInt=0;
		char auxStringU [50];
		char auxStringD[50];
		IVC* auxImageU;
		IVC* auxImageD;

		#pragma region Gera Histograma

		for (size_t j = 0; j <  i; j++)
		{
			sprintf(auxStringU, "imagens_letras\\letra_%i.pbm", j);
			sprintf(auxStringD, "imagens_letras_histograma\\letra_%i.pbm", j);
			
			auxImageU = vc_read_image(auxStringU);
			auxImageD = vc_image_new(colunas,linhas, 1, 255);

			vc_xpto_histogram(auxImageU, auxImageD);					 
			vc_write_image(auxStringD, auxImageD);

			vc_image_free(auxImageU);
			vc_image_free(auxImageD);
		 
		}

		#pragma endregion


		float *percentagem;

		#pragma region Estrutura de identificação

		for (hh = 0; hh < 8; hh++)
		{				
			sprintf(auxStringU, "imagens_letras_histograma\\letra_%i.pbm", hh);
			auxImageU= vc_read_image(auxStringU);
			dados[hh] = vc_identify_letter(auxImageU);
					
		}

		#pragma endregion

		dados[hh] = '\0';
	
		return dados;
	}

	char vc_identify_letter(IVC *srcdst)
	{
		#define tamanho 18
		char cha = '-';
		IVC* imageAux;
		float percentagem[tamanho];
		char auxString[tamanho][50] = {"imagens_letras_origem\\letra_0.pbm",
			"imagens_letras_origem\\letra_1.pbm",
			"imagens_letras_origem\\letra_2.pbm",
			"imagens_letras_origem\\letra_3.pbm",
			"imagens_letras_origem\\letra_4.pbm",
			"imagens_letras_origem\\letra_6.pbm",
			"imagens_letras_origem\\letra_8.pbm",
			"imagens_letras_origem\\letra_9.pbm",
			"imagens_letras_origem\\letra_D.pbm",
			"imagens_letras_origem\\letra_F.pbm",
			"imagens_letras_origem\\letra_G.pbm",
			"imagens_letras_origem\\letra_S.pbm",
			"imagens_letras_origem\\letra_H.pbm",
			"imagens_letras_origem\\letra_N.pbm",
			"imagens_letras_origem\\letra_ponto.pbm",
			"imagens_letras_origem\\letra_Q.pbm",		  
			"imagens_letras_origem\\letra_1_defeito.pbm",
			"imagens_letras_origem\\letra_8_defeito.pbm" };

		for (size_t i = 0; i < tamanho; i++)
		{
			imageAux = vc_read_image(auxString[i]);	 	
			percentagem[i] = (vc_compare_images(srcdst, imageAux));
		}
		
		float maior = 0;
		int indice = 0;
		for (size_t i = 0; i < tamanho; i++)
		{
			if (percentagem[i] > maior)
			{
				maior = percentagem[i];
				indice = i;				
			}
		}
	

		switch (indice)
		{
		case 0:
			cha = '0';
			break;

		case 1:
			cha = '1';
			break;

		case 2:
			cha = '2';
			break;

		case 3:
			cha = '3';
			break;

		case 4:
			cha = '4';
			break;

		case 5:
			cha = '6';
			break;

		case 6:
			cha = '8';
			break;

		case 7:
			cha = '9';
			break;

		case 8:
			cha = 'D';
			break;
		
		case 9:
			cha = 'F';
			break;
		
		case 10:
			cha = 'G';
			break;
		
		case 11:
			cha = 'S';
			break;

		case 12:
			cha = 'H';
			break;

		case 13:
			cha = 'N';
			break;

		case 14:
			cha = '-';
			break;

		case 15:
			cha = 'Q';
			break;	 

		case 16:
			cha = '1';
			break;

		case 17:
			cha = '8';
			break;
		}

		return cha;
	}

	int vc_save_image_plate(IVC *srcdst,unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax, unsigned int i)
	{
		IVC *temp = vc_image_new((xMax - xMin) + 1, (yMax - yMin) + 1, 1, 255);
		long int pos, posx;
		int hh = 0;
		int xx=0, yy ,x,y;
		char tempString[28];

		//copia a informação de uma imagem para a outra
		for (x = xMin; x <= xMax; x++)
		{
			yy = 0;
			for (y = yMin; y <= yMax; y++)
			{
				pos = y* srcdst->bytesperline + x *srcdst->channels;
				posx = yy* temp->bytesperline + xx * temp->channels;
				temp->data[posx] = (int)srcdst->data[pos];
				yy++;
			}
			xx++;
		}

#pragma region Geração de nome
		sprintf(tempString, "imagens_letras\\letra_%i.pbm", i);

#pragma endregion

		vc_write_image(tempString, temp);
		vc_image_free(temp);  

		return 1;
	
	}
	
	//compara uma imagem e obtenho a percentagem do erro entre elas
	float vc_compare_images(IVC *srcU , IVC *srcD)
	{
		if ((srcU->width <= 0) || (srcU->height <= 0) || (srcU->data == NULL) || (srcU->channels != 1))
			return 0;

		if ((srcD->width <= 0) || (srcD->height <= 0) || (srcD->data == NULL) || (srcD->channels != 1))
			return 0;

		if ((srcD->width != srcU->width) || (srcD->height != srcU->height))
			return 0;

		long int pos;
		int erro[25] = {0};



		//basicamente fazer a diferença entre dois histogramas na posicao i, e elevar essa diferença ao quadrado
		for (size_t x = 0; x < srcU->width; x++)
		{
			for (size_t y = 0; y < srcU->height; y++)
			{
				pos = y* srcU->bytesperline + x * srcU->channels;
				if (srcU->data[pos] != srcD->data[pos]  )
					erro[x]++;

			}
		}			

		float maior = 0;
		for (size_t i = 0; i < 25; i++)
		{
			erro[i] *= erro[i];	
			maior += erro[i];
			  
		}
		
			
		return  ((float)(100) - ((float)maior / (float)(srcU->width*srcU->height)));
	}

	//Redimensiona uma imagem através do algoritmo do vizinho mais proximo
	int vc_resize_image(int wD, int hD, unsigned int i)
	{
		char tempString[50];
		sprintf(tempString, "imagens_letras\\letra_%i.pbm", i);
		IVC* tempU = vc_image_new(wD, hD, 1, 255);
		IVC* tempD = vc_read_image(tempString);
		int wU = tempD->width;
		int hU = tempD->height;
		double x_ratio = wU / (double)wD;
		double y_ratio = hU / (double)hD;
		double px, py;
		long int pos;
		

		for (int y = 0; y<hD; y++) {
			for (int x = 0; x<wD; x++) {
				px =  floor(x*x_ratio);
				py = floor(y*y_ratio);

				pos = y* tempU->bytesperline + x * tempU->channels;
				tempU->data[pos] = tempD->data[(int)((py*wU) + px)];
			}
		}

		vc_write_image(tempString, tempU);
		vc_image_free(tempU);
		vc_image_free(tempD);

		return 1;
	}

	//gera um histograma fora do comum para uma imagem
	int vc_xpto_histogram(IVC* src, IVC* srcD)
	{		 
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos;
		long int size = src->width * src->height;
		int contaPixeis[35] = { 0 };

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;
				if (src->data[pos] == 255)
					contaPixeis[y]++;
			}

		}

		int x, y;

		for (x = 0; x < srcD->width; x++)
		{
			for (y = 0; y < srcD->height; y++)
			{
				
				pos = y* srcD->bytesperline + x *srcD->channels;

				// estou conciente que deveria estar aqui srcD->height 	mas tal como o nome indica é um histograma xpto
				if (contaPixeis[x] >= (srcD->width - y))
					srcD->data[pos] = (unsigned char)255;

				else
					srcD->data[pos] = (unsigned char)0;

			}

		}
		return  1;
	}
		
	//não utilizado
	int vc_errase(IVC *srcdst, int xMin, int yMin, int xMax, int yMax)
	{
		unsigned char *data = (unsigned char*)srcdst->data;
		int width = srcdst->width, height = srcdst->height;
		int channels = srcdst->channels;
		int levels = srcdst->levels;
		int bytesperline = srcdst->bytesperline;
		long int pos;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 3))
			return 0;


		if ((xMax == NULL) || (xMin == NULL))
		{

			for (size_t y = 0; y < height; y++)
			{
				for (size_t x = 0; x < width; x++)
				{
					pos = y* bytesperline + x *channels;

					if ((y >= yMin && y <= yMax))
						continue;

					
					data[pos] = 0;
					data[pos + 1] = 0;
					data[pos + 2] = 0;
				}

			}
		}

		else
		{						
			for (size_t y = 0; y < height; y++)
			{
				for (size_t x = 0; x < width; x++)
				{
					pos = y* bytesperline + x *channels;

					if ((x >= xMin && x <= xMax) && (y >= yMin && y <= yMax))
					{
						x = xMax;
						continue;

					}
					data[pos] = 0;
					data[pos + 1] = 0;
					data[pos + 2] = 0;
				}

			}
		}
		return 1;
	}

	//não utilizado
	int vc_fill_stuff(IVC *src, IVC *dst, int cor)
	{
		unsigned char *data = (unsigned char*)src->data;
		int width = src->width, height = src->height;
		int channels = src->channels;
		int levels = src->levels;
		int bytesperline = src->bytesperline;
		long int pos;
		int pontosSeguidos =  0 ;
		Lista lista = NULL;
		lista = (Lista*)calloc(1,sizeof(struct nodo));
		int contU = 0;//imaginando que este é a cor preta
		int contD = 0;//imaginando que este é a cor branca
		int y;

		if ((width <= 0) || (height <= 0) || (data == NULL) || (channels != 1))
			return 0;

		for (size_t y = 0; y < height; y++)
		{
			for (size_t x = 0; x < width; x++)
			{
				pos = y* bytesperline + x *channels;

				//exemplo quero preencher contornos pretos
				if (data[pos] == cor) 
				{
					contU = 1;

					if (contU == contD)
					{
						contU = 0;
						contD = 0;
						lista->pixeis = y;
						lista->yMax = x;
						lista->yMin = x - pontosSeguidos;
						lista = Inserir(lista, 0, 0, 0);
						pontosSeguidos = 0;
						for ( ; x < width; x++)
						{
							pos = y* bytesperline + x *channels;

							//exemplo quero preencher contornos pretos
							if (data[pos] != cor)
								break;
						}
					}
				}

				else
				{	
					if (contU == 1)
					{
						contD = 1;
						pontosSeguidos++;
					}
				}
			}
			contU = 0;
			contD = 0;
			pontosSeguidos = 0;
		}


		for (y = 0; y < height; y++)
		{
				for (size_t x = 0; x < width; x++)
				{
					pos = y* bytesperline + x *channels;
					dst->data[pos] =255 - cor;
				}
		}	 

		lista = lista->seguinte;

		for (y = height; y >= 0; y--)
		{
			if (lista->yMax != lista->yMin && lista->pixeis == y)
			{			
				for (size_t x = lista->yMin; x <= lista->yMax; x++)
				{
					pos = y* bytesperline + x *channels;
					dst->data[pos] = cor;				
				}

				if (lista->seguinte == NULL)
					break;

				lista = lista->seguinte;
			}
			if (lista->pixeis == y)
				y++;
		}

		return 1;
	}
  
	#pragma endregion

	#pragma region Numeros e letras (Não utilizado)

	int numero_um(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

	
		r&= ((xMax - xMin) <= (srcdst->width / 60));
		r &= ((yMax - yMin) > 6);

		return r;
	}

	int numero_seis(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + pontoY * 4)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 5)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + pontoY * 14)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 15)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 15)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + pontoY * 13)* srcdst->bytesperline + (xMin + pontoX * 11) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 13)* srcdst->bytesperline + (xMin + pontoX * 13) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 14)* srcdst->bytesperline + (xMin + pontoX * 12) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + pontoY * 13)* srcdst->bytesperline + (xMin + pontoX * 7) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 13)* srcdst->bytesperline + (xMin + pontoX * 9) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 14)* srcdst->bytesperline + (xMin + pontoX * 8) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + pontoY * 18)* srcdst->bytesperline + (xMin + pontoX * 15) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 19)* srcdst->bytesperline + (xMin + pontoX * 15) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 18)* srcdst->bytesperline + (xMin + pontoX * 16) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + pontoY * 29)* srcdst->bytesperline + (xMin + pontoX * 7) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 29)* srcdst->bytesperline + (xMin + pontoX * 8) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 29) * srcdst->bytesperline + (xMin + pontoX * 9) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		return r;
	}

	int numero_quatro(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		//Parte de cima
		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)+2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + 2)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2+ 3)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de cima lado esquerdo
		pos = (yMin + pontoY * 4)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + pontoY * 5)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		//meio lado direito
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 5)* srcdst->bytesperline + (xMax - (pontoX * 3)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 4)* srcdst->bytesperline + (xMax - (pontoX * 3)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		//centro
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + ((yMax - yMin) / 2))* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 +2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		//parte de baixo  direita
		pos = (yMax - pontoY * 6)* srcdst->bytesperline + (xMin + (xMax - xMin)/2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 6)* srcdst->bytesperline + (xMin + (xMax - xMin) / 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 7) * srcdst->bytesperline + (xMin + (xMax - xMin) / 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo  direita
		pos = (yMax - pontoY * 6)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 6)* srcdst->bytesperline + (xMin + pontoX * 4) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 7) * srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo  baixo
		pos = (yMax - pontoY * 3)* srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 2)* srcdst->bytesperline + (xMax - pontoX * 4) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 4) * srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo  direita
		pos = (yMax - pontoY * 6)* srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 6)* srcdst->bytesperline + (xMax - pontoX * 4) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 7) * srcdst->bytesperline + (xMax - pontoX *3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		return r;
	}			 

	int numero_oito(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		//parte de cima 
		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de cima lado esquerdo
		pos = (yMin + pontoY * 4)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 5)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//meio lado direito
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 5)* srcdst->bytesperline + (xMax - (pontoX * 3)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 4)* srcdst->bytesperline + (xMax - (pontoX * 3)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//centro
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + ((yMax - yMin) / 2))* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + ((yMax - yMin) / 2) - pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);


		//parte de baixo lado esquerdo
		pos = (yMin + ((yMax - yMin) / 2 + pontoY * 4))* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + ((yMax - yMin) / 2 + pontoY * 4)) * srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo lado direito
		pos = (yMax - pontoY * 2)* srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 3)* srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);


		//parte de baixo
		pos = (yMax - pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		return r;
	}

	int numero_nove(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		//cima
		pos = (yMin + pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de cima esquerda
		pos = (yMin + pontoY * 4)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 5)* srcdst->bytesperline + (xMin + pontoX * 4) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte do meio esquerda
		pos = (yMin + pontoY * 14)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 15)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 15)* srcdst->bytesperline + (xMin + pontoX * 4) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte do meio direita
		pos = (yMin + pontoY * 14)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 15)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 15)* srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//centro
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 11) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = ((yMin + (yMax - yMin) / 2) + pontoY * 1)  * srcdst->bytesperline + (xMin + pontoX * 13) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 12) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo direita
		pos = (yMax - pontoY * 5)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 5)* srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 4)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo esquerda
		pos = (yMin + (yMax - yMin) / 2 + pontoY * 3)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2 + pontoY * 3)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2 + pontoY * 3)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		//baixo
		pos = (yMax - pontoY * 3)* srcdst->bytesperline + (xMin + (xMax - xMin) / 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 2)* srcdst->bytesperline + (xMin + (xMax - xMin) / 2 + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 2) * srcdst->bytesperline + (xMin + (xMax - xMin) / 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		return r;
	}

	int letra_q(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		//parte de cima
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		// lado direito
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		// centro
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) + 1)* srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) - 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		// lado esquerdo
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo
		pos = (yMax - pontoY * 2)* srcdst->bytesperline + xMin + ((xMax - xMin) / 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 3)* srcdst->bytesperline + xMin + ((xMax - xMin) / 2 - 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 3) * srcdst->bytesperline + xMin + ((xMax - xMin) / 2 + 1)* srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//a barra do Q
		pos = (yMax - pontoY * 1)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 1)* srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - pontoY * 2) * srcdst->bytesperline + (xMax - pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);


		return r;
	}

	int letra_n(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		//parte de cima
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = yMin * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		// lado direito
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		// centro
		pos = (yMin + (yMax - yMin) / 2 - 3)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) + 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2 - 3)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) + 2)* srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2 - 2)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) +3) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		// lado esquerdo
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		//parte de baixo
		pos = (yMax - pontoY * 2)* srcdst->bytesperline + xMin + ((xMax - xMin) / 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMax - pontoY * 3)* srcdst->bytesperline + xMin + ((xMax - xMin) / 2 - 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMax - pontoY * 3) * srcdst->bytesperline + xMin + ((xMax - xMin) / 2 + 1)* srcdst->channels;
		r &= (srcdst->data[pos] == 0);
 
		return r;
	}

	int letra_f(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		//parte de cima
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin * srcdst->bytesperline + (xMax- pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY *2) * srcdst->bytesperline + (xMin) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		// lado direito
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		// centro
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) + 1)* srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) - 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 3) + (xMax - xMin)/3 + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		// lado esquerdo
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + 1)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 2)* srcdst->bytesperline + (xMin + pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 2)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 1)* srcdst->bytesperline + (xMin + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);


		//parte de baixo
		pos = (yMax - pontoY * 2)* srcdst->bytesperline + xMin + ((xMax - xMin) / 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMax - pontoY * 3)* srcdst->bytesperline + xMin + ((xMax - xMin) / 2 - 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMax - pontoY * 3) * srcdst->bytesperline + xMin + ((xMax - xMin) / 2 + 1)* srcdst->channels;
		r &= (srcdst->data[pos] == 0);	 	

		return r;
	}

	int letra_s(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax)
	{
		long int pos;
		int r = 1;
		float percentagemX = (100 * 1) / (xMax - xMin);
		float percentagemY = (100 * 1) / (yMax - yMin);
		int pontoX = 1;
		int pontoY = 1;

		//parte de cima
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMin * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + ((yMax - yMin) / 6)) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 5)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + ((yMax - yMin) / 6)) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 5) + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMin + ((yMax - yMin) / 6)) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 5)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + ((yMax - yMin) / 6)) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 5) - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		// lado direito
		pos = (yMin + (yMax - yMin) / 3)* srcdst->bytesperline + (xMax - pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 3)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMin + (yMax - yMin) / 3 + 1)* srcdst->bytesperline + (xMax - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		// centro
		pos = (yMin + (yMax - yMin) / 2 )* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 )* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2))* srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMin + (yMax - yMin) / 2 + pontoY * 1)* srcdst->bytesperline + (xMin + ((xMax - xMin) / 2) + 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		// lado esquerdo
		pos = (yMax - (yMax - yMin) / 3)* srcdst->bytesperline + (xMin + pontoX * 3) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMax - (yMax - yMin) / 3)* srcdst->bytesperline + (xMin + pontoX * 2)* srcdst->channels;
		r &= (srcdst->data[pos] == 0);
		pos = (yMax - (yMax - yMin) / 3 - 1)* srcdst->bytesperline + (xMin+ pontoX * 2) * srcdst->channels;
		r &= (srcdst->data[pos] == 0);

		//parte de baixo
		pos = (yMax - pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax- pontoY * 1) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 + 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = yMax * srcdst->bytesperline + (xMin + ((xMax - xMin) / 2 - 1)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMax - ((yMax - yMin) / 6)) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 5)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - ((yMax - yMin) / 6)) * srcdst->bytesperline + (xMin + ((xMax - xMin) / 5) + pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		pos = (yMax- ((yMax - yMin) / 6) + pontoY * 2) * srcdst->bytesperline + (xMax - ((xMax - xMin) / 5)) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);
		pos = (yMax - ((yMax - yMin) / 6)+ pontoY * 2) * srcdst->bytesperline + (xMax - ((xMax - xMin) / 5) - pontoX * 1) * srcdst->channels;
		r &= (srcdst->data[pos] == 255);

		return r;
	}

	#pragma endregion	   

	#pragma region Pinta coisas

	//pinta uma determinada cor num pixel. A imagem pode ser RGB ou escalas de gray
	void PintPonto(IVC *imagem, unsigned int x, unsigned int y, int cor)
	{
		unsigned int colunas = (x), linhas = (y);
		unsigned int pos;
		pos = (linhas * imagem->bytesperline + colunas * imagem->channels);

		if ( pos < 0 || imagem->width <= x || imagem->height <= y);

		else {
			if (imagem->channels == 3)
			{
				imagem->data[pos] = cor;
				imagem->data[pos+1] = cor;
				imagem->data[pos+2] = cor;
			}
			else
				imagem->data[pos] = cor;

		}
	}

	//pinta uma linha
	void PintLinha(IVC *imagem, unsigned int xU, unsigned int yU, unsigned int xD, unsigned int yD, int cor)
	{

		int dx = abs(xD - xU);//diferença entre x
		int sx = xU < xD ? 1 : -1; // verificar se a linha é para a frente ou para trás
		int dy = abs(yD - yU);//diferença entre y
		int sy = yU < yD ? 1 : -1;// verificar se a linha é para baixo ou para cima
		int err = (dx>dy ? dx : -dy) / 2;
		int e2;

		for (;;) {

			PintPonto(imagem, xU, yU, cor);

			if (xU == xD && yU == yD)
				break;

			e2 = err;
			if (e2 >-dx)
			{
				err -= dy;
				xU += sx;
			}
			if (e2 < dy) { err += dx; yU += sy; }
		}
	}

	//Faz um redimensionamento caso não tenha os minimos (comprimento e largura)
	int PintRetangulo(IVC *imagem, unsigned int xU, unsigned int yU, unsigned int xD, unsigned int yD, int cor)
	{

		if (xU >= imagem->width  || xD >= imagem->width)
			return 0;
		if (yU >= imagem->width || yD >= imagem->width)
			return 0;

		if (xD - xU < MINCOMPRIMENTO)
			xD = xU + (MINCOMPRIMENTO + (MINCOMPRIMENTO * 0.5));


		if (yD - yU < MINLATERAL)
			yD = yU + MINLATERAL + (MINLATERAL * 0.5);

		PintLinha(imagem, xU, yU, xU + abs(xU - xD), yU, cor);

		PintLinha(imagem, xU + abs(xU - xD), yU, xU + abs(xU - xD), yU + abs(yU - yD), cor);

		PintLinha(imagem, xU + abs(xU - xD), yU + abs(yU - yD), xU, yU + abs(yU - yD), cor);

		PintLinha(imagem, xU, yU + abs(yU - yD), xU, yU, cor);
		return 1;
	}

	#pragma endregion 

	#pragma region Listas Ligadas

	void Liberta(Lista l) {
		Lista aux;
		if (l != NULL) {
			aux = l->seguinte;
			free(l);
			Liberta(aux);
		}
	}

	void LibertaCompleta(ListaCompleta l) {
		ListaCompleta aux;
		if (l != NULL) {
			aux = l->seguinte;
			free(l);
			LibertaCompleta(aux);
		}
	}

	ListaCompleta InserirCompleta(ListaCompleta l, unsigned int xMin, unsigned int xMax, unsigned int yMin, unsigned int yMax, unsigned int pixeis)
	{
		ListaCompleta novoNodo = NULL;
		novoNodo = (ListaCompleta)malloc(sizeof(struct nodoC));
		novoNodo->yMin = yMin;
		novoNodo->yMax = yMax;
		novoNodo->xMin = xMin;
		novoNodo->xMax = xMax;
		novoNodo->pixeis = pixeis;
		novoNodo->seguinte = l;
		return novoNodo;
	}

	Lista Inserir(Lista l, unsigned int min, unsigned int max, unsigned int pixeis)
	{
		Lista novoNodo = NULL;
		novoNodo = (Lista)malloc(sizeof(struct nodo));
		novoNodo->yMin = min;
		novoNodo->yMax = max;
		novoNodo->pixeis = pixeis;
		novoNodo->seguinte = l;
		return novoNodo;
	}
	#pragma endregion 


#pragma endregion

#pragma region Imagem

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//            FUNÇÕES: ALOCAR E LIBERTAR UMA IMAGEM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




// Alocar memória para uma imagem
IVC *vc_image_new(int width, int height, int channels, int levels)
{
	IVC *image = (IVC *)malloc(sizeof(IVC));

	if (image == NULL) return NULL;
	if ((levels <= 0) || (levels > 255)) return NULL;

	image->width = width;
	image->height = height;
	image->channels = channels;
	image->levels = levels;
	image->bytesperline = image->width * image->channels;
	image->data = (unsigned char *)malloc(image->width * image->height * image->channels * sizeof(char));

	if (image->data == NULL)
	{
		return vc_image_free(image);
	}

	return image;
}


// Libertar memória de uma imagem
IVC *vc_image_free(IVC *image)
{
	if (image != NULL)
	{
		if (image->data != NULL)
		{
			free(image->data);
			image->data = NULL;
		}

		free(image);
		image = NULL;
	}

	return image;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//    FUNÇÕES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


char *netpbm_get_token(FILE *file, char *tok, int len)
{
	char *t;
	int c;

	for (;;)
	{
		while (isspace(c = getc(file)));
		if (c != '#') break;
		do c = getc(file);
		while ((c != '\n') && (c != EOF));
		if (c == EOF) break;
	}

	t = tok;

	if (c != EOF)
	{
		do
		{
			*t++ = c;
			c = getc(file);
		} while ((!isspace(c)) && (c != '#') && (c != EOF) && (t - tok < len - 1));

		if (c == '#') ungetc(c, file);
	}

	*t = 0;

	return tok;
}


long int unsigned_char_to_bit(unsigned char *datauchar, unsigned char *databit, int width, int height)
{
	int x, y;
	int countbits;
	long int pos, counttotalbytes;
	unsigned char *p = databit;

	*p = 0;
	countbits = 1;
	counttotalbytes = 0;

	for (y = 0; y<height; y++)
	{
		for (x = 0; x<width; x++)
		{
			pos = width * y + x;

			if (countbits <= 8)
			{
				// Numa imagem PBM:
				// 1 = Preto
				// 0 = Branco
				//*p |= (datauchar[pos] != 0) << (8 - countbits);

				// Na nossa imagem:
				// 1 = Branco
				// 0 = Preto
				*p |= (datauchar[pos] == 0) << (8 - countbits);

				countbits++;
			}
			if ((countbits > 8) || (x == width - 1))
			{
				p++;
				*p = 0;
				countbits = 1;
				counttotalbytes++;
			}
		}
	}

	return counttotalbytes;
}


void bit_to_unsigned_char(unsigned char *databit, unsigned char *datauchar, int width, int height)
{
	int x, y;
	int countbits;
	long int pos;
	unsigned char *p = databit;

	countbits = 1;

	for (y = 0; y<height; y++)
	{
		for (x = 0; x<width; x++)
		{
			pos = width * y + x;

			if (countbits <= 8)
			{
				// Numa imagem PBM:
				// 1 = Preto
				// 0 = Branco
				//datauchar[pos] = (*p & (1 << (8 - countbits))) ? 1 : 0;

				// Na nossa imagem:
				// 1 = Branco
				// 0 = Preto
				datauchar[pos] = (*p & (1 << (8 - countbits))) ? 0 : 1;

				countbits++;
			}
			if ((countbits > 8) || (x == width - 1))
			{
				p++;
				countbits = 1;
			}
		}
	}
}


IVC *vc_read_image(char *filename)
{
	FILE *file = NULL;
	IVC *image = NULL;
	unsigned char *tmp;
	char tok[20];
	long int size, sizeofbinarydata;
	int width, height, channels;
	int levels = 255;
	int v;

	// Abre o ficheiro
	if ((file = fopen(filename, "rb")) != NULL)
	{
		// Efectua a leitura do header
		netpbm_get_token(file, tok, sizeof(tok));

		if (strcmp(tok, "P4") == 0) { channels = 1; levels = 1; }    // Se PBM (Binary [0,1])
		else if (strcmp(tok, "P5") == 0) channels = 1;               // Se PGM (Gray [0,MAX(level,255)])
		else if (strcmp(tok, "P6") == 0) channels = 3;               // Se PPM (RGB [0,MAX(level,255)])
		else
		{
#ifdef VC_DEBUG
			printf("ERROR -> vc_read_image():\n\tFile is not a valid PBM, PGM or PPM file.\n\tBad magic number!\n");
#endif

			fclose(file);
			return NULL;
		}

		if (levels == 1) // PBM
		{
			if (sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &width) != 1 ||
				sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &height) != 1)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tFile is not a valid PBM file.\n\tBad size!\n");
#endif

				fclose(file);
				return NULL;
			}

			// Aloca memória para imagem
			image = vc_image_new(width, height, channels, levels);
			if (image == NULL) return NULL;

			sizeofbinarydata = (image->width / 8 + ((image->width % 8) ? 1 : 0)) * image->height;
			tmp = (unsigned char *)malloc(sizeofbinarydata);
			if (tmp == NULL) return 0;

#ifdef VC_DEBUG
			printf("\nchannels=%d w=%d h=%d levels=%d\n", image->channels, image->width, image->height, levels);
#endif

			if ((v = fread(tmp, sizeof(unsigned char), sizeofbinarydata, file)) != sizeofbinarydata)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tPremature EOF on file.\n");
#endif

				vc_image_free(image);
				fclose(file);
				free(tmp);
				return NULL;
			}

			bit_to_unsigned_char(tmp, image->data, image->width, image->height);

			free(tmp);
		}
		else // PGM ou PPM
		{
			if (sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &width) != 1 ||
				sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &height) != 1 ||
				sscanf(netpbm_get_token(file, tok, sizeof(tok)), "%d", &levels) != 1 || levels <= 0 || levels > 255)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tFile is not a valid PGM or PPM file.\n\tBad size!\n");
#endif

				fclose(file);
				return NULL;
			}

			// Aloca memória para imagem
			image = vc_image_new(width, height, channels, levels);
			if (image == NULL) return NULL;

#ifdef VC_DEBUG
			printf("\nchannels=%d w=%d h=%d levels=%d\n", image->channels, image->width, image->height, levels);
#endif

			size = image->width * image->height * image->channels;

			if ((v = fread(image->data, sizeof(unsigned char), size, file)) != size)
			{
#ifdef VC_DEBUG
				printf("ERROR -> vc_read_image():\n\tPremature EOF on file.\n");
#endif

				vc_image_free(image);
				fclose(file);
				return NULL;
			}
		}

		fclose(file);
	}
	else
	{
#ifdef VC_DEBUG
		printf("ERROR -> vc_read_image():\n\tFile not found.\n");
#endif
	}

	return image;
}


int vc_write_image(char *filename, IVC *image)
{
	FILE *file = NULL;
	unsigned char *tmp;
	long int totalbytes, sizeofbinarydata;

	if (image == NULL) return 0;

	if ((file = fopen(filename, "wb")) != NULL)
	{
		if (image->levels == 1)
		{
			sizeofbinarydata = (image->width / 8 + ((image->width % 8) ? 1 : 0)) * image->height + 1;
			tmp = (unsigned char *)malloc(sizeofbinarydata);
			if (tmp == NULL) return 0;

			fprintf(file, "%s %d %d\n", "P4", image->width, image->height);

			totalbytes = unsigned_char_to_bit(image->data, tmp, image->width, image->height);
			printf("Total = %ld\n", totalbytes);
			if (fwrite(tmp, sizeof(unsigned char), totalbytes, file) != totalbytes)
			{
#ifdef VC_DEBUG
				fprintf(stderr, "ERROR -> vc_read_image():\n\tError writing PBM, PGM or PPM file.\n");
#endif

				fclose(file);
				free(tmp);
				return 0;
			}

			free(tmp);
		}
		else
		{
			fprintf(file, "%s %d %d 255\n", (image->channels == 1) ? "P5" : "P6", image->width, image->height);

			if (fwrite(image->data, image->bytesperline, image->height, file) != image->height)
			{
#ifdef VC_DEBUG
				fprintf(stderr, "ERROR -> vc_read_image():\n\tError writing PBM, PGM or PPM file.\n");
#endif

				fclose(file);
				return 0;
			}
		}

		fclose(file);

		return 1;
	}

	return 0;
}

#pragma endregion