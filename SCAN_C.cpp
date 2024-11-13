#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

void scan(int previousPosition, int currentPosition, vector<int> requestQueue, int maxDiskPosition){
	bool movingUpwards = currentPosition > previousPosition; 
	vector<int> movementPath;				
    int totalDistance = 0;				
	sort(requestQueue.begin(), requestQueue.end());
	
	vector<int> requestsAbove, requestsBelow;
	for(int request : requestQueue){
		if(request > currentPosition) requestsAbove.push_back(request);
		else requestsBelow.push_back(request);
	}
	
	if(movingUpwards){
		if(!requestsAbove.empty()){
			for(int request : requestsAbove){
				movementPath.push_back(request);
				totalDistance += abs(currentPosition - request);
				currentPosition = request;			
			}
		}
		if(!requestsBelow.empty()){
			totalDistance += abs(currentPosition - maxDiskPosition);
			currentPosition = maxDiskPosition;
			movementPath.push_back(maxDiskPosition);
			
			for(auto it = requestsBelow.rbegin(); it != requestsBelow.rend(); ++it){
				movementPath.push_back(*it);
				totalDistance += abs(currentPosition - *it);
				currentPosition = *it;	
			}
		}
	}
	else{
		if(!requestsBelow.empty()){
			for(auto it = requestsBelow.rbegin(); it != requestsBelow.rend(); ++it){
				movementPath.push_back(*it);
				totalDistance += abs(currentPosition - *it);
				currentPosition = *it;	
			}
		}
		if(!requestsAbove.empty()){
			totalDistance += abs(currentPosition - 0);
			currentPosition = 0;
			movementPath.push_back(0);
			
			for(int request : requestsAbove){
				movementPath.push_back(request);
				totalDistance += abs(currentPosition - request);
				currentPosition = request;			
			}
		}
	}
	cout << "Recorrido: ";
    for (int position : movementPath) {
        cout << position << " ";
    }
    cout << endl;
    
    cout << "Longitud: " << totalDistance << endl;
    double time = static_cast<double>(totalDistance) / movementPath.size();
    cout << "Tiempo promedio: " << time << endl;
}

void cscan(int previousPosition, int currentPosition, vector<int> requestQueue, int maxDiskPosition){
	bool movingUpwards = currentPosition > previousPosition; // Determinar la direccion
	vector<int> movementPath;				// Almacenar recorrido
    int totalDistance = 0;				// Longitud total
	sort(requestQueue.begin(), requestQueue.end());
	
	vector<int> requestsAbove, requestsBelow;
	for(int request : requestQueue){
		if(request > currentPosition) requestsAbove.push_back(request);
		else requestsBelow.push_back(request);
	}
	
	if(movingUpwards){
		if(!requestsAbove.empty()){
			for(int request : requestsAbove){
				movementPath.push_back(request);
				totalDistance += abs(currentPosition - request);
				currentPosition = request;			
			}
		}
		if(!requestsBelow.empty()){
			totalDistance += abs(currentPosition - maxDiskPosition);
			currentPosition = maxDiskPosition;
			movementPath.push_back(maxDiskPosition);
			
			totalDistance += maxDiskPosition;
			currentPosition = 0;
			movementPath.push_back(0);
			
			for(int request : requestsBelow){
				movementPath.push_back(request);
				totalDistance += abs(currentPosition - request);
				currentPosition = request;			
			}
		}
	}
	else{
		if(!requestsBelow.empty()){
			for(auto it = requestsBelow.rbegin(); it != requestsBelow.rend(); ++it){
				movementPath.push_back(*it);
				totalDistance += abs(currentPosition - *it);
				currentPosition = *it;	
			}
		}
		if(!requestsAbove.empty()){
			totalDistance += abs(currentPosition - 0);
			currentPosition = 0;
			movementPath.push_back(0);
			
			totalDistance += maxDiskPosition;
			currentPosition = maxDiskPosition;
			movementPath.push_back(maxDiskPosition);
			
			for(auto it = requestsAbove.rbegin(); it != requestsAbove.rend(); ++it){
				movementPath.push_back(*it);
				totalDistance += abs(currentPosition - *it);
				currentPosition = *it;	
			}
		}
	}
	cout << "Recorrido: ";
    for (int position : movementPath) {
        cout << position << " ";
    }
    cout << endl;
    
    cout << "Longitud: " << totalDistance << endl;
    double time = static_cast<double>(totalDistance) / movementPath.size();
    cout << "Tiempo promedio: " << time << endl;
}

int main(){
	int testCases;
	ifstream inputFile("input.txt");
	inputFile >> testCases;
	
	for (int t = 0; t < testCases; t++){
		int currentPosition, previousPosition, maxDiskPosition, numRequests;
		inputFile >> currentPosition;
	    inputFile >> previousPosition;
	    inputFile >> maxDiskPosition;
	    inputFile >> numRequests;
	    vector<int> requestQueue(numRequests);
	    for (int i = 0; i < numRequests; i++) {
	        inputFile >> requestQueue[i];
	    }
	    
        cout << ">>>Caso de prueba " << t + 1 << ":" << endl;
        cout << "      ++++++  ALGORITMO SCAN   ++++++ " << endl;
        scan(previousPosition, currentPosition, requestQueue, maxDiskPosition);
        cout << "--------------------------------------" << endl;
        cout << "      ++++++  ALGORITMO CSCAN  ++++++" << endl;
        cscan(previousPosition, currentPosition, requestQueue, maxDiskPosition);
        cout << " " << endl;
	}
	
    inputFile.close();
    return 0;
}
