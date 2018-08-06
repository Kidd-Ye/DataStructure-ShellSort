//
//  main.cpp
//  ShellSort
//
//  Created by kidd on 2018/8/6.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
using namespace std;

void ShellSort_one(int arr[], int length){
    
    for (int dk = length/2; dk >= 1; dk = dk/2) {
        for (int i = dk + 1; i <= length; ++i) {
            if (arr[i] < arr[i-dk]) {
                arr[0] = arr[i];
                int j;
                for (j = i-dk; j > 0 && arr[0] < arr[j]; j-=dk) {
                    arr[j+dk] = arr[j];
                }
                arr[j+dk] = arr[0];
            }
        }
    }
}



void ShellSort(int arr[], int length) {
    
    int dk = length/2;
    int x,j;
    while(dk >= 1) {
        for(int i = dk; i < length; i++) {
            x=arr[i];
            j=i-dk;
            //直接插入排序，会向前找所适合的位置
            while(j>=0 && arr[j]>x) {
                //交换位置
                arr[j+dk]=arr[j];
                j=j-dk;
            }
            arr[j+dk]=x;
        }
        dk = dk/2;
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, ShellSort !\n";
    
    int arr[] = {0,1,45,23,76,87,35,26,38,22,66,8,10};
    int length = sizeof(arr)/sizeof(*arr);
    cout << "第一种写法：" <<endl;
    ShellSort_one(arr, length-1);
    for (int i = 1; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "第二种写法：" <<endl;
    int arr1[] = {0,1,45,23,76,87,35,26,38,22,66,8,10};
    ShellSort(arr1, length);
    for (int i = 1; i < length; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}
