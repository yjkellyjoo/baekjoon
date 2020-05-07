//
// Created by Yeojin Kelly Joo on 2020/05/07.
//

#include <stdio.h>

int height[100000];

int max(int a, int b){
    if (a < b){
        return b;
    }
    else {
        return a;
    }
}

int min(int a, int b){
    if (a < b){
        return a;
    }
    else {
        return b;
    }
}

int area_divide_and_conquer(int left, int right){
    if(left == right){
        return height[left];
    }
    else {
        int mid = (right + left) / 2;
        int answer = max(area_divide_and_conquer(left, mid), area_divide_and_conquer(mid + 1, right));

        // 중간 값 계산
        // 첫번째 중간 직사각형
        int low = mid;
        int high = mid+1;
        int h = min(height[low], height[high]);
        answer = max(answer, h*2);
        // 그 다음 직사각형들
        while (left < low || high < right){
            // 왼 오 중 높이가 더 높은 쪽으로 이동
            // 오른쪽으로 가는 조건
            if(high < right && ((low == left) || height[low-1] < height[high+1])){
                high++;
                h = min(h, height[high]);
            }
            // 왼쪽으로 가는 조건
            else {
                low--;
                h = min(h, height[low]);
            }
            answer = max(answer, h*(high - low + 1));
        }
        return answer;
    }
}


int main(){
    int n;

    printf("input number of bars: ");
    scanf("%d", &n);
    printf("input heights in order: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &height[i]);
    }

    int answer = area_divide_and_conquer(0, n);
    printf("answer: %d\n", answer);

    return 0;
}