#include <chrono>
#include <iostream>
#include <stdexcept>
#include <string>

#ifdef PROFILE_GPERF
#include <gperftools/profiler.h>
#endif

#include "Algorithm.h"
#include "FileHandler.h"
#include "Sudoku.h"

#define SOLUTION_DIRECTORY "solution"

using namespace std;

int solve(const string FILE_NAME, const string SOLUTION_DIR){
    //TODO
}

int main(int argc, char** argv) {
    if(argc < 2){
        cout << "Not enough arguments";
        return 0;
    }
    const string FILE_NAME = string(argv[1]);

const clock_t BEGIN = clock();
#if   defined TIME
    //Do nothing
#elif defined PROFILE_VALGRIND
    //Do nothing
#elif defined PROFILE_GPERF
    string currentTime =to_string(chrono::system_clock::now().time_since_epoch().count());  
    string logName ="log/gperf/" + FILE_NAME + "_" + currentTime + ".log";  
    ProfilerStart(logName.c_str());
#elif defined CACHE
    //Do nothing
#endif
    
    solve(FILE_NAME, SOLUTION_DIRECTORY);

#if   defined TIME
    //Do nothing
#elif defined PROFILE_VALGRIND
    //Do nothing
#elif defined PROFILE_GPERF
    ProfilerStop();
#elif defined CACHE
    //Do nothing //TODO find out what we need to profile cache
#endif

    const clock_t END = clock();
    const clock_t ELASPED = END - BEGIN;
    cout << "Completed in " << ELASPED <<"\n";

#ifdef TIME
    ofstream file("log/time_report.txt", ofstream::out | ofstream::app);
    if(file.is_open()){
        file << FILE_NAME << " : " << (((double)ELASPED)/1000000) << " sec\n";
        file.close();
    }
#endif
    return 0;
}
