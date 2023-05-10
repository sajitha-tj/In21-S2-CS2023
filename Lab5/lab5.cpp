#include<iostream>
#include<chrono>
#include<iomanip>

using namespace std;

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void RecursiveQuickSort(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start;
    for(int j = start;j<end;j++)
    {
        if(arr[j] <= pivot)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    if(start < i-1)
    {
        RecursiveQuickSort(arr,start,i-1);
    }
    if(i+1 < end)
    {
        RecursiveQuickSort(arr,i+1,end);
    }
}


void NonRecursiveQuickSort(int arr[],int start,int end){
    int stack[end-start+1];
    int top = -1;
    stack[++top] = start;
    stack[++top] = end;
    while(top >= 0)
    {
        end = stack[top--];
        start = stack[top--];
        int pivot = arr[end];
        int i = start;
        for(int j = start; j < end; j++)
        {
            if(arr[j] <= pivot)
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                i++;
            }
        }
        int temp = arr[i];
        arr[i] = arr[end];
        arr[end] = temp;
        if(i+1 < end)
        {
            stack[++top] = i+1;
            stack[++top] = end;
        }
        if(start < i-1)
        {
            stack[++top] = start;
            stack[++top] = i-1;
        }
    }
}


void randomArrayGen(int arr[],int size)
{
    for(int i = 0;i<size;i++)
    {
        arr[i] = rand()%1001;
    }
    
}

int main(){
    while (true){
        int size;
        cout << "Array size : ";
        cin >> size;

        if(size < 0){
            return 0;
        }

        int arr[size];
        randomArrayGen(arr, size);
        int copyOfArr[size];
        for(int j=0; j < size; j++){
            copyOfArr[j] = arr[j];
        }
        auto start_time = chrono::high_resolution_clock::now();
        RecursiveQuickSort(arr,0,size-1);
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count();
        cout<<"Time taken by recursive quicksort: "<<std::fixed << std::setprecision(10)<<duration<<" microseconds"<<endl;

        auto nr_start_time = chrono::high_resolution_clock::now();
        NonRecursiveQuickSort(copyOfArr,0,size-1);
        auto nr_end_time = chrono::high_resolution_clock::now();
        auto nr_duration = chrono::duration_cast<chrono::duration<double>>(nr_end_time - nr_start_time).count();
        cout<<"Time taken by non recursive quicksort: "<<std::fixed << std::setprecision(10)<<nr_duration<<" microseconds"<<endl;
    }
    return 0;
}