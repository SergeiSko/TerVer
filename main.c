#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 50

static Tesk;

float fMax(float a[SIZE]);
float fMin(float a[SIZE]);
float fSg(float max, float min);
float fsokr(float a);
float Abs2(float a);
int kolMi(float a[SIZE], float min, float max);
float fokr(float b);
float fOkrPlus(float a);

int main()
{
    int i, kolP[5], kolM[5];
    float a[SIZE], tmp;
    int flag = 0;
    char EndTesk[10] = {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'};

    FILE *read_file;
    read_file = fopen("C:\\Laba\\Ter2.txt", "r");
    for(i = 0; i < SIZE; i += 5)
    {
        fscanf(read_file, "%f ", &a[i]);
        fscanf(read_file, "%f ", &a[i + 1]);
        fscanf(read_file, "%f ", &a[i + 2]);
        fscanf(read_file, "%f ", &a[i + 3]);
        fscanf(read_file, "%f ", &a[i + 4]);
    }
    do
    {
        flag = 0;
        for (i = 1; i < SIZE; i++)
        {
            if (a[i] < a[i - 1])
            {
                tmp = a[i -1];
                a[i - 1] = a[i];
                a[i] = tmp;
                flag = 1;
            }
        }
    } while(flag == 1);
    ///--------------------------------------
    float max, min;
    int temp;
    float j, det, sokr, otkl, kmax, kmin;
    max = fMax(a);
    min = fMin(a);
    det = fSg(max, min);
    sokr = fsokr(det);
    otkl = Abs2(det - sokr);
    ///------

    kmin = (float) ((int) (min));
    kmax = (float) ((int) (max));

    for(j = kmin, i = 0; j < kmax; i++)
    {
        kolM[i] = kolMi(a, kmin, kmax);
        j += 0.7;
    }
    for(i = 0; i < 8;i++)
    {
        printf("[%d]: %d\n", i, kolM[i]);
    }
    ///--------------------------------------
    ///+++++++статастическое среднее и дисперсия
    float sred = 0, dis = 0;
    for(i = 0; i < SIZE; i++)
    {
        sred += a[i];
    }
    sred /= 50;
    for(i = 0; i < SIZE; i++)
    {
        dis += pow((a[i] - sred), 2);
    }
    dis *= 50/49;
    printf("Statist srednee = %.3f\ndispersia: %.3f\n", sred, dis);
    ///-------stat srednee i stat dispers iz 6 chasti
    float xStarI[8] = {-2.65, -1.95, -1.25, -0.55, 0.15, 0.85, 1.55, 2.25};///указывается из таблицы 3
    float mI[8] = {1, 1, 8, 11, 14, 8, 6, 1};

    float sum2 = 0, sum3 = 0;
    for(i = 0; i < 8; i++)
    {
        sum2 += xStarI[i] * mI[i];
    }
    sum2 /= 50;
    printf("staticst srednee: %f\n", sum2);
    for(i = 0; i < 8; i++)
    {
        sum3 += (xStarI[i] - sum2) * (xStarI[i] - sum2) * mI[i];///возведено в квадрат без метода pow
    }
    sum3 /= 50;
    printf("staticst dispers: %f\n", sum3);

    ///+++++++
    FILE *Sfile;
    Sfile = fopen("C:\\Laba\\TerOtv2.txt", "w");
    fprintf(Sfile, "Statist srednee = %.3f\ndispersia: %.3f\n", sred, dis);
    for(i = 0; i < SIZE; i += 5)
    {
        fprintf(Sfile, "%.3f ", a[i]);
        fprintf(Sfile, "%.3f ", a[i +1]);
        fprintf(Sfile, "%.3f ", a[i +2]);
        fprintf(Sfile, "%.3f ", a[i +3]);
        fprintf(Sfile, "%.3f \n", a[i +4]);
    }
    fprintf(Sfile, "Max:= %.3f\nMin:= %.3f\ndet: %.3f\nSokr: %.3f\nOtkl: %.3f\nkmin: %.3f\n", max, min, det, sokr, otkl, kmin);
    fclose(Sfile);

    printf("Max:= %.3f\nMin:= %.3f\nDet: %.3f\nSokr: %.3f\nOtkl: %.3f\nkMax: %d\nkMin: %.3f\n", max, min, det, sokr, otkl, kmax, kmin);
    return 0;
}

float fMax(float a[SIZE])
{
    float max = a[0];
    int i;

    for(i = 1; i < SIZE; i++)
    {
        if (a[i] > max)
        max = a[i];
    }
    return max;
}

float fMin(float a[SIZE])
{
    float min = a[0];
    int i;

    for(i = 1; i < SIZE; i++)
    {
        if (a[i] < min)
        min=a[i];
    }
    return min;
}

float fSg(float max, float min)
{
    float det;
    det =(max - min)/(1 + 3.32 * log10(50));
    return det;
}
float fsokr(float b)
{
    float a = b;
    a = ((float) ((int) (a * 10))) / 10;
    b = ((float) ((int) (a * 100))) / 100;
    if(a >= 0.*5)
    {
        a += 0.1;
    }
    return a;
}

float Abs2(float a)
{
    if(a < 0)
    {
        a *= -1;
    }
    return a;
}

int kolMi(float a[SIZE], float min, float max)
{
    int i, kol = 0;

    for(i = 0; i < SIZE; i++)
    {
        if(a[i] < max && a[i] > min)
        {
            kol++;
        }
    }

    return kol;
}

float fokr(float a)
{
    float b = a;
    a = (int) (a);
    if(a < 0)
    {
        b = a - 1;
    }
    else
    {
        b = a + 1;
    }
    return b;
}

float fOkrPlus(float a)
{


    return a;
}

