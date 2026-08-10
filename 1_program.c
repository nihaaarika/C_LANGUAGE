#include <stdio.h>

void main() {
    
    int arr[100], n, i, key, found = 0;
    int comparison = 0;
    
    printf("enter number of value : ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
    printf("element %d", i+1);
    scanf("%d", &arr[i]);  
    }
    
    printf("\n element to search: ");
    scanf("%d", &key);
    
    for(i =0; i < n; i++) {
        comparison ++ ;
        
        if(arr[i] == key) {
        found = 1;
        break;
        }
    }
    
    if(found == 1) {
        printf("\n Element %d found at this position %d", key, i+1);
        printf("\n Total comparison: %d", comparison);
    } else {
        printf("\n Element %d not found", key);
        printf("\n Total coparison: %d", comparison);
    }
    
}
