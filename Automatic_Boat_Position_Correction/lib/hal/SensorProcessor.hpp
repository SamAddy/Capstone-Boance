#ifndef _SENSOR_PROCESSOR_H
#define _SENSOR_PROCESSOR_H

#include "../interfaces/IAccelerometer.hpp"
#include "../interfaces/IGyroscope.hpp"
#include "../libraries/LSM6DSL-Arduino/src/LSM6DSL.h"

class SensorProcessor
{
    public:
        SensorProcessor(IAccelerometer& accel, IGyroscope& gyro);
        ~SensorProcessor(){}

        void Calibrate(int nrOfSamples);

        Position GetFilteredRotation();
        
        float GetLastAccelReadings(int nrOfReadings);
        Position GetLastRotationReadings(int nrOfReadings);

    private:

        IAccelerometer& accelerometer;
        IGyroscope& gyroscope;

        Position lastRotation;
        unsigned long currentTime;
        unsigned long previousTime;
        unsigned long elapsedTime;

};

#endif