#include <iostream>
#include <cstring>  
#include "wavfile.h"

using namespace std;
const int Max_Size =  1000000;
const int Max_name = 100;
void readFromFile(unsigned char arr[], int &size, int& samplingRate);
void upSampleAudio(unsigned char arr[], int size, int samplingRate, char* fileName);
void allocateArray(unsigned char *& arr, int size);
void deallocateArray(unsigned char *& arr);
unsigned char* shrinkarray(unsigned char arr[], int size);
unsigned char* doublearray(unsigned char *& arr, int size);
void FillWithMean(unsigned char *in,unsigned char *out, int N,int size);
void downSampleAudio(unsigned char arr[], int size, int samplingRate, char* fileName);
void movingAverageFilter(unsigned char *& arr,int &size, char inputFile[],char outputFile[], int N, bool &success);
void mergeArray(unsigned char *& arr1, unsigned char *& arr2,unsigned char*& arr3, int &size1, int &size2, int& size3);



// audio mixing
void audioMixing()
{
    char fileName1[Max_name] = "sallimono.wav";
    char fileName2[Max_name] = "dhani.wav";
    
    char outName1[Max_name] = "mixed_salli.wav";
    char outName2[Max_name] = "mixed_dhani.wav";

    int samplingRate1, samplingRate2;
    unsigned char *arr1 = nullptr;
    unsigned char *arr2 = nullptr;
    unsigned char *arr3 = nullptr;
    int size1=Max_Size,size2=Max_Size;
    
    allocateArray(arr1,size1);
    allocateArray(arr2,size2);
    
    readWavFile(fileName1, arr1, size1, samplingRate1);
    readWavFile(fileName2, arr2, size2, samplingRate2);
    
    int size3 = size1+size2;
    allocateArray(arr3, size3);
    
    mergeArray(arr1, arr2, arr3, size1, size2, size3);
    writeWavFile(outName1, arr3, size3, samplingRate1);
    writeWavFile(outName2, arr3, size3, samplingRate2);
    
    deallocateArray(arr1);
    deallocateArray(arr2);
    deallocateArray(arr3);
    
}

// mergeArray
void mergeArray(unsigned char *& arr1, unsigned char *& arr2,unsigned char*& arr3, int &size1, int &size2, int& size3)
{
    int i=0;
    int j=0;
    int k=0;
    while (i<size1 && j<size2)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    while (i<size1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j<size2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    
}

// MovingAverageFilter function
void movingAverageFilter(unsigned char *& arr,int &size, char inputFile[],char outputFile[], int N, bool &success)
{
    size = Max_Size;
    unsigned char *filteredData = nullptr;
    
    int samplingRate;
    
    
    if(readWavFile(inputFile, arr, size, samplingRate))
    {
       allocateArray(filteredData, size); 
        
        // Apply moving average filter
        FillWithMean(arr, filteredData, N, size);

        // Write filtered data to new file
        writeWavFile(outputFile, filteredData, size, samplingRate);

        deallocateArray(filteredData);
        success = true;
    }
    else
    {
        success = false;
    }
}

// File Reading Function
void readFromFile(unsigned char arr[], int &size, int &samplingRate)
{
    char fileName[Max_name];
    cout << "Enter the file name: " << endl;
    cin >> fileName;
    bool success = readWavFile(fileName, arr, size, samplingRate); 
    if(success)
    {
        cout << "File Read Successfully" << endl;
        cout << "Length: " << size << endl;
        cout << "Sampling Rate: " << samplingRate << endl;
    }
    else
        cout << "Error reading wav file." << endl;
}

// Upsampling Audio Function
void upSampleAudio(unsigned char arr[], int size, int samplingRate, char* fileName)
{
    unsigned char* upsampledArr = doublearray(arr, size); 
    int newSize = size*2;
    writeWavFile(fileName, upsampledArr, newSize, samplingRate); 
    deallocateArray(upsampledArr);
}

// downSampling Audio Function
void downSampleAudio(unsigned char arr[], int size, int samplingRate, char* fileName)
{
    unsigned char* downsampledArr =  shrinkarray(arr, size);
    int new_size = (size + 1) / 2;
    writeWavFile(fileName, downsampledArr, new_size, samplingRate); 
    deallocateArray(downsampledArr);
}

// allocate Memory Function
void allocateArray(unsigned char *& arr, int size)
{
    arr = new unsigned char [size];
}

// Deallocate Memory function
void deallocateArray(unsigned char *& arr)
{
    delete[] arr;
}

// Printing function for array
void print(unsigned char *& arr, int size)
{
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << '\n';
}

// duplicating array function
unsigned char* doublearray(unsigned char *& arr, int size)
{
    int new_size = size * 2;
    unsigned char* double_arr = new unsigned char [new_size];
    int N=0;
    for(int i=0; i<size; i++)
    {
        *(double_arr+N) = arr[i];
        *(double_arr+N+1) = arr[i];
        N+=2;
    }
    return double_arr;
}

// shrinking array function
unsigned char* shrinkarray(unsigned char arr[], int size)
{
    int new_size;
    if(size%2!=0)
    {
        new_size = (size/2)+1;
    }
    else 
    {
        new_size = (size/2);
    }
    unsigned char* shrink_arr = new unsigned char [new_size];
    int N=0;
    for(int i=0; i<size; i+=2)
    {
        shrink_arr[N] = arr[i];
        N++;
    }
    return shrink_arr;
}

// Mean function
void FillWithMean(unsigned char *in,unsigned char *out, int N,int size)
{
    int left,right,count,sum=0;
    for(int i=0; i<size; i++)
    {
        left = i - N;
        if(left < 0)
            left = 0;
            
            right = i + N;
            if(right >= size)
            right = size - 1;
            for(int j=left; j<=right; j++)
            {
                sum += in[j];
                count = right - left + 1;
            }
            out[i] =  sum/count;
            sum=0;
            count=0;
        
        
    }
    
}

int main()
{
    int size = Max_Size;
    unsigned char *arr = nullptr;
    int input;
    int samplingRate;
    char fileName[Max_name];
    allocateArray(arr, size);
    bool process = true;
    while (process)
    {
        
        cout << "Welcome to the Menu option: "
             << "\n1. Read Audio File"
             << "\n2. Up Sample Audio"
             << "\n3. Down Sample Audio"
             << "\n4. Apply Moving Average Filter"
             << "\n5. Mix two Audio Signals"
             << "\n6. Play file"
             << "\n7. Exit" << endl;
        cin >> input;

        if(input == 1)
        {
            readFromFile(arr, size, samplingRate);
        }
        else if(input == 2)
        {
            cout << "Enter New File Name you want to make: " << endl;
            cin >> fileName;
            upSampleAudio(arr, size, samplingRate, fileName); 
        }
        else if(input == 3)
        {
            cout << "Enter New File Name you want to make: " << endl;
            cin >> fileName;
            downSampleAudio(arr, size, samplingRate, fileName);
        }
        else if(input == 4)
        {
            char inputFile[Max_name];
            char outputFile[Max_name];

            cout << "Enter input wav file: ";
            cin >> inputFile;
            int N;

            cout << "Enter output wav file: ";
            cin >> outputFile;

            cout << "Enter value of N: ";
            cin >> N;
            bool success=true; 
            movingAverageFilter(arr, size, inputFile, outputFile, N, success);
            if (success)
            {
                cout << "File Read Successfully" << endl;
            }
            else 
                cout << "Error while reading the file" << endl;
        }
        else if(input == 5)
        {
            audioMixing();
        }
        else if(input == 6)
        {
            cout << "Enter File Name: " << endl;
            cin >> fileName;
            playWavFile(fileName);
        }
        else if(input == 7 || input>= 7)
        {
            process = false;
        }
    }
    deallocateArray(arr);
    return 0;
}

