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


#define VC_DEBUG
#define EspacoMatricula 1
#define BRANCO 255
#define PRETO 0
#define MAXINT 4294967295
#define PERCENTAGEM 10
#define MINLATERAL 30
#define MINCOMPRIMENTO 60
#define DEFINEWHITE 210

#define HSVVALUEWHITE 170
#define HSVSATWHITE 15

#define HSVHUEMINBLUE 170
#define HSVHUEMAXBLUE 220

#define HSVVALUEMINBLUE 190
#define HSVVALUEMAXBLUE 255

#define HSVSATMINBLUE 70
#define HSVSATMAXBLUE 100

#define HSVSATMINBLACK 10
#define HSVSATMAXBLACK 70

#define HSVVALUEMINBLACK 10
#define HSVVALUEMAXBLACK 120

#define VALOR 50
#define XORSWAP (a, b) ((a)^=(b),(b)^=(a),(a)^=(b))


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   Listas ligadas
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//Listas Ligadas
typedef struct nodo {
	unsigned int yMin;
	unsigned int yMax;
	unsigned int pixeis;
	struct nodo *seguinte;
} *Lista, no;

typedef struct nodoC {
	unsigned int yMin;
	unsigned int yMax;
	unsigned int xMin;
	unsigned int xMax;
	unsigned int pixeis;
	struct nodoC *seguinte;
} *ListaCompleta, noC;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   MACROS
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define MAX3(a,b,c) (a > b ? (a > c? a: c) : (b > c? b : c))
#define MIN3(a,b,c) (a < b ? (a < c? a: c) : (b < c? b : c))


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                   ESTRUTURA DE UMA IMAGEM
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


typedef struct {
	unsigned char *data;
	int width, height;
	int channels;			// Binário/Cinzentos=1; RGB=3
	int levels;				// Binário=1; Cinzentos ]1,255]; RGB [1,255]
	int bytesperline;		// width * channels
} IVC;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//                    PROTÓTIPOS DE FUNÇÕES
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// FUNÇÕES: ALOCAR E LIBERTAR UMA IMAGEM
IVC *vc_image_new(int width, int height, int channels, int levels);
IVC *vc_image_free(IVC *image);

// FUNÇÕES: LEITURA E ESCRITA DE IMAGENS (PBM, PGM E PPM)
IVC *vc_read_image(char *filename);
int vc_write_image(char *filename, IVC *image);

// FUNÇÕES: DESENHO
int vc_gray_negative(IVC *srcdst);			//mostrar o negativo de uma imagem em tons de cinzento
int vc_rgb_negative(IVC *srcdst);			//mostrar o negativo de uma imagem em RGB
int vc_rgb_with_only_r(IVC *srcdst);		//mostra apenas o vermelho 
int vc_rgb_with_only_g(IVC *srcdst);		//mostra apenas o verde 
int vc_rgb_with_only_b(IVC *srcdst);		//mostra apenas o azul 
int vc_rgb_get_red_gray(IVC *srcdst);		//o que é vermelho passa a branco
int vc_rgb_get_green_gray(IVC *srcdst);		//o que é verde passa a branco
int vc_rgb_get_blue_gray(IVC *srcdst);		//o que é azul passa a branco
int vc_rgb_to_gray(IVC *src, IVC *dst);		//passa uma imagem de cores para tons de cinzento
int vc_rgb_to_hsv(IVC *src, IVC *dst);
int vc_rgb_to_hsv_filter_yellow(IVC *srcdst, int hueMin, int hueMax, int satMin, int satMax, int valueMin, int valueMax);
int vc_rgb_to_hsv_filter_red(IVC *src, IVC *dst);
int vc_gray_to_binary(IVC *src, int threshold);
int vc_gray_to_binary_global_mean(IVC *src);
int vc_gray_to_binary_midpoint(IVC *src, IVC *dst,int kernel);
int vc_binary_dilate(IVC *src, IVC *dst, int kernel);
int vc_binary_erode(IVC *src, IVC *dst, int kernel);
int vc_binary_open(IVC *src, IVC *dst, int kernel);
int vc_binary_close(IVC *src, IVC *dst, int kernel);
int vc_clear_lines(IVC *srcdst, int color, float percentagem);
int vc_clear_colluns(IVC *srcdst, int color, float percentagem);
int vc_contem_cores(IVC *RGB, int pontos[4]);
int* vc_rgb_to_hsv_filter_colors(IVC *srcdst, int contaPixeis[3], int pontos[4]);
int vc_focus_area(IVC *srcdst, float percentagem, int cor);
int vc_clear_missing_pixels(IVC *srcdst, int quantidade, int espacamento ,int cor); //quantidade  =  nº de conjunto de pixeis em linha  e espaçamento = nº de casas que poderá ter de espaço
int vc_segment_area(IVC *srcdst, int area, int numeroPontos, int cor);
int vc_segment_area_horizontal(IVC *src, int area, int numeroPontos, int cor); // se maior que a quantidade de pontos apaga
int vc_segment_area_vertical(IVC *src, int area, int numeroPontos, int cor); // se maior que a quantidade de pontos apaga
int vc_clear_missing_lines(IVC *srcdst, int quantidade, int cor);// se menor que a quantidade entao apaga
int vc_clear_missing_lines_major(IVC *srcdst, int quantidade, int cor);	
float vc_collun_mean(IVC *srcdst, int color);
int vc_clear_colluns(IVC *srcdst, int color, float percentagem);
int vc_line_mean_compare(IVC *srcdst, float mean, int color);
float vc_line_mean(IVC *srcdst, int color);
int vc_rentangle(IVC *srcdst, int espaco, int cor);		 
int vc_only_live_greatter_zona(IVC *srcdst, int cor);
char* vc_identify_plate(IVC *imagem, int cor);
int imagem_um(IVC *imageSrc, IVC *imageDst);
int imagem_dois(IVC *imageSrc, IVC *imageDst);
int imagem_tres(IVC *imageSrc, IVC *imageDst);
int imagem_quatro(IVC *imageSrc, IVC *imageDst);
int imagem_cinco(IVC *imageSrc, IVC *imageDst);
int imagem_todas(char * filenew, char* fileold);
int imagem_todas_retangle(char * filenew, char* fileold);
int vc_binary_blob_labelling(IVC *src, IVC *dst);
int* vc_find_retangle(IVC *srcdst ,IVC* imagemRGB ,int label);
int menor_array(int array[], int size);
int vc_is_rectangle(IVC *srcdst, int cor, int pontos[4]);
int vc_save_image_plate(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax, unsigned int i);
int vc_gray_histogram(IVC* src, IVC* srcD);
float vc_compare_images(IVC *srcU, IVC *srcD);
char vc_identify_letter(IVC *srcdst);
int vc_xpto_histogram(IVC* src, IVC* srcD);
int vc_resize_image(int wD, int hD, unsigned int i);
char* str_reverse(char* str);
int vc_gray_histogram_equalization(IVC *srcdst);
int vc_errase(IVC *srcdst, int xMin, int yMin, int xMax ,int yMax);
int* vc_area(IVC *srcdst, int cor);
int vc_gray_edge_prewitt(IVC *src, IVC *dst, float th);
int vc_gray_edge_sobel(IVC *src, IVC *dst, float th);
int vc_fill_stuff(IVC *src, IVC *dst, int cor);
int vc_rentangleRGB(IVC *srcdst, int pontos[4], int espaco, int cor);
int* vc_white_histogram(IVC *src, int pontos[4]);

int PintRetangulo(IVC *imagem, unsigned int xU, unsigned int yU, unsigned int xD, unsigned int yD, int cor);
void PintLinha(IVC *imagem, unsigned int xU, unsigned int yU, unsigned int xD, unsigned int yD, int cor);
void PintPonto(IVC *imagem, unsigned int x, unsigned int y, int cor);

void Liberta(Lista l);
Lista Inserir(Lista l, unsigned int min, unsigned int max, unsigned int pixeis);
ListaCompleta InserirCompleta(ListaCompleta l, unsigned int xMin, unsigned int xMax, unsigned int yMin, unsigned int yMax, unsigned int pixeis);
void LibertaCompleta(ListaCompleta l);

int numero_um(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int numero_seis(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int numero_oito(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int numero_quatro(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int numero_nove(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int letra_q(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int letra_n(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int letra_f(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
int letra_s(IVC *srcdst, unsigned int yMin, unsigned int yMax, unsigned int xMin, unsigned int xMax);
