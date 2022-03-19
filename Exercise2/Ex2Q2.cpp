#include <stdio.h>

long long* converter(long long* arr, long long second);

long long* converter(long long* arr, long long second){
    long long day = second / (24 * 3600);
    second -= (day * 24 * 3600);
    long long hour = second / 3600;
    second -= (hour * 3600);
    long long minute = second / 60;
    second -= (minute * 60);
    arr[0] = day;
    arr[1] = hour;
    arr[2] = minute;
    arr[3] = second;
    return arr;
}


int main(){
    long long arr[4];
    long long* result;
    long long second;
    printf("Enter the number of seconds:");
    scanf("%lld", &second);
    result = converter(arr, second);
    printf("%lld seconds = %lld days, %lld hours, %lld minutes, %lld seconds\n", 
        second, result[0], result[1], result[2], result[3]);
}