#include<stdio.h>

int main()
{
    int n = 0;
    char screen[7][26];
    for (int i = 0; i < 7;i++){
        for (int k = 0; k < 26;k++){
            screen[i][k] = ' ';
        }
    }

    char zero[7][5] = {{"*****"}, 
                       {"*   *"},
                       {"*   *"}, 
                       {"*   *"}, 
                       {"*   *"}, 
                       {"*   *"}, 
                       {"*****"}};

    char one[7][5] = {{"    *"}, 
                      {"    *"}, 
                      {"    *"}, 
                      {"    *"}, 
                      {"    *"}, 
                      {"    *"}, 
                      {"    *"}};

    char two[7][5] = {{"*****"}, 
                      {"    *"}, 
                      {"    *"}, 
                      {"*****"}, 
                      {"*    "}, 
                      {"*    "}, 
                      {"*****"}};

    char three[7][5] = {{"*****"},
                        {"    *"}, 
                        {"    *"}, 
                        {"*****"}, 
                        {"    *"}, 
                        {"    *"}, 
                        {"*****"}};

    char four[7][5] = {{"*   *"},
                       {"*   *"},
                       {"*   *"},
                       {"*****"},
                       {"    *"},
                       {"    *"},
                       {"    *"}};

    char five[7][5] = {{"*****"}, 
                       {"*    "}, 
                       {"*    "}, 
                       {"*****"}, 
                       {"    *"}, 
                       {"    *"}, 
                       {"*****"}};

    char six[7][5] = {{"*****"},
                      {"*    "},
                      {"*    "},
                      {"*****"},
                      {"*   *"},
                      {"*   *"},
                      {"*****"}};

    char seven[7][5] = {{"*****"},
                        {"    *"},
                        {"    *"},
                        {"    *"},
                        {"    *"},
                        {"    *"},
                        {"    *"}};

    char eight[7][5]= {{"*****"},
                       {"*   *"},
                       {"*   *"},
                       {"*****"},
                       {"*   *"},
                       {"*   *"},
                       {"*****"}};

    char nine[7][5] = {{"*****"},
                       {"*   *"},
                       {"*   *"},
                       {"*****"},
                       {"    *"},
                       {"    *"},
                       {"*****"}};
    

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n;i++){
        for (int r = 0; r < 7;r++){
            for (int k = 0; k < 26;k++){
            screen[r][k] = ' ';
            }
        }
        int offset = 0;
        char queue[6] = {0};
        fgets(queue, 6, stdin);
        for (int i = 0; i < 7;i++){
            if(queue[i]==10)
                queue[i] = 0;
        }
            printf("%s:\n", queue);
        for (int k = 0; k < 4;k++){
            switch(queue[k]){
                case 48:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = zero[p][q];
                    }
                }
                break;
                case 49:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = one[p][q];
                    }
                }
                break;
                case 50:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = two[p][q];
                    }
                }
                break;
                case 51:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = three[p][q];
                    }
                }
                break;
                case 52:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = four[p][q];
                    }
                }
                break;
                case 53:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = five[p][q];
                    }
                }
                break;
                case 54:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = six[p][q];
                    }
                }
                break;
                case 55:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = seven[p][q];
                    }
                }
                break;
                case 56:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = eight[p][q];
                    }
                }
                break;
                case 57:
                for (int p = 0; p < 7;p++){
                    for (int q = 0; q < 5;q++){
                        screen[p][q + offset] = nine[p][q];
                    }
                }
                break;
            }
        if(queue[k+1]==0){
        break;
        }
        else{
        offset = offset + 7;
        }
    }
    for (int i = 0; i < 7;i++){
        for (int k = 0; k < 26 ;k++){
            printf("%c", screen[i][k]);
        }
        printf("\n");
    }
    //printf("\n");  
}

    
}
