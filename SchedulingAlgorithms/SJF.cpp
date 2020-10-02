/*

Scheduling Algorithm SJF 
created by Velisarios 

*/

#include <iostream>
using namespace std;


class SJF{
    public:
        static int* calcWaitingTime(int* burstTime, int quantum, int burstTimeSize){
           int* waitingTime;
           waitingTime = new int[burstTimeSize];
           SJF::bubblesort(burstTime, burstTimeSize);
           int sum = 0;
           for(int i = 0; i < burstTimeSize; i++){
               waitingTime[i] = sum;
               sum = sum + burstTime[i];
           }

           return waitingTime;

       }

       static void bubblesort(int* array, int size){
           for(int i = 0; i < size-1; i++){
            for(int j = 0; j < size - i - 1; j++){
                if(array[j] > array[j+1])
                {
                     array[j] = array[j]+ array[j+1];
                     array[j+1] = array[j]-array[j+1];
                     array[j] = array[j] - array[j+1];
                }

            }
        }
      }

       static int* calcTurnAroundTime(int* burstTime, int* waitingTime, int burstTimeSize){
           int* turnAroundTime;
           turnAroundTime = new int[burstTimeSize];
           
           for(int i = 0; i < burstTimeSize; i++){
               turnAroundTime[i] = burstTime[i] + waitingTime[i];
           }

           return turnAroundTime;
       }

       static void printAvgTimes(int* burstTime, int quantum, int burstTimeSize){
           int n = burstTimeSize;
           int totalWaitingTime = 0;
           int totalTurnAroundTime = 0;

           int* waitingTime = calcWaitingTime(burstTime, quantum, burstTimeSize);
           int* turnAroundTime = calcTurnAroundTime(burstTime, waitingTime, burstTimeSize);

           cout << "Process " << " Burst Time " << 
					" Waiting Time " << " Turnaround Time\n" << endl; 
           cout << "=======  ==========  ============  ===============" << endl;

           
           for(int i = 0 ; i < n; i++){
              totalWaitingTime += waitingTime[i]; 
			totalTurnAroundTime += turnAroundTime[i];
            cout << i << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] <<
                  "\t\t" << turnAroundTime[i] << endl;
           }

           cout << "\nAverage waiting time = " << 
						(float)totalWaitingTime / (float)n << endl;

           cout <<  "Average turnaround time = " << 
						(float)totalTurnAroundTime / (float)n << endl;          
       }
};


int main(){
    int burstTime[4] = {5, 15, 4, 3};
    int quantunm = 3;

    SJF::printAvgTimes(burstTime, quantunm, 4);
}