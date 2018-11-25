#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize "Ofast"

bool compare(const vector<int>& a, const vector<int>& b) {
    int am = 1;
    int bm = 1;
    for(const auto&num:a) {
        am *= num;
    }
    for(const auto&num:b) {
        bm *= num;
    }
    return(am < bm);
}

int main() {
    int N;
    scanf("%i", &N);
    vector< vector<int> > boxes(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            int dimension;
            scanf("%i", &dimension);
            boxes[i].push_back(dimension);
        }
    }
    sort(boxes.begin(), boxes.end(), compare);

    int M;
    scanf("%i", &M);
    int toBPackaged [M][3];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            int dim;
            scanf("%i", &dim);
            toBPackaged[i][j] = dim;
        }
    }

    for(auto package: toBPackaged) {
        bool foundBoxThatFits = false;
        long int boxSize;
        for(auto box: boxes) {
            int w = package[0]; int l = package[1]; int h = package[2];
            if(
            (w <= box[0] && l <= box[1] && h <= box[2]) || 
            (w <= box[0] && h <= box[1] && w <= box[2]) || 

            (h <= box[0] && l <= box[1] && w <= box[2]) ||  
            (h <= box[0] && w <= box[1] && l <= box[2]) ||

            (l <= box[0] && h <= box[1] && w <= box[2]) || 
            (l <= box[0] && w <= box[1] && h <= box[2]) 
            ) {
                foundBoxThatFits = true;
                boxSize = box[0] * box[1] * box[2];
                break;
            }

        }
        if(foundBoxThatFits) {
            printf("%li\n", boxSize);
        } else {
            printf("Item does not fit.\n");
        }
    }
}