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

#include "vc.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <process.h>
#include <windows.h> 
#pragma warning(disable : 4996)

#pragma region Methods


/// <summary>
/// Comoes the correu.
/// </summary>
/// <param name="estado">if set to <c>true</c> [estado].</param>
int ComoCorreu(int estado)
{
	if (estado == 1) {
		printf("\nTudo bem\n");
		return 1;
	}
	else
		printf("\nTudo mal\n");
	return 0;

}

// Texto
/// <summary>
/// Menus this instance.
/// </summary>
void Menu()
{
	printf("\n# 1 - Polo");
	printf("\n# 2 - Mercedes estranho");
	printf("\n# 3 - Mercedes preto");
	printf("\n# 4 - Volvo");
	printf("\n# 5 - Todas");
	printf("\n# 6 - Especial de corrida");
	printf("\n# 7 - Abordagem diferente");
	printf("\n# 0 - Sair\n\n");
	printf("->");

}

//Mecanismo de recepção da opção
/// <summary>
/// Recebes the opcao menu.
/// </summary>
/// <param name="opcao">The opcao.</param>
int RecebeOpcaoMenu(int opcao)
{
	int boleano;
	opcao = -1;
	boleano = 0;
	system("cls");
	Menu();

	do
	{
		scanf("%d", &opcao);
		if (opcao >= 0 && opcao <= 9)
			boleano = 1;
	} while (boleano != 1);
	return opcao;
}

//Texto
/// <summary>
/// Repetir | Sair
/// </summary>
void SubMenu()
{
	printf("\n\n# 1 - Repetir");
	printf("\n# 0 - Sair\n\n");
	printf("->");

}

//Mecanismo de recepção da sub opção
/// <summary>
/// Receive the sub opcao menu.
/// </summary>
/// <param name="opcaoSubMenu">The opcao sub menu.</param>
int RecebeOpcaoSubMenu(int opcaoSubMenu)
{
	int boleano;
	opcaoSubMenu = -1;
	boleano = 0;
	SubMenu();

	do
	{
		scanf("%d", &opcaoSubMenu);
		if (opcaoSubMenu >= 0 && opcaoSubMenu <= 1)
			boleano = 1;
	} while (boleano != 1);
	system("cls");
	return opcaoSubMenu;
}

char* str_reverse(char* str)
{
	float len;
		int i;
	char temp;

	len = strlen(str);
	int k;

	for (i = 0, k = len - 1; i < (len / 2); i++, k--)
	{
		temp = str[k];
		str[k] = str[i];
		str[i] = temp;

	}
	

	str[9] = '\0';
	return str;
}


#pragma endregion 	  			 

int main(void)
{	
	//Pesos das cores | intensidade = r*0.299 + g*0.587 + b* 0.114;
	int hi = MessageBox(0,"Queres ver o meu trabalho ?","Visão por Computador",4);

	if (hi != 6)
		return 0;	

	#pragma region Variaveis

	IVC *imageSrc;
	IVC *imageDst;
	int formula;	
	int i=0;
	
	int niveis = 1;		
	int opcaoMenu = -1;
	int opcaoSubMenu = -1;
	char *filenameNew;
	char *filenameOld;

	#pragma endregion
	
	
	#pragma region Body

	do
	{
		opcaoMenu = RecebeOpcaoMenu(opcaoMenu);

		switch (opcaoMenu)
		{

			#pragma region 1

					case 1:
						do
						{
							system("cls");

							filenameNew = "Novas_Imagens\\polo.pbm";
							filenameOld = "Images\\Plate\\Imagem01-8449FS.ppm";

							imageSrc = vc_read_image(filenameOld);
							imageDst = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);
							
							#pragma region Verificação

							if (imageSrc == NULL)
							{
								printf_s("Error -> File not found");
								getchar();
								return 0;
							}

							#pragma endregion 

							if(ComoCorreu(imagem_um(imageSrc, imageDst)) != 1);

							//Escrever a imagem	
							else vc_write_image(filenameNew, imageDst);

							//Escrever a imagem	
							vc_write_image(filenameNew, imageDst);

							//Abrir Ficheiros
							system(filenameOld);
							system(filenameNew);	  							

							opcaoSubMenu=RecebeOpcaoSubMenu(opcaoSubMenu);
						} while (opcaoSubMenu != 0);
						i++;
						break;

			#pragma endregion

			#pragma region 2

					case 2:
						do
						{
							system("cls");

							filenameNew = "Novas_Imagens\\mercedes_estranho.pbm";
							filenameOld = "Images\\Plate\\Imagem02-8281DH.ppm";

							imageSrc = vc_read_image(filenameOld);
							imageDst = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

							#pragma region Verificação

							if (imageSrc == NULL)
							{
								printf_s("Error -> File not found");
								getchar();
								return 0;
							}

#pragma endregion 

							if(ComoCorreu(imagem_dois(imageSrc, imageDst)) != 1);

							//Escrever a imagem	
							else vc_write_image(filenameNew, imageDst);

							//Escrever a imagem	
							vc_write_image(filenameNew, imageDst);

							//Abrir Ficheiros
							system(filenameOld);
							system(filenameNew);

							opcaoSubMenu=RecebeOpcaoSubMenu(opcaoSubMenu);
						} while (opcaoSubMenu != 0);
						i++;
						break;

			#pragma endregion

			#pragma region 3

					case 3:
						do
						{
							system("cls");

							filenameNew = "Novas_Imagens\\mercedes_preto.pbm";
							filenameOld = "Images\\Plate\\Imagem03-6468QN.ppm";

							imageSrc = vc_read_image(filenameOld);
							imageDst = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

							#pragma region Verificação

							if (imageSrc == NULL)
							{
								printf_s("Error -> File not found");
								getchar();
								return 0;
							}

#pragma endregion 

							if(ComoCorreu(imagem_tres(imageSrc, imageDst)) != 1);

							//Escrever a imagem	
							else vc_write_image(filenameNew, imageDst);

							//Escrever a imagem	
							vc_write_image(filenameNew, imageDst);

							//Abrir Ficheiros
							system(filenameOld);
							system(filenameNew);

							opcaoSubMenu=RecebeOpcaoSubMenu(opcaoSubMenu);
						} while (opcaoSubMenu != 0);
						i++;
						break;

			#pragma endregion

			#pragma region 4

					case 4:
						do
						{
							system("cls");

							filenameNew = "Novas_Imagens\\volvo.pbm";
							filenameOld = "Images\\Plate\\Imagem04-11GF03.ppm";

							imageSrc = vc_read_image(filenameOld);
							imageDst = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

							#pragma region Verificação

							if (imageSrc == NULL)
							{
								printf_s("Error -> File not found");
								getchar();
								return 0;
							}

#pragma endregion 

							if(ComoCorreu(imagem_quatro(imageSrc, imageDst))!= 1);

							//Escrever a imagem	
							else vc_write_image(filenameNew, imageDst);

							//Abrir Ficheiros
							system(filenameOld);
							system(filenameNew);

							opcaoSubMenu=opcaoSubMenu= RecebeOpcaoSubMenu(opcaoSubMenu);
						} while (opcaoSubMenu != 0);
						i++;
						break;

			#pragma endregion

			#pragma region 5

					case 5:
						do
						{
							system("cls");

							filenameNew = "Novas_Imagens\\Todas\\polo.ppm";
							filenameOld = "Images\\Plate\\Imagem01-8449FS.ppm";
							ComoCorreu(imagem_todas(filenameNew,filenameOld));
							system(filenameNew);

							filenameNew = "Novas_Imagens\\Todas\\mercedes_estranho.ppm";
							filenameOld = "Images\\Plate\\Imagem02-8281DH.ppm";
							ComoCorreu(imagem_todas(filenameNew, filenameOld));
							system(filenameNew);

							filenameNew = "Novas_Imagens\\Todas\\mercedes_preto.ppm";
							filenameOld = "Images\\Plate\\Imagem03-6468QN.ppm";
							ComoCorreu(imagem_todas(filenameNew, filenameOld));
							system(filenameNew);

							filenameNew = "Novas_Imagens\\Todas\\volvo.ppm";
							filenameOld = "Images\\Plate\\Imagem04-11GF03.ppm";
							ComoCorreu(imagem_todas(filenameNew, filenameOld));
							system(filenameNew);

							filenameNew = "Novas_Imagens\\Todas\\branco.ppm";
							filenameOld = "Images\\Plate\\IMG_20160331_144028.ppm";
							ComoCorreu(imagem_todas(filenameNew, filenameOld));
							system(filenameNew);

							filenameNew = "Novas_Imagens\\Todas\\mota.ppm";
							filenameOld = "Images\\Plate\\imagem6.ppm";
							ComoCorreu(imagem_todas(filenameNew, filenameOld));
							system(filenameNew);

							filenameNew = "Novas_Imagens\\Todas\\matpreto.ppm";
							filenameOld = "Images\\Plate\\imagem7.ppm";
							ComoCorreu(imagem_todas(filenameNew, filenameOld));
							system(filenameNew);


							opcaoSubMenu=RecebeOpcaoSubMenu(opcaoSubMenu);
						} while (opcaoSubMenu != 0);

						break;

			#pragma endregion

			#pragma region 6

					case 6:
						do
						{
							system("cls");

							filenameNew = "Novas_Imagens\\branco.pbm";
							filenameOld = "Images\\Plate\\IMG_20160331_144028.ppm";

							imageSrc = vc_read_image(filenameOld);
							imageDst = vc_image_new(imageSrc->width, imageSrc->height, 1, 255);

							#pragma region Verificação

							if (imageSrc == NULL)
							{
								printf_s("Error -> File not found");
								getchar();
								return 0;
							}

#pragma endregion 

							if (ComoCorreu(imagem_cinco(imageSrc, imageDst)) != 1);

							//Escrever a imagem	
							else vc_write_image(filenameNew, imageDst);

							//Abrir Ficheiros
							system(filenameOld);
							system(filenameNew);

							opcaoSubMenu = RecebeOpcaoSubMenu(opcaoSubMenu);
						} while (opcaoSubMenu != 0);

						break;

#pragma endregion

			#pragma region 7

					case 7:
						do
						{
							system("cls");


							
							
							filenameNew = "Novas_Imagens\\polo.ppm";
							filenameOld = "Images\\Plate\\Imagem01-8449FS.ppm";
							ComoCorreu(imagem_todas_retangle(filenameNew, filenameOld));
							system(filenameNew);
								

							filenameNew = "Novas_Imagens\\mercedes_estranho.ppm";
							filenameOld = "Images\\Plate\\Imagem02-8281DH.ppm";
							ComoCorreu(imagem_todas_retangle(filenameNew, filenameOld));
							system(filenameNew);

							
							filenameNew = "Novas_Imagens\\mercedes_preto.ppm";
							filenameOld = "Images\\Plate\\Imagem03-6468QN.ppm";
							ComoCorreu(imagem_todas_retangle(filenameNew, filenameOld));
							system(filenameNew);							
							
							
							
							filenameNew = "Novas_Imagens\\volvo.ppm";
							filenameOld = "Images\\Plate\\Imagem04-11GF03.ppm";
							ComoCorreu(imagem_todas_retangle(filenameNew, filenameOld));
							system(filenameNew);
							

							opcaoSubMenu = RecebeOpcaoSubMenu(opcaoSubMenu);
						} while (opcaoSubMenu != 0);

						break;

			#pragma endregion

			#pragma region 0

					case 0:
						exit(0);

						break;

			#pragma endregion

			#pragma region Default

					default:
						printf("\nNot Found");

						break;

			#pragma endregion
		}

	} while (true);

	#pragma endregion

										   
	#pragma region Resto  
		
	//Free
	vc_image_free(imageSrc);
	vc_image_free(imageDst);
	

	//END
	printf("Press any key");
	getchar();

#pragma endregion

	return 0;
}  