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

#include "Header.hpp"											   



#pragma region Funcoes	 

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

int vc_categorize(Mat src, OVC imagem)
{
	char str[500] = { 0 };
	sprintf(str, "Area: %d", imagem.area);
	putText(src, str, cvPoint((imagem.xc / 1.1), imagem.yc - 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
	sprintf(str, "Perimetro: %d", imagem.perimeter);
	putText(src, str, cvPoint((imagem.xc / 1.1), imagem.yc - 20), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
	int laranjinhas = imagem.pixeisLaranja, area = imagem.area;

#pragma region Calibre

	if ((laranjinhas <= (area / 10)))
	{
		putText(src, "Objecto Nao Identificado", cvPoint(imagem.xc - 5, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
	}

	else
	{
		int valor = ((imagem.width *MM) / PIXEIS);

		if (valor >= 100)
		{
			putText(src, "Calibre : 0", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 87 && valor < 100)
		{
			putText(src, "Calibre : 1", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 84 && valor < 96)
		{
			putText(src, "Calibre : 2", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 81 && valor < 92)
		{
			putText(src, "Calibre : 3", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 77 && valor < 88)
		{
			putText(src, "Calibre : 4", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 73 && valor < 84)
		{
			putText(src, "Calibre : 5", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 70 && valor < 80)
		{
			putText(src, "Calibre : 6", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 67 && valor < 76)
		{
			putText(src, "Calibre : 7", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 64 && valor < 73)
		{
			putText(src, "Calibre : 8", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 62 && valor < 70)
		{
			putText(src, "Calibre : 9", cvPoint(imagem.xc - RADIUS*RADIUS*RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 60 && valor < 68)
		{
			putText(src, "Calibre : 10", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 58 && valor < 66)
		{
			putText(src, "Calibre : 11", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 56 && valor < 63)
		{
			putText(src, "Calibre : 12", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}
		else if (valor > 53 && valor < 60)
		{
			putText(src, "Calibre : 13", cvPoint(imagem.xc - RADIUS*RADIUS *RADIUS, imagem.yc + 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}


	}

#pragma endregion





	return 1;
}

int vc_categorize2(Mat src, OVC imagem)
{
	
	char str[500] = { 0 };		 
	
#pragma region Categoria

		float areaObjeto = imagem.area, areaVerde = imagem.pixeisOutros;

		double area = (double)((areaVerde *100) / (areaObjeto));
	

		if (area <= 2.2)
		{
			putText(src, "Categoria : Extra", cvPoint(imagem.xc - RADIUS*RADIUS*RADIUS, imagem.yc + 60), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}

		else if (area <= 3.5)
		{
			putText(src, "Categoria : I", cvPoint(imagem.xc - RADIUS*RADIUS*RADIUS, imagem.yc + 60), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}

		else if (area <= 8)
		{
			putText(src, "Categoria : II", cvPoint(imagem.xc - RADIUS*RADIUS*RADIUS, imagem.yc + 60), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}

		else
		{
			putText(src, "Categoria : III", cvPoint(imagem.xc - RADIUS*RADIUS* RADIUS, imagem.yc + 60), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		}


#pragma endregion

	
	return 1;
}

Mat vc_find_contourn(Mat src)
{
	Mat dst(src.rows, src.cols, CV_8UC3);

	int x, y;
	long int posA, posB, posC, posD, posX, posE, posF, posG, posH, posO;

	for (y = 1; y< src.rows - 1; y++)
	{
		for (x = 1; x< src.cols - 1; x++)
		{
			posX = y * src.step + x * 1;
			posO = y * dst.step + x * 3;

			//apagado dará os contornos perfeitos, mas diminui o desempenho
			if (src.data[posX] == 0)
			{
				//comentado dara mais desempenho
				dst.data[posO] = 0;
				dst.data[posO + 1] = 0;
				dst.data[posO + 2] = 0;
				continue;
			}
			posA = y * src.step + x * 1 - (1) - (src.step);
			posB = y * src.step + x * 1 - (src.step);
			posC = y * src.step + x * 1 + (1) - (src.step);
			posD = y * src.step + x * 1 - (1);
			posE = y * src.step + x * 1 + (1);
			posF = y * src.step + x * 1 - (1) + (src.step);
			posG = y * src.step + x * 1 - (src.step);
			posH = y * src.step + x * 1 + (1) + (src.step);


			if ((src.data[posA] == 0 || src.data[posB] == 0 || src.data[posC] == 0 || src.data[posD] == 0 || src.data[posE] == 0 || src.data[posF] == 0 || src.data[posG] == 0 || src.data[posH] == 0) &&
				(src.data[posA] != 0 || src.data[posB] != 0 || src.data[posC] != 0 || src.data[posD] != 0 || src.data[posE] != 0 || src.data[posF] != 0 || src.data[posG] != 0 || src.data[posH] != 0)) {
				dst.data[posO] = 255;
				dst.data[posO + 1] = 255;
				dst.data[posO + 2] = 255;
			}

			//apagar se quizer ver o objecto
			else {
				dst.data[posO] = 0;
				dst.data[posO + 1] = 0;
				dst.data[posO + 2] = 0;
			}
		}
	}

	return dst;
}

Mat remove_fundo(Mat src)
{
	Mat dst = src.clone();
	int i, size = src.rows * src.cols * 3;		

	for (i = 0; i < size; i += 3) 
	{
		if (src.data[i] > 60)
		{
			dst.data[i] = 255;
			dst.data[i+1] = 255;
			dst.data[i+2] = 255;
		}		
	}
	
	return dst;
}						 									   

int vc_bgr_to_hsv2(Mat src, Mat ref, int xMin, int yMin, int xMax, int yMax, int *pixeisVerde, int *pixeisOutros, float corB, float corG, float corR)
{
	(*pixeisVerde) = 0;
	(*pixeisOutros) = 0;
	int pixeis = 0;
	float r, g, b, hue, saturation, value, valueOrigin = MAX3(corB,corG,corR), maior, menor, saturationOrigin = (((valueOrigin - MIN3(corB, corG, corR)) / (valueOrigin))*255.0f);
	long int pos_src, pos_ref;


	for (int y = yMin; y <= yMax; y++)
	{
		for (int x = xMin; x <= xMax; x++)
		{
			pos_src = y* src.step + x * 3;

			pos_ref = y* ref.step + x * 1;

			if (ref.data[pos_ref] == 255)
			{


				r = (float)src.data[pos_src + 2];
				g = (float)src.data[pos_src + 1];
				b = (float)src.data[pos_src];

				maior = MAX3(r, g, b);
				menor = MIN3(r, g, b);

				value = maior;

				if (value == 0.0)
				{
					hue = 0.0;
					saturation = 0.0;
				}

				else
				{
					saturation = (unsigned char)(((maior - menor) / (maior))*255.0f);

					if (saturation == 0.0)
						hue = 0.0;

					else
					{
#pragma region Hue 
						//Hue toma valores entre [0,360]
						if ((maior - menor) != 0)
						{
							if (maior == r && g >= b)
								hue = ((60.0f * (g - b) / (maior - menor)));

							else if (maior == r && b > g)
								hue = ((360.0f + 60.0f * (g - b) / (maior - menor)));

							else if (maior == g)
								hue = ((120.0f + 60.0f * (b - r) / (maior - menor)));

							else if (maior == b)
								hue = ((240.0f + 60.0f * (r - g) / (maior - menor)));

						}

						else
							hue = 0;

#pragma endregion     
					}
				}
				if ((hue >= 10 && hue <= 30) && (value >= 50 && value <= 255) && (saturation >= 50 && saturation <= 255))
				{
					pixeis++;

				}

				//if ((saturation >= 241 && value <= 149 && value >= 138) || ((hue >= 25 && hue <= 26) && (saturation >= 225 && saturation <= 234 && value >= 147 && value <= 158)))
				//if ((saturation >= 247 && value <= 143 && value >= 142) || ((hue >= 25 && hue <= 26) && (saturation >= 226 && saturation <= 233 && value >= 148 && value <= 157)))
					// else if (hue >= 20 && hue <= 35 && (saturation >= 240 || value < 55 ))
					//if ((saturation >= 200 && value <= 150 ) || src.data[pos_src] <= 3)
					//else if (hue >= 26 && hue <= 35 && (src.data[pos_src + 0] <= 1 && (src.data[pos_src + 1] <= 60 || src.data[pos_src + 2] <= 110)))
				else	
					(*pixeisOutros)++;

				//if ((saturationOrigin) >= saturation) Identifica com sucesso as falhas contudo o reflexo da luz no objecto faz com que identifique falhas onde nao existem
				if ( (corB+8) < (src.data[pos_src]) && (value) >= (valueOrigin));//eliminar a alguma luminosidade
				
				else if ((saturationOrigin) >= saturation)
				{
					
					(*pixeisVerde)++;
				}
			}
		}
	}	  

	return pixeis;
}

Mat vc_bgr_to_gray(Mat src)
{
	int i, size = src.rows * src.cols * 3, sizedst = src.rows * src.cols;
	Mat destino(src.rows, src.cols, CV_8U);
	int pontos = (int)((CONTORNO * src.cols) / 100);

	for (size_t i = 0; i < src.rows; i++)
	{
		for (size_t z = 0; z < pontos; z++)
		{
			destino.data[i* destino.step + 0 + pontos] = 255;
			destino.data[i* destino.step + src.cols - 1 - pontos] = 255;
		}
	}

	for (size_t i = 0; i < src.rows; i++)
	{
		for (size_t z = 0; z < pontos; z++)
		{
			destino.data[0 * destino.step + i + pontos] = 255;
			destino.data[0 * destino.step + src.rows - 1 - pontos] = 255;
		}
	}

	for (sizedst = 0, i = 0; i<size; i += 3) destino.data[sizedst++] = (src.data[i] + src.data[i + 1] + src.data[i + 2]) / 3;

	return destino;
}

Mat vc_gray_to_binary(Mat src, int lim)
{
	Mat destino = destino.zeros(src.rows, src.cols, CV_8UC1);
 	int i = 0, size = src.rows * src.cols;

	for (; i < size; i++)
	{
		if (src.data[i] > lim)
		{
			destino.data[i] = 255;
		}
	}

	return destino;
}

OVC* vc_binary_blob_labelling(Mat src, Mat &dst, int *nlabels, int* auxtable)
{
	int x, y, a, b;
	long int i, size;
	long int posX, posA, posB, posC, posD;
	int labeltable[256] = { 0 };
	int labelarea[256] = { 0 };
	int label = 1; // Etiqueta inicial.
	int num;
	float *area = (float*)calloc(254, sizeof(int));
	OVC *blobs; // Apontador para lista de blobs (objectos) que sera retornada desta funcaoo.


	// Copia dados da imagem binaria para imagem grayscale
	dst = src.clone();

	// Todos os pixeis de plano de fundo devem obrigatoriamente ter valor 0
	// Todos os pixeis de primeiro plano devem obrigatoriamente ter valor 255
	// Serao atribuidas etiquetas no intervalo [1,254]
	// Este algoritmo este assim limitado a 254 labels
	for (i = 0, size = src.cols * src.rows; i<size; i++)
	{
		if (dst.data[i] != 0) dst.data[i] = 255;
	}


	for (y = 0; y<src.rows; y++)
	{
		dst.data[y * src.cols + 0 * 1] = 0;
		dst.data[y * src.cols + (src.cols - 1) * 1] = 0;
	}
	for (x = 0; x<src.cols; x++)
	{
		dst.data[0 * src.cols + x * 1] = 0;
		dst.data[(src.rows - 1) * src.cols + x * 1] = 0;
	}

	// Efectua a etiquetagem
	for (y = 1; y<src.rows - 1; y++)
	{
		for (x = 1; x<src.cols - 1; x++)
		{
			// Kernel:
			// A B C
			// D X

			posA = (y - 1) * src.cols + (x - 1) * 1; // A
			posB = (y - 1) * src.cols + x * 1; // B
			posC = (y - 1) * src.cols + (x + 1) * 1; // C
			posD = y * src.cols + (x - 1) * 1; // D
			posX = y * src.cols + x * 1; // X

										 // Se o pixel foi marcado
			if (dst.data[posX] != 0)
			{
				if ((dst.data[posA] == 0) && (dst.data[posB] == 0) && (dst.data[posC] == 0) && (dst.data[posD] == 0))
				{
					dst.data[posX] = label;
					labeltable[label] = label;
					label++;
				}
				else
				{
					num = 255;

					if ((dst.data[posA] != 0) && (dst.data[posA] != 255) && (dst.data[posA] < num))
					{
						num = dst.data[posA];
					}
					if ((dst.data[posB] != 0) && (dst.data[posB] != 255) && (dst.data[posB] < num))
					{
						num = dst.data[posB];
					}
					if ((dst.data[posC] != 0) && (dst.data[posC] != 255) && (dst.data[posC] < num))
					{
						num = dst.data[posC];
					}
					if ((dst.data[posD] != 0) && (dst.data[posD] != 255) && (dst.data[posD] < num))
					{
						num = dst.data[posD];
					}

					// Actualiza a tabela de etiquetas
					if ((dst.data[posA] != 0) && (dst.data[posA] != 255))
					{
						if (labeltable[dst.data[posA]] != labeltable[num])
						{
							for (a = 1; a<label; a++)
							{
								if (labeltable[a] == labeltable[dst.data[posA]])
								{
									labeltable[a] = labeltable[num];
								}
							}
						}
					}
					if ((dst.data[posB] != 0) && (dst.data[posB] != 255))
					{
						if (labeltable[dst.data[posB]] != labeltable[num])
						{
							for (a = 1; a<label; a++)
							{
								if (labeltable[a] == labeltable[dst.data[posB]])
								{
									labeltable[a] = labeltable[num];
								}
							}
						}
					}
					if ((dst.data[posC] != 0) && (dst.data[posC] != 255))
					{
						if (labeltable[dst.data[posC]] != labeltable[num])
						{
							for (a = 1; a<label; a++)
							{
								if (labeltable[a] == labeltable[dst.data[posC]])
								{
									labeltable[a] = labeltable[num];
								}
							}
						}
					}
					if ((dst.data[posD] != 0) && (dst.data[posD] != 255))
					{
						if (labeltable[dst.data[posD]] != labeltable[num])
						{
							for (a = 1; a<label; a++)
							{
								if (labeltable[a] == labeltable[dst.data[posD]])
								{
									labeltable[a] = labeltable[num];
								}
							}
						}
					}
					labeltable[dst.data[posX]] = num;

					// Atribui a etiqueta ao pixel
					dst.data[posX] = num;
				}
			}
		}
	}



	// Volta a etiquetar a imagem
	// e contar area
	for (y = 1; y<src.rows - 1; y++)
	{
		for (x = 1; x<src.cols - 1; x++)
		{
			posX = y * src.cols + x * 1; // X

			if (dst.data[posX] != 0)
			{
				dst.data[posX] = labeltable[dst.data[posX]];
				area[(int)dst.data[posX]]++;
			}
		}
	}




	// Contagem do numero de blobs
	// Passo 1: Eliminar, da tabela, etiquetas repetidas
	for (a = 1; a<label - 1; a++)
	{
		for (b = a + 1; b<label; b++)
		{
			if (labeltable[a] == labeltable[b]) labeltable[b] = 0;
		}
	}
	// Passo 2: Conta etiquetas e organiza a tabela de etiquetas, para que nao hajam valores vazios (zero) entre etiquetas
	*nlabels = 0;
	for (a = 1; a<label; a++)
	{
		if (labeltable[a] != 0)
		{
			labeltable[*nlabels] = labeltable[a]; // Organiza tabela de etiquetas
			(*nlabels)++; // Conta etiquetas
		}
	}



	// Se nao ha blobs
	if (*nlabels == 0) return NULL;

	int aa = 0;
	// Cria lista de blobs (objectos) e preenche a etiqueta
	blobs = (OVC *)calloc((*nlabels), sizeof(OVC));
	if (blobs != NULL)
	{
		for (a = 0; a < (*nlabels); a++)
		{
			blobs[a].label = labeltable[a];
			auxtable[aa++] = labeltable[a];
			blobs[a].area = area[labeltable[a]];
		}	

	}
	else return NULL;



	return blobs;
}

int vc_binary_blob_info(Mat src, Mat ref, OVC *blobs, int nblobs, int* auxtable)
{
	long int pos, posRef, sumx, sumy;
	int xmin, ymin, xmax, ymax, x, y, ii;
	int valor = 0;
	xmin = src.cols - 1;
	ymin = src.rows - 1;
	xmax = 0;
	ymax = 0;
	for (size_t i = 0; i < nblobs; i++)
	{
		if (blobs[i].area >((src.rows* src.cols) / 20))
		{
			blobs[i].x = xmin;
			blobs[i].y = ymin;
			blobs[i].width = xmax;
			blobs[i].height = ymax;
		}
	}


	for (y = 1; y < src.rows - 1; y++)
	{
		for (x = 1; x < src.cols - 1; x++)
		{
			pos = y * src.cols + x * 1;
			posRef = y * ref.step + x * 3;

			if (src.data[pos] != 0)
			{
				for (ii = 0; ii < nblobs; ii++)
				{
					if (src.data[pos] == auxtable[ii])
					{
						valor = ii;
						break;
					}
				}
										
				//cor media
				blobs[valor].corR += ref.data[posRef + 2];
				blobs[valor].corG += ref.data[posRef + 1];
				blobs[valor].corB += ref.data[posRef];

				// Centro de Gravidade
				blobs[valor].xc += x;
				blobs[valor].yc += y;

				// Bounding Box
				if (blobs[valor].x > x) blobs[valor].x = x;
				if (blobs[valor].y > y) blobs[valor].y = y;
				if ((blobs[valor].width + blobs[valor].x) < x) blobs[valor].width = (x - blobs[valor].x) + 1;
				if ((blobs[valor].height + blobs[valor].y) < y) blobs[valor].height = (y - blobs[valor].y) + 1;

				// Perímetro
				// Se pelo menos um dos quatro vizinhos não pertence ao mesmo label, então é um pixel de contorno
				if ((src.data[pos - 1] != blobs[valor].label) || (src.data[pos + 1] != blobs[valor].label) || ((src.data[pos - src.cols] != blobs[valor].label) || (src.data[pos + src.cols] != blobs[valor].label)))
				{
					blobs[valor].perimeter++;
				}
			}
		}
	}

	for (size_t i = 0; i < nblobs; i++)
	{
		if (blobs[i].area > ((src.rows* src.cols) / 20))
		{
			// Centro de Gravidade
			blobs[i].xc /= MAX(blobs[i].area, 1);
			blobs[i].yc /= MAX(blobs[i].area, 1);


			blobs[i].corR /= blobs[i].area;
			blobs[i].corG /= blobs[i].area;
			blobs[i].corB /= blobs[i].area;
		}	 		
	}
	



	return 1;
}
   
void DefinePt()
{
	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	fflush(stdin);//limpar a memória temporária	
}

void Apresentacao(TCHAR* username)
{
	DefinePt();
	DWORD username_len = 20 + 1;
	GetUserName(username, &username_len);
}

Mat vc_redimention_size(Mat contornos, OVC* objecto, int numero)
{
	Mat dst = dst.zeros(contornos.rows, contornos.cols, CV_8UC1);

	for (size_t i = 0; i < numero; i++)
	{
		if (!(objecto[i].area >((contornos.rows* contornos.cols) / 20)))
			continue;

		Mat src = vc_binary_erode(contornos, objecto[i], 9);
		int y;
		int width = objecto[i].x + objecto[i].width + 1, height = objecto[i].y + objecto[i].height + 1;
		int channels = 1;
		int bytesperline = src.step;
		long int pos;
		int pontosSeguidos = 0;
		int contU = 0;//imaginando que este é a cor preta
		int contD = 0;//imaginando que este é a cor branca
		Lista lista = (Lista)calloc(1, sizeof(struct nodo));
		int pontos = (int)((PERCENTAGEM * objecto[i].width) / 100);
		int contAA = 0;
		int cont = 0;
		for (size_t y = objecto[i].y - 1; y < height + 1; y++)
		{

			for (size_t x = objecto[i].x - 1; x < width + 1; x++)
			{
				pos = y* bytesperline + x *channels;

				if (src.data[pos] == 0)
				{
					contU = 1;

					if (contU == contD)
					{
						contU = 0;
						contD = 0;

						if ((x - pontos) <= (x - pontosSeguidos + pontos) || pontosSeguidos <= (pontos*4))
						{
							pontosSeguidos = 0;
							continue;
						}
						contAA++;
						lista->pixeis = y;
						lista->yMax = x - pontos;
						lista->yMin = x - pontosSeguidos + pontos;
						lista = Inserir(lista, 0, 0, 0);
						pontosSeguidos = 0;

						for (; x < width; x++)
						{
							pos = y* bytesperline + x *channels;

							if (src.data[pos] == 0)
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

		if (lista->seguinte != NULL)
		{
			lista = lista->seguinte;

			for (y = height; y >= 0; y--)
			{
				if (lista->pixeis == y)
				{
					cont++;

					for (size_t x = lista->yMin; x <= lista->yMax; x++)
					{
						pos = y* bytesperline + x *channels;
						dst.data[pos] = 255;
					}

					if (lista->seguinte == NULL)
						break;

					lista = lista->seguinte;
				}
				if (lista->pixeis == y)
					y++;
			}
		}
		//printf("y = %d\nx = %d", cont, contAA);
		free(lista);


	}

	return dst;
}



#pragma endregion

#pragma region Não utilizados


int vc_bgr_to_hsv(Mat src, int xMin, int yMin, int xMax, int yMax)
{
	int pixeis = 0;
	float r, g, b, hue, saturation, value, maior, menor;
	long int pos_src, pos_destino;


	for (int y = yMin; y <= yMax; y++)
	{
		for (int x = xMin; x <= xMax; x++)
		{
			pos_src = y* src.step + x * 3;

			r = (float)src.data[pos_src + 2];
			g = (float)src.data[pos_src + 1];
			b = (float)src.data[pos_src];

			maior = MAX3(r, g, b);
			menor = MIN3(r, g, b);

			value = maior;

			if (value == 0.0)
			{
				hue = 0.0;
				saturation = 0.0;
			}

			else
			{
				saturation = (unsigned char)(((maior - menor) / (maior))*255.0f);

				if (saturation == 0.0)
					hue = 0.0;

				else
				{
#pragma region Hue 
					//Hue toma valores entre [0,360]
					if ((maior - menor) != 0)
					{
						if (maior == r && g >= b)
							hue = ((60.0f * (g - b) / (maior - menor)));

						else if (maior == r && b > g)
							hue = ((360.0f + 60.0f * (g - b) / (maior - menor)));

						else if (maior == g)
							hue = ((120.0f + 60.0f * (b - r) / (maior - menor)));

						else if (maior == b)
							hue = ((240.0f + 60.0f * (r - g) / (maior - menor)));

					}

					else
						hue = 0;

#pragma endregion     
				}
			}

			if ((hue >= 10 && hue <= 30) && (value >= 50 && value <= 255) && (saturation >= 50 && saturation <= 255))
			{
				pixeis++;

			}
		}
	}


	return pixeis;
}



int menor(int a, int b, int c, int d)
{
	int menor = 1;

	if (a == 0)
		return MIN3(b, c, d);

	else if (b == 0)
		return MIN3(a, c, d);

	else if (c == 0)
		return MIN3(b, a, d);

	else if (d == 0)
		return MIN3(b, c, a);

	else
	{
		if (a < b && a < c && a < d)
			return a;

		if (b < a && b < c && b < d)
			return b;

		if (c < b && c < a && c < d)
			return c;

		if (d < b && d < c && d < a)
			return d;
	}

}

Mat vc_binary_blob_labelling2(Mat src)
{
	Mat dst = src.clone();
	unsigned char *datasrc = (unsigned char *)src.data;
	unsigned char *datadst = (unsigned char *)dst.data;
	int width = src.cols;
	int height = src.rows;
	int bytesperline = src.step;
	int channels = 1;
	int a, b, c, d;
	long int pos, posk;
	int y, x;
	unsigned char tabela[256] = { 0 };
	int label = 1;



#pragma region Contornos
	for (x = 0; x < width; x++)
	{
		pos = 0 * bytesperline + x * channels;
		src.data[pos] = 0;
		pos = (height - 1) * bytesperline + x * channels;
		src.data[pos] = 0;
	}

	for (y = 0; y < height; y++)
	{
		pos = y * bytesperline + 0 * channels;
		src.data[pos] = 0;
		pos = y * bytesperline + (width - 1) * channels;
		src.data[pos] = 0;
	}
#pragma endregion

#pragma region Origem

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pos = y * bytesperline + x * channels - (x * channels) - (y*bytesperline);
			a = (int)src.data[pos];

			pos = y * bytesperline + x * channels - (y*bytesperline);
			b = src.data[pos];

			pos = y * bytesperline + x * channels + (x * channels) - (y*bytesperline);
			c = src.data[pos];

			pos = y * bytesperline + x * channels - (x * channels);
			d = src.data[pos];


			pos = y * bytesperline + x * channels;
			if (src.data[pos] == (unsigned char)255)
			{
				if (a == 0 && b == 0 && c == 0 && d == 0)
				{
					dst.data[pos] = label;
					label++;
				}

				else
				{
					dst.data[pos] = (unsigned char)menor(a, b, c, d);
				}
			}
		}
	}

#pragma endregion


	//vc_write_image("Novas_Imagens\\vc-0007.pbm", dst);
	//system("Novas_Imagens\\vc-0007.pbm");

#pragma region Tabela

	for (y = 0; y < 254; y++)
	{
		tabela[y] = y;
	}

#pragma endregion

	label = 1;

#pragma region Alterar_a_tabela

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pos = y * bytesperline + x * channels - (x * channels) - (y*bytesperline);
			a = (int)dst.data[pos];

			pos = y * bytesperline + x * channels - (y*bytesperline);
			b = (int)dst.data[pos];

			pos = y * bytesperline + x * channels + (x * channels) - (y*bytesperline);
			c = (int)dst.data[pos];

			pos = y * bytesperline + x * channels - (x * channels);
			d = (int)dst.data[pos];


			pos = y * bytesperline + x * channels;
			if ((int)src.data[pos] == 255)
			{
				if (a != dst.data[pos] && a != 0)
				{
					tabela[label] = MIN(a, (int)dst.data[pos]);
				}

				if (b != dst.data[pos] && b != 0)
				{
					tabela[label] = MIN(b, (int)dst.data[pos]);
				}

				if (c != dst.data[pos] && c != 0)
				{
					tabela[label] = MIN(c, (int)dst.data[pos]);
				}

				if (d != dst.data[pos] && d != 0)
				{
					tabela[label] = MIN(d, (int)dst.data[pos]);
				}

				if (a == 0 && b == 0 && c == 0 && d == 0)
					label++;
			}
		}
	}


#pragma endregion

#pragma region Destino

	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			pos = y * bytesperline + x * channels;

			for (size_t i = 1; i < 255; i++)
			{
				if ((int)dst.data[pos] == i)
					dst.data[pos] = tabela[i];
			}

		}
	}


#pragma endregion


	return dst;
}

Mat vc_diferencas(Mat origem, Mat frame)
{
	Mat diferenca;
	absdiff(origem, frame, diferenca);

	Mat foregroundMask = Mat::zeros(diferenca.rows, diferenca.cols, CV_8UC1);

	float threshold = 30.0f;
	float dist;

	for (int j = 0; j < diferenca.rows; ++j) {
		for (int i = 0; i < diferenca.cols; ++i)
		{
			cv::Vec3b pix = diferenca.at<cv::Vec3b>(j, i);

			dist = (pix[0] * pix[0] + pix[1] * pix[1] + pix[2] * pix[2]);
			dist = sqrt(dist);

			if (dist > threshold)
			{
				foregroundMask.at<unsigned char>(j, i) = 255;
			}
		}
	}

	return diferenca;
}

Mat vc_gray_lowpass_gaussian_filter(Mat src)
{
	Mat dst;
	dst = src.clone();
	int i, j;
	long int pos, posX;
	float gaussarray[5] = { (float) 0.061, (float) 0.242, (float) 0.383, (float) 0.242, (float) 0.061 };
	float gausssum;



	for (int y = 5; y< src.rows; y++)
	{
		for (int x = 5; x< src.cols; x++)
		{
			gausssum = 0.0;

			for (j = 0; j<5; j++)
			{
				for (i = 0; i<5; i++)
				{
					pos = (y - j) * src.step + (x - i) * 1;

					gausssum += ((float)src.data[pos]) * gaussarray[i] * gaussarray[j];
				}
			}

			posX = y * src.step + x * 1;

			dst.data[posX] = (unsigned char)gausssum;
		}
	}

	return dst;
}

Mat vc_fill_stuff(Mat src)
{
	Mat dst;
	dst = src.clone();

	for (size_t i = 0; i < 3; i++)
	{
		long int pos;
		int pontosSeguidos = 0;
		Lista lista = (Lista)calloc(1, sizeof(struct nodo));
		int contU = 0;//imaginando que este é a cor preta
		int contD = 0;//imaginando que este é a cor branca
		int y;

		for (size_t y = 0; y < src.rows; y++)
		{
			for (size_t x = 0; x < src.cols; x++)
			{
				pos = y* src.step + x * 1;

				//exemplo quero preencher contornos pretos
				if (src.data[pos] != 0)
				{
					contU = 1;

					if (contU == contD)
					{
						if (pontosSeguidos > 100)
						{
							contU = 0;
							contD = 0;
							pontosSeguidos = 0;
						}

						else
						{
							contU = 0;
							contD = 0;
							lista->pixeis = y;
							lista->yMax = x;
							lista->yMin = x - pontosSeguidos;
							lista = Inserir(lista, 0, 0, 0);
							pontosSeguidos = 0;
							for (; x < src.cols; x++)
							{
								pos = y* src.step + x * 1;

								//exemplo quero preencher contornos pretos
								if (src.data[pos] != 0)
									break;
							}
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





		for (y = 0; y < src.rows; y++)
		{
			for (size_t x = 0; x < src.cols; x++)
			{
				pos = y* src.step + x * 1;
				dst.data[pos] = src.data[pos];
			}
		}

		lista = lista->seguinte;

		for (y = src.rows; y >= 0; y--)
		{
			if (lista == NULL)
				break;

			if (lista->yMax != lista->yMin && lista->pixeis == y)
			{
				for (size_t x = lista->yMin; x <= lista->yMax; x++)
				{
					pos = y* src.step + x * 1;
					dst.data[pos] = 255;
				}

				if (lista->seguinte == NULL)
					break;

				lista = lista->seguinte;
			}
			if (lista->pixeis == y)
				y++;
		}

	}

	return dst;
}

Mat vc_binary_erode(Mat src, OVC objeto, int kernel)
{
	Mat dst = src.clone();

	int width = objeto.x + objeto.width;
	int height = objeto.y + objeto.height;
	int bytesperline = src.step;
	int channels = 1;
	int x, y;
	int xx, yy;
	int xxyymax = (kernel - 1) / 2;
	int xxyymin = -xxyymax;
	int max, min;
	long int pos, posk;

	int cont = 0;



	for (y = objeto.y; y<height; y++)
	{
		for (x = objeto.x; x<width; x++)
		{
			cont = 0;
			pos = y * bytesperline + x * channels;

			max = src.data[pos];
			min = src.data[pos];

			// NxM Vizinhos
			for (yy = xxyymin; yy <= xxyymax; yy++)
			{
				for (xx = xxyymin; xx <= xxyymax; xx++)
				{
					if ((y + yy >= 0) && (y + yy < height) && (x + xx >= 0) && (x + xx < width))
					{
						posk = (y + yy) * bytesperline + (x + xx) * channels;

						if (src.data[posk] != 0) cont++;
					}
				}
			}

			if (cont == kernel*kernel)
				dst.data[pos] = 255;

			else
				dst.data[pos] = 0;

		}
	}

	return dst;
}

Mat vc_binary_erode2(Mat src, int kernel)
{
	Mat dst = src.clone();

	int width = src.cols;
	int height = src.rows;
	int bytesperline = src.step;
	int channels = 1;
	int x, y;
	int xx, yy;
	int xxyymax = (kernel - 1) / 2;
	int xxyymin = -xxyymax;
	int max, min;
	long int pos, posk;

	int cont = 0;



	for (y = 0; y<height; y++)
	{
		for (x = 0; x<width; x++)
		{
			cont = 0;
			pos = y * bytesperline + x * channels;

			max = src.data[pos];
			min = src.data[pos];

			// NxM Vizinhos
			for (yy = xxyymin; yy <= xxyymax; yy++)
			{
				for (xx = xxyymin; xx <= xxyymax; xx++)
				{
					if ((y + yy >= 0) && (y + yy < height) && (x + xx >= 0) && (x + xx < width))
					{
						posk = (y + yy) * bytesperline + (x + xx) * channels;

						if (src.data[posk] != 0) cont++;
					}
				}
			}

			if (cont == kernel*kernel)
				dst.data[pos] = 255;

			else
				dst.data[pos] = 0;

		}
	}

	return dst;
}

int vc_detect_stuff(Mat src, OVC objecto)
{
	long int pos_destino;
	int pixeis = 0;

	for (int y = objecto.y; y< (objecto.y + objecto.height); y++)
	{
		for (int x = objecto.x; x< (objecto.x + objecto.width); x++)
		{
			pos_destino = y* src.step + x;

			if (src.data[pos_destino] < 55 && src.data[pos_destino] > 10) {
				src.data[pos_destino] = 0;
				pixeis++;
			}

			else
				src.data[pos_destino] = 255;
		}
	}
	return pixeis;
}

Mat vc_gray_negative(Mat src)
{
	Mat destino;

	destino = src.clone();

	long int pos_destino;


	for (int y = 0; y< src.rows; y++)
	{
		for (int x = 0; x< src.cols; x++)
		{
			pos_destino = y* destino.step + x;

			destino.data[pos_destino] = 255 - src.data[pos_destino];
		}
	}
	return destino;
}

int vc_binary_blob_info2(Mat src, Mat ref, OVC *blobs, int nblobs)
{
	long int pos, posRef, sumx, sumy;
	int xmin, ymin, xmax, ymax, x, y, i;


	// Conta área de cada blob
	for (i = 0; i<nblobs; i++)
	{
		if (blobs[i].area < ((src.rows* src.cols) / 20));
		else
		{
			xmin = src.cols - 1;
			ymin = src.rows - 1;
			xmax = 0;
			ymax = 0;

			sumx = 0;
			sumy = 0;


			blobs[i].corR = 0, blobs[i].corG = 0, blobs[i].corB = 0, blobs[i].area = 0;
			for (y = 1; y<src.rows - 1; y++)
			{
				for (x = 1; x<src.cols - 1; x++)
				{
					pos = y * src.cols + x * 1;
					posRef = y * ref.step + x * 3;

					if (src.data[pos] == blobs[i].label)
					{
						// Área
						blobs[i].area++;

						//cor media
						blobs[i].corR += ref.data[posRef + 2];
						blobs[i].corG += ref.data[posRef + 1];
						blobs[i].corB += ref.data[posRef];

						// Centro de Gravidade
						sumx += x;
						sumy += y;

						// Bounding Box
						if (xmin > x) xmin = x;
						if (ymin > y) ymin = y;
						if (xmax < x) xmax = x;
						if (ymax < y) ymax = y;

						// Perímetro
						// Se pelo menos um dos quatro vizinhos não pertence ao mesmo label, então é um pixel de contorno
						if ((src.data[pos - 1] != blobs[i].label) || (src.data[pos + 1] != blobs[i].label) || ((src.data[pos - src.cols] != blobs[i].label) || (src.data[pos + src.cols] != blobs[i].label)))
						{
							blobs[i].perimeter++;
						}
					}
				}
			}

			// Bounding Box
			blobs[i].x = xmin;
			blobs[i].y = ymin;
			blobs[i].width = (xmax - xmin) + 1;
			blobs[i].height = (ymax - ymin) + 1;

			// Centro de Gravidade
			//blobs[i].xc = (xmax - xmin) / 2;
			//blobs[i].yc = (ymax - ymin) / 2;
			blobs[i].xc = sumx / MAX(blobs[i].area, 1);
			blobs[i].yc = sumy / MAX(blobs[i].area, 1);


			blobs[i].corR /= blobs[i].area;
			blobs[i].corG /= blobs[i].area;
			blobs[i].corB /= blobs[i].area;

		}

	}

	return 1;
}

#pragma endregion

#pragma region Pinta coisas
/*
void PintPonto(Mat &imagem, unsigned int x, unsigned int y, int core)
{
	unsigned int colunas = (x), linhas = (y);
	unsigned int pos;
	pos = (linhas * imagem.step + colunas * 3);

	if (((3 * imagem.cols * imagem.rows) + 3 < pos) || pos < 0 || imagem.cols <= x || imagem.rows <= y);

	else {
		imagem.data[pos] = core;
		imagem.data[pos + 1] = core;
		imagem.data[pos + 2] = core;
	}
}

void PintLinha(Mat &imagem, unsigned int xU, unsigned int yU, unsigned int xD, unsigned int yD, int core = 255)
{

	int dx = abs(xD - xU);//diferença entre x
	int sx = xU < xD ? 1 : -1;
	int dy = abs(yD - yU);//diferença entre y
	int sy = yU < yD ? 1 : -1;
	int err = (dx>dy ? dx : -dy) / 2;
	int e2;

	for (;;) {

		PintPonto(imagem, xU, yU, core);

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

void PintaCirculo(Mat &imagem, int cordUx, int cordUy, unsigned int radius, int core)
{
	int f = 1 - radius;
	int ddF_x = 0;
	int ddF_y = -2 * radius;
	int x = 0;
	int y = radius;

	PintPonto(imagem, cordUx, cordUy + radius, core);
	PintPonto(imagem, cordUx, cordUy - radius, core);
	PintPonto(imagem, cordUx + radius, cordUy, core);
	PintPonto(imagem, cordUx - radius, cordUy, core);

	while (x < y)
	{
		if (f >= 0)
		{
			y--;
			ddF_y += 2;
			f += ddF_y;
		}
		x++;
		ddF_x += 2;
		f += ddF_x + 1;
		PintPonto(imagem, cordUx + x, cordUy + y, core);
		PintPonto(imagem, cordUx - x, cordUy + y, core);
		PintPonto(imagem, cordUx + x, cordUy - y, core);
		PintPonto(imagem, cordUx - x, cordUy - y, core);
		PintPonto(imagem, cordUx + y, cordUy + x, core);
		PintPonto(imagem, cordUx - y, cordUy + x, core);
		PintPonto(imagem, cordUx + y, cordUy - x, core);
		PintPonto(imagem, cordUx - y, cordUy - x, core);
	}
}
  */

#pragma endregion 