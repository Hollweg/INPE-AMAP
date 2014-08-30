
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <sys/types.h>
#include <dirent.h>

short int num_error = 0;
short int counter = 0;


/*****************************************************************************
 * Name:
 *     Transc_Arch_SUPIM_South_America_Data_Sample_1_10
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivos - Transforma arquivos provenientes do SUPIM
 *   em arquivos prontos para simulacao no SGEMS. A funcao recorta os dados de TEC do globo
 *   pegando apenas valores contidos na américa latina. Filtro de amostras TEC de 2e^11
 *
 *****************************************************************************/



int Transc_Arch_SUPIM_South_America_Data_Sample_1_10(const char *name_arch_in, const char *name_arch_out, short int header){

    FILE *input,*output;
    float lat,lon,alt,ne;
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    short int header_receiver;
    float pi = 3.1415927;
    int counter = 0;

    Inicio_Verificacao_Dados:

                header_receiver = header;
                raw = name_arch_in;
                out = name_arch_out;

                if (header_receiver == 1 ){
                        if ((output = fopen(out,"w")) == NULL)  {
                            printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Supim \n");
                        fprintf(output,"4 \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"Longitude \n");
                        fprintf(output,"Altitude \n");
                        fprintf(output,"NE\n");

                        fclose(output);
                                        }

                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);




    Inicio_Transcricao_Dados:

                do{
                       while((strcmp(temp,"LAT")!=0) && (!feof(input))){
                                fscanf(input,"%s",temp);
                                //printf("%s",temp);
                                                    }

                        fscanf(input,"%f",&lat);
                        //printf("%.8f\n",lat);

                        // Leitura do label "LON"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        // Leitura do label "ALT"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&alt);
                        //printf("%.1f\n",alt);

                        while((strcmp(temp,"NE")!=0) && (!feof(input))){
                            fscanf(input,"%s",temp);
                            //printf("%s",temp);
                                                    }
                        fscanf(input,"%f",&ne);
                        counter = counter + 1;

                        if (counter == 10)
                        {
                                if (((lon >= cos(-70*pi/180)) && (lon <= cos(-30*pi/180))) && (((lat <= cos (-40*pi/180)) && (lat >= 0))))
                                    {
                                    //fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada
                                    if (ne > 2.0e+11)
                                        fprintf(output, "%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada
                                    }
                         counter = 0;
                        }
                   //Modelo de Campo Supim
                                                                                                                           //usar a equacao matematica discreta ao lado
                                                                                                                                                        //deduzida de acordo com o que o SUPIM recolhe
                                                                                                                                                        //de informacoes
                                                                                                                                                        //plotados no arquivo na forma x,y,z e NE
                } while (!feof(input));

    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;

}//~~

/*****************************************************************************
 * Name:
 *     Transc_Arch_SUPIM_South_America
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivos - Transforma arquivos provenientes do SUPIM
 *   em arquivos prontos para simulacao no SGEMS. A funcao recorta os dados de TEC do globo
 *   pegando apenas valores contidos na américa latina. Filtro de amostras TEC de 2e^11
 *
 *****************************************************************************/



int Transc_Arch_SUPIM_South_America(const char *name_arch_in, const char *name_arch_out, short int header){

    FILE *input,*output;
    float lat,lon,alt,ne;
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    short int header_receiver;
    float pi = 3.1415927;

    Inicio_Verificacao_Dados:

                header_receiver = header;
                raw = name_arch_in;
                out = name_arch_out;

                if (header_receiver == 1 ){
                        if ((output = fopen(out,"w")) == NULL)  {
                            printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Supim \n");
                        fprintf(output,"4 \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"Longitude \n");
                        fprintf(output,"Altitude \n");
                        fprintf(output,"NE\n");

                        fclose(output);
                                        }

                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);




    Inicio_Transcricao_Dados:

                do{
                       while((strcmp(temp,"LAT")!=0) && (!feof(input))){
                                fscanf(input,"%s",temp);
                                //printf("%s",temp);
                                                    }

                        fscanf(input,"%f",&lat);
                        //printf("%.8f\n",lat);

                        // Leitura do label "LON"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        // Leitura do label "ALT"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&alt);
                        //printf("%.1f\n",alt);

                        while((strcmp(temp,"NE")!=0) && (!feof(input))){
                            fscanf(input,"%s",temp);
                            //printf("%s",temp);
                                                    }
                        fscanf(input,"%f",&ne);
                        counter = counter + 1;


                        if (((lon >= cos(-70*pi/180)) && (lon <= cos(-30*pi/180))) && (((lat <= cos (-40*pi/180)) && (lat >= 0))))
                            {
                            //fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada
                            if (ne > 2.0e+11)
                                fprintf(output, "%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada
                            }

                   //Modelo de Campo Supim
                                                                                                                           //usar a equacao matematica discreta ao lado
                                                                                                                                                        //deduzida de acordo com o que o SUPIM recolhe
                                                                                                                                                        //de informacoes
                                                                                                                                                        //plotados no arquivo na forma x,y,z e NE
                } while (!feof(input));

    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;

}//~~


/*****************************************************************************
 * Name:
 *     Transc_Arch_SUPIM_Data_Sample_400
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivos - Transforma arquivos provenientes do SUPIM
 *   em arquivos prontos para simulacao no SGEMS. A funcao contem um data sample
 *   pegando 2 amostra em cada 400 amostras que contenham valores validos de TEC
 *
 *****************************************************************************/


int Transc_Arch_SUPIM_Data_Sample_400(const char *name_arch_in, const char *name_arch_out, short int header){

    FILE *input,*output;
    float lat,lon,alt,ne;
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    short int header_receiver;
    float pi = 3.1415927;

    Inicio_Verificacao_Dados:

                header_receiver = header;
                raw = name_arch_in;
                out = name_arch_out;

                if (header_receiver == 1 ){
                        if ((output = fopen(out,"w")) == NULL)  {
                            printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Supim \n");
                        fprintf(output,"4 \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"Longitude \n");
                        fprintf(output,"Altitude \n");
                        fprintf(output,"NE\n");

                        fclose(output);
                                        }

                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);




    Inicio_Transcricao_Dados:

                do{
                       while((strcmp(temp,"LAT")!=0) && (!feof(input))){
                                fscanf(input,"%s",temp);
                                //printf("%s",temp);
                                                    }

                        fscanf(input,"%f",&lat);
                        //printf("%.8f\n",lat);

                        // Leitura do label "LON"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        // Leitura do label "ALT"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&alt);
                        //printf("%.1f\n",alt);

                        while((strcmp(temp,"NE")!=0) && (!feof(input))){
                            fscanf(input,"%s",temp);
                            //printf("%s",temp);
                                                    }
                        fscanf(input,"%f",&ne);
                        counter = counter + 1;

                   //Modelo de Campo Supim
                                                                                                                                                    //das coordenadas x,y e z deve-se



                  if (counter == 400){
                             fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada
                             counter = 0;
                                            }

                                            //das coordenadas x,y e z deve-se
                                            //usar a equacao matematica discreta ao lado
                                            //deduzida de acordo com o que o SUPIM recolhe
                                            //de informacoes
                                            //plotados no arquivo na forma x,y,z e NE
                } while (!feof(input));

    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;

}//~~

/*****************************************************************************
 * Name:
 *     Transc_Arch_SUPIM_Data_Sample
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivos - Transforma arquivos provenientes do SUPIM
 *   em arquivos prontos para simulacao no SGEMS. A funcao nao contem um data sample
 *   pegando apenas valores de NE maiores que 1e^11.
 *
 *****************************************************************************/


int Transc_Arch_SUPIM_Data_Sample(const char *name_arch_in, const char *name_arch_out, short int header){

    FILE *input,*output;
    float lat,lon,alt,ne;
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    short int header_receiver;
    float pi = 3.1415927;

    Inicio_Verificacao_Dados:

                header_receiver = header;
                raw = name_arch_in;
                out = name_arch_out;

                if (header_receiver == 1 ){
                        if ((output = fopen(out,"w")) == NULL)  {
                            printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Supim \n");
                        fprintf(output,"4 \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"Longitude \n");
                        fprintf(output,"Altitude \n");
                        fprintf(output,"NE\n");

                        fclose(output);
                                        }

                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);




    Inicio_Transcricao_Dados:

                do{
                       while((strcmp(temp,"LAT")!=0) && (!feof(input))){
                                fscanf(input,"%s",temp);
                                //printf("%s",temp);
                                                    }

                        fscanf(input,"%f",&lat);
                        //printf("%.8f\n",lat);

                        // Leitura do label "LON"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        // Leitura do label "ALT"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&alt);
                        //printf("%.1f\n",alt);

                        while((strcmp(temp,"NE")!=0) && (!feof(input))){
                            fscanf(input,"%s",temp);
                            //printf("%s",temp);
                                                    }
                        fscanf(input,"%f",&ne);
                        counter = counter + 1;


                        if (ne > 1e+11){
                             fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada
                             //counter = 0;
                                            }

                   //Modelo de Campo Supim
                   //das coordenadas x,y e z deve-s                                                                                                                             //usar a equacao matematica discreta ao lado
                   //deduzida de acordo com o que o SUPIM recolhe
                   //de informacoes
                   //plotados no arquivo na forma x,y,z e NE

                } while (!feof(input));

    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;

}//~~


/*****************************************************************************
 * Name:
 *    Transc_Arch_Org_SUPIM_all
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivos - Transforma arquivos provenientes do SUPIM
 *   em arquivos prontos para simulacao no SGEMS. A funcao nao contem nenhum tipo de
 *   data sample. Pegando todos os valores de NE disponiveis no arquivo bruto
 *
 *****************************************************************************/

int Transc_Arch_Org_SUPIM_all(const char *name_arch_in, const char *name_arch_out, short int header){

    FILE *input,*output;
    float lat,lon,alt,ne;
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    short int header_receiver;
    float pi = 3.1415927;

    Inicio_Verificacao_Dados:

                header_receiver = header;
                raw = name_arch_in;
                out = name_arch_out;

                if (header_receiver == 1 ){
                        if ((output = fopen(out,"w")) == NULL)  {
                            printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Supim \n");
                        fprintf(output,"4 \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"Longitude \n");
                        fprintf(output,"Altitude \n");
                        fprintf(output,"NE\n");

                        fclose(output);
                                        }

                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);




    Inicio_Transcricao_Dados:

                do{
                       while((strcmp(temp,"LAT")!=0) && (!feof(input))){
                                fscanf(input,"%s",temp);
                                //printf("%s",temp);
                                                    }

                        fscanf(input,"%f",&lat);
                        //printf("%.8f\n",lat);

                        // Leitura do label "LON"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        // Leitura do label "ALT"
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&alt);
                        //printf("%.1f\n",alt);

                        while((strcmp(temp,"NE")!=0) && (!feof(input))){
                            fscanf(input,"%s",temp);
                            //printf("%s",temp);
                                                    }
                        fscanf(input,"%f",&ne);
                        //counter = counter + 1;


                      if (ne > 0){
                             fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne);       //Fazendo a transformacao mais adequada
                             //counter = 0;
                                     }                                                                                                                         //de informacoes
                                                                                                                                                                      //plotados no arquivo na forma x,y,z e NE
                } while (!feof(input));

    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;

}


/*****************************************************************************
 * Name:
 *    Transc_Arch_Org_Erro
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivos - Transforma arquivos finais de
 *   simulacao SGEMS - Erro = Variancia - em arquivos que possam novamente
 *   ser plotados em formato .txt por algum visualizador de matriz
 *
 *****************************************************************************/


int Transc_Arch_Org_Erro(const char *name_arch_in, char *name_arch_out, short int header){

    FILE *input,*output;
    float lat,lon,ne;
    char teste[200];
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    short int header_receiver;


    Inicio_Verificacao_Dados:

                header_receiver = header;
                raw = name_arch_in;
                out = name_arch_out;

                if (header_receiver == 1 ){
                        if ((output = fopen(out,"w")) == NULL)  {
                            printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Variancia \n");
                        fprintf(output,"3 \n");
                        fprintf(output,"Longitue \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"Valor \n");
                        fclose(output);
                                        }

                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);

    Inicio_Transcricao_Dados:

        do{

            fscanf(input,"%s",teste);

           }while((strcmp(teste,"Erro") != 0) && (!feof(input)));

            do{
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lat);

                        //printf("%.8f\n",lat);
                        // Leitura do label "LON"

                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&ne);

                        //printf("%f \n",ne);

                        // Gravação no arquivo de saida
                        // fprintf(output,"%f %f %f %f",1*lat,1*lon,1*alt,1*ne);

                       /*if (header_receiver == 0){
                               do{
                                        fscanf(output,"%f",&ne);

                                  }while(!feof(output));
                                        }
                        */
                       //fseek(output, 0, SEEK_END);

                            //fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada

                        //if (ne != 999.000)
                            fprintf(output,"%f %f %f \n", (lon - 360) ,lat , ne); //Fazendo a transformacao mais adequada


                                                                            //das coordenadas x,y e z deve-se
                                                                            //usar a equacao matematica discreta ao lado
                                                                            //deduzida de acordo com o que o SUPIM recolhe
                                                                            //de informacoes
                                                                            //plotados no arquivo na forma x,y,z e NE
                } while (!feof(input));


    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;

}//~~



/*****************************************************************************
 * Name:
 *    Transc_Arch_Org_SGEMS_Single
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivo - Transforma arquivo de 1 hora no formato
 *   recebido por observacao espacial para formato SGEMS - Cria labels e organiza
 *   em 3 colunas: latitude/longitude/NE
 *   P.S: Valores NE de 999.999 sao descartdos via software
 *
 *****************************************************************************/

int Transc_Arch_Org_SGEMS_Single(const char *name_arch_in, const char *name_arch_out, short int header){

    FILE *input,*output;
    float lat,lon,ne;
    char teste[200];
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    short int header_receiver;


    Inicio_Verificacao_Dados:

                header_receiver = header;
                raw = name_arch_in;
                out = name_arch_out;

                if (header_receiver == 1 ){
                        if ((output = fopen(out,"w")) == NULL)  {
                            printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Supim \n");
                        fprintf(output,"3 \n");
                        fprintf(output,"Longitude \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"NE\n");
                        fclose(output);
                                        }

                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);

    Inicio_Transcricao_Dados:

        do{

            fscanf(input,"%s",teste);

           }while((strcmp(teste,"[x10^16/m^2]") != 0) && (!feof(input)));

            do{
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lat);

                        //printf("%.8f\n",lat);
                        // Leitura do label "LON"

                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&ne);

                        //printf("%f \n",ne);

                        // Gravação no arquivo de saida
                        // fprintf(output,"%f %f %f %f",1*lat,1*lon,1*alt,1*ne);

                       /*if (header_receiver == 0){
                               do{
                                        fscanf(output,"%f",&ne);

                                  }while(!feof(output));
                                        }
                        */
                       //fseek(output, 0, SEEK_END);

                            //fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada

                        if (ne != 999.000)
                            fprintf(output,"%f %f %f \n", (lon - 360), lat, ne); //Fazendo a transformacao mais adequada


                                                                            //das coordenadas x,y e z deve-se
                                                                            //usar a equacao matematica discreta ao lado
                                                                            //deduzida de acordo com o que o SUPIM recolhe
                                                                            //de informacoes
                                                                            //plotados no arquivo na forma x,y,z e NE
                } while (!feof(input));

    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;

}//~~


/*****************************************************************************
 * Name:
 *    Transc_Arch_Org_SGEMS_Multi
 * In:
 *    const char *name_arch_in, const char *name_arch_out, short int header
 * Out:
 *    0
 * Description:
 *   Funcao de transcricao de arquivos - Transforma multiplos arquivos de hora no formato
 *   recebido por observacao espacial para formato SGEMS - Cria labels e organiza
 *   em 3 colunas: latitude/longitude/NE
 *
 *   P.S: Valores NE de 999.999 sao descartados via software
 *
 *****************************************************************************/

int Transc_Arch_Org_SGEMS_Multi(const char *name_arch_in, const char *name_arch_out){

    FILE *input,*output;
    float lat,lon,ne;
    char teste[200];
    char temp[200];
    const char *raw;
    const char *out;
    char caracter;
    int contador = 0;

    Inicio_Verificacao_Dados:


                raw = name_arch_in;
                out = name_arch_out;


                if ((output = fopen(out,"w")) == NULL)  {
                        printf("Erro de Abertura no arquivo %s \n", out);
                                                                }

                        fprintf(output,"Supim \n");
                        fprintf(output,"3 \n");
                        fprintf(output,"Longitude \n");
                        fprintf(output,"Latitude \n");
                        fprintf(output,"NE\n");
                        fclose(output);


                if ((input = fopen(raw,"rt")) == NULL){
                        printf("Erro de Abertura no arquivo %s \n", raw);
                        goto Final_Transcricao_Dados;
                                                      }

                else if ((output = fopen(out,"a")) == NULL)
                        printf("Erro de Abertura no arquivo %s \n", out);

                //fopen(output);

    Inicio_Transcricao_Dados:

        do{

            fscanf(input,"%s",teste);

           }while((strcmp(teste,"[x10^16/m^2]") != 0) && (!feof(input)));

            do{
                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lat);

                        //printf("%.8f\n",lat);
                        // Leitura do label "LON"

                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&lon);
                        //printf("%.8f\n",lon);

                        fscanf(input,"%s",temp);
                        fscanf(input,"%f",&ne);

                        //printf("%f \n",ne);

                        // Gravação no arquivo de saida
                        // fprintf(output,"%f %f %f %f",1*lat,1*lon,1*alt,1*ne);

                       /*if (header_receiver == 0){
                               do{
                                        fscanf(output,"%f",&ne);

                                  }while(!feof(output));
                                        }
                        */
                       //fseek(output, 0, SEEK_END);

                            //fprintf(output,"%f %f %f %f \n", (cos(lon)*cos(lat))*(6370000+alt) ,(sin(lon)*cos(lat))*(6370000+alt), sin(lat)*(6370000+alt), ne); //Fazendo a transformacao mais adequada

                        if (ne != 999.000){
                         //   if (contador == 600){
                            fprintf(output,"%f %f %f \n", (lon - 360) ,lat, ne); //Fazendo a transformacao mais adequada
                         //       contador = 0;   }
                            contador++;
                                           }
                     /*       if (( lon > 180) && (lon <=270))
                                fprintf(output,"%f %f %f \n", (lon - 180) ,lat, ne); //Fazendo a transformacao mais adequada
                              else if (( lon > 270) && (lon <=360))
                                fprintf(output,"%f %f %f \n", (360 - lon) ,lat, ne); //Fazendo a transformacao mais adequada


                      */

                                                                            //das coordenadas x,y e z deve-se
                                                                            //usar a equacao matematica discreta ao lado
                                                                            //deduzida de acordo com o que o SUPIM recolhe
                                                                            //de informacoes
                                                                            //plotados no arquivo na forma x,y,z e NE
                } while (!feof(input));

    fclose(input);
    fclose(output);

              Final_Transcricao_Dados:

    return 0;
}

/*****************************************************************************
 * Name:
 *    int Main
 * In:
 *    int argc, char * argv
 * Out:
 *    0
 * Description:
 *   Funcao princpal do codigo. Seta estrutura onde ficam os arquivos de leitura
 *   e faz a chamada das funcoes correspondentes de transcricao de arquivos
 *
 *
 *****************************************************************************/


int main(int argc, char * argv){

    struct dirent *de=NULL;
    DIR *d=NULL;
    char completePath[100];
    char *output_file;
    short int flag = 0;
    static int quantity = 0;
    int valor = 0;

begin:

    printf ("\n\nINSITUTO NACIONAL DE PESQUISAS ESPACIAIS \n");
    printf ("CENTRO REGIONAL SUL \n");
    printf ("CLIMA ESPACIAL \n");
    printf ("SOFTWARE DE MANIPULACAO DE ARQUIVOS \n \n");

    printf ("Coloque os arquivos que de origem dentro da pasta InFiles \n");
    printf ("Selecione abaixo um dos modos de manipulacao \n");
    printf ("Digite para selecionar o modo de operacao do Software \n \n");
    printf ("1 - Manipulacao de arquivo unico de Estacao de GPS para (SGEMS)\n \n");
    printf ("2 - Manipulacao de arquivos de Variancia do (SGEMS)\n \n");
    printf ("3 - Manipulacao de arquivos de Estacao de GPS para (SGEMS)\n \n");
    printf ("4 - Manipulacao de arquivos amostrados do globo do Supim para (SGEMS)\n \n");
    printf ("5 - Manipulacao de arquivos amostrados do globo com data sample \nNE 1e11 do Supim \n \n");
    printf ("6 - Manipulacao de arquivos amostrados do globo com data sample \nde 1 em cada 400 amostras do Supim \n \n");
    printf ("7 - Manipulacao de arquivos amostrados da America do Sul do \nSupim. Ne > 2e11 \n \n");
    printf ("8 - Manipulacao de arquivos amostrados da America do Sul com \ndata sample de 1 para 10 do Supim \n \n");

recebe_valor:

    scanf("%d", &valor);
    //printf ("%d", valor);

    if ((((valor != 1) && (valor != 2)) && (valor != 3)) && (valor != 4) && (valor != 5) && (valor != 6) && (valor != 7) && (valor != 8)){
        valor = 0;
        goto recebe_valor;
                    }

    d=opendir("InFiles");
    if(d == NULL)
    {
        perror("Couldn't open directory");
        return(2);
    }

    output_file = "output.txt";

    // Loop while not NULL
    while(de = readdir(d)){
        //printf("Evaluating: %s\n",de->d_name);
        if ((strcmp(de->d_name,".") != 0) && (strcmp(de->d_name,"..") != 0)){
            strcpy(completePath,"./InFiles/");
            strcat(completePath,de->d_name);
            printf("\n%s",completePath);

            if (flag == 0){

                if (valor == 1)
                    Transc_Arch_Org_SGEMS_Single(completePath, "out.txt", 1);

                else if (valor == 2)
                    Transc_Arch_Org_Erro(completePath, "out.txt", 1);

                else if (valor == 3)
                    Transc_Arch_Org_SGEMS_Multi(completePath, output_file);

                else if (valor == 4)
                    Transc_Arch_Org_SUPIM_all (completePath, "out.txt", 1);

                else if (valor == 5)
                    Transc_Arch_SUPIM_Data_Sample (completePath, "out.txt", 1);

                else if (valor == 6)
                    Transc_Arch_SUPIM_Data_Sample_400 (completePath, "out.txt", 1);

                else if (valor == 7)
                    Transc_Arch_SUPIM_South_America (completePath, "out.txt", 1);

                else if (valor == 8)
                    Transc_Arch_SUPIM_South_America_Data_Sample_1_10 (completePath, "out.txt", 1);



                flag = 1;
                          }

             else

                 if (valor == 1)
                    Transc_Arch_Org_SGEMS_Single(completePath, "out.txt", 0);

                 else if (valor == 2)
                     Transc_Arch_Org_Erro(completePath, "out.txt", 0);

                 else if (valor == 3){
                     quantity++;

                     switch(quantity){


                                case 1: output_file = "output2.txt";
                                        break;

                                case 2: output_file = "output3.txt";
                                        break;

                                case 3: output_file = "output4.txt";
                                        break;

                                case 4: output_file = "output5.txt";
                                        break;

                                case 5: output_file = "output6.txt";
                                        break;

                                case 6: output_file = "output7.txt";
                                        break;

                                case 7: output_file = "output8.txt";
                                        break;

                                case 8: output_file = "output9.txt";
                                        break;

                                case 9: output_file = "output10.txt";
                                        break;

                                case 10: output_file = "output11.txt";
                                         break;

                                case 11: output_file = "output12.txt";
                                         break;

                                case 12: output_file = "output13.txt";
                                         break;

                                case 13: output_file = "output14.txt";
                                         break;

                                case 14: output_file = "output15.txt";
                                         break;

                                case 15: output_file = "output16.txt";
                                         break;

                                case 16: output_file = "output17.txt";
                                         break;

                                case 17: output_file = "output18.txt";
                                         break;

                                case 18: output_file = "output19.txt";
                                         break;

                                case 19: output_file = "output20.txt";
                                         break;

                                case 20: output_file = "output21.txt";
                                         break;

                                case 21: output_file = "output22.txt";
                                         break;

                                case 22: output_file = "output23.txt";
                                         break;

                                case 23: output_file = "output24.txt";
                                         break;

                                        }

                        Transc_Arch_Org_SGEMS_Multi(completePath, output_file);

                                    }

                    else if (valor == 4)
                        Transc_Arch_Org_SUPIM_all(completePath, "out.txt", 0);

                    else if (valor == 5)
                        Transc_Arch_SUPIM_Data_Sample (completePath, "out.txt", 0);

                    else if (valor == 6)
                        Transc_Arch_SUPIM_Data_Sample_400 (completePath, "out.txt", 0);

                    else if (valor == 7)
                         Transc_Arch_SUPIM_South_America (completePath, "out.txt", 0);

                    else if (valor == 8)
                        Transc_Arch_SUPIM_South_America_Data_Sample_1_10 (completePath, "out.txt", 0);

       }
    }

    closedir(d);

}//~~
