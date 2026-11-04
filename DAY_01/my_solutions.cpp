// Day 01 — my solutions
// Put your own implementations here, then run from the course root:
//     make test DAY=01 SRC=DAY_01/my_solutions.cpp
// The tests call everything defined below, so keep every name and signature.
// Leave anything unfinished as its stub: its checks report FAIL, the rest still run.
// Do not add main(); the test file provides it.
#include <cmath>
#include <string>
#include <vector>
#include<algorithm>
#include<numeric>
#include<cmath>


// ===== Main assignment: telemetry analyser =====
// TODO: copy your finished functions from starter/telemetry_analyser.cpp.

double minimum_reading(const std::vector<double>& readings) {
    // TODO: smallest value; 0.0 for empty input.
    if(readings.empty())
    return 0.0;
    else
    {
        // std::sort(readings.begin(),readings.end());
        // return(readings.at(0));

       return(*std::min_element(readings.begin(),readings.end()));

    }
}

double maximum_reading(const std::vector<double>& readings) {
    // TODO: largest value; 0.0 for empty input.

    if(readings.empty())
        return 0.0;

        else{
        return *std::max_element(readings.begin(),readings.end());

        }


    }   

double average_reading(const std::vector<double>& readings) {
    // TODO: mean value; 0.0 for empty input.
    if(readings.empty())
    return 0.0;
    
    else{

        return double(std::accumulate(readings.begin(),readings.end(),0.0)/readings.size());

    }
}

std::string classify_robot(double minimum_distance) {
    // TODO: CRITICAL < 0.20, CAUTION < 0.50, otherwise CLEAR.
    if(std::isnan(minimum_distance))
    return "UNKNOWN";

    if(minimum_distance<0.20)
    {
        return "CRITICAL";
    }

    if(minimum_distance<0.50)
    { return "CAUTION";
    }

    return "CLEAR";
         
    
}

// ===== Challenge 1: count close obstacles =====
int count_close_readings(const std::vector<double>& readings, double threshold) {
    // TODO: count readings strictly below threshold.
    
    return std::count_if(readings.begin(),readings.end(),[threshold](double distance){return distance<threshold;});
    
}

// ===== Challenge 2: convert and filter =====
std::vector<double> valid_readings(const std::vector<double>& readings) {
    // TODO: return readings in [0.0, 10.0]; do not modify the input.

    std::vector<double> valid_readings={};
    for(double data:readings)
    {if (data>=0.0 && data<=10.0)

        valid_readings.push_back(data);
        

    }
    return valid_readings;
}

// ===== Exam Part A: root mean square =====
double calculate_rms(const std::vector<double>& values) {
    // TODO: sqrt(mean of squares); 0.0 for empty input.
    
    if(!values.empty())
    {
    double sum_squares=0.0;
    sum_squares = std::accumulate(values.begin(),values.end(),sum_squares,[](double sum_squares, double value){return (sum_squares + value*value);  });
    return std::sqrt(sum_squares/values.size());

    }


    return 0.0;

}

// ===== Exam Part B: your corrected average() =====
double average(const std::vector<double>& values) {
    if (values.empty()) return 0.0;
    double total = 0.0;
    for (double value : values) total += value;
    return total / static_cast<double>(values.size());
}
