

#ifndef SIMPLEANOMALYDETECTOR_H_
#define SIMPLEANOMALYDETECTOR_H_

#include "anomaly_detection_util.h"
#include "AnomalyDetector.h"
#include <vector>
#include <algorithm>
#include <string.h>
#include <math.h>

struct correlatedFeatures{
	string feature1,feature2;  // names of the correlated features
	float corrlation;
	Line lin_reg;
	float threshold;
};

/**
 * SimpleAnomalyDetector class implements interface TimeSeriesAnomalyDetector
 */
class SimpleAnomalyDetector:public TimeSeriesAnomalyDetector{
	vector<correlatedFeatures> cf;
    float threshold;
public:
	SimpleAnomalyDetector();
	virtual ~SimpleAnomalyDetector();

	virtual void learnNormal(const TimeSeries& ts);
	virtual vector<AnomalyReport> detect(const TimeSeries& ts);
    void setCorrelationThreshold(float threshold){
        this -> threshold = threshold;
    }
	vector<correlatedFeatures> getNormalModel(){
		return cf;
	}

protected:
    Point** toPoints(vector<float> x, vector<float> y) {

	}

};



#endif /* SIMPLEANOMALYDETECTOR_H_ */