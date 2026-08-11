#include <stdio.h>
#include <math.h>

int main() {
    float w[50] = {40,70,61,58,58,50,72,63,51,62,65,60,68,68,78,54,52,60,50,70,60,35,53,58,79,60,62,61,55,65,51,39,45,58,50,65,62,50,72,62,52,65,67,87,45,75,71,52,65,59};
    int n=50, i, freq[6]={0};
    float min=w[0], max=w[0], sum=0, mean, sd, sq=0;

    for(i=0;i<n;i++) {
        if(w[i]<min) min=w[i];
        if(w[i]>max) max=w[i];
        sum += w[i];
    }
    mean = sum/n;
    for(i=0;i<n;i++) sq += pow(w[i]-mean,2);
    sd = sqrt(sq/(n-1));

    printf("Min=%.2f Max=%.2f Mean=%.2f SD=%.2f\n", min, max, mean, sd);

    for(i=0;i<n;i++) {
        if(w[i]>=30 && w[i]<=39) freq[0]++;
        else if(w[i]>=40 && w[i]<=49) freq[1]++;
        else if(w[i]>=50 && w[i]<=59) freq[2]++;
        else if(w[i]>=60 && w[i]<=69) freq[3]++;
        else if(w[i]>=70 && w[i]<=79) freq[4]++;
        else if(w[i]>=80 && w[i]<=89) freq[5]++;
    }

    printf("\nClass  Frequency\n");
    for(i=0;i<6;i++) printf("%d-%d      %d\n", 30+i*10, 39+i*10, freq[i]);

    printf("\nHistogram\n");
    for(i=0;i<6;i++) {
        printf("%d-%d: ", 30+i*10, 39+i*10);
        for(int j=0;j<freq[i];j++) printf("*");
        printf("\n");
    }
    return 0;
}
