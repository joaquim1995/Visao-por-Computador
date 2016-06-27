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


			 

int main(void)
{


#pragma region Vars
	IplImage *frameS;
	Mat frame, final, background = imread("fundo.ppm");
	Mat  gray, fruta, preencido, contorno, nova, bin, inverse;
	int i = 0, inicio, fim, inicioTotal, fimTotal, totLaranjas = 0, totOutros = 0, nblobs, label, pontos= (int)((CONTORNO * contorno.cols) / 100), pontosEspeciais, auxIni = 0, auxFim = 0, passa = 0;
	OVC *blobs;
	OVC objeto;
	bool debugMode = false;
	bool trackingEnabled = false;
	//pause and resume code
	bool pause = false;
	VideoCapture capture;
	int contU = 0, contD = 0, conU = 0, conD = 0,ii = 0;
	int pixeisVerdes = 0, pixeisOutros = 0;
	pontosEspeciais = (int)((CONTORNO * contorno.rows) / 100);
	pontosEspeciais = pontosEspeciais*(pontosEspeciais / 2) - 2;

	// Vídeo
	char *videofile = "video-tp2.avi";
	CvCapture *captureS;
	struct
	{
		int width, height;
		int ntotalframes;
		int fps;
		int nframe;
	} video;
	// Texto
	CvFont font, fontbkg;
	double hScale = 0.5;
	double vScale = 0.5;
	int lineWidth = 1;
	char str[500] = { 0 };
	// Outros
	int key = 0;

#pragma endregion

	while (1) {

		capture.open(videofile);
		if (!capture.isOpened()) {
			cout << "ERROR ACQUIRING VIDEO FEED\n";
			getchar();
			return -1;
		}

		contD = 0, conU = 0, conD = 0, contU = 0;

#pragma region Start

		/* Leitura de vídeo de um ficheiro */
		captureS = cvCaptureFromFile(videofile);

		/* Verifica se foi possível abrir o ficheiro de vídeo */
		if (!captureS)
		{
			fprintf(stderr, "Erro ao abrir o ficheiro de vídeo!\n");
			return 1;
		}

		/* Número total de frames no vídeo */
		video.ntotalframes = (int)cvGetCaptureProperty(captureS, CV_CAP_PROP_FRAME_COUNT);
		/* Frame rate do vídeo */
		video.fps = (int)cvGetCaptureProperty(captureS, CV_CAP_PROP_FPS);
		/* Resolução do vídeo */
		video.width = (int)cvGetCaptureProperty(captureS, CV_CAP_PROP_FRAME_WIDTH);
		video.height = (int)cvGetCaptureProperty(captureS, CV_CAP_PROP_FRAME_HEIGHT);

		/* Cria uma janela para exibir o vídeo */
		cvNamedWindow("Origem", CV_WINDOW_NORMAL);

		/* Inicializa a fonte */
		cvInitFont(&font, CV_FONT_HERSHEY_SIMPLEX, hScale, vScale, 0, lineWidth);
		cvInitFont(&fontbkg, CV_FONT_HERSHEY_SIMPLEX, hScale, vScale, 0, lineWidth + 1);
		inicio = GetTickCount();

#pragma endregion

		while (capture.get(CV_CAP_PROP_POS_FRAMES) < capture.get(CV_CAP_PROP_FRAME_COUNT) - 1)
		{

			if (passa < PASSAIMAGEM)
			{/* Leitura de uma frame do vídeo */
				capture.read(frame);
				frameS = cvQueryFrame(captureS);

				passa++;
			}
			else
			{
				passa = 0;
#pragma region Get Frame

				/* Leitura de uma frame do vídeo */
				capture.read(frame);
				frameS = cvQueryFrame(captureS);
				/* Número da frame a processar */
				video.nframe = video.nframe = (int)cvGetCaptureProperty(captureS, CV_CAP_PROP_POS_FRAMES);

				fim = GetTickCount();

#pragma endregion	


#pragma region Escreve as coisas bonitas   


				/* Exemplo de inserção texto na frame */
				sprintf(str, "RESOLUCAO: %dx%d", video.width, video.height);
				cvPutText(frameS, str, cvPoint(20, 20), &fontbkg, cvScalar(0, 0, 0));
				cvPutText(frameS, str, cvPoint(20, 20), &font, cvScalar(110, 110, 110));
				sprintf(str, "TOTAL DE FRAMES: %d", video.ntotalframes);
				cvPutText(frameS, str, cvPoint(20, 40), &fontbkg, cvScalar(0, 0, 0));
				cvPutText(frameS, str, cvPoint(20, 40), &font, cvScalar(110, 110, 110));
				sprintf(str, "FRAME RATE: %d", video.fps);
				cvPutText(frameS, str, cvPoint(20, 60), &fontbkg, cvScalar(0, 0, 0));
				cvPutText(frameS, str, cvPoint(20, 60), &font, cvScalar(110, 110, 110));
				sprintf(str, "N. FRAME: %d", video.nframe);
				cvPutText(frameS, str, cvPoint(20, 80), &fontbkg, cvScalar(0, 0, 0));
				cvPutText(frameS, str, cvPoint(20, 80), &font, cvScalar(110, 110, 110));
				sprintf(str, "TEMPO: %d s", (fim - inicio) / 1000);
				cvPutText(frameS, str, cvPoint(20, 100), &fontbkg, cvScalar(0, 0, 0));
				cvPutText(frameS, str, cvPoint(20, 100), &font, cvScalar(110, 110, 110));
				sprintf(str, "Laranjas: %d", totLaranjas);
				cvPutText(frameS, str, cvPoint(20, 120), &fontbkg, cvScalar(0, 0, 0));
				cvPutText(frameS, str, cvPoint(20, 120), &font, cvScalar(110, 110, 110));
				sprintf(str, "Outros: %d", totOutros);
				cvPutText(frameS, str, cvPoint(20, 140), &fontbkg, cvScalar(0, 0, 0));
				cvPutText(frameS, str, cvPoint(20, 140), &font, cvScalar(110, 110, 110));


#pragma endregion	


#pragma region	Operações

				if (debugMode == true) {

					inicioTotal = GetTickCount();
					auxIni = GetTickCount();
					//remove o fundo
					fruta = remove_fundo(frame);
					auxFim = GetTickCount();
					sprintf(str, "Remover Fundo: %d ms", (auxFim - auxIni));
					cvPutText(frameS, str, cvPoint(20, 160), &fontbkg, cvScalar(0, 0, 0));
					cvPutText(frameS, str, cvPoint(20, 160), &font, cvScalar(110, 110, 110));

					//vai para cinza
					auxIni = GetTickCount();
					gray = vc_bgr_to_gray(fruta);
					auxFim = GetTickCount();
					sprintf(str, "Bgr to gray: %d ms", (auxFim - auxIni));
					cvPutText(frameS, str, cvPoint(20, 180), &fontbkg, cvScalar(0, 0, 0));
					cvPutText(frameS, str, cvPoint(20, 180), &font, cvScalar(110, 110, 110));

					//// Muda a cor do fundo
					auxIni = GetTickCount();
					floodFill(gray, Point(20, 20), Scalar(0));
					auxFim = GetTickCount();
					sprintf(str, "FloodFill: %d ms", (auxFim - auxIni));
					cvPutText(frameS, str, cvPoint(20, 200), &fontbkg, cvScalar(0, 0, 0));
					cvPutText(frameS, str, cvPoint(20, 200), &font, cvScalar(110, 110, 110));

					//binariza
					auxIni = GetTickCount();
					bin = vc_gray_to_binary(gray, 0);
					auxFim = GetTickCount();
					sprintf(str, "Binarizacao: %d ms", (auxFim - auxIni));
					cvPutText(frameS, str, cvPoint(20, 220), &fontbkg, cvScalar(0, 0, 0));
					cvPutText(frameS, str, cvPoint(20, 220), &font, cvScalar(110, 110, 110));

					OVC* objetos = (OVC*)calloc(1, sizeof(OVC));
					int* auxtable = (int*)calloc(256, sizeof(int));
					label = 0;

					////encontra contornos
					auxIni = GetTickCount();
					objetos = vc_binary_blob_labelling(bin, contorno, &label, auxtable);
					auxFim = GetTickCount();
					sprintf(str, "Labelling: %d ms", (auxFim - auxIni));
					cvPutText(frameS, str, cvPoint(20, 240), &fontbkg, cvScalar(0, 0, 0));
					cvPutText(frameS, str, cvPoint(20, 240), &font, cvScalar(110, 110, 110));

					auxIni = GetTickCount();
					vc_binary_blob_info(contorno, frame, objetos, label, auxtable);
					auxFim = GetTickCount();
					fimTotal = GetTickCount();
					sprintf(str, "Blobs Info: %d ms", (auxFim - auxIni));
					cvPutText(frameS, str, cvPoint(20, 260), &fontbkg, cvScalar(0, 0, 0));
					cvPutText(frameS, str, cvPoint(20, 260), &font, cvScalar(110, 110, 110));
														
					sprintf(str, "Tempo demorado: %d ms", (fimTotal - inicioTotal));
					cvPutText(frameS, str, cvPoint(20, 280), &fontbkg, cvScalar(0, 0, 0));
					cvPutText(frameS, str, cvPoint(20, 280), &font, cvScalar(110, 110, 110));

					namedWindow("Remove Fundo", WINDOW_NORMAL);
					imshow("Remove Fundo", fruta);
					namedWindow("Gray", WINDOW_NORMAL);
					imshow("Gray", gray);
					namedWindow("Bin", WINDOW_NORMAL);
					imshow("Bin", bin);
					namedWindow("Contorno", WINDOW_NORMAL);
					imshow("Contorno", contorno);
				}

				else				
				{
					destroyWindow("Gray"); 
					destroyWindow("Bin");
					destroyWindow("Contorno");
				}


				if (trackingEnabled)
				{
					//remove o fundo
					fruta = remove_fundo(frame);

					//vai para cinza
					gray = vc_bgr_to_gray(fruta);

					//// Muda a cor do fundo					 
					floodFill(gray, cv::Point(20, 20), Scalar(0));

					//binariza
					bin = vc_gray_to_binary(gray, 0);
													   
					OVC* objetos = (OVC*)calloc(1, sizeof(OVC));
					int* auxtable = (int*)calloc(256,sizeof(int));
					////encontra contornos
					label = 0;
					objetos = vc_binary_blob_labelling(bin, contorno, &label, auxtable);
					vc_binary_blob_info(contorno, frame, objetos, label, auxtable);


					nova = vc_redimention_size(contorno, objetos, label);	
					
					contU = 0;
					conU = 0;
					/*
					#pragma region ORDENAÇAO

										for (size_t i = 0; i < label; i++)
										{
											pixeisVerdes = 0;
											if (objetos[i].area > ((video.width * video.height) / 100))
											{
												if ((pontos + 1 == objetos[i].y) || (contorno.rows - 1 - pontos + 1) == (objetos[i].y + objetos[i].height))
												{
													objeto = objetos[i];
													objetos[i] = objetos[0];
													objetos[0] = objeto;
												}
												else
												{
													objetos[i].pixeisLaranja = vc_bgr_to_hsv(frame, objetos[i].x, objetos[i].y, (objetos[i].x + objetos[i].width), (objetos[i].y + objetos[i].height), &pixeisVerdes);

													if (objetos[i].pixeisLaranja >= (objetos[i].area) / 1.5)
													{
														contU++;
													}

													else
													{
														conU++;
													}
												}
											}
										}
					#pragma endregion
					  */

					ii = 0;
					for (int i = 0; i < label; i++)
					{
						if (objetos[i].area > ((video.width * video.height) / 20))
						{

							//se estiver a entrar ou a sair algo
							if (pontos + 1 >= objetos[i].y || (contorno.rows - 1 - pontos + 1) <= (objetos[i].y + objetos[i].height))
							{
								/*
								if (ii == 0)
								{
									//frame = vc_find_contourn(contorno);  // nao pode ser descomentado devido á comentação da ordenação
									ii++;
								}
								*/

								//desenha o centro do circulo
								circle(frame, Point(objetos[i].xc, objetos[i].yc), 3.14, Scalar(0, 0, 254), -1);

							}

							else
							{
								if ((pontosEspeciais + 1 >= objetos[i].y || (contorno.rows - 1 - pontosEspeciais + 1) <= (objetos[i].y + objetos[i].height)));

								else
								{
									objetos[i].pixeisLaranja = vc_bgr_to_hsv2(frame, nova, objetos[i].x, objetos[i].y, (objetos[i].x + objetos[i].width), (objetos[i].y + objetos[i].height), &pixeisVerdes, &pixeisOutros, objetos[i].corB, objetos[i].corG, objetos[i].corR);

									//é laranja	
									if (objetos[i].pixeisLaranja*2.5 >= ((pixeisOutros)+(pixeisVerdes)))
									{

										//esta correcta a atribuiçao nao está enganada a atribuiçao de variaveis
										//colocar  informaçao da categoria etc
										objetos[i].pixeisOutros = pixeisVerdes;
										objetos[i].pixeisPretos = pixeisOutros;
										vc_categorize2(frame, objetos[i]);

										contU++;
									}
									//não é laranja
									else
									{
										conU++;
									}
								}																	


								//desenha o centro do circulo
								circle(frame, Point(objetos[i].xc, objetos[i].yc), 3.14, Scalar(0, 254, 0), -1);
								//desenha o circulo
								circle(frame, Point(objetos[i].xc, objetos[i].yc), objetos[i].width / 2, Scalar(0, 254, 0), 3, 8, 0);

								//colocar  informaçao da categoria etc
								vc_categorize(frame, objetos[i]);
							}

						}
					}


					namedWindow("Track", WINDOW_NORMAL);
					imshow("Track", frame);
					free(objetos);
					free(auxtable);


				}

				else
				{
					destroyWindow("Track");
				}







#pragma endregion


#pragma region Conta
				if (contU != contD && contU != 0 && contU != 2)
				{
					totLaranjas++;
					contD = contU;
				}
				else
					contD = contU;

				if (conU != conD && conU != 0 && conU != 2)
				{
					totOutros++;
					conD = conU;
				}
				else
					conD = conU;
#pragma endregion

				cvShowImage("Origem", frameS);

#pragma region Opcoes de caracteres

				switch (waitKey(5)) {

				case 27: //'esc', sair
					return 0;

				case 'q': //'q', sair para resumo
					key = 1;
					break;
				case 116: //'t' , tracking
					trackingEnabled = !trackingEnabled;
					if (trackingEnabled == false) cout << "Tracking disabled." << endl;
					else cout << "Tracking enabled." << endl;
					break;
				case 100: //'d' , debug
					debugMode = !debugMode;
					if (debugMode == false) cout << "Debug mode disabled." << endl;
					else cout << "Debug mode enabled." << endl;
					break;
				case 112: //'p' pause/resume 
					pause = !pause;
					if (pause == true) {
						cout << "Code paused, press 'p' again to resume" << endl;
						while (pause == true) {
							switch (waitKey()) {
							case 112:
								pause = false;
								cout << "Code Resumed" << endl;
								break;
							}
						}
					}
				}

#pragma endregion

				//se premiu o 'q'
				if (key == 1)
					break;
			}
		}
		capture.release();
		if (key == 1)
			break;
	}


#pragma region Resultado 


	/* Fecha a janela */
	cvDestroyWindow("Origem");


	Mat result = imread("fundo.jpeg");

	namedWindow("Resultado", WINDOW_NORMAL);
	TCHAR *username = (TCHAR*)calloc(21, sizeof(TCHAR));;
	Apresentacao(username);
	while (true)
	{
		sprintf(str, "Nome : %ws", username);
		putText(result, str, cvPoint(20, 20), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		sprintf(str, "RESOLUCAO: %dx%d", video.width, video.height);
		putText(result, str, cvPoint(20, 40), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		sprintf(str, "TOTAL DE FRAMES: %d", video.fps);
		putText(result, str, cvPoint(20, 60), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		sprintf(str, "TEMPO: %d s", (fim - inicio) / 1000);
		putText(result, str, cvPoint(20, 80), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		sprintf(str, "Laranjas: %d", totLaranjas);
		putText(result, str, cvPoint(20, 100), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);
		sprintf(str, "Outros: %d", totOutros);
		putText(result, str, cvPoint(20, 120), CV_FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 100), 2);

		imshow("Resultado", result);

		switch (waitKey(10))
		{
		case 'q':
			return 0;
			break;
		}


	}



#pragma endregion


	return 0;
}
